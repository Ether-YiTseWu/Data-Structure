#include <iostream>
using namespace std;

# define size 10

int map[size][size] =
{
	{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 }
};

class Node
{
public:
	int Data = 0;
	Node *next;
	Node(void)
	{
		next = NULL;
	}
};

class graph
{
public:
	// Create Adjacency List
	Node head[size];

	void setMyway(void);
	void setTeacher(void);
	void visit(int i, int *isvisit, Node *H);
};

void graph::setMyway(void)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Node" << i + 1 << " : ";
		for (int j = 0; j < size; j++)
		{
			if (map[i][j] == 1)
			{
				cout << "[" << j+1 << "]";
				Node *p = &head[i], *newNode = new Node();
				newNode->Data = j;
				while (p->next != NULL)
					p = p->next;
				p->next = newNode;
			}
		}
		cout << endl;
	}
}
void graph::setTeacher(void)
{
	Node *ptr, *newNode;
	for (int i = 0; i < 10; i++)
	{
		head[i].Data = i;
		cout << "Node " << i+1 << " --> ";
		ptr = &head[i];
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 1)
			{
				newNode = new Node;
				newNode->Data = j;
				ptr->next = newNode;
				cout << "[" << newNode->Data + 1 << "]";
				ptr = ptr->next;
			}
		}
		cout << endl;
	}
}
// DFS (Depth-First Search) Algorithm
void  graph::visit(int i, int *isvisit, Node *H)
{
	Node *ptr = H[i].next;
	isvisit[i] = 1;
	cout << "visit = " << i + 1 << endl;
	while (ptr != NULL)
	{
		if (isvisit[ptr->Data] == 0)
			visit(ptr->Data, isvisit, H);
		ptr = ptr->next;
	}
}

int main()
{
	graph G1, G2;
	int isvisit1[size] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int isvisit2[size] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	G1.setMyway();
	G1.visit(0, isvisit1, G1.head);
	cout << endl;

	G2.setTeacher();
	G2.visit(0, isvisit2, G2.head);

	system("pause");
	return 0;
}
