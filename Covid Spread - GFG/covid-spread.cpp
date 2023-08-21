//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }
        
        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
            
                int dr[] = {0,1,0,-1};
                int dc[] = {1,0,-1,0};
                
                for(int i=0; i<4; i++) {
                    int nr = r+dr[i];
                    int nc= c+dc[i];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1) {
                        // dfs(nr, nc, vis, grid, cnt);
                        q.push({nr, nc});
                        grid[nr][nc] = -1;
                    }
                }
            }
            
            lvl++;
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return lvl-1;
        //code here
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends