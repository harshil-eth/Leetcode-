//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool isPrime(long n) {
        if(n == 1)return false;
        for(int i=2;i<=sqrt(n);i++) {
            if(n%i == 0) return false;
        }
        return true;
    }
    int solve(int num1,int num2)
    {   
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        vector<int>vis(1e5,0);
        
        queue<pair<string,int>>q;
        q.push({s1,0});
        
        while(!q.empty()) {
            string s = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            vis[stoi(s)] = 1;
            
            if(s == s2) return steps;
            
            for(int i=0;i<s.size();i++) {
                char ch = s[i];
                for(int j=0;j<10;j++){
                    if(i==0 and j==0)continue;
                    s[i] = char(j+'0');
                    int num = stoi(s);
                    if(isPrime(num) and !vis[num]) {
                        q.push({s,steps+1});
                        vis[num] = 1;
                    }
                }
                s[i] = ch;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends