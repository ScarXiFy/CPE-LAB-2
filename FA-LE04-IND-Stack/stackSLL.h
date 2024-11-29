#ifndef STACKSLL_H_INCLUDED
#define STACKSLL_H_INCLUDED

    typedef struct Record {
    char firstName[100];
    char middleName[100];
    char lastName[100];
    char mobileNumber[100];
    char emailAddress[100];
    } Record;

    typedef struct Node {
        Record record;
    struct Node* next;
    } Node;

    typedef struct {
        Node* top; // points to the top node of the list
    } LinkedList;

    void push(LinkedList* list);
    void pop(LinkedList* list);
    void show(LinkedList* list);


#endif // STACKSLL_H_INCLUDED
