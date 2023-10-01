//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void f(int ind, string &s, string ds, vector<string> &ans, unordered_set<string> &st) {
        
        if(ind >= s.size()) {
            ds.pop_back();
            ans.push_back(ds);
            return;
        }
        
        string temp = "";
        for(int i=ind; i<s.size(); i++) {
            temp += s[i];
            if(st.find(temp) != st.end()) {
                f(i+1, s, ds + temp + " ", ans, st);
            }
        }
    }

public:
    vector<string> wordBreak(int n, vector<string>& dic, string s)
    {
        // code here
        unordered_set<string> st(dic.begin(), dic.end());
        
        vector<string> ans;
        string ds="";
        f(0, s, ds, ans, st);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends