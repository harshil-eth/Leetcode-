//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	   // vector<pair<int, int>> adj[n];
	   // for(auto it:edges) {
	   //     adj[it[0]].push_back({it[1], it[2]});
	   // }
	    
	    vector<int> dist(n, 1e9);
	    dist[0] = 0;
	    for(int i=0; i<n-1; i++) {
	        for(auto it: edges) {
	            int u = it[0];
	            int v = it[1];
	            int wt = it[2];
	            
	            if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
	                dist[v] = wt + dist[u];
	            }
	        }
	    }
	    
	    for(auto it:edges) {
            int u=it[0], v=it[1], wt=it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return 1;
            }
        }
        
        return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends