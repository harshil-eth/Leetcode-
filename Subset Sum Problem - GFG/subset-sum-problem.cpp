//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
private:

    int f(int ind, int k, vector<int> arr, vector<vector<int>> &dp) {
        if(ind == 0) return (arr[0] == k);
        if(k == 0) return 1;
        if(dp[ind][k] != -1) return dp[ind][k];
        
        bool notTake = f(ind-1, k, arr, dp);
        bool take = false;
        if(arr[ind] <= k) 
            take = f(ind-1, k-arr[ind], arr, dp);
            
        return dp[ind][k] = notTake | take;
    }

public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
    //     int totsum=0;
	   // for(int i=0;i<arr.size();i++) totsum += arr[i];
	    vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
	    return f(n-1, sum, arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends