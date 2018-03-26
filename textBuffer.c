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



void addNewLine(struct buffer* ptr, int line, int lineCount){
	char** textBufferPtr = ptr->textBuffer;
	int i;
	//Move all indices down 1 to make room for the new line
	for (i = lineCount; i >= line; i--){
		textBufferPtr[i] = textBufferPtr[i - 1];
	}

	//Creating the new line where it should be
	textBufferPtr[line - 1] = "\n";
	
	//Update lineCount
	lineCount++;
	ptr->lineCount = lineCount;
	
}
