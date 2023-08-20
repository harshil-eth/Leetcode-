//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node (int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class cmp {
    public:
    bool operator() (const node* a, const node* b) {
        return a->data > b->data;
    }
};

class Solution
{
    private:
    void traverse(node* root, string temp, vector<string> &ans) {
        
        if(!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }
        
        traverse(root->left, temp+'0', ans);
        traverse(root->right, temp+'1', ans);
    }
    
	public:
		vector<string> huffmanCodes(string s,vector<int> f,int n)
		{
		    // Code here
		    priority_queue<node*, vector<node*>, cmp> pq;
		    
		    for(int i=0; i<n; i++) {
		        node* t = new node(f[i]);
		        pq.push(t);
		    }
		    
		    while(pq.size() > 1) {
		        auto left = pq.top();
		        pq.pop();
		        
		        auto right = pq.top();
		        pq.pop();
		      
		        node* newnode = new node(left->data + right->data);
		        newnode->left = left;
		        newnode->right = right;
		        pq.push(newnode);
		    }
		    
		    node* root = pq.top();
		    
		    vector<string> ans;
		    string temp = "";
		    traverse(root, temp, ans);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends