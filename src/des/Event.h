#pragma once
#include <ostream>
#include <functional>

using std::cout;
using std::endl;

class Event {
private:
    int time;

public:

    Event(int time): time(time) {};
    ~Event();
    virtual void execute() = 0;
   bool operator>(const Event &e) const {
        return this->time > e.time;
    }

    virtual bool getStatus() = 0;
    int getTime() const { return time; }

    friend std::ostream &operator<<(std::ostream &os, const Event &e) {
        os << e.time;
        return os;
    }
};