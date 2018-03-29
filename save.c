 #include <stdio.h>
 #include <stdlib.h>
 #include <ncurses.h>
 #include "save.h"

void save(char *filename, int num_lines, char ** text) {
   FILE *file = fopen(filename, "w");
   
   for (int i = 0; i < num_lines; i++) {
	
	   for (int j = 0; j < strLen(text[i]); j++) {
			fputc(text[i][j], file);
		}
   }
   fclose(filename);
 }
