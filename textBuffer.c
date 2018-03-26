// textBuffer.c 
// Programmed by John Barulich

#include "textBuffer.h"

//Returns the number of lines of the initial text file
//Inserts each line into an array of char*
int fillBuffer(char* file, char* textBuffer[], int lineCount){
	FILE *in;
	in = fopen(file, "r");
	int i;
	//Allocate memory for each pointer of the buffer
	for (i = 0; i < MAX_LEN_ROW; i++){
		textBuffer[i] = malloc(MAX_LEN_ROW * sizeof *textBuffer);
	}
	
	//Inserts the line into textBuffer[lineCount] and incrememnts lineCount
	while (lineCount < MAX_LEN_ROW && fgets(textBuffer[lineCount], MAX_LEN_COL, in)){
		lineCount++;	
	}
	return lineCount;
}
