#include <iostream>
#include <cstdlib>
using namespace std;

class list
{
	private:
		struct node
		{
			int currReq;
			int nextReq;
			bool skip;
			node *next;
			node *prev;
		};
		struct node *head;
		struct node *tail;
		struct node *current;
		struct node *temp;
		int nodeCount;
		int currFloor;
	public:
		list()
		{
			head = NULL;
			tail = NULL;
			current = NULL;
			temp = NULL;
			nodeCount = 0;
			currFloor = 1;
		}
		void geton(int, int);
		void move();
};

void list :: geton(int arg, int arg2)
{
	struct node *ptr = new node;
	ptr -> next = NULL;
	ptr -> prev = NULL;
	ptr -> currReq = arg;
	ptr -> nextReq = arg2;
	ptr -> skip = false;
	if (nodeCount == 0)
	{
		head = ptr;
		tail = ptr;
		nodeCount++;
	}
	else
	{
		current = head;
		while (current -> next != NULL)
		{
			current = current -> next;
		}
		current -> next = ptr;
		ptr -> prev = current;
		tail = ptr;
		nodeCount++;
	}
}

void list :: move()
{
	int reqDone = 0;
	// values used to tell elevator which direction to go
	bool up = true;
	bool down = false;
	int floor = currFloor; // save current floor elevator is on
	
	cout << "Elevator moving...\n\n"; 
	while (reqDone != nodeCount) // once this is true, program will know all current requests have been done
	{
		current = head;
		while (current != NULL)
		{
			if(current -> skip)
			{
			// do nothing, and check next request
			;
			}
			else if(floor == current -> currReq && current -> nextReq != 0)
			{
				cout << "someone got on, on floor " << floor << endl;
				currFloor = floor;
				current -> currReq = current -> nextReq;
				current -> nextReq = 0;
			}
			else if(floor == current -> currReq && current -> nextReq == 0)
			{
				cout << "someone got off, on floor " << floor << endl;
				currFloor = floor;
				current -> currReq = 0;
				current -> skip = true;
				reqDone++;
			}
			else
			{
				// do nothing, and check next request
			;
			}
				current = current -> next;
		}
		// make elevator go up or down	
		if(up)
		{
			if(floor == 11)
			{
				up = false;
				down = true;
			}
			else
			{
				floor++;
			}	
		}
		if(down)
		{
			if(floor == 0)
			{
				up = true;
				down = false;
			}
			else
			{
				floor--;
			}	
		}
	}	

	cout << "\nElevator stopped, waiting for more requests...\n\n";
	
//	delete current request list after fulfilling requests
	current = head;
	while (current -> next != NULL)
	{
		temp = current;
		current = current -> next;
		delete temp;
		nodeCount--;
	}
	temp = current;
	current = current -> next;
	delete temp;
	nodeCount--;
	
	head = NULL;
	tail = NULL;
	current = NULL;
	temp = NULL;
}

int main()
{
	list elevator;
	
	cout << "Waiting for requests... \n\n";
	//event list and function calls
	elevator.geton(4,6);
	elevator.move();
	
	elevator.geton(8,2);
	elevator.geton(1,5);
	elevator.geton(9,3);
	elevator.move();
	
	elevator.geton(10,2);
	elevator.geton(7,4);
	elevator.move();
	
	elevator.geton(1,7);
	elevator.move();
	cout << "No more requests... \n";
}
