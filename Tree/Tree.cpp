#include<iostream>
using namespace std;

class treeNode
{
public:
	int Data;
	treeNode *LNode, *RNode;
	treeNode(int i)
	{
		Data = i;
		LNode = RNode = NULL;
	}
};

class BTree
{
public:
	treeNode *root;
	void InOrder(treeNode* node)  // 中序走訪 in order
	{
		if (node != NULL)
		{
			InOrder(node->LNode);
			cout << "[" << node->Data << "]" << " -> ";
			InOrder(node->RNode);
		}
	}

	void PreOrder(treeNode* node)  // 前序走訪 pre order
	{
		if (node != NULL)
		{
			cout << "[" << node->Data << "]" << " -> ";
			PreOrder(node->LNode);
			PreOrder(node->RNode);
		}
	}

	void PostOrder(treeNode* node)  // 後序走訪 post order
	{
		if (node != NULL)
		{
			PostOrder(node->LNode);
			PostOrder(node->RNode);
			cout << "[" << node->Data << "]" << " -> ";
		}
	}
	void Add_TreeNode(int);
	BTree(void)
	{
		root = NULL;
	}
};

void BTree::Add_TreeNode(int value)
{
	cout << "Add Data : " << value << endl;
	treeNode *newNode = new treeNode(value);
	if (root == NULL)
	{
		root = newNode;
		return;
	}
	treeNode *currentNode = root;
	while (1)
	{
		if (currentNode->Data > value)
		{
			if (currentNode->LNode == NULL)
			{
				currentNode->LNode = newNode;
				return;
			}
			currentNode = currentNode->LNode;
		}
		else
		{
			if (currentNode->RNode == NULL)
			{
				currentNode->RNode = newNode;
				return;
			}
			currentNode = currentNode->RNode;
		}
	}
}

int main()
{
	BTree B1;

	B1.Add_TreeNode(8);
	B1.Add_TreeNode(17);
	B1.Add_TreeNode(31);
	B1.Add_TreeNode(9);
	B1.Add_TreeNode(98);
	B1.Add_TreeNode(12);

	cout << endl << "InOrder : ";
	B1.InOrder(B1.root);
	cout << " END" << endl << "PreOrder : ";
	B1.PreOrder(B1.root);
	cout << " END" << endl << "PostOrder : ";
	B1.PostOrder(B1.root);
	cout << " END" << endl << endl;

	system("pause");
	return 0;
}