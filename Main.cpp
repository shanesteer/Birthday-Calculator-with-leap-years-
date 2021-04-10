#include <iostream>
#include <ctime>
#include "Date.h"
#include "Date.cpp"
#include <string>


using namespace std;

    int yeardiff;
    int monthdiff;
    int daydiff;
    int dd;
    int mm;
    int yy;
    string w;
    int refdate;

int main()
{
    string firstname;
    string familyname;
    cout << "Please enter your first name: \n";
    //cin >> firstname;
    //incase the person has 2 first names
    getline(cin, firstname);
    //ensures that the firstname field is filled
    if(firstname == "" || firstname == " ")
    {
        cout << "Invalid name. Please rerun and enter a valid name." << endl;
        exit(1);
    }
    cout << "Please enter your surname: \n";
    cin >> familyname;
    //ensures that the surname field is filled
    if(familyname == "" || familyname == " ")
    {
        cout << "Invalid name. Please rerun and enter a valid name." << endl;
        exit(1);
    }
    

    int d;
    int m;
    int y;

    cout << "What day were you born on (1-31): \n";
    cin >> d;
    cout << "What month were you born in (1-12): \n";
    cin >> m;
    cout << "What year were you born in (1000-9999): \n";
    cin >> y;


    cout << "Would you like to enter your own reference date or the current date for comparing? \n" ;
    cout << "Enter '1' for Yes or '0' for NO: \n";
    cin >> refdate;

    if(refdate == 1)
    {
        cout << "Please enter a day for comparing (1-31): \n";
        cin >> dd;
        cout << "Please enter a month for comparing (1-12): \n";
        cin >> mm;
        cout << "Please enter a year for comparing (1000-9999): \n";
        cin >> yy;


    }
    else
    {
        dd = local_time -> tm_mday;
        mm = 1 + local_time -> tm_mon;
        yy = 1900 + local_time -> tm_year;
    }
    

    Date q(d, m, y);
    Date q1(dd,mm,yy);

    if(q<q1)
    {
        // reference for calculations taken and modified from https://gist.github.com/mrtejaslol/cd0ec1357e1f510871c0ddc836079c83
        yeardiff = yy - y;
        monthdiff = mm - m;
        daydiff = dd - d;

        if(daydiff < 0) //if difference in days is less than 0, it is before the birthdate
        {
                monthdiff--;
                daydiff += 31;

        }

        if(monthdiff < 0) //if difference in months is less than 0, it is before the birthdate
        {
            yeardiff--;
            monthdiff += 12;
        }
    }

    else
    {
        yeardiff = y - yy;
        monthdiff = m - mm;
        daydiff = d - dd;
        


        if(daydiff < 0) //if difference in days is less than 0, it is before the birthdate
        {
                monthdiff--;
                daydiff += 31;

        }

        if(monthdiff < 0) //if difference in months is less than 0, it is before the birthdate
        {
            yeardiff--;
            monthdiff += 12;
        }
    }


    

    cout << "Name: " << firstname << " " << familyname << "\n";

    cout << "Reference Date: " << q1 << endl;

    //calls operator << to output birthday
    cout << q << endl;

    //calls the string() function to output birthday month with actual month name
    cout << string(q) << endl;

    //outputs the difference in years, months and days
    cout << "Which is " << yeardiff << " years, " << monthdiff << " months and " << daydiff << " days from the reference date." << endl;

    //checks if the date entered is in a leap year.
    q.isLeapYear();
 

}