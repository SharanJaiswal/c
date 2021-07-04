#include <stdio.h>
#include <stdlib.h>

// Enqueue Dequeue Capacity Size Flush

typedef struct node
{
    int data;
    struct node *link;
} Node;

int enqueue_arr(int *arr, int capacity, int *front, int *rear)
{
    int data;
    scanf("%d", &data);
    if(*rear == -1) // or *front==-1 or both is -1
    {
        arr[++*rear] = data;
        ++*front;
        return 1;
    }
    else if((*rear + 1) % capacity == *front)
    {
        return 0;
    }
    else
    {
       *rear = (*rear + 1) % capacity;
        arr[*rear] = data;
        return 1;
    }
}

int dequeue_arr(int *arr, int capacity, int *front, int *rear, int *flag)
{
    if(*rear == -1) // or *front==-1 or both is -1
    {
        *flag = 0;
        return -1;
    }
    else if (*front == *rear)
    {
        int data = arr[*front];
        *front = -1;
        *rear = -1;
        *flag = 1;
        return data;
    }
    else
    {
        int data = arr[*front];
        *front = (*front + 1) % capacity;
        *flag  = 1;
        return data;
    }
}

int CurrentSize_arr(int *arr, int capacity, int *front, int *rear)
{
    if(*front < *rear) { return *rear - *front + 1; }
    else if(* rear < *front) { return capacity - (*front - *rear - 1); }
    else if(*rear == -1) { return 0; }
    else { return 1; }
}

int enqueue_sll(Node **rear_ptr, int *size, int capacity)
{
    int data;
    scanf("%d", &data);
    if(*size == capacity)
    {
        return 0;
    }
    else
    {
        Node *temp = (Node *)calloc(1, sizeof(Node));
        temp->data = data;
        if(!*rear_ptr)
        {
            *rear_ptr = temp;
            (*rear_ptr)->link = *rear_ptr;
            ++*size;
        }
        else
        {
            temp->link = (*rear_ptr)->link;
            (*rear_ptr)->link = temp;
            *rear_ptr = (*rear_ptr)->link;
            ++*size;
        }
        return 1;
    }
}

int dequeue_sll(Node **rear_ptr, int *size, int capacity, int *flag)
{
    if(!*rear_ptr)
    {
        *flag = 0;
        return -1;
    }
    else
    {
        if((*rear_ptr)->link == *rear_ptr)
        {
            int data = (*rear_ptr)->data;
            free(*rear_ptr);
            *rear_ptr = NULL;
            --*size;
            *flag = 1;
            return data;
        }
        else
        {
            Node *temp = (*rear_ptr)->link;
            int data = temp->data;
            (*rear_ptr)->link = (*rear_ptr)->link->link;
            free(temp);
            --*size;
            *flag = 1;
            return data;
        }
    }
}

int CurrentSize_sll(Node *rear)
{
    int size = 0;
    Node *rearNodeAddr = rear;
    if(!rearNodeAddr)
    {
        return 0;
    }
    else if((rearNodeAddr)->link == rearNodeAddr)
    {
        return 1;
    }
    else
    {
        rearNodeAddr = rearNodeAddr->link;
        size++;
        while(rearNodeAddr != rear)
        {
            size++;
            rearNodeAddr = rearNodeAddr->link;
        }
        return size;
    }
}

void Flush_ssl(Node **rear_ptr)
// Start deleting node from front(cuz thats the rule for easiness.)
// Since it is while loop, take address of next node in temp. itr will point to node to be freed.
// At last node(rear node), its link still point to dead node. So it needed to be handled so that while loop ends in its next iteration
// Which is possible only at starting cuz there is no way to backtrack at this point
// At last, rear_ptr is pointing to dead node. So, it needs to be pointing to NULL.
{
    Node *itr = (*rear_ptr)->link;
    (*rear_ptr)->link = NULL;
    while(itr)
    {
        printf("%p : %d\t", itr, itr->data);
        Node *temp = itr->link;
        free(itr);
        itr = temp;
    }
    *rear_ptr = NULL;
}

int main()
{
    #include "../fileio.h"
    int capacity;
    scanf("%d", &capacity);

    // // // Queue using array
    // int *arr = (int *)calloc(capacity, sizeof(int)), front = -1, rear = -1;

    // // Enqueue
    // int e;
    // scanf("%d", &e);
    // for(int i = 0; i < e; i++)
    // {
    //     printf(enqueue_arr(arr, capacity, &front, &rear) ? "Successful. Queued.\n" : "Unsuccessful. Queue is full already.\n");
    // }

    // // Dequeue
    // int d;
    // scanf("%d", &d);
    // for(int i = 0; i < d; i++)
    // {
    //     int flag, data = dequeue_arr(arr, capacity, &front, &rear, &flag);
    //     printf(flag ? "Successful. Dequeued Item : %d.\n" : "Unsuccessful. Queue already empty.\n", data);
    // }

    // // Capacity = capacity;

    // // Size
    // printf("Current Size : %d.\n", CurrentSize_arr(arr, capacity, &front, &rear));

    // // Flush
    // rear = front = -1;

    // // Queue using SLL
    Node *rear = NULL;
    int size  = 0;

    // Enqueue
    int e;
    scanf("%d", &e);
    for(int i = 0; i < e; i++)
    {
        printf(enqueue_sll(&rear, &size, capacity) ? "Successful. Queued.\n" : "Unsuccessful. Queue is already full.\n");
    }
    
    // Dequeue
    int d, flag;
    scanf("%d", &d);
    for(int i = 0; i < d; i++)
    {
        int data = dequeue_sll(&rear, &size, capacity, &flag);
        printf(flag ? "Successful. Dequeued Item : %d.\n" : "Unsuccessful. Queue already empty.\n", data);
    }

    // Capacity = capacity;

    // // Size = size; (or, if size variable is not to be used anytime at all, then below is the code)
    // printf("Current size of the Queue is : %d.\n", CurrentSize_sll(rear));

    // // Flush Queue
    // Flush_ssl(&rear);

    return 0;
}