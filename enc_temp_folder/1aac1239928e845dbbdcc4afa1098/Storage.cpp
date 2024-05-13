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

void StoredEvents::SearchByDate(string userDate, vector<Event> tempVector)
{
    int userMonth;
    int userDay;
    int tempMonth;
    int tempDay;
    string tempStr;
    int slashIndex;
    int i = 0;
    int ii = 0;
    Event tempEvent;

    //separate input string into month and day
    slashIndex = userDate.find('/');

    while (userDate.at(i) != '/' )
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
    for (ii = 0; ii < tempVector.size(); ++ii)
    {
        tempEvent = tempVector.at(ii);

        slashIndex = tempEvent.getEventDate().find('/');

        while (tempEvent.getEventDate().at(i) != '/')         
        {
            tempStr = tempEvent.getEventDate().at(i);
            i++;
        }
        tempMonth = stoi(tempStr);

       i++;
        tempStr = "";

        if (tempMonth == userMonth)
        {
            while (
                   tempEvent.getEventDate().size() != i)
            {
                tempStr = tempEvent.getEventDate().at(i);
                i++;
            }
            tempDay = stoi(tempStr);

            i = 0;
            tempStr = "";

            if (tempDay == userDay)
            {
                cout << tempEvent.getEventName() << endl
                     << tempEvent.getEventDate() << endl
                     << tempEvent.getEventCountry() << endl
                     << tempEvent.getEventDescription() << endl;
            }
        }
    }
}

void StoredEvents::SaveEvents(vector<Event> tempVector)
{
    fstream fileOut;

    fileOut.open("Team 5 Multicultural Calendar/StoredEvents.txt", ofstream::trunc);
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
        fileOut << tempName;

        tempDate = tempEvent.getEventDate();
        fileOut << tempDate;

        tempCountry = tempEvent.getEventCountry();
        fileOut << tempCountry;

        tempDescription = tempEvent.getEventDescription();
        fileOut << tempName;
    }

    fileOut.close();
}
