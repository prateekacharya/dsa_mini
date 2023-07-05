#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int count = 0;
struct node
{
    int regno, age, phno,cos;
    char name[20];
    int marks;
    struct node *next;
} *first = NULL, *last = NULL, *temp = NULL, *temp1;
void course(int cos)
{
    switch(cos)
    {
        case 1:printf("\nThe student course is Bachelor of Engineering\n");
        break;
        case 2:printf("The student course is Bachelor of Computer Application\n");
        break;
        case 3:printf("The student course is Bachelor of Science\n");
        break;
        case 4:printf("The student course is Bachelor of Commerce\n");
        break;
        case 5:printf("The student course is Bachelor of Arts\n");
        break;
        case 6:printf("The student course is MBBS\n");
        break;
        case 7:printf("The student course is BDS\n");
        break;
        case 8:printf("The student course is Master's in Computer Application\n");
        break;
        case 9:printf("The student course is MAster's of Technology\n");
        }
}
void create()
{
    int regno, age, phno, ch1,cos;
    char name[20];
    float marks;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter regno of the Student : ");
    scanf("%d", &regno);
    printf("\nEnter the phone number of the student:");
    scanf("%d", &phno);
    printf("\nEnter age of the student:");
    scanf("%d", &age);
    printf("\nEnter the name of the student:");
    fflush(stdin);
    gets(name);
    printf("\nEnter the year of the student:");
    scanf("%d",&marks);
    printf("The course of the student:");
    printf("1.Bachelor of Engineering\n");
    printf("2.Bachelor of Computer Application\n");
    printf("3.Bachelor of Science\n");
    printf("4.Bachelor of Commerce\n");
    printf("5.Bachelor of Arts\n");
    printf("6.MBBS\n");
    printf("7.BDS\n");
    printf("8.Master's in Computer Application\n");
                  printf("9.Master's of Technology\n");
    scanf("%d", &cos);
    strcpy(temp->name, name);
    temp->marks = marks;
    temp->regno = regno;
    temp->phno = phno;
    temp->age = age;
    temp->cos=cos;
    temp->next = NULL;
    count++;
}
void insert_atlast()
{
    if (first == NULL)
    {
        create();
        first = temp;
        last = first;
    }
    else
    {
        create();
        last->next = temp;
        last = temp;
    }
}
void display()
{
    temp1 = first;
    if (temp1 == NULL)
    {
        printf("NO STUDENTS ARE THERE..!! \n");
        return;
    }    printf("\n STUDENT DETAILS ARE AS FOLLOWS : \n");
    while (temp1 != NULL)
    {
        fflush(stdout);
        printf("NAME\t\tREG.NO\t\tAGE\t\tPHONE NUMBER\t\tYEAR\t\t\n");
        printf("\n\n%s\t\t%d\t\t%d\t\t%d\t\t%d\n\n\n", temp1->name, temp1->regno, temp1->age,temp1->phno, temp1->marks);
        course(temp1->cos);
        temp1 = temp1->next;
    }
    printf(" No of students = %d ", count);
}
int deleteend()
{
    struct node *temp;
    temp = first;
    if (temp->next == NULL)
    {
        free(temp);
        first = NULL;
    }
    else
    {
        while (temp->next != last)
          temp = temp->next;
        free(last);
        temp->next = NULL;
        last = temp;
    }
    count--;
    return 0;
}
int main()
{
    int ch, n, i;
    first = NULL;
    temp = temp1 = NULL;
    while (1)
    {
        system("COLOR 12");
        printf("\n-----------------WELCOME TO SIR M VISVESVARAYA INSTITUTE OF TECHNOLOGY---------------------\n");
        printf("\n\t\t 1.ADD SSTUDENT'S DETAILS:");
        printf("\n\t\t 2.DISPLAY STUDENT'S DETAILS:");
        printf("\n\t\t 3.DELETE RECORD OF student:");
        printf("\n\t\t 4.EXIT\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("\n\t\t CHOOSE THE ABOVE OPTION : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            insert_atlast();
            break;
            case 2:
            display();
            break;
            case 3:
            deleteend();
            break;
            case 4:
            exit(0);
            default:
            printf("SELECT A CHOICE FROM ABOVE\n");
        } } 
