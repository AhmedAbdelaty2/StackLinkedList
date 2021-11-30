#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Student{
    int id;
    char Name[10];
};

struct Node{
    struct Student S;
    struct Node *pPrev;
};

struct Node *pTail;

void PrintStudent(struct Student s);
struct Student Fill(void);

void printScreen(void);

struct Node *creatNode(struct Student s);
int push(struct Student s);
struct Student pop(void);

int main()
{
    struct Student s;
    char x;
    int ret;

    while(x != '3')
    {
        system("cls");
        printScreen();
        x=getch();
        system("cls");

        switch(x)
        {
        case '1':
            {
                s = Fill();
                ret = push(s);
                if(ret==0)
                    printf("Error :'(");
                else if(ret==1)
                    printf("The student has been added successfully");
                getch();
                break;
            }
        case '2':
            {
                s = pop();
                if(s.id==-1)
                    printf("there is no data for any students");
                else
                    PrintStudent(s);
                getch();
                break;
            }
        }
    }
    return 0;
}

void PrintStudent(struct Student s)
{
    int i;

    printf("\n");
    printf("The student ID is: %d\n", s.id);
    printf("The student name is: %s\n", s.Name);
}

struct Student Fill(void)
{
    struct Student s;
    int i;

    printf("Please, Enter the student ID: ");
    scanf("%d", &s.id);

    printf("Please, Enter the student Name: ");
    scanf("%s", s.Name);

    printf("\n");
    return s;
}

void printScreen(void)
{
    printf("1- push\n");
    printf("2- pop\n");
    printf("3- exit\n");
}

struct Node *creatNode(struct Student s)
{
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));

    if(ptr)
    {
        ptr->S = s;
        ptr->pPrev = NULL;
    }
    return ptr;
}

int push(struct Student s)
{
    int retval=0;
    struct Node *ptr;
    ptr = creatNode(s);

    if(ptr)
    {
        if(!pTail)
            pTail = ptr;

        else
        {
            ptr->pPrev = pTail;
            pTail = ptr;
        }
        retval = 1;
    }
    return retval;
}

struct Student pop(void)
{
    struct Node *ptr;
    struct Student s;

    s.id = -1;
    ptr = pTail;

    if(pTail)
    {
        s = ptr->S;
        pTail = pTail->pPrev;
        free(ptr);
    }
    return s;
};
