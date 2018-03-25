CC = gcc
CFLAGS = -Wall
LDFLAGS = -lncurses
OBJS = Editor.o	Prog2.o
TARGET = Proj2
DEPS = Editor.h

exe: $(TARGET)

Prog2: $(OBJS) 
	$(CC) $(CFLAGS) -o Prog2 $(OBJS) $(LDFLAGS)

Prog2.o: $(DEPS)
	$(CC) $(CFLAGS) -o Prog2.o Prog2.c $(LDFLAGS) 

Editor.o: Editor.h
	$(CC) $(CFLAGS) -o Editor.o Editor.c $(LDFLAGS)

#test: Proj2 Editor.h
#	./Proj2

clean: 
	rm -f $(OBJS) Proj2
