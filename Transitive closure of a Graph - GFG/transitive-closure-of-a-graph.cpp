//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
        // code here
        
        // dikajsta
        vector<int> adj[n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(graph[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<vector<int>> ans(n, vector<int> (n, 0));
        
        for(int i=0; i<n; i++) {
            // consider i as src node now, and try to go everywhere
            
            queue<pair<int, int>> q;
            q.push({0, i});
            
            vector<int> dist(n, 1e9);
            dist[i] = 0;
            
            while(!q.empty()) {
                auto it = q.front();
                q.pop();
                int dis = it.first;
                int node = it.second;
                
                for(auto it: adj[node]) {
                    int adjnode = it;
                    if(1 + dis < dist[adjnode]) {
                        dist[adjnode] = 1 + dis;
                        q.push({dist[adjnode], adjnode});
                    }
                }
            }
            
            for(int j=0; j<n; j++) {
                if(dist[j] != 1e9) {
                    ans[i][j] = 1;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends