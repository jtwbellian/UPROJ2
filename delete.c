#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "delete.h"


int Delete(char ** text, int *row int lineCount){
//Vars to store current cursor position
int x,y;
//get current position 
getyx(stdscr,y,x);
//move cursor to beginning of line
for(int i = x; i < lineCount; i++){
   
   strcpy(src, text[i+1]);
   strncpy(dest, src, MAX_LEN_ROW);
   text[i] =  dest;
}

}