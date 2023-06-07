//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp) {
//         if(ind == prices.size()) return 0;
//         if(cap == 0) return 0;
//         if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap]; 
        
//         int profit =0;
//         if(buy) {
//             profit = max(-prices[ind] + f(ind+1, 0, cap, prices, dp), f(ind+1, 1, cap, prices, dp));
//         }   
//         else {
//             profit = max(+prices[ind] + f(ind+1, 1, cap-1, prices, dp), f(ind+1, 0, cap, prices, dp));
//         }
        
//         return dp[ind][buy][cap] = profit;
//     }

int maxProfit(vector<int>&prices){
    //Write your code here..
    int n=prices.size();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    // return f(0, 1, 2, prices, dp);
    
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
        //need not to write the base case as they are already worth 0 stated while declaring

        for(int ind=n-1;ind>=0;ind--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=2; cap++) { //starting cap with 1 as 0 was for base case
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

        return dp[0][1][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends