#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *temp=NULL;
struct node *front=NULL;//ilk dugum
struct node *rear=NULL;//son dugum

void enqueue(int x)
{
    struct node *eklenecek=malloc(sizeof(struct node));
    eklenecek->data=x;

    if(front==NULL)
    {
        front=eklenecek;
        front->next=front;
        rear=eklenecek;
        rear->next=NULL;
    }
    else if(front->next==front)
    {
        front->next=eklenecek;
        eklenecek->next=NULL;
        rear=eklenecek;
    }
    else
    {
        rear->next=eklenecek;
        rear=eklenecek;
        rear->next=NULL;
    }
}
void dequeue()
{
    if(front==NULL)
    {
        printf("\nqueue is empty|n\n");
    }
    else
    {
        temp=front->next;
        free(front);
        front=temp;
    }
}
void print()
{
    system("cls");
    if(front==NULL)
    {
        printf("\nqueue is empty\n\n");
    }
    else
    {
        printf("queue : \n");
        temp=front;
        while(temp->next!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
    printf("\n");
}

int main()
{
    int data;
    int secim;

    while(1)
    {

        printf("********IMPLEMENTATION OF DINAMIK QUEUE********\n\n");
        printf("1-enqueue\n");
        printf("2-dequeue\n");
        printf("3-print\n");
        printf("4-cikis\n\n");

        printf("yapacaginiz islemi seciniz : ");
        scanf("%d",&secim);

        switch(secim)
        {
        case 1:
            {
                printf("\neklemek istediginiz elemani giriniz : ");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
        case 2:
            {
                dequeue();
                break;
            }
        case 3:
            {
                print();
                break;
            }
        case 4:
            {
                return 0;
            }

        }
    }

    return 0;
}
