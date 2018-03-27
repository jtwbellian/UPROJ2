CC = gcc
CFLAGS = -Wall -c
LDFLAGS = -lncurses
<<<<<<< HEAD
OBJS = Editor.o	Proj2.o textBuffer.o Delete.o
TARGET = Proj2
DEPS = Editor.h textBuffer.h delete.h
=======
OBJS = Editor.o	Proj2.o textBuffer.o
TARGET = Proj2
DEPS = Editor.h textBuffer.h Proj2.c 
>>>>>>> master

#all: $(TARGET)

Proj2: $(OBJS) 
	$(CC)  -o Proj2 $(OBJS) $(LDFLAGS)

Proj2.o: $(DEPS)
	$(CC) $(CFLAGS) -o Proj2.o Proj2.c $(LDFLAGS) 

Editor.o: Editor.h
	$(CC) $(CFLAGS) -o Editor.o Editor.c $(LDFLAGS)

textBuffer.o: textBuffer.h
	$(CC) $(CFLAGS) -o textBuffer.o textBuffer.c $(LDFLAGS)

<<<<<<< HEAD
Delete.o: delete.h
	$(CC) $(CFLAGS) -o Delete.o delete.c $(LDFLAGS)

#test: Proj2 Editor.h
#	./Proj2

clean: 
	rm -f $(OBJS) Proj2
=======

clean: 
	rm -f $(OBJS)
>>>>>>> master
