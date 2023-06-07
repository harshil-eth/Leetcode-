//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  private:
  
    // int f(int ind, int k, int arr[]) {
    //     if(ind == 0) return (arr[0] == k);
    //     if(k == 0) return 1;
        
    //     bool notTake = f(ind-1, k, arr);
    //     bool take = false;
    //     if(arr[ind] <= k) 
    //         take = f(ind-1, k-arr[ind], arr);
            
    //     return notTake | take;
    // }

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++) sum += arr[i];
	   // return f(n-1, totsum, arr);
	    
	    vector<vector<int>> dp(n, vector<int> (sum+1, 0));
	   for(int i=0;i<n;i++) {
	       dp[i][0] = 1;
	   }
	   if(arr[0] <= sum) dp[0][arr[0]] = 1;
	   
	   for(int i=1;i<n;i++) {
	       for(int j=1;j<sum+1;j++) {
	           bool notTake = dp[i-1][j];
	           bool take = false;
	           if(arr[i] <= j) 
	            take = dp[i-1][j-arr[i]];
	            
	            dp[i][j] = take | notTake;
	       }
	   }
	   
	   int mini = 1e9;
	   for(int j=0;j<sum+1;j++) {
	       if(dp[n-1][j] == 1) {
	           mini = min(mini, abs(sum-2*j));
	       }
	   }
	   
	   return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends