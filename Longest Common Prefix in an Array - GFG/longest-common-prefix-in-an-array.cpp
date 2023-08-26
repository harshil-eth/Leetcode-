//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

struct Node {
    public:
    Node* links[26];
    bool fl = false;
    int cp = 0, ew = 0;

    bool containKey(char ch) {
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    Node* get(char ch) {
        return links[ch-'a'];
    }
    bool isEnd() {
        return fl;
    }
    void setEnd() {
        fl = true;
    }
    void incPre() {
        cp++;
    }
    int getPre() {
        return cp;
    }
};  

class Trie {
    public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incPre();
        }
        node->setEnd();
    }

    int countStartingWith(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPre();
    }
};  

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        Trie trie;
        for(int i=0; i<n; i++) {
            trie.insert(arr[i]);
        }
        
        int mini = 1e9;
        string s="";
        for(int i=0; i<n; i++) {
            if(arr[i].size() < mini) {
                s = arr[i];
                mini = arr[i].size();
            }
        }
        
        string res = "";
        for(auto it: s) {
            res += it;
            if(trie.countStartingWith(res) != n) {
                res.pop_back();
                return res.size() == 0 ? "-1" : res;
            }
        }
        
        return s.size() == 0 ? "-1" : s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends