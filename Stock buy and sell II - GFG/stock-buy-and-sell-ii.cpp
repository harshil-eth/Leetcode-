//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
    private:
    int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp) {
        if(ind >= prices.size()) 
            return 0;
        if(dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;
        if(buy) {
            profit = max(-prices[ind]+f(ind+1, 0, prices, dp), 
                            0 + f(ind+1, 1, prices, dp));
        }
        else {
            profit = max(+prices[ind]+f(ind+1, 1, prices, dp), 
                            0 + f(ind+1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }
    
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        // int n=prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, dp);

    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends