//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 1e9+7;
    private:
    
    int f(int ind, int curr, int arr[], int n, int sum, vector<vector<int>> &dp) {
        if(ind >= n) {
            if(curr == sum) return 1;
            else return 0;
        }
        if(curr > sum) return 0;
        if(dp[ind][curr] != -1) 
            return dp[ind][curr];
        
        curr += arr[ind];
        int take = f(ind+1, curr, arr, n, sum, dp)%mod;
        
        curr -= arr[ind];
        int notTake = f(ind+1, curr, arr, n, sum, dp)%mod;
        
        return dp[ind][curr] = (take + notTake)%mod;
    }
    
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        int curr = 0;
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return f(0, curr, arr, n, sum, dp)%mod;
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends