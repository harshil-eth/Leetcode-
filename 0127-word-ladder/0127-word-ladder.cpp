class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& dic) {
        unordered_set<string> st(dic.begin(), dic.end());
        queue<pair<string, int>> q;
        q.push({bw, 1});
        st.erase(bw);
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            string s = it.first;
            int steps = it.second;
            
            if(s == ew) return steps;
            
            for(int i=0; i<s.size(); i++) {
                char og = s[i];
                for(char ch='a'; ch<='z'; ch++) {
                    if(og != ch) {
                        s[i] = ch;
                        if(st.find(s) != st.end()) {
                            q.push({s, steps+1});
                            st.erase(s);
                        }
                    }
                }
                s[i] = og;
            }
        }
        
        return 0;
    }
};