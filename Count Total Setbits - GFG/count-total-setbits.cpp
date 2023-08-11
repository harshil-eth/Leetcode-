//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    int f(int n) {
        int x = 0;
        while(1<<x <= n) {
            x++;
        }
        return x-1;
    }

public:
    int countBits(int n){
        // code here
        int ans = 0;
        int x = f(n);
        
        if(n == 0) return 0;
        
        int a = (x* (1<<x-1));
        int b = n - (1<<x) + 1;
        
        int rest = n - (1<<x);
        
        ans = a + b + countBits(rest);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends