#include <iostream>
#include <fstream>
#include "Storage.h"

using namespace std;

vector<Event> StoredEvents::LoadEvents(vector<Event> tempVector)
{
    ifstream fileIn;

    fileIn.open("StoredEvents.txt");
    if (!fileIn.is_open())
    {
        cout << "unable to open storage" << endl;
        return tempVector;
    }

    while (!fileIn.eof())
    {
        Event tempEvent;
        string tempName;
        string tempDate;
        string tempCountry;
        string tempDescription;

        getline(fileIn, tempName);
        tempEvent.setEventName(tempName);

        getline(fileIn, tempDate);
        tempEvent.setEventDate(tempDate);

        getline(fileIn, tempCountry);
        tempEvent.setEventCountry(tempCountry);

        getline(fileIn, tempDescription);
        tempEvent.setEventDescription(tempDescription);

        tempVector.push_back(tempEvent);
    }

    fileIn.close();

    return tempVector;
}

void StoredEvents::SearchByName(string userName, vector<Event> tempVector)
{
    int i;
    int ii;
    Event tempEvent;
    string tempString;

    for (i = 0; i != userName.length(); ++i)
    {
        userName.at(i) = tolower(userName.at(i));
    }

    for (ii = 0; ii != tempVector.size(); ++ii)
    {
        tempEvent = tempVector.at(ii);
        tempString = tempEvent.getEventName();

        for (i = 0; i != userName.length(); ++i)
        {
            tempString.at(i) = tolower(tempString.at(i));
        }

        if (tempString == userName)
        {
            cout << endl
                 << "Name: " << tempEvent.getEventName() << endl
                 << "Date: " << tempEvent.getEventDate() << endl
                 << "Country: " << tempEvent.getEventCountry() << endl
                 << "Description: " << tempEvent.getEventDescription() << endl;
            return;
        }
    }
}

void StoredEvents::DisplayEventsInMonth(string userMonth, vector<Event> tempVector)
{
    int tempMonth;
    int monthNum;
    string tempStr = "";
    int i = 0;
    int ii = 0;
    Event tempEvent;

    while (userMonth.size() != i)
    {
        tempStr.push_back(userMonth.at(i));
        i++;
    }
    monthNum = stoi(tempStr);

    i = 0;
    tempStr = "";

    //the actual searching function
    for (ii = 0; tempVector.size() != ii; ++ii)
    {
        tempEvent = tempVector.at(ii);

        while (tempEvent.getEventDate().size() != i)         
        {
            tempStr.push_back(tempEvent.getEventDate().at(i));
            i++;
        }
        tempMonth = stoi(tempStr);

        i++;

        if (tempMonth == monthNum)
        {
            cout << endl
                 << "Name: " << tempEvent.getEventName() << endl
                 << "Date: " << tempEvent.getEventDate() << endl
                 << "Country: " << tempEvent.getEventCountry() << endl
                 << "Description: " << tempEvent.getEventDescription() << endl;
        }
        i = 0;
        tempStr = "";
    }
}

void StoredEvents::SearchByDate(string userDate, vector<Event> tempVector)
{
    int userMonth;
    int userDay;
    int tempMonth;
    int tempDay;
    string tempStr;
    int i = 0;
    int ii = 0;
    Event tempEvent;

    //separate input string into month and day

    while (userDate.at(i) != '/')
    {
        tempStr.push_back(userDate.at(i));
        i++;
    }
    userMonth = stoi(tempStr);

    //resets temp vars for next iteration
    i++;
    tempStr = "";

    while (userDate.size() != i)
    {
        tempStr.push_back(userDate.at(i));
        i++;
    }
    userDay = stoi(tempStr);

    i = 0;
    tempStr = "";

    //the actual searching function
    for (ii = 0; tempVector.size() != ii; ++ii)
    {
        tempEvent = tempVector.at(ii);

        while (tempEvent.getEventDate().at(i) != '/')         
        {
            tempStr.push_back(tempEvent.getEventDate().at(i));
            i++;
        }
        tempMonth = stoi(tempStr);

        i++;
        tempStr = "";

        if (tempMonth == userMonth)
        {
            while (tempEvent.getEventDate().size() != i)
            {
                tempStr.push_back(tempEvent.getEventDate().at(i));
                i++;
            }
            tempDay = stoi(tempStr);

            if (tempDay == userDay)
            {
                cout << endl
                     << "Name: " << tempEvent.getEventName() << endl
                     << "Date: " << tempEvent.getEventDate() << endl
                     << "Country: " << tempEvent.getEventCountry() << endl
                     << "Description: " << tempEvent.getEventDescription() << endl;
            }
        }
        i = 0;
        tempStr = "";
    }
}

void StoredEvents::SaveEvents(vector<Event> tempVector)
{
    fstream fileOut;

    fileOut.open("StoredEvents.txt", ofstream::out | ofstream::trunc);
    if (!fileOut.is_open())
    {
        cout << "unable to open storage" << endl;
        return;
    }

    for (int i = 0; i < tempVector.size(); i++)
    {
        Event tempEvent;
        string tempName;
        string tempDate;
        string tempCountry;
        string tempDescription;

        tempEvent = tempVector.at(i);

        tempName = tempEvent.getEventName();
        fileOut << tempName << endl;

        tempDate = tempEvent.getEventDate();
        fileOut << tempDate << endl;

        tempCountry = tempEvent.getEventCountry();
        fileOut << tempCountry << endl;

        tempDescription = tempEvent.getEventDescription();
        fileOut << tempDescription;

        if (i != tempVector.size() - 1)
        {
            fileOut << endl;
        }
    }

    fileOut.close();
}
