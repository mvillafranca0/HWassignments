#include <iostream>
#include <string>
using namespace std;

// class for linked list
class List
{
	private:
// Node is a structure
		struct Node
		{
			string elem;
			Node *next;
		};
		int sizecount = 0;
		struct Node *head;
		struct Node *current;
		struct Node *temp;
	public:
// constructor makes private ptrs = NULL
		List()
		{
			head = NULL;
			current = NULL;
			temp = NULL;
		}
// function prototypes
		void push(string);
		void pop();
		string top();
		int size();
		bool empty();
		
};

// function definitions	
void List :: push(string arg)
{
	struct Node *newPtr = new Node;
	if(head == NULL)
	{
		current -> next = NULL;
		current -> elem = arg;
		head = newPtr;
		sizecount++;	
	}
	else
	{
		newPtr -> next = head;
		newPtr -> elem = arg;
		head = newPtr;
		sizecount++;
	}
}
	
void List :: pop()
{
	if(head == NULL)
	{
		cout << "No nodes to pop";
	}
	else
	{
		struct Node *old = head;
		head = old -> next;
		delete old;
		sizecount--;
	}
}

string List :: top()
{
	return head -> elem;
}

int List :: size()
{
	return sizecount;
}

bool List :: empty()
{
	if(head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string input;
	string temp;
	string temp2;
	string output = "\0";
	List stack;
	
	cout << "Enter a infix computation with no spaces [EX:((2+3)/1)*2]\nInput: ";
		cin >> input;
		
	for (int count = 0; count < input.length(); count++)
	{
		// checks for number
		if (isdigit(input[count]))
		{
			temp = input[count];
			output.append(temp);
		}
		// checks for '('
		else if (input[count] == '(')
		{
			temp = input[count];
			stack.push(temp);
		}
		// checks for ')'
		else if (input[count] == ')')
		{
			temp = stack.top();
			while (temp != "(")
			{
				output.append(temp);
				stack.pop();
				temp = stack.top();
			}
			stack.pop();
		}
		// checks for '*' & '/'
		else if (input[count] == '*' || input[count] == '/')
		{
			temp = stack.top();
			if (stack.empty())
			{
				temp2 = input[count];
				stack.push(temp2);
			}
			else if (((temp == "+") || temp == "-")|| temp == "(")
			{
				temp2 = input[count];
				stack.push(temp2);
			}
			else
			{
				while ((temp == "/")|| temp == "*")
				{
					if (stack.empty())
					{
						temp = "\0";
					}
					else
					{
						output.append(temp);
						stack.pop();
						temp = stack.top();
					}
				}
				temp2 = input[count];
				stack.push(temp2);
			}
		}
		// checks for '+' & '-'
		else
		{
			temp = stack.top();
			if (stack.empty())
			{
				temp2 = input[count];
				stack.push(temp2);
			}
			else if (temp == "(")
			{
				temp2 = input[count];
				stack.push(temp2);
			}
			else
			{
				while ((((temp == "/")|| temp == "*")|| temp == "+")|| temp == "-")
				{
					if (stack.empty())
					{
						temp = "\0";
					}
					else
					{
						output.append(temp);
						stack.pop();
						temp = stack.top();
					}
				}
				temp2 = input[count];
				stack.push(temp2);
			}
		}
	}
	// output postfix
	cout << output;
}
