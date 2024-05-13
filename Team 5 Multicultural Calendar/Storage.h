#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include "Events.h"
using namespace std;

class StoredEvents
{
public:
    vector<Event> LoadEvents(vector<Event>);

    void SearchByName(string, vector<Event>);

    void SearchByDate(string, vector<Event>);

    void SaveEvents(vector<Event>);
};

#endif
