#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
// Node* takeInput(){
//     int data;
//     cin>>data;
//     Node* head=NULL;
//     Node* tail=NULL;
//     while(data!=-1){
//         Node* newNode=new Node(data);
//         if(head==NULL){
//             head=newNode;
//             tail=newNode;

//         }
//         else{
//             tail->next=newNode;
//             tail=tail->next;
//         }
//         cin>>data;
//     }
//     return head;
// }

// Node* reverseLinkedList(Node* head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     Node* prev=NULL;
//     Node* curr = head;
//     Node* forward=NULL;
//     while(curr!=NULL){
//         forward=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=forward;
//     }
//     return prev;
// }

// Using recursion
// void reverseLL(Node* &head, Node* curr, Node* prev){
//     if(curr==NULL){
//         head=prev;
//         return;
//     }
//     Node* forward=curr->next;
//     reverseLL(head, forward, curr);
//     curr->next =prev;
// }

// Node* reverse1(Node* head){
//     if(head==NULL||head->next==NULL){
//         return head;
//     }
//     Node* smallHead=reverse1(head->next);
//     head->next->next=head;
//     head->next=NULL;
//     return smallHead;

// }
// T.C O(n)  and S.C=O(n)

int main()
{
    LinkedList ll;
    ll.push(11);
    ll.push(12);
    ll.push(13);
    ll.push(14);
    ll.push(15);
    cout << "Given Linked List" << endl;
    ll.print();
    ll.reverse();
    cout << "Reverse Linked List" << endl;
    ll.print();
}