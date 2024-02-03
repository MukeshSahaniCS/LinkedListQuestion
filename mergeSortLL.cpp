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
  // new node create
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}
// insert at tail/end
void insertAtTail(Node *&tail, int d)
{
  // new node create
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

Node *findMid(Node *head)
{
  Node *slow = head;
  Node *fast = head->next;
  while (fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

Node *merge(Node *left, Node *right)
{
  if (left == NULL)
  {
    return right;
  }
  if (right == NULL)
  {
    return left;
  }
  Node *ans = new Node(-1);
  Node *temp = ans;

  while (left != NULL && right != NULL)
  {
    if (left->data < right->data)
    {
      temp->next = left;
      temp = left;
      left = left->next;
    }
    else
    {
      temp->next = right;
      temp = right;
      right = right->next;
    }
  }
  while (left != NULL)
  {
    temp->next = left;
    temp = left;
    left = left->next;
  }
  while (right != NULL)
  {
    temp->next = right;
    temp = right;
    right = right->next;
  }
  ans = ans->next;
  return ans;
}
Node *mergeSort(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node *mid = findMid(head);
  Node *left = head;
  Node *right = mid->next;
  mid->next = NULL;
  left = mergeSort(left);
  right = mergeSort(right);

  Node *res = merge(left, right);
  return res;
}

Node* flattern(Node* head){
  
}

int main()
{
  Node *node1 = new Node(1);
  Node *head = node1;
  Node *tail = node1;
  insertAtTail(tail, 6);
  insertAtTail(tail, 3);
  insertAtTail(tail, 2);
  insertAtTail(tail, 5);
  print(head);
  mergeSort(head);
  print(head);
} 