#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *arb;
  Node(int x)
  {
    data = x;
    next = NULL;
    arb = NULL;
  }
};

void print(Node *&head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void insertAtTail(Node *&tail, int d)
{
  Node *temp = new Node(d);
  tail->next = temp;
  tail = temp;
}

void insertAtTail1(Node *&head, Node *&tail, int d)
{
  Node *newNode = new Node(d);
  if (head == NULL)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }
}

Node *copyList(Node *head)
{
  Node *cloneHead = NULL;
  Node *cloneTail = NULL;
  Node *temp = head;
  while (temp != NULL)
  {
    insertAtTail1(cloneHead, cloneTail, temp->data);
    temp = temp->next;
  }
  unordered_map<Node *, Node *> oldToNew;
  Node *originalNode = head;
  Node *cloneNode = cloneHead;
  while (originalNode != NULL)
  {
    oldToNew[originalNode] = cloneNode;
    originalNode = originalNode->next;
    cloneNode = cloneNode->next;
  }
  originalNode = head;
  cloneNode = cloneHead;

  while (originalNode != NULL)
  {
    cloneNode->arb = oldToNew[originalNode->arb];
    originalNode = originalNode->next;
    cloneNode = cloneNode->next;
  }
  return cloneHead;
}

Node *copyList1(Node *head)
{
  Node *cloneHead = NULL;
  Node *cloneTail = NULL;
  Node *temp = head;
  while (temp != NULL)
  {
    insertAtTail1(cloneHead, cloneTail, temp->data);
    temp = temp->next;
  }
  Node *originalNode = head;
  Node *cloneNode = cloneHead;
  while (originalNode != NULL && cloneNode != NULL)
  {
    Node *next = originalNode->next;
    originalNode->next = cloneNode;
    originalNode = next;

    next = cloneNode->next;
    cloneNode->next = originalNode;
    cloneNode = next;
  }
  // originalNode = head;
  // cloneNode = cloneHead;

  temp = head;

  while (temp != NULL)
  {
    if (temp->next != NULL)
    {
      temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
    }
    temp = temp->next->next;
  }
  originalNode = head;
  cloneNode = cloneHead;
  while (originalNode != NULL && cloneNode != NULL)
  {
    originalNode->next = cloneNode->next;
    originalNode = originalNode->next;
    if (originalNode != NULL)
    {
      cloneNode->next = originalNode->next;
    }
    cloneNode = cloneNode->next;
  }
  return cloneHead;
}

int main()
{
  Node *node1 = new Node(1);
  Node *head = node1;
  Node *tail = node1;
  insertAtTail(tail, 2);
  insertAtTail(tail, 3);
  insertAtTail(tail, 4);
  insertAtTail(tail, 5);
  print(head);
  copyList1(head);
  print(head);
}