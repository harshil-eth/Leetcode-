//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
private:
    bool f(int ind, string &s, unordered_set<string> &st) {
        if(ind >= s.size()) 
            return 1;
            
        string temp = "";
        bool ans = 0;
        for(int i=ind; i<s.size(); i++) {
            temp+=s[i];
            if(st.find(temp) != st.end()) {
                ans |= f(i+1, s, st);
            }
        }
        
        return ans;
    }

public:
    int wordBreak(string s, vector<string> &dic) {
        //code here
        unordered_set<string> st(dic.begin(), dic.end());
        
        bool ans = f(0, s, st);
        if(ans == 1) return 1;
        else return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends