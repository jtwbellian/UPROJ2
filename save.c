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
#include <fcntl.h>
#include <save.h>

//converts everything to a single string to be saved.
char *editorRowsToString(int *buflen, int num_lines, char ** text) {
  int totlen = 0;
  int j;
  for (j = 0; j < num_lines; j++)
    totlen += text[j].size + 1;
  *buflen = totlen;
  char *buf = malloc(totlen); //allocates size of string in memory
  char *p = buf;
  for (j = 0; j < num_lines; j++) {
    memcpy(p, text[j].chars, text[j].size); //copies string to memory
    p += text[j].size;
    *p = '\n';
    p++;
  }
  return buf;
}

//saves string to file
void editorSave(string filename, int num_lines, char ** text) {
  int len;
  char *buf = editorRowsToString(&len, num_lines, ** text); //calls editorRowsToString to convert text to a string
  int fd = open(filename, O_RDWR | O_CREAT, 0644); //adds standard permissions for file
  if (fd != -1) {
    if (ftruncate(fd, len) != -1) {
      if (write(fd, buf, len) == len) { //writes/overwrites to file
        close(fd); //close file
        free(buf); //free buffer
        return;
      }
    }
    close(fd);
  }
  free(buf);
}

//  case CTRL_KEY('s'): //ADD TO KEYBOARD FUNCTIONS TO ENABLE CTRL_KEY + s
//  editorSave();
//  break;