//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int mod= 1e9+7;
    #define ll long long int
    private:
    ll f(int n, vector<ll> &dp) {
        
        if(n <= 1) 
            return 1;
        if(dp[n] != -1) 
            return dp[n];
            
        ll ans = 0;
        for(ll i=1; i<=n; i++) {
            ans = ans%mod + (f(i-1, dp) * f(n-i, dp));
            ans %= mod;
        }
        
        return dp[n] = ans%mod;
    }
    
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        // basically unique bst with 5 nodes
        vector<ll> dp(n+1, -1);
        return f(n, dp)%mod;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends