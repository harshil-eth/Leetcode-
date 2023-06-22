//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	vector<pair<int, int>> find_start(char f, vector<vector<char> >& board) {
        vector<pair<int, int>> ans;
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j  < board[0].size(); ++j) {
                if(f == board[i][j]) ans.push_back({i, j});
            }
        }
        if(ans.empty())
        return {{-1, -1}};
        
        return ans;
    }
    
    bool dfs(vector<vector<char> >& board, string dic, vector<vector<int>> &vis
    , int index, int str, int end) {
        if(index == dic.size()) return true;
        // cout << str << " " << end << " " << dic[index-1] << endl;
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                if(i == 0 and j == 0) continue;
                int nr = str + i;
                int nc = end + j;
                if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc]
                and board[nr][nc] == dic[index]) {
                    vis[str][end] = 1;
                    bool temp = dfs(board, dic, vis, index+1, nr, nc);
                    vis[str][end] = 0;
                    if(temp) return true;
                    
                }
            }
        }
        
        return false;
        
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<string> ans;
	    int n = board.size();
	    int m = board[0].size();
	    
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    sort(dictionary.begin(), dictionary.end());
	    for(auto dic:dictionary) {
	        vector<pair<int, int>> strIndex = find_start(dic[0], board);
            // pair<int, int> strIndex[] = find_start(dic[0], board);
            
            if(strIndex[0].first == -1) continue;
            
            else {
                for(auto mat:strIndex) {
                    bool check = dfs(board, dic, vis, 1, mat.first, mat.second);
                    if(check) {
                        ans.push_back(dic);
                        break;
                    }
                }
            }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends