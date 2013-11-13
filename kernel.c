
void printString(char* string);
void readString(char* string);
void readSector(char* buffer, int sector);
int mod(int a, int b);
int div(int a, int b);
void handleInterrupt21(int ax, int bx, int cx, int dx);

int main() {
	char line[80];
	makeInterrupt21();
	interrupt(0x21,1,line,0,0);
	interrupt(0x21,0,line,0,0);


	while(1){
	};
}

void printString(char* string){
	int position = 0;
	while(string[position] != '\0'){
		interrupt(0x10, 0xE*256+string[position], 0, 0, 0);
		position = position +1;
	}
}
void readString(char* string){
	int position = 0;
	char character = 0x0;
	while(character != 0xd){
		character = interrupt(0x16, 0, 0, 0, 0);
		if(character == 0xd){
			break;
		}
		else if(character == 0x8){
			if(position > 1){
				position = position -1;
				interrupt(0x10, 0xE*256+character, 0, 0, 0);
			}
		}
		else {
			string[position] = character;
			position = position +1;
			interrupt(0x10, 0xE*256+character, 0, 0, 0);
		}
	}
	interrupt(0x10, 0xE*256+0xa, 0, 0, 0);
	string[position] = 0xa;
	string[position+1]= 0x0;
}
void readSector(char* buffer, int sector){
	int relSec = mod(sector,18)+1;
	int head= mod(div(sector,18),2);
	int track = div(sector,36);
	interrupt(0x13, 2*256+1, buffer, track*256+relSec, head*256+0);
	
}
int mod(int a, int b){
	while ( a >= b){
		a = a-b;
	}
	return a;

}
int div(int a, int b){
	int q = 0;
	while (q*b <= a){
		q = q+1;
	}
	return q-1;
}
void handleInterrupt21(int ax, int bx, int cx, int dx){
	
	
	if(ax == 0){
		while( bx != '\0'){
			interrupt(0x10, 0xE*256+bx, 0, 0, 0);
			bx= bx+1;
		}
	} else if (ax == 1){
		int base =bx;
		char character = 0x0;
		while(character != 0xd){
			character = interrupt(0x16, 0, 0, 0, 0);
			if(character == 0xd){
				break;
			}
			else if(character == 0x8){
				if(bx > base){
					bx = bx -1;
					interrupt(0x10, 0xE*256+character, 0, 0, 0);
				}
			}
			else {
				bx = character;
				bx = bx +1;
				interrupt(0x10, 0xE*256+character, 0, 0, 0);
			}
		}
		interrupt(0x10, 0xE*256+0xa, 0, 0, 0);
		bx = 0xa;
		bx = bx+1;
		bx = 0x0;

	} else if (ax == 2){

	} else {
		
	}
}









