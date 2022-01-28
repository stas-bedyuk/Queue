#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 6031)
#pragma warning (disable: 6011)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Queue.h"

void push(Book** HEAD,Book** TAIL)
{
    Book* s;
    int j = 1;
    do
    {

        if (!(s = (Book*)calloc(1, sizeof(Book))))
        {
            puts("No memory allocated!");
            return ;
        }
        if (!((s)->name = (char*)calloc(20, sizeof(char))))
        {
            puts("No memory allocated!");
            return;
        }
        printf("Name of book: ");
        rewind(stdin);
        gets_s((s)->name, 20);
        printf("Quantity of pages: ");
        while (!scanf("%d", &(s)->page_count) || (s)->page_count < 0)
        {
            printf("\nEnter the number!Quantity of pages: ");
            rewind(stdin);
        }
        printf("Select the field to add in:\n1--Author's name.\n2--Number of volumes.\nInput(1/2): ");
        while (!scanf("%d", &(s)->signal_un) || (s)->signal_un < 1 || (s)->signal_un >2)
        {
            printf("\nEnter the number(1/2)!!!\nInput(1/2): ");
            rewind(stdin);
        }
        switch ((s)->signal_un)
        {
        case 1:
            printf("Author's name:");
            rewind(stdin);
            gets_s((s)->a_name);

            break;
        case 2:
            printf("Number of volumes: ");
            while (!scanf("%d", &(s)->volume_count) || (s)->volume_count < 0)
            {
                printf("\nEnter the number!!!Number of volumes:\n");
                rewind(stdin);
            }
            break;
        }
        if (!*HEAD)                         // очередь еще не создана
            *HEAD = *TAIL = s;                 // устанавливаем оба указателя (голова и хвост)
                                         // на единственный элемент очереди
        else                             // очередь уже создана
        {
            (*TAIL)->l = s;                // добавляем очередной элемент в хвост очереди 
            *TAIL = (*TAIL)->l;                      // передвигаем указатель на хвост
        }
        printf("Do you want to continue typing(1/0)? ");
        while (!scanf("%d", &j) || j < 0 || j>1)
        {
            printf("Error!Do you want to continue typing(1/0)? ");
            rewind(stdin);
        }
        if (j == 0) break;
    } while (1);
}

void show(Book* HEAD)
{
    int j = 0;
    if (!HEAD)
    {
        puts("Error!");
        return;
    }
    printf("\n");
    for (int i = 0; i < 90; i++) printf("-");
    printf("\n");
    printf("| Book: |   Name of book:   | Number of pages: |   Author's name:   | Number of volumes: |\n");
    do
    {
        if (strlen(HEAD->name) > 17)
            HEAD->name[17] = '\0';
        if (strlen(HEAD->a_name) > 18)
            HEAD->a_name[18] = '\0';
        for (int i = 0; i < 90; i++) printf("-");
        printf("\n");
        if ((HEAD)->signal_un == 1)
        {

            printf("| %-5d | %-17s | %-16d | %-18s |", j , (HEAD)->name, (HEAD)->page_count, HEAD->a_name);
            for (int j = 0; j < 20; j++) printf(" ");
            printf("|\n");
        }
        if ((HEAD)->signal_un == 2)
        {
            printf("| %-5d | %-17s | %-16d |", j , (HEAD)->name, (HEAD)->page_count);
            for (int j = 0; j < 20; j++) printf(" ");
            printf("| %-18d |\n", (HEAD)->volume_count);
        }
        j++;
        HEAD = HEAD->l;
    } while (HEAD);
    for (int i = 0; i < 90; i++) printf("-");
}
void deleteALL(Book** HEAD,Book** TAIL)
{
    int j = 0;
    int i = 1;
    if (!HEAD)
    {
        puts("Error!");
        
    }
    printf("\nEnter the number of structure to delete: ");
    while (!scanf("%d", &j) || j < 0)
    {
        printf("ERROR!!!Enter the numbr of structur to delete: ");
        rewind(stdin);
    }
    Book* curr = (*HEAD)->l;
    Book* prev = *HEAD;
    if (j == 0)
    {
        *HEAD = curr;
    }
    while (i != j && curr && j > 0)
    {
        prev = curr;
        curr = curr->l;
        i++;
    }
    if (curr == *TAIL) *TAIL = prev;
    if (!curr)
    {
        printf("ERROR!");
    }

    if (j > 0 && curr) prev->l = curr->l;
}
void search(struct Book* HEAD)
{
    int g, b;
    int p = 0;
    char h[40] = { '1','\0' };
    int i = 0;
    Book* s = HEAD;
    if (!HEAD)
    {
        puts("Error!");
        return;
    }
    printf("\nSelect the structure parameter to search:");
    printf("\n1--Name of book.\n2--Number of pages.\n3--Author's name.\n4--Number of volumes.\n");
    printf("Choice(1-4):");
    while (!scanf("%d", &g) || (g < 1 || g>4))
    {
        printf("Enter the number!!!Choice(1-4):\n");
        rewind(stdin);
    }
    switch (g)
    {
    case 1:

        printf("Name of book: ");
        rewind(stdin);
        gets_s(h);
        printf("\nRESULT OF SEARCH:\n");
        do
        {

            if (strcmp(h, HEAD->name) == 0)
            {
                for (int i = 0; i < 90; i++) printf("-");
                if (HEAD->signal_un == 1)
                {
                    printf("\n| %-5d | %-17s | %-16d | %-18s |", i + 1, HEAD->name, HEAD->page_count, HEAD->a_name);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("|\n");
                }
                if (HEAD->signal_un == 2)
                {
                    printf("\n| %-5d | %-17s | %-16d |", i + 1, HEAD->name, HEAD->page_count);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("| %-18d |\n", HEAD->volume_count);
                }
                for (int i = 0; i < 90; i++) printf("-");
                printf("\n");
                p = 1;
                i++;
            }
            HEAD = HEAD->l;
        } while (HEAD);
        if (p == 0)
        {
            printf("No matches found!!!");
        }
        break;
    case 2:
        printf("Quantity of pages: ");

        while (!scanf("%d", &b))
        {
            printf("Enter the number!!!Quantity of pages:\n");
            rewind(stdin);

        }
        printf("\nRESULT:\n");
        do
        {
            if (b == HEAD->page_count)
            {
                for (int i = 0; i < 90; i++) printf("-");
                if (HEAD->signal_un == 1)
                {
                    printf("\n| %-5d | %-17s | %-16d | %-18s |", i + 1, HEAD->name, HEAD->page_count, HEAD->a_name);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("|\n");
                }
                if (HEAD->signal_un == 2)
                {
                    printf("\n| %-5d | %-17s | %-16d |", i + 1, HEAD->name, HEAD->page_count);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("| %-18d |\n", HEAD->volume_count);
                }
                for (int i = 0; i < 90; i++) printf("-");
                printf("\n");
                p = 1;
                i++;
            }
            (HEAD) = (HEAD)->l;
        } while (HEAD);
        if (p == 0)
        {
            printf("No matches found!!!");
        }
        break;
    case 3:
        printf("Author's name: ");
        rewind(stdin);
        gets_s(h);
        printf("\nRESULT OF SEARCH:\n");
        while (HEAD)
        {
            if (strcmp(h, HEAD->a_name) == 0)
            {

                for (int i = 0; i < 90; i++) printf("-");
                if (HEAD->signal_un == 1)
                {
                    printf("\n| %-5d | %-17s | %-16d | %-18s |", i + 1, HEAD->name, HEAD->page_count, HEAD->a_name);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("|\n");
                }
                if (HEAD->signal_un == 2)
                {
                    printf("\n| %-5d | %-17s | %-16d |", i + 1, HEAD->name, HEAD->page_count);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("| %-18d |\n", HEAD->volume_count);
                }
                for (int i = 0; i < 90; i++) printf("-");
                printf("\n");
                p = 1;
                i++;
            }
            (HEAD) = (HEAD)->l;
        }

        if (!p)
        {
            printf("No matches found!!!");
        }
        break;
    case 4:
        printf("Number of volumes: ");

        while (!scanf("%d", &b))
        {

            printf("Enter the number!!!Number of volumes:\n");
            rewind(stdin);
        }
        printf("\nRESULT:\n");
        while (HEAD)
        {
            if (b == HEAD->volume_count)
            {
                for (int i = 0; i < 90; i++) printf("-");
                if (HEAD->signal_un == 1)
                {
                    printf("\n| %-5d | %-17s | %-16d | %-20s |", i + 1, HEAD->name, HEAD->page_count, HEAD->a_name);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("|\n");
                }
                if (HEAD->signal_un == 2)
                {
                    printf("\n| %-5d | %-17s | %-16d |", i + 1, HEAD->name, HEAD->page_count);
                    for (int j = 0; j < 20; j++) printf(" ");
                    printf("| %-18d |\n", HEAD->volume_count);
                }
                for (int i = 0; i < 90; i++) printf("-");
                printf("\n");
                p = 1;
                i++;
            }
            (HEAD) = (HEAD)->l;
        }
        if (!p)
        {
            printf("No matches found!!!");
        }
        break;
    }

}
void save(struct Book* HEAD)
{
    FILE* f = nullptr;
    int i = 0;
    if (!HEAD)
    {
        puts("Error!");
        return;
    }
    printf("\nSelect the file type to write:\n1--Text file\n2--Binary file\nChoose:");
    while (!scanf_s("%d", &i) || i < 1 || i>2)
    {
        printf("ERROR!Choose: ");
        rewind(stdin);
    }
    switch (i)
    {
    case 1:
        if (!(f = fopen("boom.txt", "w")))
        {
            puts("File not open!");
            return;
        }
        while (HEAD)
        {

            if (HEAD->signal_un == 1)  fprintf(f, " %d %s %d %s", HEAD->signal_un, HEAD->name, HEAD->page_count, HEAD->a_name);
            if (HEAD->signal_un == 2)  fprintf(f, " %d %s %d %d", HEAD->signal_un, HEAD->name, HEAD->page_count, HEAD->volume_count);
            (HEAD) = (HEAD)->l;
        }

        break;
    case 2:
        if (!(f = fopen("boob.bin", "wb")))
        {
            puts("File not open!");
            return;
        }
        do
        {
            fwrite(&HEAD->signal_un, 4, 1, f);
            fwrite(HEAD->name, 20, 1, f);
            fwrite(&HEAD->page_count, 4, 1, f);
            if (HEAD->signal_un == 1)
            {
                fwrite(HEAD->a_name, 20, 1, f);
            }
            if (HEAD->signal_un == 2)
            {
                fwrite(&HEAD->volume_count, 4, 1, f);
            }
            (HEAD) = (HEAD)->l;
        } while (HEAD);
        break;
    }
    fclose(f);
}
void read(Book** HEAD,Book**TAIL)
{
    FILE* f;
    Book* s;
    int i = 0;
    printf("\nSelect the file type to read:\n1--Text file\n2--Binary file\nChoose:");
    while (!scanf_s("%d", &i) || i < 1 || i>2)
    {
        printf("ERROR!Choose: ");
        rewind(stdin);
    }
    switch (i)
    { 
    case 1:
        if (!(f = fopen("boom.txt", "r")))
        {
            puts("File not open!");
            return;
        }
        while (!feof(f))
        {
            if (!(s = (Book*)calloc(1, sizeof(Book))))
            {
                puts("No memory allocated!");
                return;
            }
            (s)->name = (char*)calloc(30, sizeof(char));
            fscanf_s(f, "%d", &s->signal_un);
            if (s->signal_un == 1)
            {
                fscanf(f, "%s", s->name);
                fscanf_s(f, "%d", &s->page_count);
                fscanf(f, "%s", s->a_name);
            }
            if (s->signal_un == 2)
            {
                fscanf(f, "%s", s->name);
                fscanf_s(f, "%d",&s->page_count);
                fscanf_s(f, "%d", &s->volume_count);

            }
            if (!*HEAD)                         // очередь еще не создана
                *HEAD = *TAIL = s;                 // устанавливаем оба указателя (голова и хвост)
                                             // на единственный элемент очереди
            else                             // очередь уже создана
            {
                (*TAIL)->l = s;                // добавляем очередной элемент в хвост очереди 
                *TAIL = s;                      // передвигаем указатель на хвост
            }
        }
        fclose(f);
        break;
    case 2:
        if (!(f = fopen("boob.bin", "rb")))
        {
            puts("File not open!");
            return;
        }

        while (!feof(f))
        {
            if (!(s = (Book*)calloc(1, sizeof(Book))))
            {
                puts("No memory allocated!");
                return;
            }
            (s)->name = (char*)calloc(20, sizeof(char));
            fread(&s->signal_un, 4, 1, f);
            fread(s->name, 20, 1, f);
            fread(&s->page_count, 4, 1, f);
            if (feof(f))
            {
                continue;
            }
            if (s->signal_un == 1)
            {
                fread(s->a_name, 20, 1, f);
            }
            if (s->signal_un == 2)
            {
                fread(&s->volume_count, 4, 1, f);
            }
            if (!*HEAD)                         
                *HEAD = *TAIL = s;                 
                                            
            else                             
            {
                (*TAIL)->l = s;               
                *TAIL = s;                      
            }
        }
        fclose(f);
        break;
    }
}
