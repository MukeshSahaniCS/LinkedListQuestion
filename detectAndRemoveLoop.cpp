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

void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{

    Node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deleteNode(Node *&tail, int value)
{

    // empty list
    if (tail == NULL)
    {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else
    {
        // non-empty

        // assuming that "value" is present in the Linked List
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node Linked List
        if (curr == prev)
        {
            tail = NULL;
        }

        //>=2 Node linked list
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    return false;
}

bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {

        if (visited[temp] == true)
        {
            cout << "Present on element " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floyedDetectLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "Present on element " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floyedDetectLoop(head);
    if (intersection == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;
    if (startOfLoop == NULL)
    {
        return head;
    }
    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);

    // if(isCircular(tail)){
    //     cout<<"Linked List is Circular in nature"<<endl;
    // }
    // else{
    //     cout<<"Linked List is not Circular"<<endl;
    // }

    // if(detectLoop(tail)){
    //     cout<<"Cycle is present"<<endl;

    // }
    // else{
    //     cout<<"Cycle is not present"<<endl;
    // }
    // if(floyedDetectLoop(tail)!=NULL){
    //     cout<<"Cycle is present"<<endl;

    // }
    // else{
    //     cout<<"Cycle is not present"<<endl;
    // }
    Node *loop = getStartingNode(tail);
    cout << "Loop starting at " << loop->data << endl;
    removeLoop(tail);
    print(tail);
}