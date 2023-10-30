//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&ini,vector<int>&final,int n)
	{
	    // Code here
	    queue<pair<int, pair<int, int> > > q;
	    vector<vector<int> > vis(n, vector<int> (n,0));
	    int srow = ini[0]-1, scol=ini[1]-1;
	    int erow = final[0]-1, ecol = final[1]-1;
	    q.push({0,{srow,scol}});
	    vis[srow][scol] = 1;
	    
	    while(!q.empty()) {
	        auto it = q.front();
	        q.pop();
	        int steps = it.first;
	        int row = it.second.first;
	        int col = it.second.second;
	        
	        if(row == erow && col == ecol) return steps;
	        
	        int delrow[] = {1,2,2,1,-1,-2,-2,-1};
	        int delcol[] = {2,1,-1,-2,-2,-1,1,2};
	        
	        for(int i=0;i<8;i++) {
	            int nrow = row + delrow[i];
	            int ncol = col + delcol[i];
	            
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol]) {
	                vis[nrow][ncol] = 1;
	               // if(nrow == erow && ncol == ecol) return steps+1;
	                q.push({steps+1,{nrow,ncol}});
	            }
	        }
	    }
	    
	    
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends