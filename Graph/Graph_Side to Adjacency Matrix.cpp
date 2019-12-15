// 把邊變成相鄰矩陣的方法

#include <iostream>
#include <iomanip>
using namespace std;
# define sizeX 12
# define sizeY 3
# define size  7
# define Infinity 99999
int pathCost[sizeX][sizeY] =
{
	{ 1, 2, 17 },
	{ 1, 5, 20 },
	{ 1, 6, 4 },
	{ 1, 7, 24 },
	{ 2, 3, 6 },
	{ 2, 4, 8 },
	{ 2, 7, 12 },
	{ 3, 4, 11 },
	{ 4, 5, 19 },
	{ 4, 7, 15 },
	{ 5, 6, 9 },
	{ 5, 7, 32 }
};

class sideToAdjacencyMatrix
{
public:
	int graphMatrix[size][size], startPoint, endPoint;
	void buildGraph_Matrix(int*);
	void printGraph(void);
};

void sideToAdjacencyMatrix::buildGraph_Matrix(int* pathCost)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				graphMatrix[i][j] = 0;
			else
				graphMatrix[i][j] = Infinity;
		}
	}
	
	// Let pathCost[sizeX][sizeY] = pathCost[sizeX*sizeY] 
	for (int i = 0; i < sizeX; i++)
	{
		startPoint = pathCost[i * 3];
		endPoint = pathCost[i * 3 + 1];
		graphMatrix[startPoint-1][endPoint-1] = pathCost[i * 3 + 2];
		graphMatrix[endPoint-1][startPoint-1] = pathCost[i * 3 + 2]; // This graph is bilateral
	}
}

void sideToAdjacencyMatrix::printGraph()
{
	for (int i = 0; i < size; i++)
	{
		int tmp = i + 1;
		cout << " vex" << tmp;

		for (int j = 0; j < size; j++)
			if (graphMatrix[i][j] == Infinity)
				cout << setw(5) << "X";
			else
				cout << setw(5) << graphMatrix[i][j];
		cout << endl;
	}
}

int main()
{
	int j;
	sideToAdjacencyMatrix ST1;
	
	ST1.buildGraph_Matrix(&pathCost[0][0]);
	cout << "頂點  vex1 vex2 vex3 vex4 vex5 vex6 vex7" << endl;
	ST1.printGraph();
	
	system("pause");
	return 0;
}


