#include <iostream>
#include <string>
using namespace std;

// program meant to run in C++ 11 compiler

class arrayStack
{
	private:
		int index = -1;
		char stack[200] = {'\0'};
	public:
		void push(char arg)
		{
			if (index == -1)
			{
				index++;
				stack[index] = arg;
				index++;
			}
			else
			{
				stack[index] = arg;
				index++;
			}
		};
		void pop()
		{
			if(index == -1)
			{
				cout << "Stack is empty";
			}
			else
			{
				index--;
				stack[index] = '\0';
			}
		};
		char top()
		{
			char arg = stack[index-1];
			return arg;
		};
		int size()
		{
			return index-1;
		};
		bool empty()
		{
			if (index == -1)
				return true;
			else
				return false;
		}	
};

int main()
{
	string input;
	char temp;
	bool check = true;
	// loop count
	int count;
	// parenthesis count
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int count6 = 0;
	arrayStack stack;
	cout << "Enter a infix expression with parenthesis and no spaces\nInput: ";
	getline(cin, input);
	
	// first count each parenthesis
	for (count = 0; count < input.length(); count++)
	{
		if (input[count] == '(')
		{
			count1++;
		}
		else if (input[count] == '{')
		{
			count2++;
		}
		else if (input[count] == '[')
		{
			count3++;
		}
		else if (input[count] == ')')
		{
			count4++;
		}
		else if (input[count] == '}')
		{
			count5++;
		}
		else if (input[count] == ']')
		{
			count6++;
		}
		else
		{
			// do nothing
			temp = '\0';
		}
	}
	
	// then check to see if there's the same amount of left and right parenthesis for each type
	if (count1 < count4)
	{
		cout << "Not enough '(' for ')'"; return 0;
	}
	else if (count1 > count4)
	{
		cout << "Not enough ')' for '('"; return 0;
	}
	else if (count2 < count5)
	{
		cout << "Not enough '{' for '}'"; return 0;
	}
	else if (count2 > count5)
	{
		cout << "Not enough '}' for '{'"; return 0;
	}
	else if (count3 < count6)
	{
		cout << "Not enough '[' for ']'"; return 0;
	}
	else if (count3 > count6)
	{
		cout << "Not enough ']' for '['"; return 0;
	}
	else
	{	
		cout << "Same amount of parenthesis for each parenthesis type\n"
			<< "now checking parenthesis order\n";
	}
	
	// if first part passes then it will check to see if parenthesis are ordered correctly
	for (count = 0; count < input.length(); count++)
	{
		if (isdigit(input[count]))
		// ignore
		{
			temp = '\0';
		}
		else if ((((input[count] == '+')|| input[count] == '-')|| input[count] == '*')|| input[count] == '/')
		// ignore
		{	
			temp = '\0';
		}
		else if (((input[count] == '(')|| input[count] == '{')|| input[count] == '[')
		{
			temp = input[count];
			stack.push(temp);
		}
		else
		{
			if (input[count] == ')')
			{
				temp = stack.top();
				if (temp == '(')
				{
				stack.pop();	
				}
				else
				{
					cout << "Parentheses are not ordered correctly: '('" << endl;
					check = false;
					break;
				}
			}
			if (input[count] == '}')
			{
				temp = stack.top();
				if (temp == '{')
				{
				stack.pop();	
				}
				else
				{
					cout << "Parentheses are not ordered correctly: '{'" << endl;
					check = false;
					break;
				}
			}
			if (input[count] == ']')
			{
				temp = stack.top();
				if (temp == '[')
				{
				stack.pop();
				}
				else
				{
					cout << "Parentheses are not ordered correctly: '['" << endl;
					check = false;
					break;
				}
			}
		}
	}
	
	// messages for correctly ordered parenthesis or not ordered correctly 
	if (check)
		{
			cout << "All parentheses are matched correctly" << endl;
		}
	else
		{
			cout << "Fix parentheses order" << endl;
		}
}
