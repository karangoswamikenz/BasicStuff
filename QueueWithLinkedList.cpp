#include "QueueWithLinkedList.h"
#include <iostream>
using namespace std;

void printNode(Node* n)
{
    if(!n->data)
    printf("NULL");
    else
    {
        int *x = (int *)n->data;
        cout<<*x;
    }

}

QueueWithLinkedList::QueueWithLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

QueueWithLinkedList::QueueWithLinkedList(Node* n)
{
    head = tail = n;
}

QueueWithLinkedList::QueueWithLinkedList(void* _d)
{
    Node* tmp = new Node(_d);
    head = tail = tmp;
}

void QueueWithLinkedList::enqueueNode(Node* n)
{
    if(!tail)
        head = tail = n;
    else
    {
        tail->next = n;
        tail = tail->next;
    }
}

void QueueWithLinkedList::enqueueData(void* d)
{
    Node* tmp = new Node(d);
    if(!tail)
        head = tail = tmp;
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

void QueueWithLinkedList::enqueueInt(int n)
{
    void *d = new int(n);
    Node *tmp = new Node(d);
    if(!tail)
        head = tail = tmp;
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

Node* QueueWithLinkedList::dequeueNode()
{
    if(!head) return nullptr;
    else
    {
        // get head pointer
        Node* tmp = head;

        // move head one step up.
        head = head->next;
        tmp->next = nullptr;

        // que is empty so we make tail null too
        if(!head) tail = nullptr;
        return tmp;
    }
}

void QueueWithLinkedList::popNode()
{
    if(!head) return;
    else
    {
        Node *tmp = head;
        head = head->next;
        tmp->next = nullptr;
        if(!head) tail = nullptr;
        //if(tmp) delete tmp;
    }
}

Node* QueueWithLinkedList::topNode()
{
    return head;
}

int QueueWithLinkedList::topNodeInt()
{
    Node *tmp = head;
    if(tmp)
        return *(int*)tmp->data;
    else
        return -1;
}

void QueueWithLinkedList::printQueue()
{
    Node *pntr = head;
    cout<< "<== ";
    while(pntr)
    {
        printNode(pntr);
        if(pntr->next)
            cout<<"->";
        pntr = pntr->next;
    }
    cout<< " <== \n";
}
