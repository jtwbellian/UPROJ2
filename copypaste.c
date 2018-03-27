#endif
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <locale.h>

static void do_copy(void) {
	char buf[32]; unsigned int count; char * ptr;
	PROMPT("Copy how many lines?", buf); count = strtoul(buf, &ptr, 10);
	if (ptr > buf && count > 0) {
		line_t * tmp = CUR, *pastepos = NULL; unsigned int i;
		if (pastebuf) { free_list(pastebuf); pastebuf = NULL; }
		for (i=0;i<count && tmp;i++,tmp=tmp->next) {
			if (!pastebuf) {
				pastepos = pastebuf = create_line(tmp->text, tmp->usize);
				pastepos->prev = pastepos->next = NULL;
			} else {
				pastepos->next = create_line(tmp->text, tmp->usize);
				pastepos->next->prev = pastepos; pastepos = pastepos->next;
				pastepos->next = NULL;
			}
		}
		mvprintw(height-1, 0, "Copied %u lines.", i);
	}
}

static void do_paste(void) {
	unsigned int i=0;
	line_t * cur = CUR;
	for (line_t * tmp=pastebuf;tmp;tmp=tmp->next,i++) {
		line_t * l = create_line(tmp->text, tmp->usize);
		l->next = cur->next; l->prev = cur;
		if (cur->next) cur->next->prev = l;
		cur->next = l; cur = cur->next; }
	if (i > 0) {
		mvprintw(height-1, 0, "Pasted %u lines.", i);
		cb->file_modified = 1; 
	}
}