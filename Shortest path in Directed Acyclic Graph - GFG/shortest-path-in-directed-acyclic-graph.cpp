//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
private:
    void topo(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[]) {
        vis[node] = 1;
        for(auto it:adj[node]) {
            int v = it.first;
            if(!vis[v]) {
                topo(v, vis, st, adj);
            }
        }
        
        st.push(node);
    }

  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[n];
        for(auto it:edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> vis(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                topo(i, vis, st, adj);
            }
        }
        
        //stack is ready
        
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(dist[node] != 1e9) {
                for(auto it:adj[node]) {
                    int edgeW = it.second;
                    int adjNode = it.first;
                    
                    if(dist[node]+ edgeW < dist[adjNode]) {
                        dist[adjNode] = dist[node] + edgeW;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
       
       
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends