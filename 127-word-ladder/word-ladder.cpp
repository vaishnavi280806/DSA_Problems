class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        int flag = 0;
        for (auto word : wordList){
            words.insert(word);
            if (endWord == word) flag = 1;
        }
        if (flag == 0) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        int n = beginWord.size();
        while (!q.empty()){
            auto node = q.front();
            string word = node.first;
            q.pop();

            if (word == endWord) return node.second;

            for (int i = 0; i < n; i++){
                for (int j = 0; j < 26; j++){
                    string newW = word.substr(0, i) + char(j + 97) + word.substr(i+1, n - i);
                    //cout << newW << " ";
                    if (words.count(newW)){
                        q.push({newW, node.second + 1});
                        words.erase(newW);
                    }
                }
            }

        }
        return 0;
    }
};