CC = gcc
CCFLAGS = -Wall -Wextra -Wextra 
FLAGGUI = `pkg-config --cflags --libs gtk+-3.0`
EX = ../build/graph
FILES = graph.c graph_output.c data_structures.c rpn.c input.c parsing.c

all: main

main:
	$(CC) GuiCalculator.c -c $(FLAGGUI) -lm
	$(CC) $(CCFLAGS) -c $(FILES) -lm
	$(CC) *.o -o $(EX) $(FLAGGUI) -lm
	rm -rf *.o
	$(EX)
calculator:
	$(CC) $(CCFLAGS) GuiCalculator.c -c $(FLAGGUI) -lm
	$(CC) *.o -o $(EX) $(FLAGGUI) -lm
	rm -rf *.o
clean:
	rm -rf *.o