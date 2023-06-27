//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    private:
    void insertatTail(struct Node* &head, struct Node* &tail, int val) {
        
        struct Node* temp = new Node(val);
        tail->next = temp;
        tail = temp;
        
    }
    
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        set<int> st;
        struct Node* temp = head1;
        while(temp != NULL) {
            st.insert(temp->data);
            temp = temp->next;
        }
        temp = head2;
        while(temp != NULL) {
            st.insert(temp->data);
            temp = temp->next;
        }
        
        vector<int> res;
        for(auto it:st) {
            res.push_back(it);
        }
        
        if(res.size() == 0) return NULL;
        
        struct Node* head = new Node(res[0]);
        struct Node* tail = head;
        
        for(int i=1;i<res.size();i++) {
            insertatTail(head, tail, res[i]);
        }
        
        return head;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends