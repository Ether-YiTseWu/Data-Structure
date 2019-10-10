# include <iostream>
using namespace std;

class Node
{
public:
	int Data;
	Node * next;
	Node(int data)
	{
		Data = data;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node * head = new Node(123);    // 123 no meaning, because head node has not data in linked list

	void push_front(int data)
	{
		Node * x = new Node(data);
		cout << "push_front : " << data << endl;
		if (head->next == NULL)
		{
			head->next = x;
				return;
		}
		x->next = head->next;
		head->next = x;
	}
	void push_back(int data)
	{
		Node * x = new Node(data);
		Node * p = new Node(data);

		p = head->next;
		while (p->next != NULL)
			p = p->next;
		p->next = x;
	}
	void pop_front()	//¿é¥X¥Î
	{
        if(head -> next == NULL)
        {
            cout << "Empty" << endl;
            return;
        }
        Node *node;
        node = head ->next;
        cout << "pop_front : " << node->Data <<endl;
        head->next = node ->next;
        delete node;
	}
};

int main()
{
    LinkedList L;
    for (int i = 0; i<10 ; i++)
        L.push_front(i);
    for (int i = 0; i<11 ; i++)
        L.pop_front();
	return 0;
}
