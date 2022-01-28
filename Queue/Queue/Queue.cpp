#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Queue.h"
int main()
{
    Book* HEAD = nullptr;
    Book* TAIL = nullptr;
    int j = 1;
    int i = 0;
    while (j != 0)
    {
        printf("\n\nSelect an action:\n0--EXIT\n1--ADD A QUEUE\n2--SHOW QUEUE\n3--DELETE AN ELEMENT FROM THE QUEUE\n4--QUEUE SEARCH\n5--WRITING A QUEUE TO A FILE\n6--READING QUEUE FROM THE FILE\n\nCHOOSE(0-6): ");
        while (!scanf("%d", &j) || j < 0 || j>6)
        {
            printf("ERROR!Choose: ");
            rewind(stdin);
        }
        switch (j)
        {
        case 0:
            break;
            break;
        case 1:
             push(&HEAD,&TAIL);
            break;
        case 2:
            show(HEAD);
            break;
        case 3:
            deleteALL(&HEAD,&TAIL);
            break;
        case 4:
            search(HEAD);
            break;
        case 5:
            save(HEAD);
            break;
        case 6:
            HEAD = TAIL = nullptr;
            read(&HEAD,&TAIL);
            break;
        }
    }
    free(TAIL);
    free(HEAD);
    return 0;
}