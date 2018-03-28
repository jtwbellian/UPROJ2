#include <stdio.h>
#include <string.h>
#include <ncurses.h>
int main () {
   

   int x,y;
   int x2,y2;
   int len_of_copy;

   printf("select starting point");

   getyx(stdscr,y,x);

   printf("Select end point")

   getyx(stdscr,y2,x2);

   len_of_copy = y2-y;
   char copy[len_of_copy];
   for(int i=0; i < len_of_copy; i++){

   	for (int j=y; j<=y2; i++){
   		copy[i] = textPtr[x][j];
   	}

   }
   
   return copy;
}
