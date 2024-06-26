//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:

    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) {
            return dp[i][j] = 0 + f(i-1, j-1, s, t, dp);
        }
        else {
            return dp[i][j] = 1 + min( f(i-1, j, s, t, dp), min( f(i-1, j-1, s,t, dp), f(i, j-1, s, t, dp)));
        }
    }

  public:
    int editDistance(string s, string t) {
        // Code here
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n-1, m-1, s, t, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends