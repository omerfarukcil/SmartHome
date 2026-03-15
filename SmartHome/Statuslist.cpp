#include "StatusList.h"

StatusList::StatusList() : head(nullptr), count(0) {}

StatusList::~StatusList() { clear(); }

void StatusList::add(const string& message) {
    StatusNode* newNode = new StatusNode(message);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        StatusNode* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }
    ++count;
}

void StatusList::show() const {
    if (isEmpty()) { cout << "Status list is empty.\n"; return; }
    StatusNode* current = head;
    int i = 1;
    while (current != nullptr) {
        cout << "  " << i++ << ". " << current->message << "\n";
        current = current->next;
    }
}

void StatusList::clear() {
    StatusNode* current = head;
    while (current != nullptr) {
        StatusNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    count = 0;
}

int StatusList::getCount() const { return count; }