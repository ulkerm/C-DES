#pragma once
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class Buffer {
    std::vector<int> buffer;
    int count = 0;
    int maxSize;

public:
    Buffer(int maxSize) : maxSize(maxSize) {};

    void addItem() {
        if (buffer.size() < maxSize) {
            count++;
            buffer.push_back(count);
        } else {
            std::cout << "Buffer is full. Cannot add more data." << std::endl;
        }
    }

    void removeItem() {
        if (!buffer.empty()) {
            buffer.pop_back();
            count--;
        } else {
            std::cout << "Buffer is empty. Cannot remove data." << std::endl;
        }
    }
};