//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        if(S == 0 && N>1) return "-1";
        int digit = 0, sum = 0, firstD = 9;
        string ans = "";
        while(digit<N){
           sum += firstD;
           if(S - sum >= 0){
               ans += firstD + '0';
               digit++;
           }else{
               sum -= firstD;
               firstD--;
           }
            
        }
        if(digit == N && S == sum) return ans;
        return "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends