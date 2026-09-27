class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> st;

        for(auto w: wordList) {
            st.insert(w);
        }
        st.erase(beginWord);

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            string word = q.front().first;
            int numChanges = q.front().second;
            q.pop();

            if(word == endWord) return numChanges;

            for(int i=0; i<word.size(); i++) {
                int original = word[i];

                for(char ch = 'a'; ch < 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        q.push({word, numChanges+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};