class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> st;
        for(auto word: wordList) {
            st.insert(word);
        }
        st.erase(beginWord);

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (word == endWord) return dist;

            for(int i=0; i<word.size(); i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, dist+1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};