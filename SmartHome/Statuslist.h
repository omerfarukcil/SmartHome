#pragma once
#include <string>
#include <iostream>
using namespace std;

// Linked List node
struct StatusNode {
    string      message;
    StatusNode* next;
    StatusNode(const string& msg) : message(msg), next(nullptr) {}
};

class StatusList {
private:
    StatusNode* head;
    int         count;

public:
    StatusList();
    ~StatusList();

    void add(const string& message);      // Pass by reference
    void show()   const;
    void clear();
    int  getCount() const;

    // Inline function
    inline bool isEmpty() const { return head == nullptr; }
};