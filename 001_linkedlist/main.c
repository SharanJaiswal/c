// IF HEAD NEEDS TO BE UPDATED IN ANY OPERATION, pass &head to the **HEAD_POINTER
#include <stdio.h>
#include <stdlib.h>

typedef struct SLL_Node
{
    int data;
    struct SLL_Node *link;
} SLL_Node;

void printSLL(SLL_Node *head)
{
    SLL_Node *itr = head;
    while (itr)
    {
        printf("%d ", itr->data);
        itr = itr->link;
    }
    printf("\n");
}

void printSSL_Rec_H2T_withArrow(SLL_Node *head)
{
    if(head)
    {
        printf("%d", head->data);
        if(head->link)
        {
            printf(" -> ");
        }
        printSSL_Rec_H2T_withArrow(head->link);
    }
}

void printSSL_Rec_T2H_withArrow(SLL_Node *head)
{
    if(head)
    {
        printSSL_Rec_T2H_withArrow(head->link);
        printf("%d <- ", head->data);
    }
}

void printSLLwithArrow(SLL_Node *head)
{
    SLL_Node *itr = head;
    while(itr)
    {
        printf("%d", itr->data);
        if(itr->link)
        {
            printf(" -> ");
        }
        itr = itr->link;
    }
    printf("\n");
}

void addNodeOnHead (SLL_Node **head_ptr)
{
    int data;
    // Enter data of the SLL_Node
    scanf("%d", &data);
    SLL_Node *temp = (SLL_Node *)calloc(1, sizeof(SLL_Node));
    temp->data = data;
    temp->link = NULL;

    if(!*head_ptr)
    {
        *head_ptr = temp;
    }
    else
    {
        temp->link = *head_ptr;
        *head_ptr = temp;
    }
}

void addNodeOnTail(SLL_Node **head_ptr)
{
    SLL_Node *temp = (SLL_Node *)malloc(sizeof(SLL_Node));
    scanf("%d", &temp->data);
    temp->link = NULL;

    if(!*head_ptr)
    {
        *head_ptr = temp;
    }
    else
    {
        SLL_Node *itr = *head_ptr;
        while(itr->link)
        {
            itr = itr->link;
        }
        itr->link = temp;
    }
}

int FindIndexOfElement(int data, SLL_Node *head)
{
    if(!head)
    {
        printf("Linked List is empty. ");
        return -1;
    }
    else
    {
        int count = 0;
        SLL_Node *itr = head;
        while(itr)
        {
            if(itr->data == data)
            {
                // count++;
                printf("Indexing starts from \"0\" from head of Linked-List.\n");
                return count;
            }
            count++;
            itr = itr->link;
        }
        return -1;
    }
}

int FindElementAtIndex(int idx, SLL_Node *head, int *flag)
{
    if(!head)
    {
        *flag = 1;
        printf("Linked-List is empty.\n");
        return -1;
    }
    else
    {
        int count = 0;
        SLL_Node *itr = head;
        while(itr)
        {
            if(count == idx)
            {
                printf("Indexing starts from \'0\' , from head.\n");
                return itr->data;
            }
            itr = itr->link;
            count++;
        }
        printf("Indexing starts from \'0\' , from head.\nIndex asked lies out of current length of Linked-List.\n");
        *flag = 1;
        return -1;
    }
}

int LengthOfSLL(SLL_Node *head)
{
    int count = 0;
    if(!head)
    {
        return count;
    }
    else
    {
        SLL_Node *itr = head;
        while(itr)
        {
            count++;
            itr = itr->link;
        }
        return count;
    }
}

void DeleteNodeAtIndex(int idx, SLL_Node **head_ptr)
{
    if(!*head_ptr)
    {
        printf("Linked-list is empty.\n");
        return;
    }
    if(idx < 0)
    {
        printf("Invalid Index.\n");
        return;
    }
    else    // Since every case is already handled. Hence, List has at least one node.
    {
        printf("Indexing starts from \"0\", from \"Head\".\n");
        SLL_Node *itr = *head_ptr;
        if (idx == 0)
        {
            *head_ptr = (*head_ptr)->link;
            free(itr);
            printf("Successful!\n");
        }
        else
        {
            int count = 0;  // denoting current possible count of node pointed by iterator. Also, it starts counting from 0, to track corresponding indx of node.
            while(itr->link)
            {
                count++;    // since next node is present, hence updating count value
                if(count == idx)
                {
                    SLL_Node *temp = itr->link;
                    itr->link = itr->link->link;
                    free(temp);
                    printf("Successful.\n");
                    return;
                }
                itr = itr->link;
            }
            printf("Unsuccessful.\nIndex greater than maximum index of Linked_list.\n");
        }
    }
}

void DeleteFirstOccurence(int data, SLL_Node **head_ptr)
{
    if(!*head_ptr)
    {
        printf("List is Empty. Unsuccessful.\n");
    }
    else
    {
        SLL_Node *itr = *head_ptr;
        if((*head_ptr)->data == data)
        {
            *head_ptr = (*head_ptr)->link;
            free(itr);
            printf("Unsuccessful.\n");
            return;
        }
        else
        {
            while(itr->link)
            {
                if(itr->link->data == data)
                {
                    SLL_Node *temp = itr->link;
                    itr->link = itr->link->link;
                    free(temp);
                    printf("Successful.\n");
                    return;
                }
                itr = itr->link;
            }
            printf("No node present with data value %d.\nUnsuccessful.\n", data);
            return;
        }
    }
}

void ListReversal_Itr(SLL_Node **head_ptr)
{
    if(!*head_ptr || !(*head_ptr)->link)    // Second operand in if can be implicitly handled in else part; but for the sake of print statement, its written here.
    {
        printf("No change in SLL reversal.\n");
    }
    else
    {
        SLL_Node *prev = NULL, *cur = *head_ptr, *next = NULL;
        while(cur)
        {
            next = cur->link;
            cur->link = prev;
            prev = cur;
            cur = next;
        }
        *head_ptr = prev;
    }

}

void Rec_Reversal(SLL_Node **head_ptr, SLL_Node *prev, SLL_Node *cur)   // WORKER
{
    if(!cur)
    {
        *head_ptr = prev;
        return;
    }
    Rec_Reversal(head_ptr, cur, cur->link);
    cur->link = prev;
}
void ListReversal_Rec(SLL_Node **head_ptr)  //DRIVER
{
    SLL_Node *cur = *head_ptr, *prev = NULL;
    Rec_Reversal(head_ptr, prev, cur);
}

void MoveLastNodeToFront(SLL_Node **head_ptr)
{
    if(!*head_ptr || !(*head_ptr)->link)
    {
        return;
    }
    else
    {
        SLL_Node *itr = *head_ptr;
        while(itr->link->link)
        {
            itr = itr->link;
        }
        itr->link->link = *head_ptr;
        *head_ptr = itr->link;
        itr->link = NULL;
        return;
    }
}

void SwapNodesPairData(SLL_Node **head_ptr)
{
    if(!*head_ptr || !(*head_ptr)->link)
    {
        return;
    }
    else
    {
        SLL_Node *p = *head_ptr, *q = (*head_ptr)->link;
        while(q)
        {
            int temp = p->data;
            p->data = q->data;
            q->data = temp;
            p = q->link;
            q = p ? p->link : NULL;
        }
    }
}

int IsInNonDecOrder(SLL_Node *head)
{
    return ((head == NULL) || (head->link == NULL) || ((head->data <= head->link->data) && IsInNonDecOrder(head->link)));
}

int main()
{
    #include "../fileio.h"
    // Enter the numer of nodes to make SSL.
    int n;
    scanf("%d", &n);
    
    // // Add node on head
    // SLL_Node *head = NULL;
    // for(int i = 0; i < n; i++)
    // {
    //     addNodeOnHead(&head);
    // }
    // printSLL(head);

    // Add node on the tailend
    SLL_Node *head = NULL;
    for(int i = 0; i < n; i++)
    {
        addNodeOnTail(&head);
    }
    printSLLwithArrow(head);

    // // Finding an element in SLL based on node index
    // int eleToFind, idx;
    // scanf("%d", &eleToFind);
    // idx = FindIndexOfElement(eleToFind, head);
    // printf((idx == -1) ? "Element Not Found.\n" : "Element found at index : %d.\n", idx);

    // // Finding data of a particular node of Linked-List
    // int idx, flag = 0, element;
    // scanf("%d", &idx);
    // element = FindElementAtIndex(idx, head, &flag);
    // printf((flag) ? "Index not Found.\n" : "Element found at index %d is : %d.\n", idx, element);

    // // Length of SLL
    // int len = LengthOfSLL(head);
    // printf((len) ? "Linked-List consists of %d nodes.\n" : "Linked-List is empty.\n", len);

    // // Deleting element at index
    // int IndexToBeDeleted;
    // scanf("%d", &IndexToBeDeleted);
    // DeleteNodeAtIndex(IndexToBeDeleted, &head);
    // printf("Linked-List after attempting deletion of node at %d Index:--\n", IndexToBeDeleted);
    // printSLLwithArrow(head);

    // // Deleting first Occurence of data
    // int data;
    // scanf("%d", &data);
    // DeleteFirstOccurence(data, &head);
    // printf("After attempting deletion of node with data value %d, Linked-List is:--\n", data);
    // printSLLwithArrow(head);

    // // Array reversal using both iterative and recursive method
    // ListReversal_Itr(&head);
    // printSLLwithArrow(head);
    // ListReversal_Rec(&head);
    // printSLLwithArrow(head);

    // // Printing SLL H2T|T2H using recursion, with arrow
    // printSSL_Rec_H2T_withArrow(head);
    // printf("\n");
    // printSSL_Rec_T2H_withArrow(head);
    // printf("\n");

    // // Move Last Node to Front, tail node to be shifted to front, pointed by head
    // MoveLastNodeToFront(&head);
    // printSLLwithArrow(head);

    // // Swap nodes' data pairwise from left, if possible.
    // SwapNodesPairData(&head);
    // printSLLwithArrow(head);

    // // Checking if list is in non decreasing order
    // int flag = IsInNonDecOrder(head);
    // printf(flag ? "It is in non-decreasing order.\n" : "It is NOT in non-decreasing order.\n");


    return 0;
}