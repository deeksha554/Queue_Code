#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define Maxstk 10

typedef struct Stack{
     int top;
     int arr[Maxstk];
}stack;

void push(stack *s1,int item){
    if(s1->top==Maxstk-1){
        printf("\nSTACK OVERFLOW!!!\n");
        return;
    }
    s1->top++;
    s1->arr[s1->top] = item;
}
int pop(stack *s1){
     if(s1->top==-1){
        printf("\nSTACK UNDERFLOW!!!\n");
        return -1;
    }
   int item=s1->arr[s1->top--];
   return item;
}
int peep(stack s1){
     if(s1.top==-1){
        printf("\nSTACK IS EMPTY!!!\n");
        return -1;
    }
   int item=s1.arr[s1.top];
   return item;
}
void display(stack s1){
     int i;
     for(i=0;i<=s1.top;i++){
         printf("%d\t",s1.arr[i]);
     }
          printf("\n");  }

int main(){
    stack s1;
    s1.top = -1;
    int ch,item;
    do{
        system("cls");
        printf("\n1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter item to be pushed into stack : ");
            scanf("%d",&item);
            push(&s1,item);
            break;
            case 2:
            item =  pop(&s1);
            if(item!=-1){
            printf("\nItem which is popped is : %d\n",item);
            }
            break;
            case 3:
            item =  peep(s1);
            if(item!=-1){
            printf("\nItem which is peeped is : %d\n",item);
            }
            break;
            case 4:
            display(s1);
            break;
            case 5:
            break;
            default:
            printf("\nINVALID INPUT!!! PLEASE ENTER VALID INPUT....\n");
            break;
        }
        printf("\nPress any key to continue......");
        getch();
    }while(ch!=5);
    return 0;   
 }