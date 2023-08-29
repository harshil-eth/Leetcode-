//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    private:
    Node* revll(Node* &head) {
        Node* curr = head;
        Node* next = NULL, *prev = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node* t = head;
        Node* hh = revll(head);
        
        int maxi = -1e9;
        Node* anshead = new Node(-1);
        Node* ans = anshead;
        
        Node* curr = hh;
        while(curr) {
            if(curr->data >= maxi) {
                ans->next = new Node(curr->data);
                ans = ans->next;
                maxi = max(maxi, curr->data);
            }
            curr = curr->next;
        }
        
        anshead = anshead->next;
        Node* finalans = revll(anshead);
        return finalans;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends