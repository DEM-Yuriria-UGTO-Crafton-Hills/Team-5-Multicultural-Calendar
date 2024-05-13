#ifndef EVENTS_H
#define EVENTS_H

#include <string>
using namespace std;


class Event {

protected:
    // Member data that will be inherited by the classes AmericanEvent and MexicanEvent
    string name;
    string date;
    string country;
    string description;

public:

    // These functions will set and get the name of an event that the user is searching for/creating
    void setEventName(string);
    string getEventName();

    void setEventDate(string);
    string getEventDate();

    void setEventCountry(string);
    string getEventCountry();

    void setEventDescription(string);
    string getEventDescription();

    void PrintEventInfo() const;
};



#endif