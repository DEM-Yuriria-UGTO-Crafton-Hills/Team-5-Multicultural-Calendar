#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <vector>
#include "MexicanEvent.h"
#include "AmericanEvent.h"
#include "Storage.h"

using namespace std;
void options(int, string[2]);
void calendarPrint(int);
int IntroScreen();
int StringToInt(string);
int Calendar(int);
bool IsItAnInt(string);
int Screen();
int MonthDayHold[2];
long monthPoint = 0;


int Days[12]{ 31,29,31,30,31,30,31,31,30,31,30,31 };
string months[] = { "January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December" };
void SearchFunction(string);
int main()
{
    MonthDayHold[0] = 1;
    MonthDayHold[1] = 1;
    int OptionChoice = 100;
    string WAIT;
    string EventNameAndDes[2];
    EventNameAndDes[0] = "";
    EventNameAndDes[1] = "";
    int choice;
    int month;
    int MonthAndDay[2] = { 1,2 };
    string day;
    choice = IntroScreen();
    string Date = "";
    //variables neccesary to load the file and keep it in RAM
    vector<Event> LoadedEvents;
    StoredEvents storedEvents;

    //reads all file contents and loads them into the vector
    //in the order they were written to the file
    LoadedEvents = storedEvents.LoadEvents(LoadedEvents);

    do
    {
        system("cls");
        if (choice == 0) {
            break;
        }



        if (choice == 1) {
            options(choice, EventNameAndDes);
            SearchFunction(EventNameAndDes[0]);
            if (MonthDayHold[1] == 33) {
                std::cout << "The event could not be found. " << endl;

            }
            else {
                std::cout << "The event is on " << months[MonthDayHold[0]] << ", " << MonthDayHold[1] << endl;

            }
            getline(cin, WAIT);
            system("cls");
        }

        if (choice == 2) {
            month = Calendar(choice);
            std::cout << "Please select a day" << endl;
            getline(cin, day);
            while (IsItAnInt(day) || Days[month] < stoi(day) || stoi(day) < 0) {
                std::cout << "Please select a day. " << endl << "There are: " << Days[month] << " days in " << months[month] << endl;
                getline(cin, day);


            }
            options(choice, EventNameAndDes);

            system("cls");
            std::cout << "Your new Event:" << endl;
            std::cout << "Name: " << EventNameAndDes[0] << endl;
            std::cout << "Description: " << EventNameAndDes[1] << endl;
            getline(cin, WAIT);
            system("cls");
        }

        if (choice == 3) {
            month = Calendar(choice);

            //Print out all events for the month
            getline(cin, WAIT);
            system("cls");
        }

        if (choice == 4) {
            month = Calendar(choice);
            std::cout << "Please select a day" << endl;
            getline(cin, day);
            while (IsItAnInt(day) || Days[month] < stoi(day) || stoi(day) < 0) {
                std::cout << "Please select a day. " << endl << "There are: " << Days[month] << " days in " << months[month] << endl;
                getline(cin, day);
            }
            Date = to_string(month + 1) + "/" + day;
            storedEvents.SearchByDate(Date,LoadedEvents);

            
            getline(cin, WAIT);
            system("cls");
        }

        choice = Screen();

    } while (choice != 0);

    std::cout << "Thanks for viewing the calendar" << endl;
    delete[] EventNameAndDes;
    return 0;
}

void options(int choice, string DescriptAndName[2]) {

    DescriptAndName[0] = "";
    DescriptAndName[1] = "";
    string dayHolder = "";
    int day = 32;


    bool num = true;




    switch (choice) {

    case 2: {
        std::cout << "Please enter a name for the new event" << endl;
        getline(cin, DescriptAndName[0]);
        std::cout << "Please enter a description of the new event" << endl;
        getline(cin, DescriptAndName[1]);
        break;
    }
    case 1: {

        std::cout << "Please enter the name of the event" << endl;
        getline(cin, DescriptAndName[0]);
        break;
    }

          return;
    }

}
void calendarPrint(int month) {

    int i = 0;
    int k = 0;
    int counterSpace = 0;
    int WeekDayStart = 0;
    int monthHolder = month;

    std::cout << "         " << months[monthHolder] << endl;
    std::cout << "  S    M    T    W   Th    F    S     " << endl;
    std::cout << "------------------------------------------" << endl;

    map<string, int> weekday;
    weekday["January"] = 1;//0
    weekday["February"] = 4;//1
    weekday["March"] = 5;//2
    weekday["April"] = 1;//3
    weekday["May"] = 3;//4
    weekday["June"] = 6;//5
    weekday["July"] = 1;//6
    weekday["August"] = 4;//7
    weekday["September"] = 0;//8
    weekday["October"] = 2;//9
    weekday["November"] = 5;//10
    weekday["December"] = 0;//11
    WeekDayStart = weekday[months[month]];

    for (i = 1; i <= Days[monthHolder]; i++) {
        if (k == 0 && counterSpace != WeekDayStart && WeekDayStart != 0) {
            for (counterSpace = 0; counterSpace < WeekDayStart; counterSpace++) {
                std::cout << "     ";
                k++;
            }

        }
        if (i < 10) {

            std::cout << setw(1) << left << "  " << i << "  ";
            counterSpace++;

        }
        else {
            std::cout << setw(2) << left << " " << i << " ";
            counterSpace++;
        }
        if (counterSpace % 7 == 0) {
            std::cout << endl << endl;
        }


    }
    std::cout << endl << endl;


    return;
}
int Calendar(int choice) {

    string month;

    int NumberOfMonth = 0;

    std::cout << "Please enter a month " << endl;


    getline(cin, month);
    NumberOfMonth = StringToInt(month);

    while (NumberOfMonth == 12) {
        system("cls");
        std::cout << "Please enter a month " << endl;
        getline(cin, month);
        NumberOfMonth = StringToInt(month);
    }
    system("cls");
    calendarPrint(NumberOfMonth);
    return NumberOfMonth;

    return 13;
}
int IntroScreen() {
    string choice;
    int numchoice = 5;
    int loopchoice = 4;
    bool num = true;
    std::cout << "                                 Welcome to a calendar" << endl;

    std::cout << "0) Exit" << endl <<
        "1) Search for an Event." << endl <<
        "2) Add an event." << endl <<
        "3) Output all events of a specific month" << endl <<
        "4) Events of a specific day" << endl;
    while (num || loopchoice > 4 || loopchoice < 0) {
        std::cout << "Please input a number between 0 to 4" << endl;
        getline(cin, choice);
        num = IsItAnInt(choice);
        if (!num) {
            loopchoice = stoi(choice);
        }
    }
    numchoice = stoi(choice);
    return numchoice;
}
int StringToInt(string MonthNum) {
    bool num = false;
    int monthHold = 0;
    bool PlaceHolder = false;

    map<string, int> weekday;
    weekday["JANUARY"] = 0;//0
    weekday["FEBRUARY"] = 1;//1
    weekday["MARCH"] = 2;//2
    weekday["APRIL"] = 3;//3
    weekday["MAY"] = 4;//4
    weekday["JUNE"] = 5;//5
    weekday["JULY"] = 6;//6
    weekday["AUGUST"] = 7;//7
    weekday["SEPTEMBER"] = 8;//8
    weekday["OCTOBER"] = 9;//9
    weekday["NOVEMBER"] = 10;//10
    weekday["DECEMBER"] = 11;//11

    for (unsigned int k = 0; k < MonthNum.size(); k++) {
        if (isdigit(MonthNum.at(k))) {
            num = true;
        }
    }
    if (num) {
        monthHold = stoi(MonthNum);
        monthHold = monthHold - 1;
    }

    else {
        for (unsigned int i = 0; i < MonthNum.size(); i++) {
            MonthNum.at(i) = toupper(MonthNum.at(i));
        }
        if (weekday.find(MonthNum) == weekday.end()) {
            PlaceHolder = true;
        }
        else {
            monthHold = weekday.find(MonthNum)->second;
        }
    }
    if (monthHold < 0 || monthHold > 11 || PlaceHolder) {
        monthHold = 12;
    }

    return monthHold;
}
bool IsItAnInt(string Maybe) {
    bool STRING = false;

    int numHold;
    for (int i = 0; i < Maybe.size(); i++) {
        if (isalpha(Maybe.at(i))) {
            STRING = true;
        }
    }
    return STRING;
}
void SearchFunction(string EvName) {

    MonthDayHold[1] = 33;
    MonthDayHold[0] = 33;

    vector<string> Events(31);
    Events.at(1) = "CHECK";
    if (EvName == Events.at(1)) {
        MonthDayHold[1] = 0;
        MonthDayHold[0] = 1;
    }

    return;
}
int Screen() {
    string choice;
    int numchoice = 4;
    int loopchoice = 4;
    bool num = true;

    std::cout << "0) Exit" << endl <<
        "1) Search for an Event." << endl <<
        "2) Add an event." << endl <<
        "3) Output all events of a specific month" << endl <<
        "4) Events of a specific day" << endl;

    while (num || loopchoice > 4 || loopchoice < 0) {
        std::cout << "Please input a number between 0 to 4" << endl;
        getline(cin, choice);
        num = IsItAnInt(choice);
        if (!num) {
            loopchoice = stoi(choice);
        }
    }
    numchoice = stoi(choice);
    return numchoice;
}