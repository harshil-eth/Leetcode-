//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class node {
    public:
    int key, val;
    node* next;
    node* prev;
    node (int key_, int val_) {
        this->key = key_;
        this->val = val_;
    }
};

class LRUCache
{
    private:

    public:
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> mp;

    void addnode(node* newnode) {
        node* t = head->next;
        newnode->next = t;
        newnode->prev = head;
        head->next = newnode;
        t->prev = newnode;
    }

    void deletenode(node* nodetodel) {
        node* delprev = nodetodel->prev;
        node* delnext = nodetodel->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        // code here
        head->next = tail;
        tail->prev = head;
        this->cap = capacity;
    }
    
    //Function to return value corresponding to the key.
    int GET(int keyy)
    {
        // your code here
        if(mp.find(keyy) != mp.end()) {
            node* resnode = mp[keyy];
            int res = resnode->val;
            mp.erase(keyy);
            deletenode(resnode);
            addnode(resnode);
            mp[keyy] = head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int keyy, int value)
    {
        // your code here   
        if(mp.find(keyy) != mp.end()) {
            node* existing = mp[keyy];
            mp.erase(keyy);
            deletenode(existing);
        }
        if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(keyy, value));
        mp[keyy] = head->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends