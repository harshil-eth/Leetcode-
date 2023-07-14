//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char s[], int n)
{
    //code here
    
    int c = 0;
    vector<vector<bool>> dp(n, vector<bool> (n, 0));
    
    for(int g = 0; g<n; g++) {
        
        for(int i=0, j=g; j<n; i++, j++) {
            if(g == 0 ){
                dp[i][j] = 1;
                
            }
            else if(g == 1) {
                dp[i][j] = s[i] == s[j];
            }
            else {
                if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;
                }
            }
            
            if(dp[i][j] == 1) c++;
            
            
        }
    }
    
    
    return c - n;
    
}