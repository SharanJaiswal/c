#include <stdio.h>
#include <stdlib.h>
// push pop capacity size=top+1 peek isfull isempty flush
typedef struct Node
{
    int data;
    struct Node *link;
} Node;

int push_arr(int *arr, int capacity, int *top)
{
    int data;
    scanf("%d", &data);

    if(*top + 1 == capacity) { return 0; }
    else
    {
        arr[++*top] = data;
        return 1;
    }
}

int pop_arr(int *arr, int *top, int *flag)
{
    if(*top == -1)
    {
        *flag = 0;
        return -1;
    }
    else
    {
        *flag = 1;
        --*top;
        return arr[*top+1];
    }
}

int push_sll(Node **head_ptr, int capacity, int *top)
{
    int data;
    scanf("%d", &data);
    if(*top+1 == capacity)
    {
        return 0;
    }
    else
    {
        if(!*head_ptr)
        {
            *head_ptr = (Node *)calloc(1, sizeof(Node));
            (*head_ptr)->link = NULL;
            (*head_ptr)->data = data;
        }
        else
        {
            Node *temp = (Node *)calloc(1, sizeof(Node));
            temp->link = *head_ptr;
            temp->data = data;
            *head_ptr = temp;
        }
        ++*top;
        return 1;
    }
}

int pop_sll(Node **head_ptr, int *top, int *flag)
{
    if(*top == -1)
    {
        *flag = 0;
        return -1;
    }
    else
    {
        Node *temp = *head_ptr;
        *head_ptr = (*head_ptr)->link;
        int data = temp->data;
        free(temp);
        --*top;
        *flag = 1;
        return data;
    }
}

int main()
{
    #include "../fileio.h"

    int capacity;
    scanf("%d", &capacity);

    // // // Stack using arrays
    // int *arr = (int *)calloc(capacity, sizeof(int)), top = -1;

    // // Push in array stack
    // int p;
    // scanf("%d", &p);
    // for(int i = 0; i < p; i++)
    // {
    //     printf(push_arr(arr, capacity, &top) ? "Successful. Pushed on Stack.\n" : "Unsuccessful. Stack Overflow.\n");
    // }

    // // Pop an element from stack
    // int q;
    // scanf("%d", &q);
    // for(int i = 0; i< q; i++)
    // {
    //     int flag, data = pop_arr(arr, &top, &flag);
    //     printf(flag ? "Popped data : %d.\n" : "Unsuccessful. Stack Underflow.\n", data);
    // }


    // // // Stack using SLL
    // Node *head = NULL;
    // int top = -1;
    
    // // Push in SLL stack
    // int p;
    // scanf("%d", &p);
    // for(int i = 0; i < p; i++)
    // {
    //     printf(push_sll(&head, capacity, &top) ? "Successful. Pushed on stack.\n" : "Unsuccessful. Stack Overflow.\n");
    // }

    // // Pop from Stack SLL
    // int q;
    // scanf("%d", &q);
    // for(int i = 0; i < q; i++)
    // {
    //     int flag, data = pop_sll(&head, &top, &flag);
    //     printf(flag ? "Successful. Popped item : %d.\n" : "Unsuccessful. Stack Underflow.\n", data);
    // }

    // // Peek
    // printf("Peeking element : %d.\n", arr[top]);

    // // Flush Stack
    // top = -1;

    // // Is stack full?
    // printf(top+1 == capacity ? "Stack is Full.\n" : "Stack is NOT Full.\n");

    // // Is stack Empty?
    // printf(top == -1 ? "Stack is Empty.\n" : "Stack is NOT Empty.\n");

    // // Capacity and size
    // printf("Capacity : %d.\nSize : %d.\n", capacity, top + 1);

    return 0;
}