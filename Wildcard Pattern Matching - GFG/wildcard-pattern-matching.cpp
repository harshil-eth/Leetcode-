//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    bool f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

        if(i<0 && j<0) return 1;
        if(i<0 && j>=0) return 0;
        if(j<0 && i>=0) {
            for(int ii=0; ii<=i; ii++) {
                if(s[ii] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) 
            return dp[i][j];

        if(s[i] == t[j] || s[i] == '?') {
            return dp[i][j] = f(i-1, j-1, s, t, dp);
        }

        if(s[i] == '*') {
            return dp[i][j] = f(i-1, j, s, t, dp) | f(i, j-1, s, t, dp);
        }

        return dp[i][j] = false;
    }
    
  public:
/*You are required to complete this method*/
    int wildCard(string s,string t)
    {
        
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return f(n-1, m-1, s, t, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends