#include <iostream>
#include "Simulator.h"

using std::cout;
using std::endl;

void Simulator::addEvent(Event* e) {
    e->execute();
    if(e->getStatus()) {
        pq.push(e);
        cout << "The time of the  ProduceEvent:  " << e->getTime() << endl;
    } else {
        step();
        cout << "The time of the  ConsumeEvent:  " << e->getTime() << endl;
    }
    curTime = curTime == 0 ? e->getTime() : (curTime > e->getTime()? e->getTime() : curTime);
}

void Simulator:: step() {
    if(!pq.empty()) {
        pq.pop();
        Event* curEvent = pq.top();
        curTime = curEvent->getTime();
    }
}

void Simulator::run(int time) {
    while (!pq.empty() && time >= curTime)
        step();
    if (!pq.empty())
        cout << "The queue run till " << time << " and stopped!" << endl;
    else
        cout << "The queue is empty!" << endl;

}

void Simulator::display() {
    std::cout << "[ ";
    while(!pq.empty()) {
        Event* e = pq.top();
        pq.pop();
        std::cout << *e << "  ";
    }
    std::cout << "]\n" << std::endl;
}
