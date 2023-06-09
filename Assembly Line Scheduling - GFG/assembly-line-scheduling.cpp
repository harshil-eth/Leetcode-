//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++



class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x){
      //Code Here
      int n=a[0].size();
      vector<int> res1(n), res2(n);
      
      res1[0] = e[0] + a[0][0];
      res2[0] = e[1] + a[1][0];
      
      for(int i=1;i<n;i++) {
          
          res1[i] = min( res1[i-1] + a[0][i], res2[i-1] + t[1][i] + a[0][i]);
          res2[i] = min( res2[i-1] + a[1][i], res1[i-1] + t[0][i] + a[1][i]);
      }
      
      return min( res1[n-1] + x[0], res2[n-1] + x[1]);
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends