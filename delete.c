// delete.c
// Programmed by Osa Edomwande

#include <ncurses.h>
#include "delete.h"


int Delete(char ** text, int line, int lineCount){

/*	int x,y;
	getyx(stdscr,y,x);
	move(y,0);
	clrtoeol();
	move(y, x);
*/

	int x,y;
	
	getyx(stdscr,y,x);

	for(int i = line; i < lineCount; i ++)
	{
		text[i+1] = text[i];
	}
	
return 0;
}
