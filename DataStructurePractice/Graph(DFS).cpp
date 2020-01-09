#include <iostream>
using namespace std;
# define size 10

int adjacencyMatrix[size][size] =
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

class DFS
{
public:
	Node adList[size];
	int visit[size];

	void toAdjacencyList(void);
	void dfsVisit(int);
	DFS(void)
	{
	    for(int i = 0; i < size ; i++)
            visit[i] = 0;
	}
};

void DFS::toAdjacencyList(void)
{
    for (int i = 0; i < size ; i++)
    {
        cout << "VEX" << i << " --> ";
        for(int j = 0; j < size ; j++)
        {
            if(adjacencyMatrix[i][j]==1)
            {
                cout << "[" << j+1 << "]";
				Node *p = &adList[i], *newNode = new Node(); // 一定要用動態記憶體
				while (p->next != NULL)
					p = p->next;
				newNode->Data = j;
				p -> next = newNode;
            }
        }
        cout << endl;
    }
    cout << endl;
}

void DFS::dfsVisit(int i)
{
    Node *ptr = adList[i].next;
    visit[i] = 1;
    cout << "visit = " << i+1 << endl;
    while(ptr != NULL)
    {
        if (visit[ptr->Data] == 0)
            dfsVisit(ptr->Data);
        ptr = ptr -> next;
    }
}

int main()
{
	DFS P1;

	P1.toAdjacencyList();
	P1.dfsVisit(0);
	cout << endl;

	return 0;
}
