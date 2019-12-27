#include <iostream>
using namespace std;

# define sizeX 13
# define sizeY 3
# define size  7
# define Infinity 999

int pathCost[sizeX][sizeY] =
{
	{ 1, 2, 4 },
	{ 1, 3, 6 },
	{ 1, 4, 6 },
	{ 2, 3, 1 },
	{ 2, 5, 7 },
	{ 3, 5, 6 },
	{ 3, 6, 4 },
	{ 4, 3, 2 },
	{ 4, 6, 5 },
	{ 5, 3, 6 },
	{ 5, 7, 6 },
	{ 6, 5, 1 },
	{ 6, 7, 8 },
};

class findShortestPath
{
public:
	int adjacencyMatrix[size][size], startPoint, endPoint;
	double distance[size];
	bool visited[size];

	void build_AdjacencyMatrix_mine();
	void build_AdjacencyMatrix_teacher(int*);
	void print_AdjacencyMatrix(void);
	void findPath(void);

	findShortestPath()
	{
		for (int i = 0; i < size; i++)
			visited[i] = 0;
	}
};

void findShortestPath::build_AdjacencyMatrix_mine()
{	
	// build adjacencyMatrix, the cost of nodeX to nodeX is 0, others are Infinity 
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				adjacencyMatrix[i][j] = 0;
			else
				adjacencyMatrix[i][j] = Infinity;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < sizeX; k++)
			{
				if (pathCost[k][0] == i+1 && pathCost[k][1] == j+1)
					adjacencyMatrix[i][j] = pathCost[k][2];
			}
		}
	}
}

// Note the parameter *pathCost. Let pathCost[sizeX][sizeY] = pathCost[sizeX*sizeY] 
void findShortestPath::build_AdjacencyMatrix_teacher(int *pathCost)
{
	// build adjacencyMatrix, the cost of nodeX to nodeX is 0, others are Infinity 
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				adjacencyMatrix[i][j] = 0;
			else
				adjacencyMatrix[i][j] = Infinity;
		}
	}

	for (int i = 0; i < sizeX; i++)
	{
		startPoint = pathCost[i * 3];
		endPoint = pathCost[i * 3 + 1];
		adjacencyMatrix[startPoint - 1][endPoint - 1] = pathCost[i * 3 + 2];
		adjacencyMatrix[endPoint - 1][startPoint - 1] = pathCost[i * 3 + 2]; // This graph is bilateral
	}
}

void findShortestPath::print_AdjacencyMatrix()
{
	for (int i = 0; i < size; i++)
	{
		int tmp = i + 1;
		cout << " vex" << tmp;

		for (int j = 0; j < size; j++)
			if (adjacencyMatrix[i][j] == Infinity)
				cout << "    " << "X";
			else
				cout << "    " << adjacencyMatrix[i][j];

		cout << endl;
	}
}

void findShortestPath::findPath(void)
{
	// Copy the matrix's first row to distance matrix, and let visited[0] = 1
	for (int i = 0; i < size; i++)
		distance[i] = adjacencyMatrix[0][i];
	visited[0] = 1;

	// print 
	cout << endl << "Add Node    : 1";
	cout << endl << "Distance    : ";
	for (int i = 0; i < size; i++)
		cout << distance[i] << "    ";
	cout << endl << "Visted Node : ";
	for (int i = 0; i < size; i++)
		cout << visited[i] << "    ";
	cout << endl;

	// Search the shortest path
	while (1)
	{
		int minCost = 1000, distanceTmp[size], minCost_NodeIndex, path[size];

		// find the node we should add and this node's index (陣列中最小且沒有被拜訪過的)
		for (int i = 0; i < size; i++)
			if (distance[i] < minCost && visited[i] != 1)
				minCost = distance[i], minCost_NodeIndex = i;
		visited[minCost_NodeIndex] = 1;

		// add min cost
		for (int i = 0; i < size; i++)
			distanceTmp[i] = adjacencyMatrix[minCost_NodeIndex][i] + minCost;
		for (int i = 0; i < size; i++)
			if (distance[i] > distanceTmp[i])
				distance[i] = distanceTmp[i];

		// print 
		cout << endl << "Add Node    : " << minCost_NodeIndex + 1;
		cout << endl << "Distance    : ";
		for (int i = 0; i < size; i++)
			cout << distance[i] << "    ";
		cout << endl << "Visted Node : ";
		for (int i = 0; i < size; i++)
			cout << visited[i] << "    ";
		cout << endl;

		// Break Condition (all nodes have been visited)
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += visited[i];
		if (sum == size)
			break;
	}

	// print 
	cout << endl << endl << "The distance of start node to other's node" ;
	cout << endl << "vex1   vex2   vex3   vex4   vex5   vex6   vex7" << endl;
	for (int i = 0; i < size; i++)
		cout << distance[i] << "      ";
}

int main()
{
	int j;
	findShortestPath P1;

	//P1.build_AdjacencyMatrix_teacher(&pathCost[0][0]);
	P1.build_AdjacencyMatrix_mine();
	cout << "頂點  vex1 vex2 vex3 vex4 vex5 vex6 vex7" << endl;
	P1.print_AdjacencyMatrix();
	P1.findPath();

	cout << endl << endl;
	system("pause");
	return 0;
}
