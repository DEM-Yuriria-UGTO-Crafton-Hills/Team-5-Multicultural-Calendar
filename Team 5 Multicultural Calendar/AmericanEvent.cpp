#include <iostream>
#include "AmericanEvent.h"

using namespace std;

// Default constructor that initializes a new American event to have No Data in all fields
// except for country, which is initialized to America.
AmericanEvent::AmericanEvent() {
    name = "NoName";
    date = "NoDate";
    country = "America";
    description = "NoDescription";
}