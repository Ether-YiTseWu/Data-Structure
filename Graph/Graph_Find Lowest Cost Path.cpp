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

class Node
{
public:
	int Data;
	Node *next;
	Node(void)
	{
		next = NULL;
	}
};

class findLowestCostPath
{
public:
	Node nodeConnectCount[size];
	int graphMatrix[size][size], sortPathCost[sizeX][sizeY], ansPath[size - 1][sizeY], startPoint, endPoint, flag = 0;
	void buildGraph_Matrix(int*);
	void printGraph(void);
	void sortpathCost(int pathCost[sizeX][sizeY]);
	void findLowestPath(int sortPathCost[sizeX][sizeY]);
	findLowestCostPath(void)
	{
		// initialize the linked list array data 1~7
		for (int i = 0; i < size; i++)
			nodeConnectCount[i].Data = i + 1;
	}
};

void findLowestCostPath::sortpathCost(int pathCost[sizeX][sizeY])
{
	// Copy pathCost to sortPathCost
	for (int i = 0; i < sizeX; i++)
		for(int j = 0; j < sizeY;j++)
			sortPathCost[i][j] = pathCost[i][j];
			
	// bubble sort (sort index and cost)
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = i + 1; j < sizeX; j++)
		{
			if (sortPathCost[i][2] > sortPathCost[j][2])
			{
				int tmpNode1 = sortPathCost[i][0], tmpNode2 = sortPathCost[i][1], tmpCost = sortPathCost[i][2];
				
				sortPathCost[i][0] = sortPathCost[j][0];
				sortPathCost[j][0] = tmpNode1;
				sortPathCost[i][1] = sortPathCost[j][1];
				sortPathCost[j][1] = tmpNode2;
				sortPathCost[i][2] = sortPathCost[j][2];
				sortPathCost[j][2] = tmpCost;
			}
		}
	}
	cout << endl << "sortPathCost" << endl;
	for (int i = 0; i < sizeX; i++)
		cout << sortPathCost[i][0] << ' ' << sortPathCost[i][1] << ' ' << sortPathCost[i][2] << endl;

	cout << endl << endl;
}
void findLowestCostPath::findLowestPath(int sortPathCost[sizeX][sizeY])
{
	int count = 0;
	
	// Find the lowest path
	for (int i = 0; i < sizeX; i++)
	{
		int node1, node2;
		node1 = sortPathCost[i][0];
		node2 = sortPathCost[i][1];

		// Add elememt to Adjacency linked list
		for (int j = 0; j < size; j++)
		{
			Node *p = &nodeConnectCount[j], *newNode = new Node();
			if (nodeConnectCount[j].Data == node1)
			{
				newNode->Data = node2;
				while (p->next != NULL)
					p = p->next;
				p->next = newNode;
			}
			else if (nodeConnectCount[j].Data == node2)
			{
				newNode->Data = node1;
				while (p->next != NULL)
					p = p->next;
				p->next = newNode;
			}
		}

		// Judge this node ignore/ not ignore (this part is imperfect)
		Node *q = &nodeConnectCount[node1 - 1];
		flag = 0;   // initialize flag to zero
		while(q->next != NULL && flag!= 1)
		{
			Node *w = &nodeConnectCount[node2 - 1];
			while(w->next != NULL && flag!= 1)
			{
				if (q->Data == w->Data)
					flag = 1;
				else
					flag = 0;
				w = w -> next;
			}
			q = q -> next;
		}

		// Continue or find a new path
		if (flag == 1)
		{
			cout << "ignore one path (because connecting like a ring) :  " << node1 << " -> " << node2 << endl;
			continue;
		}
		else if (flag == 0)
		{
			ansPath[count][0] = node1;
			ansPath[count][1] = node2;
			ansPath[count][2] = sortPathCost[i][2];
			count++;
		}

		if (count == 6)
			break;
	}
	
	// Print ansPath
	cout << endl << "LowestPath" << endl;
	for (int i = 0; i < size - 1; i++)
		cout << ansPath[i][0] << ' ' << ansPath[i][1] << ' ' << ansPath[i][2] << endl;
	
	// Print ansPath
	cout << endl << endl << "Adjacency List" << endl;
	for (int j = 0; j < size; j++)
	{
		Node *p = &nodeConnectCount[j];
		cout << "Node " << j + 1 << " : ";
		while (p->next != NULL)
		{
			cout << p->Data << "  ";
			p = p->next;
		}
		cout << endl;
	}
	cout << endl << endl;
}
void findLowestCostPath::buildGraph_Matrix(int* pathCost)
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

	for (int i = 0; i < sizeX; i++)
	{
		startPoint = pathCost[i * 3];
		endPoint = pathCost[i * 3 + 1];
		graphMatrix[startPoint - 1][endPoint - 1] = pathCost[i * 3 + 2];
		graphMatrix[endPoint - 1][startPoint - 1] = pathCost[i * 3 + 2]; // This graph is bilateral
	}
}
void findLowestCostPath::printGraph()
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
	findLowestCostPath Path1;
	Path1.buildGraph_Matrix(&pathCost[0][0]);
	cout << "³»ÂI  vex1 vex2 vex3 vex4 vex5 vex6 vex7" << endl;
	Path1.printGraph();
	cout << endl;

	Path1.sortpathCost(pathCost);
	Path1.findLowestPath(Path1.sortPathCost);

	system("pause");
	return 0;
}
