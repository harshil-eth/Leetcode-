//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
        
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    
    void dfs2(int node, int &cnt, int &sum, vector<int> adj[], vector<int> &vis) {
        
        vis[node] = 1;
        cnt++;
        sum += node;
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs2(it, cnt, sum, adj, vis);
            }
        }
    }
    
  public:
  long long largestSumCycle(int n, vector<int> edges)
  {
      // creating adj list
      vector<int> adj[n];
      for(int i=0; i<n; i++) {
          if(edges[i] != -1) {
              adj[i].push_back(edges[i]);
          }
      }
      
      // storing acc to finish time
      stack<int> st;
      vector<int> vis(n, 0);
      
      for(int i=0; i<n; i++) {
          if(!vis[i]) {
              dfs(i, adj, vis, st);
          }
      }
      
      // revreseing edges
      vector<int> adjt[n];
      for(int i=0; i<n; i++) {
          vis[i] = 0;
          for(auto it: adj[i]) {
              //phle i- >it thi edge
            //   ab it->i karni hai
            adjt[it].push_back(i);
          }
      }
      
      int ans = 0, scc = 0; // scc is count of scc
      int cnt, sum;
      while(!st.empty()) {
          int node = st.top();
          st.pop();
         
          if(!vis[node]) {
              
              scc++;
              cnt = 0;
              sum = 0;
                
              dfs2(node, cnt, sum, adjt, vis);
          }
          
          if(cnt > 1) {
              ans = max(ans, sum);
          }
      }
      
      if(scc == n) {
          return -1; // as no cycle is present
      }
      return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends