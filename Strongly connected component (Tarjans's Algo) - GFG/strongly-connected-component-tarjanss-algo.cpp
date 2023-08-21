//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
        vis[node] = 1;
        for(auto i:adj[node]) {
            if(!vis[i]) {
                dfs(i,vis,adj,st);
            }
        }
        
        st.push(node);
    }
    
    void dfs3(int node, vector<int> &vis, vector<vector<int>> &adjT, vector<int> &temp) {
        vis[node] = 1;
        temp.push_back(node);
        for(auto it:adjT[node]) {
            if(!vis[it]) {
                dfs3(it,vis,adjT, temp);
            }
        }
    }
    
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfs(i,vis,adj,st);
            }
        }
        
        //step2 -> reverse graph
        vector<vector<int>> adjT(V);
        for(int i=0;i<V;i++) {
            vis[i] = 0;
            for(auto it:adj[i]) {
                //i -> it abhi ye hai
                //isko it -> i mai convert karn hai
                adjT[it].push_back(i);
            }
        }
        
        //step3 do a dfs
        int scc=0;
        vector<vector<int>> ans;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                scc++;
                vector<int> temp;
                dfs3(node,vis,adjT, temp);
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends