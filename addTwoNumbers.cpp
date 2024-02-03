#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int d)
  {
    this->data = d;
    this->next = NULL;
  }
  ~Node()
  {
    int value = this->data;
    if (this->next != NULL)
    {
      delete next;
      next = NULL;
    }
    cout << " memory is free for node with data " << value << endl;
  }
};

void insertAtHead(Node *&head, int d)
{
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}
void insertAtTail(Node *&tail, int d)
{
  Node *temp = new Node(d);
  tail->next = temp;
  tail = temp;
}

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

Node *reverse(Node *head)
{
  Node *curr = head;
  Node *prev = NULL;
  Node *next = NULL;
  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

void insertAtTail1(struct Node *&head, struct Node *&tail, int val)
{
  Node *temp = new Node(val);
  if (head == NULL)
  {
    head = temp;
    tail = temp;
    return;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

struct Node *add(struct Node *f, struct Node *s)
{
  int carry = 0;
  Node *ansHead = NULL;
  Node *ansTail = NULL;
  while (f != NULL || s != NULL || carry != 0)
  {
    int val1 = 0;
    if (f != NULL)
    {
      val1 = f->data;
    }
    int val2 = 0;
    if (s != NULL)
    {
      val2 = s->data;
    }

    int sum = carry + val1 + val2;
    int digit = sum % 10;
    insertAtTail1(ansHead, ansTail, digit);
    carry = sum / 10;
    if (f != NULL)
    {
      f = f->next;
    }
    if (s != NULL)
    {
      s = s->next;
    }
  }

  return ansHead;
}

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
  first = reverse(first);
  second = reverse(second);
  Node *ans = add(first, second);
  ans = reverse(ans);
  return ans;
}

int main()
{
  Node *node1 = new Node(4);
  Node *head = node1;
  Node *tail = node1;
  insertAtTail(tail, 5);
  print(head);
  Node *node2 = new Node(3);
  Node *head2 = node2;
  Node *tail2 = node2;
  insertAtTail(tail2, 4);
  insertAtTail(tail2, 5);
  print(head2);
  Node *ans = addTwoLists(head, head2);
  print(ans);
}