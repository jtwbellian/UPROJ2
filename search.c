#include <ncurses.h>			
#include <string.h> 
#define SIZE 10
#define LENGTH 180
int main()
{
    char string[SIZE][LENGTH] = {"Test\0","These are times\0","That try Men's souls\0"};

    char mesg[]="Enter a string: ";		
    char str[80];
    int row,col;
	int sizeofinput = strlen(str);	
		

		 
    initscr();				
    getmaxyx(stdscr,row,col);		
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
                     		
    getstr(str);
    mvprintw(LINES - 3, 0, "You Entered: %s", str);

    mvprintw(LINES - 4, 0, "Input Length: %i", sizeofinput);	

    for (int i = 0; i < SIZE; ++i)
    {
        for (int n = 0; n < LENGTH; ++n)
        {
            mvprintw(LINES - 10, 0, "Testing:");
            if (string[i][n] == str[0])
            {
                mvprintw(LINES - 9, 0, "First Character Found");  
            }
        }
    }

    getch();
    endwin();
    return 0;
}
