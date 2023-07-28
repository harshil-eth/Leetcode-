//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    void f(int i, int j, string &path, vector<string> &res, vector<vector<int>> &g, int n) {
        
        if(i == n-1 && j == n-1) {
            res.push_back(path);
            return;
        }
        
        if(i+1 < n &&  g[i+1][j] == 1) {
            path.push_back('D');
            g[i][j] = 0;
            f(i+1, j, path, res, g, n);
            path.pop_back();
            g[i][j] = 1;
        }
        
        if(j-1 >= 0 &&  g[i][j-1] == 1) {
            path.push_back('L');
            g[i][j] = 0;
            f(i, j-1, path, res, g, n);
            path.pop_back();
            g[i][j] = 1;
        }
        
        if(j+1 < n &&  g[i][j+1] == 1) {
            path.push_back('R');
            g[i][j] = 0;
            f(i, j+1, path, res, g, n);
            path.pop_back();
            g[i][j] = 1;
        }
        
        if(i-1 >= 0 &&  g[i-1][j] == 1) {
            path.push_back('U');
            g[i][j] = 0;
            f(i-1, j, path, res, g, n);
            path.pop_back();
            g[i][j] = 1;
        }
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &g, int n) {
        // Your code goes here
        vector<string> res;
        if(g[0][0] == 0) return {};
        
        string path;
        f(0, 0, path, res, g, n);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends