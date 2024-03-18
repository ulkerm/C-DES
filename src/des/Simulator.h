#pragma once

#include <iostream>
#include <queue>
#include "Event.h"


class Simulator {
    std::priority_queue<Event*, std::vector<Event*>, std::function<bool(Event*, Event*)>> pq =
            std::priority_queue<Event*, std::vector<Event*>, std::function<bool(Event*, Event*)>>(
                    [](Event *a, Event *b) { return *a > *b; });

    int curTime = 0;

    public:
    void addEvent(Event* e);
    void step();
    void run(int time);
    void display();
};

