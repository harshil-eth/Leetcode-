//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    long long mod = 1e9+7;
    private:
    long long f(int n, vector<long long> &dp) {
            
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1)     
            return dp[n];
        
        long long op1 = f(n-1, dp)%mod;
        long long op2 = f(n-2, dp)%mod;
        long long op3 = f(n-3, dp)%mod;
        
        return dp[n] = (op1%mod + op2%mod + op3%mod)%mod;
    }
    
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        vector<long long> dp(n+1, -1);
        return f(n, dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends