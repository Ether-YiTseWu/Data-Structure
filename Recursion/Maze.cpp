#include <iostream>
#define mazeSize 10
using namespace std;

int maze[mazeSize][mazeSize] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

class create_Maze
{
public:
	int startI, startJ, endI, endJ, seq = 0;

	void setStart(int i, int j)
	{
		startI = i, startJ = j;
	}
	void setEnd(int i, int j)
	{
		endI = i, endJ = j;
	}
	void visit_maze(int maze[mazeSize][mazeSize], int i, int j);
	void go(int maze[mazeSize][mazeSize])
	{
		visit_maze(maze, startI, startJ);
	}
};

void create_Maze::visit_maze(int maze[mazeSize][mazeSize], int i, int j)
{
	maze[i][j] = 2;

	if (i == endI && j == endJ)
	{
		seq++;
		cout << "\n \t  Find the Exit #" << seq << "\n \n";
		for (int i = 0; i < mazeSize; i++)
		{
			printf("\t");
			for (int j = 0; j < mazeSize; j++)
			{
				if (maze[i][j] == 1)
					cout << "¢p";
				else if (maze[i][j] == 2)
					cout << "¡»";
				else if (maze[i][j] == 0)
					cout << "  ";
			}
			cout << endl;
		}
	}

	if (maze[i][j + 1] == 0)
		visit_maze(maze, i, j + 1);
	if (maze[i + 1][j] == 0)
		visit_maze(maze, i + 1, j);
	if (maze[i][j - 1] == 0)
		visit_maze(maze, i, j - 1);
	if (maze[i - 1][j] == 0)
		visit_maze(maze, i - 1, j);

	maze[i][j] = 0;
}

int main()
{
	create_Maze M1;
	M1.setStart(1, 1);
	M1.setEnd(8, 8);
	M1.go(maze);

	system("pause");
	return 0;
}
