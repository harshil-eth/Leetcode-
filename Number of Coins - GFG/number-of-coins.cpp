//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    
    int f(int ind, int sum, int coins[], vector<vector<int>> &dp) {
        if(ind == 0) {
            if(sum%coins[ind] == 0) return sum/coins[ind];
            else return 1e9;
        }
        
        if(dp[ind][sum] != -1) 
            return dp[ind][sum];

        int notpick = 0 + f(ind-1, sum, coins, dp);
        int pick = 1e9;
        if(coins[ind] <= sum) {
            pick = 1 + f(ind, sum-coins[ind], coins, dp);
        }

        return dp[ind][sum] = min(pick, notpick);
    }

	public:
	int minCoins(int coins[], int n, int t) 
	{ 
	    // Your code goes here
	   // int n=coins.size();
	   vector<vector<int>> dp(n, vector<int> (t+1, -1));
        int ans = f(n-1, t, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends