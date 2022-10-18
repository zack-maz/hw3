#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    
    if (head == NULL) //set head to empty at the end
    {
        if (smaller != NULL) smaller->next = NULL; 
        if (larger != NULL) larger->next = NULL;
        return;
    }

    if (head->val > pivot) 
    {
        if (larger == NULL) //fill first node of larger 
        {
            larger = head;
            head = head->next;
            llpivot(head, smaller, larger, pivot);
        }
        else
        {
            larger->next = head;
            head = head->next;
            llpivot(head, smaller, larger->next, pivot);
        }
    }
    else
    {
        if (smaller == NULL)  //fill first node of smaller
        {
            smaller = head;
            head = head->next;
            llpivot(head, smaller, larger, pivot);
        }
        else 
        {
            smaller->next = head;
            head = head->next;
            llpivot(head, smaller->next, larger, pivot);
        }
    }


}