#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
       head = reverseList(head);

       printList(head);

       cout << endl;
    }
    return 0;
}

Node* reverseList(Node *head)
{
    Node *prev = NULL, *next = NULL;
    Node *current = head;
    
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

