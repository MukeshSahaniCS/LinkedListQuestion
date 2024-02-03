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

bool checkPalindrome(vector<int> arr)
{
  int n = arr.size();
  int s = 0;
  int e = n - 1;
  while (s <= e)
  {
    if (arr[s] != arr[e])
    {
      return 0;
    }
    s++;
    e--;
  }
  return 1;
}
bool isPalidrom(Node *head)
{
  vector<int> arr;
  Node *temp = head;
  while (temp != NULL)
  {
    arr.push_back(temp->data);
    temp = temp->next;
  }
  return checkPalindrome(arr);
}

Node *getMid(Node *head)
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

bool isPalindrom(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return true;
  }
  Node *middle = getMid(head);
  Node *temp = middle->next;
  middle->next = reverse(temp);
  Node *head1 = head;
  Node *head2 = middle->next;
  while (head2 != NULL)
  {
    if (head1->data != head2->data)
    {
      return false;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  temp = middle->next;
  middle->next = reverse(temp);

  return true;
}

int main()
{

  Node *node1 = new Node(1);
  Node *head = node1;
  Node *tail = node1;
  insertAtTail(tail, 2);
  insertAtTail(tail, 2);
  insertAtTail(tail, 1);
  print(head);
  if (isPalindrom(head))
  {
    cout << "This is a Palindrome" << endl;
  }
  else
  {
    cout << "This is not a Palindrome" << endl;
  }
}