//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:

    int f(int ind, int arr[], int k, vector<vector<int>> &dp) {
        if(ind == 0) {
            return arr[0] == k;
        }
        if(dp[ind][k] != -1) return dp[ind][k];
        int notPick = f(ind-1, arr, k, dp);
        int pick = 0;
        if(arr[ind] <= k) 
            pick = f(ind-1, arr, k-arr[ind], dp);
            
        return dp[ind][k] = pick | notPick;
    }
    
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        
        if(sum % 2) return 0;
        int k  =sum /2;
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return f(n-1, arr, k, dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends