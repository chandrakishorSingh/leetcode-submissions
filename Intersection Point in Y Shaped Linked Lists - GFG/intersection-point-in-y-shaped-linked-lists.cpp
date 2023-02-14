//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

int getLength(Node* head) {
    int result = 0;
    
    while (head != NULL) {
        result++;
        head = head->next;
    }
    
    return result;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    if (len1 > len2) {
        swap(head1, head2);
        swap(len1, len2);
    }
    
    // cout << len1 << " " << len2 << endl;
    
    int diff = len2 - len1;
    for (int i = 0; i < diff; i++) {
        head2 = head2->next;
    }
    
    int result = -1;
    while (head1 != NULL) {
        // cout << head1->data << " " << head2->data << endl;
        if (head1 == head2) {
            result = head1->data;
            break;
        }
        
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return result;
}
// 5 3
// 10 3
// 15 6
// 30 9
// -1
