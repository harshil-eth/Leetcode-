//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int timer = 1;
private:
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, int tin[], int low[], 
                    vector<vector<int>> &bridges) {

        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it:adj[node]) {
            if(it == parent) continue;
            if(!vis[it]) {
                dfs(it, node, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        //adj list is mdade
        vector<int> vis(V,0);
        int tin[V];
        int low[V];
        vector<vector<int>> bridges;
        
        for(int i=0; i<V;i++) {
            dfs(i, -1, adj, vis, tin, low, bridges);
        }
        
        vector<int> to_check;
        to_check.push_back(c);
        to_check.push_back(d);
        
        vector<int> to_check2;
        to_check2.push_back(d);
        to_check2.push_back(c);
        
        for(int i=0; i<bridges.size(); i++) {
            vector<int> temp = bridges[i];
            if(temp == to_check) return true;  
            if(temp == to_check2) return true;  
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends