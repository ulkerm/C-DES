#include <iostream>
#include "Simulator.h"
#include "Buffer.h"
#include "ConsumeEvent.h"
#include "ProduceEvent.h"


void testRun() {
    int seedForProduction = 90;
    int seedForConsumer = 80;
    int countOfEvent = 10;
    cout << "------  Testing run  ------" << endl;
    Simulator pq;
    Buffer buffer(20);
    for (int i = 0; i < countOfEvent; i++) {
        pq.addEvent(new ProduceEvent(rand() % seedForProduction, &buffer));
    }

    for (int i = 0; i < countOfEvent / 2; i++) {
        pq.addEvent(new ConsumeEvent(rand() % seedForConsumer, &buffer));
    }
    pq.run(72);
    pq.display();
}

void testBufferFull() {
    int seedForProduction = 90;
    int seedForConsumer = 80;
    int countOfEvent = 20;
    cout << "------  Testing buffer full  ------" << endl;
    Simulator pq;
    Buffer buffer(10);
    for (int i = 0; i < countOfEvent; i++) {
        pq.addEvent(new ProduceEvent(rand() % seedForProduction, &buffer));
    }

    for (int i = 0; i < countOfEvent / 2; i++) {
        pq.addEvent(new ConsumeEvent(rand() % seedForConsumer, &buffer));
    }
    pq.run(80);
    pq.display();
}

void testMoreConsume() {
    cout << "------  Testing Consume  ------" << endl;
    int seedForProduction = 70;
    int seedForConsumer = 50;
    int countOfEvent = 10;
    Simulator pq;
    Buffer buffer(20);
    for (int i = 0; i < countOfEvent; i++) {
        pq.addEvent(new ProduceEvent(rand() % seedForProduction, &buffer));
    }

    for (int i = 0; i < countOfEvent + 2; i++) {
        pq.addEvent(new ConsumeEvent(rand() % seedForConsumer, &buffer));
    }
    pq.run(12);
    pq.display();
}


int main() {
    std::cout << "Uebung01 - Discrete Event Simulation (DES)" << std::endl;

    testRun();
    testBufferFull();
    testMoreConsume();
    return 0;
}