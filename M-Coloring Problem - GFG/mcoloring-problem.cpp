//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
private:
    bool isValid(int node, int color_todo, int color[], bool graph[101][101], int n) {
        //to check kya mai is node par color_todo kar sakta?
        
        for(int k=0; k<n; k++) {
            if(k != node && graph[node][k] == 1 && color[k] == color_todo) return false;
        }
        return true;
    }

    bool f(int node, int color[], bool graph[101][101], int n, int m) {
        if(node >= n) {
            return true;
        }
        
        for(int i=1; i<=m; i++) {
            if(isValid(node, i, color, graph, n)) {
                color[node] = i;
                if(f(node+1, color, graph, n, m) == true) return true;
                color[node] = 0;
            }
        }
        
        return false;
    }

public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        if(f(0, color, graph, n, m) == true) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends