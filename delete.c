#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "delete.h"


int Delete(char ** text, int lineCount){

int x,y;
getyx(stdscr,y,x);
move(y,0);
clrtoeol();
move(y, x);

}