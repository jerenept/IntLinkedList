//
// Created by jeremy on 12/25/15.
//  Linked List of Integers. Very basic.

#ifndef LISTS_LINKEDLIST_H
#define LISTS_LINKEDLIST_H

#endif //LISTS_LINKEDLIST_H
#ifndef LISTS_LINKEDLISTMEMBER_H
#include "LinkedListMember.h"

#endif
using namespace std;
class LinkedList {
    LinkedListMember* first;
    LinkedListMember* last;

public:
    LinkedListMember* getFirst();
    LinkedListMember* getLast();
    void append(int newLast);
    ~LinkedList();
    LinkedList();
};

/*
 * Adds an item to the end of the list. The only way to add to the list.
 */
void LinkedList::append(int newLastData){
    LinkedListMember* prevLastMember = last;
    LinkedListMember* newLastMember = new LinkedListMember(newLastData, prevLastMember, nullptr);
    if (last==nullptr){
        first = newLastMember;
        last = newLastMember;
    } else {
        prevLastMember->setNext(newLastMember);
        last=newLastMember;
    }
}
LinkedList::~LinkedList() {
    first = first->getNext();
    while (first!=last){
        delete first->getPrev();
        first = first->getNext();
    }
    delete last->getPrev();
    delete last;
}
LinkedList::LinkedList() {
    first = nullptr;
    last = nullptr;
}
LinkedListMember* LinkedList::getFirst(){
    return first;
}

LinkedListMember* LinkedList::getLast(){
    return last;
}