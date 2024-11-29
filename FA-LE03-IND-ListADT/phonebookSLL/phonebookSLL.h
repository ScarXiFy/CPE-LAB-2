#ifndef PHONEBOOK_H
    #define PHONEBOOK_H

    struct Record {
        char firstName[100];
        char middleName[100];
        char lastName[100];
        char mobileNo[100];
        char emailAddress[100];
    };

    struct Node {
        struct Record data;
        struct Node* next;
    };

        // AppendSLL Function Prototypes
    struct Node* appendRecord(struct Node** head);

        // BrowseSLL Function Prototypes
    void browseRecord(struct Node* head);
    void displayBrowseMenu();

        // ChangeSLL Function Prototypes
    void changeRecord(struct Node* head);
    void displayChangeMenu();

        // DeleteSLL Function Prototypes
    void deleteRecord(struct Node** head);
    void displayDeleteMenu();

        // PhonebookSLL Function prototypes
    void freeLinkedList(struct Node* head);
    void displayMainMenu();
    void clearScreen();

#endif
