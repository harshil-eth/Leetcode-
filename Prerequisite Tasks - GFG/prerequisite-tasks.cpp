//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    //basically cycle detect karni hai
	    // if cycle present return false
	    //and treat it as directed
	    
	    vector<int> adj[V];
	    for(auto it:prerequisites) {
	        adj[it.second].push_back(it.first);
	    }
	    
	    int indegree[V] = {0};
	    for(int i=0;i<V;i++) {
	        for(auto it:adj[i]) {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        
	        ans.push_back(node);
	        
	        for(auto it:adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    if(ans.size() == V) return true; // if topot sort was successful means no cycle present
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends