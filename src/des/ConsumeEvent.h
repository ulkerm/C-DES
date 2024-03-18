#pragma once
#include <iostream>
#include <vector>
#include "Event.h"
#include "Buffer.h"

class ConsumeEvent : public Event {
    Buffer* buffer;

public:
    ConsumeEvent(int time, Buffer* buffer): Event(time), buffer(buffer) { };
    ~ConsumeEvent();
    void execute() override {
        buffer->removeItem();
    };

    bool getStatus() override { return false; }
};

