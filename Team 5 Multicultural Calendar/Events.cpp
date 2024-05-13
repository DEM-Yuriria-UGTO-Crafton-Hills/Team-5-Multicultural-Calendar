#include <iostream>
#include "Events.h"

using namespace std;


// Definitions for the setters, getters, and info printing functions of the Event class

void Event::setEventName(string eventName) { name = eventName; } // Sets an event's name.
string Event::getEventName() { return name; } // Returns an event's name.

void Event::setEventDate(string eventDate) { date = eventDate; }// Sets an event's date.
string Event::getEventDate() { return date; }// Returns an event's date.

void Event::setEventCountry(string eventCountry) { country = eventCountry; }// Sets an event's country.
string Event::getEventCountry() { return country; }// Returns an event's country.

void Event::setEventDescription(string eventDescription) { description = eventDescription; }// Sets an event's description.
string Event::getEventDescription() { return description; }// Returns an event's description.

// Prints the name, date, country, and description of an event, in that order.
void Event::PrintEventInfo() const {

	cout << name << endl;
	cout << date << endl;
	cout << country << endl;
	cout << description << endl;

}