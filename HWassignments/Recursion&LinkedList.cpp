#include<iostream>
#include<cstdlib>
using namespace std;

// class for linked list
class List
{
	private:
// Node is a structure
		struct Node
		{
			string airportCode;
			double miles;
			Node *next;
		};
	
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
		void appendNode(string, double);
		double loopCount(string);
		double recursionCount(string, double, bool);
};

// function definitions	
void List :: appendNode(string arg, double arg2)
{
	struct Node *newPtr = new Node;
	newPtr -> next = NULL;
	newPtr -> airportCode = arg;
	newPtr -> miles = arg2;
	
	if(head != NULL)
	{
		current = head;
		while (current -> next != NULL)
		{
			current = current -> next;
		}
		current -> next = newPtr;
	}
	else
	{
		head = newPtr;
	}
}
	
double List :: loopCount(string arg)
{
	double mileCount = 0;
	current = head;
	bool check = true;
	
	
	while(current -> airportCode != arg)
	{
		mileCount = current -> miles + mileCount;
		current = current -> next;
	}
	mileCount = current -> miles + mileCount;
	return mileCount;
}

/*
 I can't get the recursion function to print out
 the right amount of miles
*/

double List :: recursionCount(string arg, double arg2, bool arg3)
{	
	if (arg3)
	{
		current = head;
	}
	
	if (arg == current -> airportCode)
	{
		arg2 = arg2 + current -> miles;
		return arg2;
	}
	else
	{
		arg2 = arg2 + current -> miles;
		current = current -> next;
		recursionCount(arg, arg2, false);
	}
}

// main function
int main()
{
	string code;
	double distance;
	int choice;
	bool loopCheck = true;
	bool firstTimeCheck = true;
	List list;
	
	list.appendNode("LGA", 0);
	cout << "This program will allow you to enter data of an Airport code\n"
		<< "and the distance in miles away from New York City's LaGuardia Airport.\n\n";
		
	while (loopCheck)
	{
		cout << "1) Add a new airport to the list\n"
			<< "2) Find and calculate the distance from LGA to a selected airport by looping\n"
			<< "3) Find and calculate the distance from LGA to a selected airport by recursion\n"
			<< "4) End program\n\n"
			<< "***NOTE***\n"
			<< "IF ENTERING MULTIPLE AIRPORTS, ENTER THEM FROM CLOSEST TO FURTHEST\n"
			<< "FROM NEW YORK CITY'S LA GUARDIA AIRPORT\n\n";
		cout << "Enter the number correlated with a menu option: "; cin >> choice;

		if (choice == 1)
		{
			cout << "*******************************************************************\n";
			cout << "Enter an airport code: ";
				cin >> code;
			if (firstTimeCheck)
			{
				cout << "Enter the distance in miles from LGA airport: ";
				firstTimeCheck = false;
			}
			else
			{
				cout << "Enter the distance in miles from the last entered airport: ";
			}
				cin >> distance;
			list.appendNode(code, distance);
			cout << "*******************************************************************";
			cout << "\n\n\n";
		}
		else if (choice == 2)
		{
			cout << "*******************************************************************\n";
			cout << "\nEnter the airport code: ";
				cin >> code;
			cout << "Airport " << code << " is ";
			cout << list.loopCount(code);
			cout << " miles from LGA\n";
			cout << "*******************************************************************";
			cout << "\n\n\n";
			
		}
		else if (choice == 3)
		{
			cout << "*******************************************************************\n";
			cout << "\nEnter the airport code: ";
				cin >> code;
			cout << "Airport " << code << " is ";
			cout << list.recursionCount(code, 0, true);
			cout << " miles from LGA\n";
			cout << "*******************************************************************";
			cout << "\n\n\n";
		}
		else if (choice == 4)
		{
			loopCheck = false;
			cout << "***PROGRAM ENDED***";
		}
		else
		{
			cout << "***INVALID INPUT***\n";
		}
	}	
}
