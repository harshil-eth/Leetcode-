//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    string findString(int a, unordered_map<int, string> &mp) {
        if(mp.find(a) != mp.end())
            return mp[a];
        
        string ans="";
        ans += mp[(a/10)*10];
        ans += " ";
        ans += mp[a%10];
        
        return ans;
    }
    
    string convertToWords(long n) {
        // code here
        unordered_map<int, string> mp;
        
        mp[0] = "";
        mp[1] = "one";
        mp[2] = "two";
        mp[3] = "three";
        mp[4] = "four";
        mp[5] = "five";
        mp[6] = "six";
        mp[7] = "seven";
        mp[8] = "eight";
        mp[9] = "nine";
        
        mp[10] = "ten";
        mp[20] = "twenty";
        mp[30] = "thirty";
        mp[40] = "forty";
        mp[50] = "fifty";
        mp[60] = "sixty";
        mp[70] = "seventy";
        mp[80] = "eighty";
        mp[90] = "ninety";
        
        mp[11] = "eleven";
        mp[12] = "twelve";
        mp[13] = "thirteen";
        mp[14] = "fourteen";
        mp[15] = "fifteen";
        mp[16] = "sixteen";
        mp[17] = "seventeen";
        mp[18] = "eighteen";
        mp[19] = "nineteen";
        
        string ans="";
        int x;
        bool flag = false;
        
        x = n/10000000;
        n = n%10000000;
        
        if(x > 0) {
            ans += findString(x, mp);
            ans += " crore ";
            flag=true;
        }

        x = n/100000;
        n = n%100000;    

        
        if(x > 0) {
            ans+= findString(x, mp);
            ans += " lakh ";    
            flag=true;
        }

        
        x = n/1000;
        n = n%1000;
        
        if(x > 0) {
            ans += findString(x, mp);
            ans += " thousand ";
            flag=true;
        }

        
        x = n/100;
        n = n%100;
        
        if(x > 0) {
            ans += findString(x, mp);
            ans += " hundred ";
            flag=true;
        }
        
        if(n > 0) {
            if(flag)
                ans += "and ";
            ans += findString(n, mp);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends