//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];    
    
        if(s[i] == t[j] && i!=j)
            return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);
        else 
            return dp[i][j] = max( f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
        
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		  
		    string a=str, b=str;
		    int n=a.size();
		    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
		    int l = f(n-1, n-1,a,b, dp);
		    return l;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends