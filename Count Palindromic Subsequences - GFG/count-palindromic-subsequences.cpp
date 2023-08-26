//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    #define ll long long int
    int mod = 1e9+7;
    /*You are required to complete below method */
    long long int  countPS(string s)
    {
       //Your code here
       ll n = s.size();
        vector<vector<ll>> dp(n, vector<ll> (n, 0));
        // int count = 0;

        for(ll g=0; g<n; g++) {
            for(ll i=0, j=g; j<n; i++, j++) {

                if(g == 0) dp[i][j] = 1;
                else if(g == 1) {
                    dp[i][j] = (s[i] == s[j]) ? 3 : 2;
                }
                else {
                    if(s[i] == s[j]) {
                        dp[i][j] = (dp[i+1][j]%mod + dp[i][j-1]%mod + 1)%mod;
                    }
                    else {
                        dp[i][j] = dp[i+1][j]%mod + dp[i][j-1]%mod - dp[i+1][j-1]%mod;
                        dp[i][j] %= mod;
                    }
                }
                
                dp[i][j] = (dp[i][j] + mod)%mod;
            }
        }

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        // return count;
        return dp[0][n-1]%mod;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends