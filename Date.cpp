#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>
#include "Date.h"

using namespace std;

time_t timeholder = time(0);
tm *local_time = localtime(&timeholder);


Date::Date()
{
    
    int d = local_time -> tm_mday;
    int m = 1 + local_time -> tm_mon;
    int y = 1900 + local_time -> tm_year;

  
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
    d = day;
    m = month;
    y = year;

    
    //checks if vales for days, months or years are 0
    if(d == 0 || m == 0 || y == 0)
    {
        cout << "Values for days, months and years cannot be zero. Please rerun and enter valid values." << endl;
        exit(1);

    }

    //checks the month of February
    else if(m == 2)
    {
        //if the year entered is a leap year, then max number of days in February is 29
        if(this->isLeapYear())
        {
            cout << "Max number of days is 29 as it is a leap year. Please rerun and enter a valid day." << endl;
            exit(1);
        }

        //if the year entered is not a leap year, then max number of days in February is 28
        else
        {
            cout << "Max number of days is 28 as it is not a leap year. Please rerun and enter a valid day." << endl;
            exit(1);
        }
        
    }

    //checks if the values entered for months exceeds 12
    else if(m > 12)
    {
        cout << "Value for months cannot exceed 12. Please rerun and enter a valid month." << endl;
        exit(1);
    }
    
    //checks if the values for days in the following months exceeds 31
    else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if(d > 31)
        {
            cout <<"Value for days cannot exceed 31 in this month. Please rerun and enter a valid day."<< endl;
            exit(1);
        }
        else
        {
            cout << "\n";
        }
    }

    //checks if the values for days in the following months exceeds 30
    else if(m == 4 || m == 6 | m == 9 || m == 11)
    {
        if(d > 30)
        {
            cout <<"Value for days cannot exceed 30 in this month. Please rerun and enter a valid day. "<< endl;
            exit(1);
        }
        else
        {
            cout << "\n";
        }
        
    }

    //checks if the values for years is within range 1000 - 9999
    else if(y < 1000 || y > 9999)
    {
        cout << "Value for year is not valid. Please rerun and enter a valid year." << endl;
        exit(1);
    }
}


//leap year function
bool Date::isLeapYear() const
{
    int year = y;

    //checks if years are divisible by 4 or divisible by 100 and 400
    if((year%4 == 0) || (year%100 == 0 && year%400 == 0))
    {
        cout << "Born in a leap year" << endl;
        return true;
    }

    else
    {
        cout << "Not born in a leap year" << endl;
        return false;
    }
    
}


bool Date::operator<(const Date& other) const
{
    //checks if the year entered by user is smaller than the reference year
    if(this->y < other.y)
    {
        cout << "The birthday entered is in the past of the reference date." <<endl;
        return true;
    }
    //checks if the year entered by user is larger than the reference year
    else if(this->y > other.y)
    {
        cout << "The birthday entered is in the future of the reference date." << endl;
        return false;
    }

    //if the year entered is the same for both, then check the month
    else
    {
        //checks if the month entered by user is smaller than the reference month
        if(this->m < other.m)
        {
            cout << "The birthday entered is in the past of the reference date." <<endl;
            return true;
        }
        //checks if the month entered by user is larger than the reference month
        else if(this->m > other.m)
        {
            cout << "The birthday entered is in the future of the reference date." << endl;
            return false;
        }

        //if the month entered is the same for both, then check the day
        else
        {
            //checks if the day entered by user is smaller than the reference day
            if(this->d < other.d)
            {
                cout << "The birthday entered is in the past of the reference date." <<endl;
                return true;
            }
            //checks if the day entered by user is larger than the reference day
            else if(this->d > other.d)
            {
                cout << "The birthday entered is in the future of the reference date." << endl;
                return false;
            }
            //if the day entered is the same, then say that both dates are equal
            else
            {
                cout << "The birthday entered is the same as the current date of the reference date." << endl;
                return false;
            }
            
        }
    }
}
    

bool Date::operator>(const Date& other) const
{
    //checks if the year entered by user is larger than the reference year
    if(this->y > other.y)
    {
        cout << "The birthday entered is in the future of the reference date." <<endl;
        return true;
    }
    //checks if the year entered by user is smaller than the reference year
    else if(this->y < other.y)
    {
        cout << "The birthday entered is in the past of the reference date." << endl;
        return false;
    }

    //if the year entered is the same for both, then check the month
    else
    {
        //checks if the month entered by user is larger than the reference month
        if(this->m > other.m)
        {
            cout << "The birthday entered is in the future of the reference date." <<endl;
            return true;
        }
        //checks if the month entered by user is smaller than the reference month
        else if(this->m < other.m)
        {
            cout << "The birthday entered is in the past of the reference date." << endl;
            return false;
        }

        //if the year entered is the same for both, then check the month
        else
        {
            //checks if the year entered by day is larger than the reference day
            if(this->d > other.d)
            {
                cout << "The birthday entered is in the future of the reference date." <<endl;
                return true;
            }
            //checks if the day entered by user is smaller than the reference day
            else if(this->d < other.d)
            {
                cout << "The birthday entered is in the past of the reference date." << endl;
                return false;
            }
            //if the day entered is the same, then say that both dates are equal
            else
            {
                cout << "The birthday entered is the same as the current date of the reference date." << endl;
                return false;
            }
            
        }
    }
}


Date::operator string() const
{
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string monthnames = months[m-1];
    ostringstream s;
    s <<"Birthday: " << monthnames << " " << setfill('0') << setw(2) << to_string(this->d) << ", " << setw(4) << to_string(this->y);
    return s.str();
}

ostream& operator<<(ostream& o, const Date& d)
{
    return cout << "Birthday: " << setfill('0') << setw(2) << d.d << "/" << setfill('0') << setw(2) << d.m << "/" << setw(4) << d.y;
}


