//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    int mod = 1e9+7;
    private:
    int f(int n, vector<int> &dp) {
        if(n <= 1) 
            return n;
        if(dp[n] != -1) 
            return dp[n];
            
        return dp[n] = (f(n-1, dp)%mod + f(n-2, dp)%mod)%mod;
    }
    
  public:
    int nthFibonacci(int n){
        vector<int> dp(n+1, -1);
        // code here
        return f(n, dp)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends