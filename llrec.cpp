#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


/*void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    //DOES HEAD NEED TO BE EMPTY?
    if (head == nullptr) 
    {
        //smaller = nullptr;
        //larger = nullptr;
        if (smaller != nullptr) smaller->next = nullptr; 
        if (larger != nullptr) larger->next = nullptr;
        return;
    }

    if (head->val > pivot) 
    {
        if (larger == nullptr) 
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
        if (smaller == nullptr) 
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


}*/










void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    larger = nullptr;
    smaller = nullptr;
    if (head == nullptr) return;

    if (head->val > pivot) 
    {
        larger = head;
        head = head->next;
        llpivot(head, smaller, larger->next, pivot);
    }
    else
    {
          smaller = head;
          head = head->next;
          llpivot(head, smaller->next, larger, pivot);
    }


}