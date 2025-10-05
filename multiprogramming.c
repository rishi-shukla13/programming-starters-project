#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
    };
struct node *head=NULL,*mov=NULL,*newnode=NULL;
void create()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the processing time of programs:- ");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
        mov=newnode;
    }
    else
    {
        mov->link=newnode;
        newnode->link=head;
        mov=newnode;
    }
}
void display()
{
    mov=head;
    do
    {
        printf("%d ",mov->data);
        mov=mov->link;
    }
    while(mov!=head);
    printf("\n");
}
int process(int a)
{
    mov=head;
    int c=1,sum=0;
    while(c!=0)
    {
        c=0;
        display();
    do
    {

        if(mov->data>0)
        {
            if(mov->data<=a)
        {
              sum=sum+mov->data;
            mov->data=0;
        }
        else
        {
        mov->data=mov->data-a;
         sum=sum+a;
        }

        ++c;
        }


        mov=mov->link;
    }
    while(mov!=head);
    }
    return sum;
}
int main()
{
    int p=0;
    printf("Enter the number of programs to be executed:- ");
    scanf("%d",&p);
    for(int i=0;i<p;++i)
    {
        create();
    }
    display();
    int m=0;
    printf("Enter the processing time alloted by CPU to each program per cycle:- ");
    scanf("%d",&m);
    printf("The total processing time is :- %d",process(m));

}
