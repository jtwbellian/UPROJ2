#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "delete.h"


//int Delete(char ** text,int lineCount){

//char src [CHAR_PER_LINE];
//char dest [CHAR_PER_LINE];
//Vars to store current cursor position
//int x,y;
//get current position 
//getyx(stdscr,y,x);
//move cursor to beginning of line
//for(int i = y; i < lineCount; i++){
   
//   strcpy(src, text[i+1]);
 //  strncpy(dest, src, MAX_LEN_ROW);
 // text[i] =  dest;
//	return lineCount - 1;
//}
int Delete(char ** text, int row, int lineCount){
	
	//Creating the new line where it should be
	text[row-1] = malloc(MAX_LEN_ROW * sizeof *text); 
	//Move lines up to replace blank line
	for (int i = row; i <= lineCount; i++){
		text[i] = text[i+1];
	}
	//Update lineCount
	return lineCount - 1;
}
