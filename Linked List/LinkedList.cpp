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
		Node * newNode = new Node(data);
		cout << "push_front : " << data << endl;
		if (head->next == NULL)
		{
			head->next = newNode;
				return;
		}
		newNode->next = head->next;
		head->next = newNode;
	}
	void push_back(int data)
	{
		Node * newNode = new Node(data);
		Node * p = new Node(data);

		p = head->next;
		while (p->next != NULL)
			p = p->next;
		p->next = newNode;
	}
	void pop_front()	//¿for output
	{
        if(head -> next == NULL)
        {
            cout << "Empty" << endl;
            return;
        }
        Node * tempNode = new Node(11);
        tempNode = head ->next;
        cout << "pop_front : " << tempNode->Data <<endl;
        head->next = tempNode ->next;
        delete tempNode;
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
