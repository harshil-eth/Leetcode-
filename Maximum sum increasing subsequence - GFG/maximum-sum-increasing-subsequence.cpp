//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n);
	    for(int i=0;i<n;i++) dp[i] = arr[i];
	    
	    for(int i=0;i<n;i++) {
	        for(int prev=0; prev<i; prev++) {
	            
	            if(arr[i] > arr[prev]) {
	                dp[i] = max(dp[i], dp[prev] + arr[i]);    
	            }
	        }
	    }
	    
	    int mx=-1e9;
	    for(int i=0;i<n;i++) {
	        mx= max(mx, dp[i]);
	    }
	    return mx;
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends