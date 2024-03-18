#pragma once
#include <iostream>
#include <vector>
#include "Event.h"
#include "Buffer.h"

class ProduceEvent : public Event {
    Buffer* buffer;

public:
    ProduceEvent(int time, Buffer* buffer): Event(time), buffer(buffer) {};
    ~ProduceEvent();
    void execute() override {
        buffer->addItem();
    };

    bool getStatus() override { return true; }
};
