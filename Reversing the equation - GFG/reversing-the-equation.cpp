//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            int n=s.size();
            reverse(s.begin(), s.end());
            
            int prev=0;
            for(int i=0;i<n;i++) {
                if(s[i] == '/' || s[i] == '*' || s[i] == '-' || s[i] == '+') {
                    int j=i-1;
                    while(prev < j) {
                        swap(s[prev], s[j]);
                        prev++;
                        j--;
                    }
                    prev = i+1;
                }
            }
            //last number ke liye
            int j=n-1;
            while(prev < j) {
                swap(s[prev], s[j]);
                prev++;
                j--;
            }
            
            return s;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends