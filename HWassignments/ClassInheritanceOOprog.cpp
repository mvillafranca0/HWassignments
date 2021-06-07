#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

// Classes (beginning)
class Party
{
	private:
		string PartyTypeCode;
		string StreetAddress;
		string StateAddress;
		string zipcode;
		string PhoneNumber;
	public:
		void assignPTC(string arg)
		{
			PartyTypeCode = arg;
		};
		
		void assignStreetAddress(string arg)
		{
			StreetAddress = arg;
		};
		
		void assignStateAddress(string arg)
		{
			StateAddress = arg;
		};
		
		void assignZipcode(string arg)
		{
			zipcode = arg;
		};
		
		void assignPhoneNumber(string arg)
		{
			PhoneNumber = arg;
		};
		
		void displayPTC();
		void displayStreetAddress();
		void displayStateAddress();
		void displayZipcode();
		void displayPhoneNumber();
};

void Party :: displayPTC()
{
	if (PartyTypeCode == "P" || PartyTypeCode == "p")
		cout << "Person";
	else
		cout << "Organization";
}

void Party :: displayStreetAddress()
{
	cout << StreetAddress;
}

void Party :: displayStateAddress()
{
	cout << StateAddress;
}

void Party :: displayZipcode()
{
	cout << zipcode;
}

void Party :: displayPhoneNumber()
{
	cout << PhoneNumber;
}

class Person: public Party
{
	private:
		int BirthMonth; int BirthDay; int BirthYear;
		string FirstName;
		string LastName;
	public:
		void assignBirthMonth(int arg)
		{
			BirthMonth = arg;
		};
		void assignBirthDay(int arg)
		{
			BirthDay = arg;
		};
		void assignBirthYear(int arg)
		{
			BirthYear = arg;
		};
		
		void assignFirstName(string arg)
		{
			FirstName = arg;
		};
		
		void assignLastName(string arg)
		{
			LastName = arg;
		};
		
		void displayBirthMonth (); void displayBirthDay (); void displayBirthYear ();
		void displayFirstName ();
		void displayLastName ();
};

void Person :: displayBirthMonth()
{
	cout << BirthMonth;
}
void Person :: displayBirthDay()
{
	cout << BirthDay;
}
void Person :: displayBirthYear()
{
	cout << BirthYear;
}

void Person :: displayFirstName()
{
	cout << FirstName;
}

void Person :: displayLastName()
{
	cout << LastName;
}

class Passenger: public Person
{
	private:
		string TicketNum;
		string FreqFlyerNum;
		double TicketPrice;
		string FlightNum;
		string SeatLocation;
		int FlightMonth; int FlightDay; int FlightYear;
		char Status;
	public:
		void assignTicketNum (string arg)
		{
			TicketNum = arg;
		};
		
		void assignFreqFlyerNum (string arg)
		{
			FreqFlyerNum = arg;
		};
		
		void assignTicketPrice (double arg)
		{
			TicketPrice = arg;
		};
		
		void assignFlightNum (string arg)
		{
			FlightNum = arg;
		};
		
		void assignSeatLocation (string arg)
		{
			SeatLocation = arg;
		};
		
		void assignFlightMonth (int arg)
		{
			FlightMonth = arg;
		};
		void assignFlightDay (int arg)
		{
			FlightDay = arg;
		};
		void assignFlightYear (int arg)
		{
			FlightYear = arg;
		};
		
		void assignStatus (char arg)
		{
			Status = arg;
		};
		
		void displayTicketNum();
		void displayFreqFlyerNum();
		void displayTicketPrice();
		void displayFlightNum();
		void displaySeatLocation();
		void displayFlightMonth(); void displayFlightDay(); void displayFlightYear();
		void displayStatus();
};

void Passenger :: displayTicketNum()
{
	cout << TicketNum;
}

void Passenger :: displayFreqFlyerNum()
{
	cout << FreqFlyerNum;
}

void Passenger :: displayTicketPrice()
{
	cout << TicketPrice;
}

void Passenger :: displayFlightNum()
{
	cout << FlightNum;
}

void Passenger :: displaySeatLocation()
{
	cout << SeatLocation;
}

void Passenger :: displayFlightMonth()
{
	cout << FlightMonth;
}
void Passenger :: displayFlightDay()
{
	cout << FlightDay;
}
void Passenger :: displayFlightYear()
{
	cout << FlightYear;
}

void Passenger :: displayStatus()
{
	if (Status == 'T' || Status == 't')
		cout << "Ticketed";
	else
		cout << "Hold";
}

// Classes (ending)

// main function prototypes

void PassengerData();
void SeatChange(Passenger);
void DisplayConfirmation(Passenger);

// main function

int main()
{
	bool menuCheck = true;
	bool loopCheck = true;
	char menuInput;
	
	do
	{
		cout << "(1) Purchase a ticket\n" << "(2) Cancel Transaction\n";
		do
		{
			cout << "Enter the number associated with the action: ";
				cin >> menuInput;
			if (menuInput == '1' || menuInput == '2')
				menuCheck = false;
			else
				cout << "Input must be '1' or '2'\n";	
		}while (menuCheck);
		
		if (menuInput == '1')
		{
			cout << endl;
			PassengerData();
			loopCheck = false;
		}
		else
			loopCheck = false;
			
	}while (loopCheck);	
}

void PassengerData()
{
	char inputChar = '0';
	int inputInt = 0;
	double inputDouble = 0;
	string inputString = "0";
	
	char confirmation;
	bool loopCheck = true;
	
	Passenger guest;
	// Program wouldn't work properly unless I inserted what is below
	getline(cin, inputString);
	
	cout << "Enter your Party Type Code ('P' = person, 'O' = organization): ";
		getline(cin, inputString); guest.assignPTC(inputString);
	cout << endl;
	
	cout << "Enter your first name: ";
		getline(cin, inputString); guest.assignFirstName(inputString);
	cout << endl;
	
	cout << "Enter your last name: ";
		getline(cin, inputString); guest.assignLastName(inputString);
	cout << endl;
	
	cout << "Enter your address (Street Address, State, then Zip Code)\n";
	cout << "Enter Street Address: ";
		getline(cin, inputString); guest.assignStreetAddress(inputString);
	cout << "Enter State (enter only capitalized initials (EX: NJ) ): ";
		getline(cin, inputString); guest.assignStateAddress(inputString);
	cout << "Enter Zipcode: ";
		getline(cin, inputString); guest.assignZipcode(inputString);
	cout << endl;
	
	cout << "Enter phone number (Example format: XXX-XXX-XXXX): ";
		getline(cin, inputString); guest.assignPhoneNumber(inputString);
	cout << endl;
	
	cout << "*Enter your date of birth*\nEnter the number of the month of the birth date: ";
		cin >> inputInt; guest.assignBirthMonth(inputInt);
	cout << "Enter the day of the month of the birth date: ";
		cin >> inputInt; guest.assignBirthDay(inputInt);
	cout << "Enter the year of the birth date: ";
		cin >> inputInt; guest.assignBirthYear(inputInt);
	cout << endl;
	
	getline(cin, inputString);
	
	cout << "Enter the ticket number: ";
		getline(cin, inputString); guest.assignTicketNum(inputString);
	cout << endl;
	
	cout << "Enter a frequent flyer number (enter 'N/A' if none): ";
		getline(cin, inputString); guest.assignFreqFlyerNum(inputString);
	cout << endl;
		
	cout << "Enter flight number: ";
		getline(cin, inputString); guest.assignFlightNum(inputString);
	cout << endl;
	
	cout << "Enter seat location: ";
		getline(cin, inputString); guest.assignSeatLocation(inputString);
	cout << endl;
	
	cout << "Enter ticket price: $";
		cin >> inputDouble; guest.assignTicketPrice(inputDouble);
	cout << endl;
	
	cout << "*Enter the flight date*\nEnter the number of the month of the flight date: ";
		cin >> inputInt; guest.assignFlightMonth(inputInt);
	cout << "Enter the day of the month for the flight date: ";
		cin >> inputInt; guest.assignFlightDay(inputInt);
	cout << "Enter the year of the flight date: ";
		cin >> inputInt; guest.assignFlightYear(inputInt);
	cout << endl;
	
	cout << "Enter a status for the flight\n('T' = ticketed or 'H' = on hold): ";
		cin >> inputChar; guest.assignStatus(inputChar);
	cout << endl; 
	
	do
	{
		cout << "('F' = confirm, 'S' = change seat, 'C' = cancel): ";
			cin >> confirmation;
		
		if (confirmation == 'F' || confirmation == 'f')
		{
			DisplayConfirmation(guest);
			loopCheck = false;
		}
		else if (confirmation == 'S' || confirmation =='s')
			SeatChange(guest);
		else if (confirmation == 'C' || confirmation == 'c')
		{
			cout << endl;
			cout << "***FLIGHT BOOK CANCELLED***\n";
			loopCheck = false;
		}
		else
			cout << "*Enter a valid input*\n";
	}while (loopCheck);
}

void SeatChange(Passenger guest)
{
	string inputString;
	
	cout << endl;
	
	cout << "This is your current seat: ";
		guest.displaySeatLocation(); cout << endl;
		
	cout << "Enter the same seat number to not change it\nor a new number to change it: ";
		getline(cin, inputString); guest.assignSeatLocation(inputString);
		
	cout << endl;
}

void DisplayConfirmation(Passenger guest)
{
	cout << "Thank you for your purchase!\n\n";
	cout << "***FLIGHT DETAILS***\n\n";
	
	cout << "Party: ";
		guest.displayPTC(); cout << endl;
	cout << "First Name: ";
		guest.displayFirstName(); cout << endl;
		
	cout << "Last Name: ";
		guest.displayLastName(); cout << endl;
		
	cout << "Date of Birth: ";
		guest.displayBirthMonth(); cout << "/";
		guest.displayBirthDay(); cout << "/";
		guest.displayBirthYear(); cout << endl;
	
	cout << "Address: ";
		guest.displayStreetAddress(); cout << ", ";
		guest.displayStateAddress(); cout << ", "; 
		guest.displayZipcode(); cout << endl;
		
	cout << "Phone Number: ";
		guest.displayPhoneNumber(); cout << endl;
		
	cout << "Ticket Number: ";
		guest.displayTicketNum(); cout << endl;
		
	cout << "Frequent Flyer Number: ";
		guest.displayFreqFlyerNum(); cout << endl;
		
	cout << "Flight Number: ";
		guest.displayFlightNum(); cout << endl;
		
	cout << "Seat Location: ";
		guest.displaySeatLocation(); cout << endl;
		
	cout << "Ticket Price: $" << setprecision(2) << fixed;
		guest.displayTicketPrice(); cout << endl;
		
	cout << "Flight Date: ";
		guest.displayFlightMonth(); cout << "/";
		guest.displayFlightDay(); cout << "/";
		guest.displayFlightYear(); cout << endl;
		
	cout << "Status: ";
		guest.displayStatus(); cout << endl;
}
