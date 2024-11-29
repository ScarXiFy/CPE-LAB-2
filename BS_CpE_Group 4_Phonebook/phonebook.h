#ifndef PHONEBOOK_H
    #define PHONEBOOK_H

    typedef struct pbook{
        char fname[100];
        char mname[100];
        char lname[100];
        char num[100];
        char email[100];
    } PBOOK;

    // in phonebook.c
    void mainMenuDisp();
    void saveToFile (PBOOK* all, int* size, int maxSize);

    // in append.c
    void appendPrcs (PBOOK* all, int* size, int maxSize);
    char* appendMenu(char* menu);

    // in browse.c
    void displayChoiceMenu ();
    void displayPrcs (PBOOK* all, int* size, int maxSize);
    
    // in change.c
    void changeChoiceMenu ();
    void changePrcs (PBOOK* all, int* size, int maxSize);

    // in delete.c
    void deletePrcs (PBOOK* all, int* size, int maxSize);

#endif
