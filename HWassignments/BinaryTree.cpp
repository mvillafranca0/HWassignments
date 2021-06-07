#include<iostream>
#include<string>
using namespace std;

class tree
{
	private:
		struct node
		{
			int numKey;
			string name;
			double balance;
			node *left;
			node *right;
		};
		
		node *root;
		
		node* makeLeaf(int arg,string arg2, double arg3);
		void search(int arg, string arg2, double arg3, node* ptr);
		void inOrder(node* ptr);
		void findPrivate(int arg, node* ptr);
	public:
		tree()
		{
			root = NULL;
		};
		void appendLeaf(int arg, string arg2, double arg3)
		{
			search(arg, arg2, arg3, root);
		};
		void print()
		{
			inOrder(root);
		};
		void find(int arg)
		{
			findPrivate(arg, root);	
		};
};

tree :: node* tree :: makeLeaf(int arg, string arg2, double arg3)
{
	node *v = new node;
	v -> numKey = arg;
	v -> name = arg2;
	v -> balance = arg3;
	v -> left = NULL;
	v -> right = NULL;
	
	return v;
}

void tree :: search(int arg, string arg2, double arg3, node* ptr)
{
	if(root == NULL)
	{
		root = makeLeaf(arg, arg2, arg3);
	}
	else if(arg < ptr -> numKey)
	{
		if (ptr -> left == NULL)
		{
			ptr -> left = makeLeaf(arg, arg2, arg3);
		}
		else
		{
			search(arg, arg2, arg3, ptr -> left); 
		}
	}
	else if(arg > ptr -> numKey)
	{
		if (ptr -> right == NULL)
		{
			ptr -> right = makeLeaf(arg, arg2, arg3);
		}
		else
		{
			search(arg, arg2, arg3, ptr -> right); 
		}
	}
	else
	{
		cout << "The key you entered is already in the tree\n";
	}
}

void tree :: inOrder(node* ptr)
{
	if(ptr == NULL)
	{
		cout << "The tree is empty\n";
	}
	else
	{
		if(ptr -> left != NULL)
		{
			inOrder(ptr -> left);
		}
		cout << "Key: " << ptr -> numKey
			<< ", Name: " << ptr -> name
			<< ", Balance Due: $" <<  ptr -> balance
			<< "\n\n";
		if(ptr -> right != NULL)
		{
			inOrder(ptr -> right);
		}
	}
}

void tree :: findPrivate(int arg, node* ptr)
{
	if(ptr -> numKey == arg)
	{
		cout << "Key: " << ptr -> numKey
			<< ", Name: " << ptr -> name
			<< ", Balance Due: $" <<  ptr -> balance
			<< "\n\n";
	}
	else if (arg < ptr -> numKey)
	{
		findPrivate(arg, ptr -> left);
	}
	else if (arg > ptr -> numKey)
	{
		findPrivate(arg, ptr -> right);
	}
	else if(ptr == NULL)
	{
		cout << "Tree node could not be found\n";
	}
	else
	{
		cout << "***ERROR***";
	}	
} 

int main()
{
	tree BST;
	int keyInput;
	string nameInput;
	double balanceInput;
	int menu;
	bool endCheck = true;
	
	do
	{
		cout << "1) Add node to tree\n"
			<< "2) Print nodes in order\n"
			<< "3) Find a specific node\n"
			<< "4) End program\n\n"
			<< "Enter a menu option 1-4: ";
		cin >> menu;

		cout << "-------------------------------\n";
		
		if (menu == 1)
		{
			cout << "Enter a integer key for the node: ";
			cin >> keyInput;
			cout<< "Enter a single name for the node: ";
			cin >> nameInput;
			cout << "Enter the balance due for the node: $";
			cin >> balanceInput;
			
			BST.appendLeaf(keyInput, nameInput, balanceInput);
			cout << "-------------------------------\n";
		}
		else if(menu == 2)
		{
			BST.print();
			cout << "-------------------------------\n";
		}
		else if(menu == 3)
		{
			cout << "Enter the key of the node you want to find: ";
			cin >> keyInput;
			
			BST.find(keyInput);
			cout << "-------------------------------\n";
		}
		else if(menu == 4)
		{
			endCheck = false;
		}
		else
		{
			cout << "Wrong menu input\n";
			cout << "-------------------------------\n";
		}	
	}while(endCheck);
	cout << "***PROGRAM ENDED***";	
}
