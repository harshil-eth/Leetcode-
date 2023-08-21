//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    int mod = 1e9+7;
    private:
    
    int f(int src, int dst, int k, vector<vector<int>> &graph, vector<vector<vector<int>>> &dp) {
        
        if(k == 0 && src == dst) return 1;
        if(k == 0) return 0;
        
        if(dp[src][dst][k] != -1) 
            return dp[src][dst][k];
    
        int ans= 0;
        for(int i=0; i<graph.size(); i++) {
            if(graph[src][i]) {
                ans = (ans%mod + f(i, dst, k-1, graph, dp)%mod)%mod; 
            }
        }
        
        return dp[src][dst][k] = ans%mod;
    }
    
  public:
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    // Code here
	    int n =graph.size();
	    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (k+1, -1)));
	    return f(u, v, k, graph, dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends