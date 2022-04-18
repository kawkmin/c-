#include<iostream>

using namespace std;

typedef struct node* treePointer;
struct node {
	char data;
	treePointer leftChild, rightChild;
};

void preorder(treePointer ptr)
{
	if (ptr)
	{
		cout << ptr->data;
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void inorder(treePointer ptr)
{
	if (ptr)
	{
		inorder(ptr->leftChild);
		cout << ptr->data;
		inorder(ptr->rightChild);
	}
}
void postorder(treePointer ptr)
{
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data;
	}
}
int main()
{
	int N;
	cin >> N;
	node nodes[27];
	for (int i = 0; i < N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		nodes[a - 'A'].data = a;
		if (b == '.')
			nodes[a - 'A'].leftChild = NULL;
		else
			nodes[a - 'A'].leftChild = &nodes[b - 'A'];
		if (c == '.')
			nodes[a - 'A'].rightChild = NULL;
		else
			nodes[a - 'A'].rightChild = &nodes[c - 'A'];
	}
	preorder(&nodes[0]);
	cout << "\n";
	inorder( &nodes[0]);
	cout << "\n";
	postorder(&nodes[0]);
	cout << "\n";
}