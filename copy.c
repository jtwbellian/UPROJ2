#include <stdio.h>
#include <string.h>
#include <ncurses.h>


int startx, starty;
int endx, endy;
int tempx,tempy;

void copyStart() {

	getyx(stdscr, tempy, tempx);
	mvprintw(0, 0, "%s", "Starting index chosen.");
	move(tempy, tempx);
	getyx(stdscr, starty, startx);
   
}


void copyEnd() {
	
	getyx(stdscr, endy, endx);
	getyx(stdscr, tempy, tempx);
	char copyString[endy-starty];
	
	mvprintw(0, 0, "%s", "End index chosen.");
	move(tempy, tempx);
	for (s = startx; s < endx; s++) {
		copyString[s] = mvinch(starty, s);
	}
}

void paste() {
	
	int pastex, pastey;
	
	getyx(stdscr, pastey, pastex);
	for (int i = 0; i < endx - startx; i++) {
		mvprintw(pastey, i + pastex, "%c", copyString[i]);
	}
	
}