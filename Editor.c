// Editor.c
// Implementation for editor functions
// Programmed by James Bellian 03/24/18

#include "Editor.h"

char filename[20];

// Initializes ncurses and prepares the editor window
void init(Editor *e, char ** lines, int nl, char * fn)
{
	strncpy(filename, fn, 20);
	// start/setup nCurses
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
	size_t n = 20;
	
	e->num_lines = nl;
	// set to 2 to give room for margins
	e->x = 1;
	e->y = 1;
	e->text = lines;
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

<<<<<<< HEAD
		// Go insert mode with 'i' (for VIM users)
		case 73: 
			e->mode = 'e';
=======
>>>>>>> master
                case 27: // ESC pressed toggle mode
                        if (e->mode == 'e')
				e->mode = 'c';
			else
				e->mode = 'e';
			mvprintw(e->h-1,1, (e->mode == 'e') ? "Line %d,%d \t-EDIT MODE-   ":"Line %d,%d \t-COMMAND MODE-",
				 e->y + e->scroll, e->x);		
                        refresh();
			break;
		}
		
		// command input when in Command Mode
		if (e->mode == 'c')
		{
			switch(ch)
			{
			// Quit 
			case 'q': case 'Q':
				e->mode = 'x';
				break;
			// add line
			case 'o': case 'O':
<<<<<<< HEAD
				e->num_lines = addNewLine(e->text, e->y + e->scroll + 1, e->num_lines);
=======
				e->num_lines = addNewLine(e->text, e->y + e->scroll , e->num_lines);
>>>>>>> master
				break;
			}		
		}
		// Keyboard input when in Edit Mode
		if (e->mode == 'e')
		{
		
		switch(ch)
			{
			// IGNORE THE FOLLOWING KEY COMMANDS (Handled above)
			case KEY_UP:
			case KEY_DOWN:
			case KEY_LEFT:
			case KEY_RIGHT:
			case 27:
			break;
			
			case 263: // Backspace
<<<<<<< HEAD
        	        	// blank out line
               		 	e->text[ e->y + e->scroll -1][e->x-1] = ' ';
=======
        	        	{
				// blank out line
               		 	//e->text[ e->y + e->scroll -1][e->x-1] = ' ';
				char * newline = e->text[e->y + e->scroll -1];
 	                       int size = strLen(newline);
        	               // newline[size+1] = '\0';

                	 
                     
  

                 

                        	for(int i = e->x-1; i < size; i ++)
                        	{
                                	newline[i] = newline[i+1];
                        	}
>>>>>>> master

             			// adjust cursor
                		if (e->x >1)
                		{
                        		e->x -= 1;
                		}
                		else
                		{
                        		e->x = e->w - 1;
                        		if (e->y > 1)
                               		 	e->y --;
                		}

                		break;
<<<<<<< HEAD
			
=======
				}
>>>>>>> master
			// For everything else, handle in type function
			default:
				type(e,ch);

			break;	
			};
		}
                clear_window(e);
                update_window(e);
                wattron(stdscr, A_REVERSE);
		mvprintw(e->h-1,1, (e->mode == 'e') ? "Line %d,%d \t-EDIT MODE-":"Line %d,%d \t-COMMAND MODE-", e->y + e->scroll, e->x);
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
        for(int i = 0; (i < e->h); i ++)
        {
                mvprintw(i + 1, 1, "%s", e->text[i + e->scroll]);
        }
}

// Prints blank spaces to clear out the window
void clear_window( Editor *e)
{
	// recalculates window size 
	// (in case it has been resized since last update)
        getmaxyx(stdscr,e->h,e->w);

        for(int i = 1; i < e->h-1; i++)
        for(int j = 0; j < e->w; j++)
        {
		if (j==0 && i >= e->num_lines - e->scroll)
                        mvprintw(i,j,"~");
                else
                        mvprintw(i,j," ");
        }
}

// Types the current character into the text field. returns true if successful, false if unexpected letter given
bool type(Editor *e, char letter)
{
	// Not a printable character
	if (letter < 32 && letter > 126) 
		return false;
	
	switch(letter)
	{
	// handle backspace
	/*
	case 263:
		// blank out line
		e->text[e->x][e->y + e->scroll] = ' ';

		// adjust cursor
		if (e->x >1)
		{
			e->x -= 1;
		}
		else
		{
                	e->x = 1;
			if (e->y > 1)
				e->y --;
		}

		//push text back
		for(int i = e->x; i < strlen(e->text[e->y + e->scroll]); i ++)
		{
			e->text[e->x - 1][e->y + e->scroll] = e->text[e->x][e->y + e->scroll];
		}

		break;
*/
	// type plain text
	default:
		{	
<<<<<<< HEAD
		if (e->x < e->w)
=======
		// When the current line is shorter than window width push it along
		if (strLen(e->text[e->y + e->scroll - 1]) < e->w)
>>>>>>> master
		{
	                char * newline = e->text[e->y + e->scroll -1];
               		int size = strLen(newline);
                	newline[size+1] = '\0';
		
			while (strLen(newline) < e->x - 1)
				{
				newline[strLen(newline)]= ' ';
				newline[strLen(newline)+1] = '\0'; 
				}
	
               	 	for(int i = size; i > e->x - 1; i --)
               		{
                        	newline[i] = newline[i-1];
                	}
        	        newline[e->x -1] = letter;
	
        	        e->text[e->y + e->scroll - 1] = newline;
	
			e->x += 1;
		}
<<<<<<< HEAD
		else
		{
			e->y += 1;
			e->x = 2;
			addNewLine(e->text, e->y, 0);
		}
=======
		// Move down when reaching end of line, or create new line
		else if (e->x >= e->w)
		{
			e->y += 1;
			e->x = 2;

			// Append a new line if reaching the end of file 
			if (e->y + e->scroll - 1 >=  e->num_lines)
				addNewLine(e->text, e->y, 0);
		}
		else if (strLen(e->text[e->y + e->scroll -1]) >= e->w)
		{


		}
		
>>>>>>> master
	
//		e->text[ e->y + e->scroll - 1] = newline;
//`		free(newline);
		break;
		}
	}

	
	return true;
}

// returns the length of a c-string
int strLen(char * str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}

	return i;

}


