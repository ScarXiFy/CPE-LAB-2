#ifndef LAURONPREMID_H_INCLUDED
#define LAURONPREMID_H_INCLUDED

typedef struct Record {
    char payDate[100];
    char Payee[100];
    char payID[100];
    char payAmount[100];

} Record;

struct Node {
        struct Record data;
        struct Node* next;
    };

    struct Node* addPaymentRecord(struct Node** head, char payDate[], char Payee[], char payID[], char payAmount[]);
    void deletePaymentRecord(struct Node** head);
    void freeLinkedList(struct Node* head);

    void displayMainMenu();
    void displayPaymentMenu(struct Node* head);
    void displayDeleteMenu();



#endif // LAURONPREMID_H_INCLUDED
