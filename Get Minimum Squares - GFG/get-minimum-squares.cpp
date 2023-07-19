//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    int f(int n, vector<int> &dp) {
        if(n == 0) 
            return 0;
        if(dp[n] != -1) 
            return dp[n];
            
        int ans = n;
        for(int i=1; i*i<=n; i++) {
            ans = min(ans, 1 + f(n-i*i, dp));
        }
        return dp[n] = ans;
    }

	public:
	int MinSquares(int n)
	{
	    // Code here
	    vector<int> dp(n+1, -1);
	    return f(n, dp);
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends