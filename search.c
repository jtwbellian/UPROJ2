#include "search.h"
#include <ncurses.h>			
#include <string.h> 

void search(char **str)
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


/*
#include "search.h"
#include <ncurses.h>			
#include <string.h>
#include <ctype.h> 

struct found{
	int y; //row
	int x; //col
};

void search(char **str, int lineCount)
{	
   	
	struct found whereAndLength[SIZE];

   	mvprintw(LINES - 4, 0, "%s",mesg);              		
	getstr(sub);
	mvprintw(LINES - 4, 0, "You Entered: %s", sub);
	while (strlen(sub) <= 0) {
		mvprintw(LINES - 4, 0, "%s", mesg);
	}
    
	int subStrLen = strlen(sub); //Length of the searched term
	char* stringPtr; //Points to the entire row
	int countMatch = 0; //Count character matches
	int totalMatch = 0; //Count total matches of searched term
	
	//Loop for all the lines of the file
	for (int i = 0; i < lineCount; i++){
		
        stringPtr = str[lineCount];
		int strLen = strlen(stringPtr);
		
        //Loop to check each character of the specific line
		for (int j = 0; j < strLen; j++){
			if (stringPtr[j] == sub[0]){
				
                //Loop to see if the subsequent characters of possible match is actually a match
				//Increment countMatch for each consecutive character 
				countMatch++;
				for (int k = j + 1, n = 1; k < j + subStrLen && k < strLen && n < subStrLen; k++, n++){
					if (stringPtr[k] == sub[n]){
						countMatch++;
					}
				}
                
                //A total match was found, set the values in the array
				if (countMatch == subStrLen){
					whereAndLength[totalMatch].y = i;
					whereAndLength[totalMatch].x = j;
					totalMatch++;
				}
                
                //Resets for the next character set
				countMatch = 0;
			}
		
		}
		
	}
    //If totalMatch == 0, print out "nothing found"
    //Else
    //print out "replacement: ", get the replacement string
    //Loop through the array from 0 to totalMatch - 1
    //Use row, column, and subStrLen to set the replacement where the original searched term was found
    
}
*/
