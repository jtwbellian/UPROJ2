
//#include "textBuffer.h"
/*
//#include "search.h"
//#include <ncurses.h>			
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#define MAX_LEN_ROW 300
#define MAX_LEN_COL 300
#define SIZE 300


struct found{
	int y; //row
	int x; //col
};

void search(char** str, int lineCount)
{	
   	
	struct found* whereAndLength[SIZE]; 
	for (int i = 0; i < SIZE; i++){ 
		whereAndLength[i] = (struct found *)malloc(sizeof(whereAndLength));
	}

   //	mvprintw(LINES - 4, 0, "%s",mesg);
   	printf("Type in a string to search for: "); 
        char sub[100];             		
	scanf("%s", sub);
	int searchStrLen = strlen(sub);
   //	mvprintw(LINES - 4, 0, "You Entered: %s", sub);
	while (strlen(sub) <= 0) {
		mvprintw(LINES - 4, 0, "%s", mesg);
	}
	int subStrLen = strlen(sub);
	char line[MAX_LEN_COL];
	int countMatch = 0;
	int totalMatch = 0;
	
	
	//Loop for all the lines of the file
	//Search portion
	for (int i = 0; i < lineCount; i++){
		char* stringPtr = str[i];
		printf("This is the line at index %d : %s\n", i, str[i]);
		int strLen = strlen(stringPtr);
		//Loop to check each character of the specific line
		for (int j = 0; j < strLen; j++){
			if (stringPtr[j] == sub[0]){
				//Loop to see if the subsequent characters of possible match is actually
				//a match
				//Increment countMatch
				countMatch++;
				for (int k = j + 1, n = 1; k < j + subStrLen && k < strLen && n < subStrLen; k++, n++){
					if (stringPtr[k] == sub[n]){
						countMatch++;
					}
				}
				//This condition means a full match was a found
				if (countMatch == subStrLen){
					whereAndLength[totalMatch]->y = i;
					whereAndLength[totalMatch]->x = j;	
					totalMatch++;
				}
				countMatch = 0;
			}
		
		}
		
	}

	for (int i = 0; i < totalMatch; i++){
		printf("Here is whereAndLength[%d] : Row %d : Col %d\n", i, whereAndLength[i]->y, whereAndLength[i]->x);
	}
	if (totalMatch == 0){
		printf("No matches found");
	}
	else{
		char replacement[MAX_LEN_COL];
		char concatStr[MAX_LEN_COL];
		char yesOrNo;
		char* linePtr;
		printf("Found %d matches!", totalMatch); 
		printf("Do you want to replace them with a string? y/n:");
		scanf(" %c", &yesOrNo);
		if (yesOrNo == 'Y' || yesOrNo == 'y'){
			printf("Type in the replacement string: ");
			scanf("%s", replacement);
			int inputLenOfRep = strlen(replacement);	
			//Loop through all matches of the found struct
			//Replace portion
			for (int i = 0; i < totalMatch; i++){
				int row = whereAndLength[i]->y;
				int col = whereAndLength[i]->x;
				linePtr = str[row];
				int lenOfLine = strlen(linePtr);
			//	for (int j = col, k = 0; j < col + inputLenOfRep && j < MAX_LEN_COL && k < inputLenOfRep; j++, k++){
			//		linePtr[j] = replacement[k];
			//	}
				//This loop concats everything from 0 to the index prior to where the match was found
				for (int j = 0; j < col; j++){
					concatStr[j] = linePtr[j];
				}
				//Insert the replacement where the searched term originally was into the concat array
				for (int j = col, k = 0; j < col + inputLenOfRep && j < MAX_LEN_COL && k < inputLenOfRep; j++, k++){
					concatStr[j] = replacement[k];
				}	
				//Insert everything else after the searched term
				for (int j = col + inputLenOfRep, k = col + searchStrLen; j < lenOfLine - searchStrLen + inputLenOfRep && k < lenOfLine; j++, k++){
					concatStr[j] = linePtr[k];
				} 
				//Copy concatStr to the row where the match was found
				strcpy(str[row], concatStr);	
			}		
		}
		else{
			printf("You answered no!");
			
		}
	}
	printf("After replacement:\n");
	for (int i = 0; i < lineCount; i++){
		printf("%s\n", str[i]);
	}
}
*/
