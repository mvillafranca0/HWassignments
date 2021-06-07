#include <iostream>
#include <iomanip>
using namespace std;

int getsize();
void process(int, double[]);
void display(int, double[]);

int main()
{
	int size = 0;
	size = getsize();
	double grades[size];
	process(size, grades);
	display(size, grades);
}

int getsize()
{
	int input = 0;
	cout << "How many grades will be provided (the max is 30): ";
	while (input < 1 || input > 30)
	{
		cin >> input;
		if (input < 1 || input > 30)
			cout << "Input must be 1-30: ";
	}
	return input;
}

void process(int arg1, double arg2[])
{
	int temp;
	bool swap;
	
	for (int count = 0; count < arg1; count++)
	{
		cout << "Enter Grade " << count+1 << " (0-100): ";
		arg2[count] = -1;
		while (arg2[count] < 0 || arg2[count] > 100)
		{
			cin >> arg2[count];
			if (arg2[count] < 0 || arg2[count] > 100)
				cout << "Input must be 0-100: ";
		}
	}
	
	do
	{
		swap = false;
		for (int count2 = 0; count2 < (arg1 - 1); count2++)
		{
			if (arg2[count2] > arg2[count2 + 1])
			{
				temp = arg2[count2];
				arg2[count2] = arg2[count2 + 1];
				arg2[count2 + 1] = temp;
				swap = true;
			}
		}
	} while (swap);	
}

void display(int arg1, double arg2[])
{
	double ave = 0;
	
	cout << "\n***GRADES WILL ARE PRINTED FROM LEAST TO GREATEST***\n\n";
	for (int count = 0; count < arg1; count++)
	{
		cout << "Grade " << count+1 << ": " << arg2[count] << endl;
		ave = ave + arg2[count];
	}
	
	ave = ave / arg1;
	cout << setprecision(2) << fixed;
	cout << endl << "The average for all the grades is: " << ave;	
}
