#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MaxQ 10

typedef struct Queue{
int front,rear;
int data[MaxQ];
}queue;
void enqueue(queue *q,int item){
if(q->rear==MaxQ-1){
   printf("\nQueue Overflow!!!!\n");
   return;
}
if(q->rear==-1){
   q->front = q->rear = 0;
}
else{
    q->rear++;
}
q->data[q->rear] = item;
}
int dequeue(queue *q){
    int item;
    if(q->front==-1){
        printf("\nQueue Underflow!!!!\n");
        return -1;
    };
    item = q->data[q->front];
    if(q->front==q->rear){
        q->front = q->rear = -1;
    }
    else{
         q->front++;
    }
    return item;
}
int peepFront(queue q){
    int item;
    if(q.front==-1){
        printf("\nQueue is Empty!!!!\n");
        return -1;
    }
    item = q.data[q.front];
    return item;
}
void display(queue q){
    int i;
    if(q.front!=-1){
    for ( i = q.front; i <= q.rear; i++)
    {
       printf("%d ",q.data[i]);
    }
    printf("\n");
    }
    
}

int main(){
    queue q;
    q.front = -1;
    q.rear = -1;
    int ch,item;
    do{
        system("cls");
        printf("\n1.Enqueue\n2.Dequeue\n3.PeepFront\n4.Display\n5.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1: 
        printf("\nEnter item you want to insert in the queue : \n");
        scanf("%d",&item);
        enqueue(&q,item);
        break;
        case 2:
        item = dequeue(&q);
        if(item!=-1){
            printf("\nItem deleted is : %d\n",item);
        }
        break;
        case 3:
          item = peepFront(q);
        if(item!=-1){
            printf("\nItem peeped is : %d\n",item);
        }
        break;
        case 4:
        display(q);
        break;
        case 5:
        break;
        default:
        printf("\nINVALID INPUT!!! PLEASE ENTER VALID INPUT.....\n");
        break;
    }
    printf("\nPress any key to continue....");
    getch();
    }while(ch!=5);
    return 0;
}