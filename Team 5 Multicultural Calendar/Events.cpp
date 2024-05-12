#include <iostream>
#include "Events.h"

using namespace std;

void Event::setEventName(string eventName) { name = eventName; }
string Event::getEventName() { return name; }

void Event::setEventDate(string eventDate) { date = eventDate; }
string Event::getEventDate() { return date; }

void Event::setEventCountry(string eventCountry) { country = eventCountry; }
string Event::getEventCountry() { return country; }

void Event::setEventDescription(string eventDescription) { description = eventDescription; }
string Event::getEventDescription() { return description; }


void Event::PrintEventInfo() const {

	cout << name << endl;
	cout << date << endl;
	cout << country << endl;
	cout << description << endl;

}