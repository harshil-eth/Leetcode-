//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        // code here
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));
        //need not to write the base case as they are already worth 0 stated while declaring

        for(int ind=n-1;ind>=0;ind--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=k; cap++) { //starting cap with 1 as 0 was for base case
                    int profit = 0;

                    if(buy) {
                        profit = max(-prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]); 
                    }
                    else {
                        profit = max(+prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                    }

                    dp[ind][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][k];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends