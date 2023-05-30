//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:

    bool f(int i, int j, vector<vector<char>>& board, string &word, int ind) {
        if(ind >= word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[ind]) return false;
        
        board[i][j] = '*';
        ind++;
        
        bool check = f(i,j+1,board, word, ind) || f(i+1,j,board, word, ind) || f(i,j-1,board, word, ind) || f(i-1,j,board, word, ind);
        
        //backtrack
        board[i][j] = word[ind-1];
        return check;
    }

public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size(), m=board[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == word[0]) {
                    bool ans = f(i, j, board, word, 0);
                    if(ans) return ans;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends