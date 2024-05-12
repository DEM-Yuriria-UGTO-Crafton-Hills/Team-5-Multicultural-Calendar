#include <iostream>
#include <fstream>
#include "Storage.h"

using namespace std;

vector<Event> StoredEvents::LoadEvents(vector<Event> tempVector)
{
    ifstream fileIn;

    fileIn.open("Team 5 Multicultural Calendar/StoredEvents.txt");
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

    while (userDate.at(i) != '/' || userDate.at(i) != '\n')
    {
        tempStr.push_back(userDate.at(i));
    }
    userMonth = stoi(tempStr);

    //resets temp vars for next iteration
    i = 0;
    tempStr = "";

    while (userDate.at(i + 1 + slashIndex) != '/' || userDate.at(i + 1 + slashIndex) != '\n')
    {
        tempStr.push_back(userDate.at(i));
    }
    userDay = stoi(tempStr);

    i = 0;
    tempStr = "";

    //the actual searching function
    for (ii = 0; ii < tempVector.size(); ++ii)
    {
        tempEvent = tempVector.at(ii);

        slashIndex = tempEvent.getEventDate().find('/');

        while (tempEvent.getEventDate().at(i) != '/' ||
               tempEvent.getEventDate().at(i) != '\n')
        {
            tempStr = tempEvent.getEventDate().at(i);
        }
        tempMonth = stoi(tempStr);

        i = 0;
        tempStr = "";

        if (tempMonth == userMonth)
        {
            while (tempEvent.getEventDate().at(i + 1 + slashIndex) != '/' ||
                   tempEvent.getEventDate().at(i + 1 + slashIndex) != '\n')
            {
                tempStr = tempEvent.getEventDate().at(i + 1 + slashIndex);
            }
            tempDay = stoi(tempStr);

            i = 0;
            tempStr = "";

            if (tempDay = userDay)
            {
                cout << tempEvent.getEventName()
                     << tempEvent.getEventDate()
                     << tempEvent.getEventCountry()
                     << tempEvent.getEventDescription();
            }
        }
    }
}

void StoredEvents::SaveEvents(vector<Event> tempVector)
{
    ifstream fileOut;

    fileOut.open("Team 5 Multicultural Calendar/StoredEvents.txt");
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
        fileOut >> tempName;

        tempDate = tempEvent.getEventDate();
        fileOut >> tempDate;

        tempCountry = tempEvent.getEventCountry();
        fileOut >> tempCountry;

        tempDescription = tempEvent.getEventDescription();
        fileOut >> tempName;
    }

    fileOut.close();
}
