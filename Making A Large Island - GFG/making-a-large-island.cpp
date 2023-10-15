//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class dsu {
  public:
  vector<int> parent, size;
  dsu (int n) {
      parent.resize(n+1);
      size.resize(n+1, 1);
      for(int i=0; i<=n; i++) parent[i] = i;
  }
  
  int findUpar(int node) {
      if(node == parent[node]) {
          return node;
      }
      return parent[node] = findUpar(parent[node]);
  }
  
  void unionbysize(int u, int v) {
      int uu = findUpar(u), vv = findUpar(v);
      if(uu == vv) return;
      
      if(size[vv] <= size[uu]) {
          parent[vv] = uu;
          size[uu] += size[vv];
      }
      else {
          parent[uu] = vv;
          size[vv] += size[uu];
      }
  }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int n = grid.size();
        dsu ds(n*n);
        
        //connecting all 1's
        for(int r=0; r<n; r++) {
            for(int c=0; c<n; c++) {
                if(grid[r][c] == 0) continue;
                
                int dr[] = {0,1,0,-1};
                int dc[] = {1,0,-1,0};
                
                for(int i =0; i<4; i++) {
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1) {
                        int node = r*n + c;
                        int newnode = nr*n + nc;
                        if(ds.findUpar(node) != ds.findUpar(newnode)) {
                            ds.unionbysize(node, newnode);
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        //checking for each 0;
        for(int r=0; r<n; r++) {
            for(int c=0; c<n; c++) {
                if(grid[r][c] == 1) continue;
                
                int dr[] = {0,1,0,-1};
                int dc[] = {1,0,-1,0};
                set<int> components;
                
                for(int i =0; i<4; i++) {
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1) {
                        int node = r*n + c;
                        int newnode = nr*n + nc;
                        components.insert(ds.findUpar(newnode));
                    }
                }
                
                int size = 0;
                for(auto it: components) {
                    size += ds.size[it];
                }
                
                ans = max(ans, size+1);
            }
        }
        
        
        // what if all 1 ones
        bool fl = 1;
        for(int i=0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0) fl = 0;
            }
        }
        
        if(fl == 1) return n*n;
        else return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends