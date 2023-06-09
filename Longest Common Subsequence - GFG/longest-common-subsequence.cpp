//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    private:
    
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];    
    
        if(s[i] == t[j])
            return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);
        else 
            return dp[i][j] = max( f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
        
    }
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return f(n-1, m-1, s1, s2, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends