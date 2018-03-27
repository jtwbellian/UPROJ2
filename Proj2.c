#include <stdio.h>
#include "Editor.h"
#include "textBuffer.h"

int main(int argc, char * argv[])
{
	char* file;

	// Check to ensure argument for text file has been given 
	if (argc != 2)
	{
		printf("Wrong number of arguments to start text editor.\n Please supply 1 argument : the name of the file you wish to open.\n\n (Program will now terminate)\n");
		return 1;
	}
	
	if (!fopen(argv[1], "r"))
	{
		printf("File \'%s\' was not found. Make sure it's in the right directory!\n (Program will now terminate)\n", argv[1]);
		return 1;
	}
	else
	{
		file = argv[1];
	}

	// Creates the text buffer structure
        // ( Start of Johns textBuffer initialization)
	buffer tb;
	buffer *ptr = &tb;
        ptr = (buffer *)malloc(sizeof( buffer));
        //initialize variables of the struct buffer
        ptr->lineCount = 0;
<<<<<<< HEAD
        char ** lines = ptr->textBuffer;

        //Pass in those values
        //ptr->textBuffer should have everything
        ptr->lineCount = fillBuffer(file, lines, ptr->lineCount);

        // (End of Johns textBuffer initialization)
=======
       // char ** lines = ptr->textBuffer;

        //Pass in those values
        //ptr->textBuffer should have everything
        ptr->lineCount = fillBuffer(file, ptr->textBuffer, ptr->lineCount);

        // (End of Johns textBuffer initialization)
/*	
	for(int i =0; i < ptr->lineCount; i ++)
	{

		printf(">%s\n" , lines[i]);
	}*/
>>>>>>> master

	// Creates the Ncurses Editor
	Editor editor;
	Editor *eptr = &editor;
<<<<<<< HEAD
	init(eptr, lines, ptr->lineCount);
=======
	init(eptr, ptr->textBuffer, ptr->lineCount,file );
>>>>>>> master
}
