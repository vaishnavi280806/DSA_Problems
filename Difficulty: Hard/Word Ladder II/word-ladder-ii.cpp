class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
         unordered_set<string> words;
        int flag = 0;

        for (string word : wordList){
            words.insert(word);
            if (word == endWord) flag = 1;
        } 
        if (flag == 0) return {};

        queue<vector<string>> q;
        q.push({beginWord});
        int n = beginWord.size();
        vector<vector<string>> res;

        while (!q.empty()){
            int s = q.size();
            for (int i = 0; i  < s; i++){
                auto node = q.front();
                q.pop();
                string word = node[node.size() - 1];

                if (word == endWord) res.push_back(node);

                for (int i = 0; i < n; i++){
                    for (char j = 'a'; j <= 'z'; j++){
                        string newW = word.substr(0, i) + j + word.substr(i + 1, n - i);
                        if (words.count(newW)){
                            vector<string> newA = node;
                            newA.push_back(newW);
                            q.push(newA);
                        }
                    }
                }
                words.erase(word);
            }
            if (res.size() != 0) return res;

        }
        return res;
    }
};