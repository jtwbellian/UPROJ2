#ifndef save_h
#define save_h
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>


char *editorRowsToString(int *buflen, int num_lines, char ** text);

void editorSave(string filename, int num_lines, char ** text)

#endif