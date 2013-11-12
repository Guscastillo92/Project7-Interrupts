
void printString(char* string);
void readString(char* string);


int main() {
	char line[80];
	printString("Hello World \0");
	readString(line);
	printString(line);
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
			position = position -1;
			interrupt(0x10, 0xE*256+character, 0, 0, 0);
		}
		else {
			string[position] = character;
			position = position +1;
			interrupt(0x10, 0xE*256+character, 0, 0, 0);
		}
	}
	string[position] = 0xa;
	string[position+1]= 0x0;
}
