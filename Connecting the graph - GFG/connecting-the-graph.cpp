//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
public:
    vector<int> parent,rank,size;
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
        rank.resize(n+1,0);
    }

    int findUpar(int node) {
        if(node == parent[node]) 
            return node;
        
        return parent[node] = findUpar(parent[node]);
    }

    void unionbyRank(int u, int v) {
        int ul_u = findUpar(u); //ul_u -> ultimate parent of u
        int ul_v = findUpar(v); 
        if(ul_u == ul_v) return;

        if(rank[ul_u] < rank[ul_v]) {
            parent[ul_u] = ul_v;
        }
        else if(rank[ul_v] < rank[ul_u]) {
            parent[ul_v] = ul_u;
        }
        else {
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        }
    }

    void unionbySize(int u, int v) {
        int ul_u = findUpar(u); //ul_u -> ultimate parent of u
        int ul_v = findUpar(v); 
        if(ul_u == ul_v) return;
        if(size[ul_u] < size[ul_v]) {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
        else {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int cntExtra=0;
        for(auto it:edge) {
            int u = it[0];
            int v = it[1];
            if(ds.findUpar(u) == ds.findUpar(v)) {
                cntExtra++;
            }
            else {
                ds.unionbySize(u,v);
            }
        }
        int connComponents = 0;
        for(int i=0;i<n;i++) {
            if(ds.parent[i] == i) connComponents++;
        }
        int ans = connComponents - 1;
        
        if(cntExtra >= ans) return ans;
        else return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends