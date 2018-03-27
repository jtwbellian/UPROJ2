CC = gcc
CFLAGS = -Wall -c
LDFLAGS = -lncurses
OBJS = Editor.o	Proj2.o textBuffer.o
TARGET = Proj2
DEPS = Editor.h textBuffer.h Proj2.c 

#all: $(TARGET)

Proj2: $(OBJS) 
	$(CC)  -o Proj2 $(OBJS) $(LDFLAGS)

Proj2.o: $(DEPS)
	$(CC) $(CFLAGS) -o Proj2.o Proj2.c $(LDFLAGS) 

Editor.o: Editor.h
	$(CC) $(CFLAGS) -o Editor.o Editor.c $(LDFLAGS)

textBuffer.o: textBuffer.h
	$(CC) $(CFLAGS) -o textBuffer.o textBuffer.c $(LDFLAGS)


clean: 
	rm -f $(OBJS)
