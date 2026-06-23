class Solution {
    void dfs(string endWord, string word, vector<string>& ds, vector<vector<string>>& res, string beginWord, unordered_map<string, int>& levels){
        if (word == beginWord){
            res.push_back(ds);
        }

        for (int i = 0; i < word.size(); i++){
            for (char j = 'a'; j <= 'z'; j++){
                string newW = word.substr(0, i) + j + word.substr(i + 1, word.size() - i);
                if (levels.count(newW) && levels[newW] + 1 == levels[word]){
                    ds.push_back(newW);
                    dfs(endWord, newW, ds, res, beginWord, levels);
                    ds.pop_back();
                }
            }
        }
        
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> words;
        int flag = 1;

        for (string word : wordList){
            words.insert(word);
            if (word == endWord) flag = 0;
        }
        if (flag == 1) return {};

        queue<string> q;
        unordered_map <string, int> levels;
        q.push(beginWord);
        levels[beginWord] = 1;
        int n = beginWord.size();

        if (words.count(beginWord)) words.erase(beginWord);

        flag = 0;

        while (!q.empty()){
            string node = q.front();
            q.pop();

            if (node == endWord) flag = 1;
            if (flag == 1 && node != endWord) break;

            for(int i = 0; i < n; i++){
                for (char j = 'a'; j <= 'z'; j++){
                    string newW = node.substr(0, i) + j + node.substr(i + 1, n - i);
                    if (words.count(newW)){
                        q.push(newW);
                        words.erase(newW);
                        levels[newW] = levels[node] + 1;
                    }
                }
            }
        }

        for (auto it : levels){
            cout << it.first << " " << it.second << endl;
        }

        vector<string> ds;
        vector<vector<string>> res;
        ds.push_back(endWord);
        dfs(endWord, endWord, ds, res, beginWord, levels);

        for (int i = 0; i < res.size(); i++){
            reverse(res[i].begin(), res[i].end());
        }

        return res;
    }
};