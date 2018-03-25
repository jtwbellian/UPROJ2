// Editor.c
// Implementation for editor functions
// Programmed by James Bellian 03/24/18

#include "Editor.h"

char * filename = "FILEA.txt";
const char * lines[] =
{
        " LINE 1 .................................................",
        " LINE 2 .................................................",
        " LINE 3 .................................................",
        " LINE 4 .................................................",
        " LINE 5 .................................................",
        " LINE 6 ................................................."
};

// initializes the editor and starts the program
void init(Editor *e)
{
	// start/setup nCurses
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
	size_t n = 20;
	
	// set to 2 to give room for margins
	e->x = 1;
	e->y = 1;

	e->scroll = 0;
	e->mode = 'e';
	getmaxyx(stdscr, e->h, e->w);
	
	mvprintw(e->h/2,e->w/3, " Welcome to Group 1 Text Editor! ");
        
	// 'Header' and 'Footer'
	wattron(stdscr,A_REVERSE);
	mvprintw(0,0,"Group 1\t\tFILE: %s\n", filename);

        mvprintw(e->h-1,1, (e->mode == 'e') ? "Line %d,%d) \t-EDIT MODE-":"Line %d,%d \t-COMMAND MODE-", e->y + e->scroll, e->x);
        wattroff(stdscr,A_REVERSE);
	
	refresh();
	start(e);
}

// Begins the main loop of the program 
void start(Editor *e)
{
	int ch;

	while (e->mode != 'x')
        {
               	 ch  = getch(); // gets the users key
		
		// read Keyboard cursor movement in both modes
                switch(ch)
                {
                case KEY_LEFT:
                        if (e->x > 1)
                                e->x --;
                        break;
                case KEY_RIGHT:
                        if (e->x < e->w-1)
                                e->x ++;
                        break;
                case KEY_UP:
                        if (e->y > 1)
                                e->y --;
                        else if (e->scroll > 0)
                                e->scroll --;
                        break;
                case KEY_DOWN:
                        if (e->y < e->h-2)
                                e->y ++;
                        else
                                e->scroll ++;
                        break;
                case 27: // ESC pressed
                        e->mode = 'x';
                        break;
                }
		
		// Keyboard input when in Edit Mode
		if (e->mode == 'e')
		{	
			
		}
	
                clear_window(e);
                update_window(e);
                wattron(stdscr, A_REVERSE);
		mvprintw(e->h-1,1, (e->mode == 'e') ? "Line %d,%d) \t-EDIT MODE-":"Line %d,%d \t-COMMAND MODE-", e->y + e->scroll, e->x);

                wattroff(stdscr,A_REVERSE);

                wmove(stdscr,e->y,e->x);


                refresh();
        }

        clear_window(e);
        mvprintw(e->h/2,e->w/3,"PROGRAM WILL NOW TERMINATE");
        mvprintw(e->h/2+1,e->w/3,"Goodbye!");
  	refresh();
        getch();
	endwin();
}


// Draws text from string buffer to window
void update_window(Editor *e)
{
	// recalculates window size (in case it has been resized since last update)
        getmaxyx(stdscr,e->h,e->w);

        // Displays the text between the scroll position and the bottom of the window
        for(int i = 0; (i < e->h && lines[i + e->scroll + 1] != NULL); i ++)
        {
                mvprintw(i + 1, 1, "%s", lines[i + e->scroll]);
        }
}

// Prints blank spaces to clear out the window
void clear_window( Editor *e)
{
	// recalculates window size (in case it has been resized since last update)
        getmaxyx(stdscr,e->h,e->w);

        for(int i = 1; i < e->h-1; i++)
        for(int j = 0; j < e->w; j++)
        {
                if (j==0)
                        mvprintw(i,j,"~");
                else
                        mvprintw(i,j," ");
        }
}




