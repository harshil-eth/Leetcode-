//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
    private:
    
    int f(int ind, vector<int> &arr, vector<int> &dp) {
        
        if(ind<0) return 0;
        if(ind == 0) return arr[0];
        if(ind == 1) return arr[1] + arr[0];
        if(dp[ind] != -1) return dp[ind];
        
        int op1 = arr[ind] + arr[ind-1] + f(ind-3, arr, dp);
        int op2 = arr[ind] + f(ind-2, arr, dp);
        int op3 = f(ind-1, arr, dp);
        return dp[ind] = max(op1, max(op2, op3));
    }
    
  public:
  int findMaxSum(vector<int>& arr){
      //Code Here
      int n=arr.size();
      vector<int> dp(n+1, -1);
      return f(n-1, arr, dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends