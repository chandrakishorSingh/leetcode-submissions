//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
public:
    
    int findLoopLength(Node* node) {
        int count = 1;
        auto it = node->next;
        
        while (it != node) {
            count++;
            it = it->next;
        }
        
        return count;
    }
    
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        auto slow = head;
        auto fast = head->next;
        bool isLoopFound = false;
        
        while (slow != NULL && fast != NULL) {
            if (slow == fast) {
                isLoopFound = true;
                break;
            }
            
            slow = slow->next;
            fast = fast->next == NULL ? NULL : fast->next->next;
        }
        
        if (!isLoopFound) {
            return;
        }
        
        // cout << "2" << endl;
        
        int loopLength = findLoopLength(slow);
        
        // cout << loopLength << endl;
        
        auto it1 = head;
        Node* prev = NULL;
        for (int i = 0; i < loopLength; i++) {
            prev = it1;
            it1 = it1->next;
        }
        
        // cout << "1" << endl;
        
        auto it2 = head;
        while (it1 != it2) {
            prev = it1;
            it1 = it1->next;
            it2 = it2->next;
        }
        
        prev->next = NULL;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends