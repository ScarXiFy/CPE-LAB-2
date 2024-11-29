#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebook.h"

#define MAXSIZE 50
#define FILENAME "phonebook.txt"

// gcc -o phonebook.exe -g phonebook.c append.c browse.c change.c delete.c
/*
void main(){

    int maxSizePBook = MAXSIZE;
    PBOOK* list = calloc(maxSizePBook, sizeof(PBOOK));
    int currSizePBook = 0;
    char userInput;

    while (1){

        mainMenuDisp();
        fflush(stdin);
        userInput = tolower(getche());

        if (userInput == 'e')
            break;

        printf("\n\n");

        switch (userInput){

            case 'a':
                appendPrcs(list, &currSizePBook, maxSizePBook);
                break;

            case 'b':
                displayPrcs (list, &currSizePBook, maxSizePBook);
                break;

            case 'c':
                changePrcs (list, &currSizePBook, maxSizePBook);
                break;

            case 'd':
                deletePrcs (list, &currSizePBook, maxSizePBook);
                break;

        }

    }

    saveToFile(list, &currSizePBook, maxSizePBook);
    free(list);

}


void mainMenuDisp() {
    system("cls");
    printf("[A]ppend\n");
    printf("[B]rowse\n");
    printf("[C]hange\n");
    printf("[D]elete\n");
    printf("[E]xit\n");
    printf("\n");
}

void saveToFile (PBOOK* all, int* size, int maxSize){
	int i;
	
    FILE* fp = fopen(FILENAME, "w");
    rewind(fp);

    fprintf(fp, ",lname,mname,fname,num,email\n");

    for(i = 0; i < *size; i++){
        fprintf(fp, "%d,%s,%s,%s,%s,%s\n", i, all[i].lname, all[i].mname, all[i].fname, all[i].num, all[i].email);
    }

    fclose(fp);
}
*/
