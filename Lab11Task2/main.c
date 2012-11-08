/*==============================================================================
 | Complete Project 5 in Chapter 9 of Problem Solving and Program Design in C by 
 | Hanly & Koffman. Write a function that accepts an 8 by 8 array of characters 
 | that represents a maze. Each position can contain either an X or a blank. 
 | Starting at position (0, 1), list any path through the maze to get to 
 | location (7, 7). Only horizontal and vertical moves are allowed. If no path 
 | exists, write a message indicating there is no path.
 | 
 | Moves can be made only to locations the contain a blank. If an X is 
 | encountered, that path is blocked and another must be chosen. Use recursion.
 ==============================================================================*/

#include <stdio.h>
#include <Windows.h>

#define MAZE_ROWS 8
#define MAZE_COLS 20

#define BORDER 219
#define WALL   219

#define TARGET_ROW 7
#define TARGET_COL 19

#define FALSE 0
#define TRUE  1

int   findPath   (char maze[][MAZE_COLS], int row, int col);
void  drawMaze   (char maze[][MAZE_COLS]);

int main (void) {
	int i = 0, j = 0;
	char maze[MAZE_ROWS][MAZE_COLS];
	char *mazeMap[MAZE_ROWS] = {"  X   X            X",
	                            "X X X X XXXXXXXXXX X",
	                            "X XXX X XXX    X X X",
	                            "X XX        XX X   X",
	                            "     X XXXX XXXXXXXX",
	                            " XXX X  XXX        X",
	                            " X X XXXX X XXXXXX X",
	                            "   X      X     XX  "};

	for (i = 0; i < MAZE_ROWS; i++)
		for (j = 0; j < MAZE_COLS; j++) {
			if (mazeMap[i][j] == 'X')
				maze[i][j] = WALL;
			else
				maze[i][j] = ' ';
		}

	drawMaze (maze);
	getchar();
	printf ("%s\n", findPath (maze, 0, 0) ? "Path exist!" : "Path does not exist");

	return 0;
}

int findPath (char maze[][MAZE_COLS], int row, int col) {
	if (row < 0 || row >= MAZE_ROWS || col < 0 || col >= MAZE_COLS)
		return FALSE;
	if (maze[row][col] == (char) WALL)
		return FALSE;
	if (maze[row][col] == '*')
		return FALSE;
	if (row == TARGET_ROW && col == TARGET_COL) {
		maze[row][col] = '*';
		system ("cls");
		drawMaze (maze);
		return TRUE;
	}

	maze[row][col] = '*';

	system ("cls");
	drawMaze (maze);
	Sleep (300);

	// NORTH
	if (findPath (maze, row - 1, col)) {
		printf ("NORTH (%d, %d)\n", row - 1, col);
		return TRUE;
	}

	// WEST
	if (findPath (maze, row, col - 1)) {
		printf ("WEST (%d, %d)\n", row, col - 1);
		return TRUE;
	}

	// EAST
	if (findPath (maze, row, col + 1)) {
		printf ("EAST (%d, %d)\n", row, col + 1);
		return TRUE;
	}

	// SOUTH
	if (findPath (maze, row + 1, col)) {
		printf ("SOUTH (%d, %d)\n", row + 1, col);
		return TRUE;
	}

	maze[row][col] = ' ';
	system ("cls");
	drawMaze (maze);
	Sleep (300);

	return FALSE;
}


void drawMaze (char maze[][MAZE_COLS]) {
	int i = 0, j = 0;

	for (i = 0; i < MAZE_COLS + 2; i++) {
		printf ("%c", BORDER);
	}

	printf ("\n");

	for (i = 0; i < MAZE_ROWS; i++) {
		printf ("%c", BORDER);
		for (j = 0; j < MAZE_COLS; j++)
			printf ("%c", maze[i][j]);
		printf ("%c\n", BORDER);
	}

	for (i = 0; i < MAZE_COLS + 2; i++) {
		printf ("%c", BORDER);
	}
	printf ("\n");
}