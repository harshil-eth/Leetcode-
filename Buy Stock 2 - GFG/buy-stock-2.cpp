//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    
    long long f(int ind, int buy, vector<long long> &prices, vector<vector<int>> &dp) {
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy]; 
        
        int profit =0;
        if(buy) {
            profit = max(-prices[ind] + f(ind+1, 0, prices, dp), f(ind+1, 1, prices, dp));
        }   
        else {
            profit = max(+prices[ind] + f(ind+1, 1, prices, dp), f(ind+1, 0, prices, dp));
        }
        
        return dp[ind][buy] = profit;
    }
    
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends