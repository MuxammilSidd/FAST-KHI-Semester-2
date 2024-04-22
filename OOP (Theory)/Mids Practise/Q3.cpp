#include <iostream>
using namespace std;
class Date
{
	int day;			// range from 1 to 31
	int month;		// range from 1 to 12
	int year;		// ranging from 2000 onwards
	
	
	// private function advance()
	void advance()
	{
		int d = day;
		int m = month;
		
		switch(m)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(d == 31)
				{
					day = 1;
					++month;
				}
				else
				{ ++day; }
				break;
			case 2:
				if(d == 29)
				{
					day = 1;
					++month;
				}
				else
				{ ++day; }
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if(d == 30)
				{
					day = 1;
					++month;
				}
				else
				{ ++day; }
				break;
		}
	//year-level validation can additionally be performed
	}
	
	
	public:
	// Date class constructor
	Date(int day = 1, int month = 1, int year = 2000)
	{
		if(day > 31 || month > 12 || year < 2000)
		{
			cout << "Date invalid";
			return;
		}
		this->day = day; this->month = month; this->year = year;
	}
	
	// function to set date
	void setDate(int date, int month, int year)
	{
		this->day = day; this->month = month; this->year = year;
	}
	
	

	// function to display date
	void showDate()
	{
		cout << day << " / " << month << " / " << year << endl;
	}
	
	// public interface to use advance()
	void callAdvance()
	{
		advance();
	}
};

int main()
{
	Date d1(31, 12, 2000);
	d1.callAdvance();	//to call advance() for updating the date
	d1.showDate();		// display date
}
