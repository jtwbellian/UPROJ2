#include <ncurses.h>			
#include <string.h> 
#define SIZE 10
#define LENGTH 180




int main()
{
    char str[SIZE][LENGTH] = {"Test\0","These are times\0","That try Men's souls\0"};

    char mesg[]="Enter a string: ";		
    char sub[80];
    int row,col;

    int linelocation;
    int whichstring;
		 
    initscr();				
    getmaxyx(stdscr,row,col);	
	
    mvprintw(LINES - 4, 0, "%s",mesg);              		
    getstr(sub);

    mvprintw(LINES - 4, 0, "You Entered: %s", sub);

    int i, j=0, k;
   bool flag = true;
   for ( int n = 0; n < SIZE; ++n )
    {
        j=0;
      for(i=0; str[n][i]; i++)
      {
        if(str[n][i] == sub[j])
        {
          for(k=i, j=0; str[n][k] && sub[j]; j++, k++)
            if(str[n][k]!=sub[j])
                break;
           if(!sub[j])
            {
            flag = false;
            whichstring = n;
            linelocation = i;
            move(n,i);
            break;
            }
        }
      }
    }
    if ( flag )
    {
        mvprintw(LINES - 3, 0, "Not a substring");
    }

    if ( !flag )
    {
        char answer;
        mvprintw(LINES - 3, 0, "Do you want to replace the string located here with another? y/n: ");
        answer = getch();
        
        if ( answer == 'y' || answer == 'Y' )
        {
            mvprintw(LINES - 2, 0, "What do you want to replace it with?");
            char newstr[80];
            getstr(newstr);
            strcpy(str[whichstring][linelocation], newstr);
            
        }
        else
        {
            mvprintw(LINES - 2, 0, "Thsi is stupid");
        }
    }

    getch();
    endwin();
    return 0;
}
