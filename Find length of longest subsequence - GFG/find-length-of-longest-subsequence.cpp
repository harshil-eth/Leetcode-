//{ Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
 
int maxSubsequenceSubstring(string x, string y, int n, int m);
 
// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

int solve(string &X, string &Y, int m, int n, vector < vector <int> > &dp) {
    if(m == 0 || n == 0)
        return 0;
    if(dp[m][n] != -1)
        return dp[m][n];
    int count1 = 0, count2, ans;
    if(X[m - 1] == Y[n - 1])
        count1 = 1 + solve(X, Y, m - 1, n - 1, dp);
    count2 = solve(X, Y, m - 1, n, dp);
    ans = max(count1, count2);
    return dp[m][n] = ans;
}

int maxSubsequenceSubstring(string X, string Y, int N, int M) {
    vector < vector <int> > dp(N + 1, vector <int>(M + 1, -1));
    int maxi = INT_MIN;
    for(int i = M - 1; i >= 0; i--) {
        maxi = max(maxi, solve(X, Y, N, i + 1, dp));
    }
    
    return maxi;
 
}