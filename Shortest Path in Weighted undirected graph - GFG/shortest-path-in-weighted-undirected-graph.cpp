//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> res;
        vector<pair<int, int>> adj[n+1];
        for(auto it:edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        vector<int> dist(n+1, 1e9);
        dist[1] = 0;
        vector<int> parent(n+1);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
        
        while(!pq.empty()) {
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();
            
            for(auto it:adj[node]) {
                int adjNode = it.first;
                int edgeW = it.second;
                
                if(dist[node] + edgeW < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edgeW;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n] == 1e9) return {-1};
        
        int node = n;
        while(parent[node] != node) {
            res.push_back(node);
            node = parent[node];
        }
        
        res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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