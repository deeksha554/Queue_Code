#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *getnode()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    return newnode;
}
void AddFirst(node **p_start, int item)
{
    node *newnode = getnode();
    if (newnode == NULL)
    {
        printf("Memory Full! Overflow\n");
        exit(1);
    }
    newnode->data = item;
    newnode->next = *p_start;
    *p_start = newnode;
}
void AddLast(node **p_start, int item)
{
    node *newnode = getnode();
    if (newnode == NULL)
    {
        printf("Memory Full! Overflow\n");
        exit(1);
    }
    newnode->data = item;
    newnode->next = NULL;
    node *ptr = *p_start;
    if (*p_start == NULL)
    {
        *p_start = newnode;
        return;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
}
void AddBefore(node **p_start, int item, int num)
{
    node *newnode = getnode();
    if (newnode == NULL)
    {
        printf("Memory Full! Overflow\n");
        exit(1);
    }
    node *preptr = NULL, *ptr = *p_start;
    newnode->data = item;
    while (ptr != NULL && ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Item %d not found.......\n", num);
        return;
    }
    if (ptr == *p_start)
    {
        newnode->next = *p_start;
        *p_start = newnode;
        return;
    }
    preptr->next = newnode;
    newnode->next = ptr;
}
void AddAfter(node **p_start, int item, int num)
{
    node *newnode = getnode();
    if (newnode == NULL)
    {
        printf("Memory Full! Overflow\n");
        exit(1);
    }
    newnode->data = item;
    node *ptr = *p_start;
    while (ptr != NULL && ptr->data != num)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Item %d not found.......\n", num);
        return;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
}
void traverse(node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int DelFirst(node **p_start){
    int item;
    node *ptr = *p_start;
    if (*p_start == NULL)
    {
        printf("Can't delete ! Underflow \n");
        return -1;
    }

    *p_start = (*p_start)->next;
    item = ptr->data;
    free(ptr);
    return item;
}
int DelLast(node **p_start){
    int item;
    node *ptr = *p_start, *preptr = NULL;
    if (*p_start == NULL)
    {
        printf("Can't delete ! Underflow \n");
        return -1;
    }
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == *p_start)
    {
        *p_start = NULL;
        item = ptr->data;
        free(ptr);
        return -1;
    }

    preptr->next = NULL;
    item = ptr->data;
    free(ptr);
    return item;
}
int DelBefore(node **p_start, int num)
{
    int item;
    node *ptr = (*p_start)->next, *preptr = *p_start;
    if (*p_start == NULL)
    {
        printf("Can't delete ! Underflow \n");
        return -1;
    }

    while (preptr->data != num && ptr != NULL && ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (preptr->data == num)
    {
        printf("There is no element before %d.....\n", num);
        return -1;
    }
    if (ptr == NULL)
    {
        printf("Item %d not found..\n", num);
        return -1;
    }
    if (*p_start == preptr)
    {
        *p_start = (*p_start)->next;
    }
    item = preptr->data;
    free(preptr);
    return item;
}
int DelAfter(node **p_start, int num)
{
    int item;
    if (*p_start == NULL)
    {
        printf("Can't delete ! Underflow \n");
        return -1;
    }
    node *ptr = (*p_start)->next, *preptr = *p_start;
    while (preptr != NULL && preptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (preptr == NULL)
    {
        printf("Item %d not found..\n", num);
        return -1;
    }
    if (preptr == *p_start && ptr == NULL)
    {
        printf("There is no element after %d.....\n", num);
        return -1;
    }

    preptr->next = ptr->next;
    item = ptr->data;
    free(ptr);
    return item;
}
int count(node *ptr)
{
    int cnt = 0;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}
int main()
{
    node *start = NULL;
    int ch, item, num, cnt;
    do
    {
        system("cls");
        printf("\n1.AddFirst \n2.AddLast \n3.AddBefore \n4.AddAfter \n5.DelFirst \n6.DelLast \n7.DelBefore \
      \n8.DelAfter \n9.Count \n10.Traverse \n11.Exit\n");
        printf("Please! Enter your choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to be inserted : \n");
            scanf("%d", &item);
            AddFirst(&start, item);
            break;
        case 2:
            printf("Enter item to be inserted : \n");
            scanf("%d", &item);
            AddLast(&start, item);
            break;
        case 3:
            printf("Enter item to be inserted : \n");
            scanf("%d", &item);
            printf("Enter number before which node to be inserted : \n");
            scanf("%d", &num);
            AddBefore(&start, item, num);
            break;
        case 4:
            printf("Enter item to be inserted : \n");
            scanf("%d", &item);
            printf("Enter number after which node to be inserted : \n");
            scanf("%d", &num);
            AddAfter(&start, item, num);
            break;

        case 5:
            item = DelFirst(&start);
            if (item != -1)
            {
                printf("Item deleted is : %d \n", item);
            }
            break;
        case 6:
            item = DelLast(&start);
            if (item != -1)
            {
                printf("Item deleted is : %d \n", item);
            }
            break;
        case 7:
            printf("Enter number before which node to be deleted : \n");
            scanf("%d", &num);
            item = DelBefore(&start, num);
            if (item != -1)
            {
                printf("Item deleted is : %d \n", item);
            }
            break;
        case 8:
            printf("Enter number after which node to be deleted : \n");
            scanf("%d", &num);
            item = DelAfter(&start, num);
            if (item != -1)
            {
                printf("Item deleted is : %d \n", item);
            }
            break;
        case 9:
            cnt = count(start);
            printf("Count is : %d\n", cnt);
            break;
        case 10:
            traverse(start);
            break;
        case 11:
            break;
        default:
            printf("INVALID NUMBER!! PLEASE ENTER VALID NUMBER....\n");
            break;
        }
        printf("Press any key to continue.....\n");
        getch();

    } while (ch != 11);

    return 0;
}