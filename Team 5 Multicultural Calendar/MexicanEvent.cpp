#include <iostream>
#include "MexicanEvent.h"

using namespace std;

// Default constructor that initializes a new Meican event to have No Data in all fields
// except for country, which is initialized to Mexico.
MexicanEvent::MexicanEvent() {
    name = "NoName";
    date = "NoDate";
    country = "Mexico";
    description = "NoDescription";
}