//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

struct Node {
    public:
    Node* links[2];
    bool fl = 0;
    
    bool containKey(int bit) {
        return links[bit] != NULL;
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
    bool isend() {
        return fl;
    }
    void setend() {
        fl = 1;
    }
};

class Trie {
    public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* node = root;
        for(int i=31; i>=0; i--) {
            int bit = (num & (1<<i)) ? 1 : 0;
            if(!node->containKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
        node->setend();
    }
    
    int getMax(int num) {
        Node* node = root;
        int ans = 0;
        for(int i=31; i>=0; i--) {
            int bit = (num & (1<<i)) ? 1 : 0;
            if(node->containKey(1^bit)) {
                ans |= (1<<i);
                node = node->get(1^bit);
            }
            else {
                node = node->get(bit);
            }
        }
        
        return ans;
    }
};

class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        //code here
        Trie trie;
        for(int i=0; i<n; i++) {
            trie.insert(arr[i]);
        }
        
        int maxi = 0;
        for(int i=0; i<n; i++) {
            maxi = max(maxi, trie.getMax(arr[i]));
        }
        
        return maxi;
    }
    
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends