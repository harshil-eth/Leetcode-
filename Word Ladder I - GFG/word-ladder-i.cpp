//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string sword, string tword, vector<string>& wordList) {
        // Code here
        queue<pair<string, int>> q;
        q.push({sword, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(sword);
        
        while(!q.empty()) {
            string word = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            if(word == tword) return dis;
            
            for(int i=0; i<word.size(); i++) {
                char og = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, dis+1});
                    }
                }
                word[i] = og;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends