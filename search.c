#include <ncurses.h>			
#include <string.h> 
#include "search.h"
#define SIZE 10
#define LENGTH 180
void search(*str)
{	
    mvprintw(LINES - 4, 0, "%s",mesg);              		
    getstr(sub);

    mvprintw(LINES - 4, 0, "You Entered: %s", sub);

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
        mvprintw(LINES - 3, 0, "Do you want to replace the string located here with another? y/n: ");
        answer = getch();
        
        if ( answer == 'y' || answer == 'Y' )
        {
            mvprintw(LINES - 2, 0, "Replacement: ");
            getstr(newstr);
            char *p = &newstr;
            char *h = &str[whichstring][linelocation];
            strcpy(h, p); 
            mvprintw(LINES -1, 0, "Completed");           
        }
    }
}
