//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    long long int f(int ind, int coins[], int t, vector<vector<long long int>> &dp) {
        if(ind == 0) {
            return t % coins[ind] == 0;
        }
        if(dp[ind][t] != -1) {
            return dp[ind][t];
        }
        
        long long int notPick = f(ind-1, coins, t, dp);
        long long int pick = 0;
        if(coins[ind] <= t) {
            pick = f(ind, coins, t - coins[ind], dp);
        }
        
        return dp[ind][t] = pick + notPick;
        
    }
    
  public:
    long long int count(int coins[], int n, int sum) {

        // code here.
        vector<vector<long long int>> dp(n+1, vector<long long int> (sum+1, -1));
        return f(n-1, coins, sum, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends