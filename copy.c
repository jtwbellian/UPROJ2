#include <stdio.h>
#include <string.h>
#include <ncurses.h>


int startx, starty;
int endx, endy;
int tempx,tempy;

void copyStart() {
	
	//get cursor starting position
	getyx(stdscr, tempy, tempx);
	mvprintw(0, 0, "%s", "Starting index chosen.");
	move(tempy, tempx);
	getyx(stdscr, starty, startx);
   
}


void copyEnd() {
	
	//get cursor ending position
	getyx(stdscr, endy, endx);
	getyx(stdscr, tempy, tempx);
	
	mvprintw(0, 0, "%s", "End index chosen.");
	move(tempy, tempx);
}

char* paste() {
	
	int pastex, pastey;
	char copyString[endx-startx]; //string to store copied text

	//load copied text into string
	for (int s = startx; s < endx; s++) {
		copyString[s] = mvinch(starty, s);
	}
	
	//paste copied text to screen at cursor location
	//getyx(stdscr, pastey, pastex);
	//for (int i = 0; i < endx - startx; i++) {
	//	mvprintw(pastey, i + pastex, "%c", copyString[i]);
	//}

	return copyString;
	
}
