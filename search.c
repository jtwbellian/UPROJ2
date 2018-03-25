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
		 
    initscr();				
    getmaxyx(stdscr,row,col);		
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
                     		
    getstr(sub);
    mvprintw(LINES - 6, 0, "You Entered: %s", sub);

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
            mvprintw(LINES - 5, 0, "Substring");
            break;
            }
        }
      }
    }
    if ( flag )
    {
        mvprintw(LINES - 5, 0, "Not a substring");
    }

    if ( !flag )
    {
        char answer;
        mvprintw(LINES - 4, 0, "Do you want to replace the string located here with another? y/n: ");
        answer = getch();

        mvprintw(LINES - 10, 0, "Here: %c", answer);
        
        if ( &answer == "y" || &answer == "Y" )
        {
            mvprintw(LINES - 3, 0, "What do you want to replace it with?");
            char newstr[80];
            getstr(newstr);
            mvprintw(LINES - 3, 0, "You Entered: %s", newstr);
        }
        else
        {
            mvprintw(LINES - 3, 0, "Thsi is stupid");
        }
    }

    getch();
    endwin();
    return 0;
}
