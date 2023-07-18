//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
  #define ll long long int
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n=s.size();
        ll mod = 1e9+7;
        //pepcoding se hi sab hai
        
        unordered_map<char, int> mp; // stores last occurenece
        vector<ll> dp(n+1);
        dp[0] = 1;

        for(int i=1; i<n+1; i++) {
            
            dp[i] = (2*dp[i-1])%mod;

            char ch = s[i-1];
            if(mp.find(ch) != mp.end()) {
                int ind = mp[ch];
                dp[i] = (dp[i] - dp[ind-1])%mod;
            }

            mp[ch] = i;
        }
        ll res = (dp[n])%mod; // empty not counting
        return res < 0 ? res+mod : res;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends