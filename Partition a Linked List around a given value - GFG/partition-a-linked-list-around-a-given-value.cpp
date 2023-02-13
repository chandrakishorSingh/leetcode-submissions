//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    vector<Node*> less;
    vector<Node*> equal;
    vector<Node*> greater;
    
    Node* it = head;
    // return it;
    while (it != NULL) {
        if (it->data < x) {
            less.push_back(it);
        } else if (it->data > x) {
            greater.push_back(it);
        } else {
            equal.push_back(it);
        }
        
        it = it->next;
    }
    
    Node* current = new Node(-1);
    Node* dummyNode = current;
    for (int i = 0; i < less.size(); i++) {
        current->next = less[i];
        current = less[i];
    }
    for (int i = 0; i < equal.size(); i++) {
        current->next = equal[i];
        current = equal[i];
    }
    for (int i = 0; i < greater.size(); i++) {
        current->next = greater[i];
        current = greater[i];
    }
    current->next = NULL;
    
    
    return dummyNode->next;
}