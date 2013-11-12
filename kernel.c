
void printToScreen(char letter,int location);


int main() {
	printToScreen('H', 0x8140);
	printToScreen('E', 0x8142);
	printToScreen('L', 0x8144);
	printToScreen('L', 0x8146);
	printToScreen('O', 0x8148);
	printToScreen(' ', 0x8150);
	printToScreen('W', 0x8152);
	printToScreen('O', 0x8154);
	printToScreen('R', 0x8156);
	printToScreen('L', 0x8158);
	printToScreen('D', 0x815A);


	
	while(1){
	};
}

void printToScreen(char letter, int location){
	putInMemory(0xB000, location, letter);
	putInMemory(0xB000, location+1, 0x7);
}
