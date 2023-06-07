//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    
    long long f(int ind, int buy, vector<long long> &prices, vector<vector<int>> &dp, int fee) {
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy]; 
        
        int profit =0;
        if(buy) {
            profit = max(-prices[ind] + f(ind+1, 0, prices, dp, fee), f(ind+1, 1, prices, dp, fee));
        }   
        else {
            profit = max( - fee +prices[ind] + f(ind+1, 1, prices, dp, fee), f(ind+1, 0, prices, dp, fee));
        }
        
        return dp[ind][buy] = profit;
    }
    
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, dp, fee);
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
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends