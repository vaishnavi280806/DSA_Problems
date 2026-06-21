class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        int n = words.size();
        int s = beginWord.size();
        vector<vector<int>> graph(n);
        int flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if (words[i] == endWord) flag = 1;
            for (int j = i + 1; j < n; j++) {
                int k = 0;
                int c = 0;
                while (k < s) {
                    if (words[i][k] != words[j][k]) c++;
                    if (c > 1) break;
                    k++;
                }
                if (c == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        if (words[n-1] != endWord && flag == 0) return 0;

        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++){
            int k = 0;
                int c = 0;
                while (k < s) {
                    if (beginWord[k] != words[i][k]) c++;
                    if (c > 1) break;
                    k++;
                }
                if (c == 1){
                    q.push({i, 2});
                    visited[i] = true;
                }
        }
        int ans = INT_MAX;
        while (!q.empty()){
            auto node = q.front();
            q.pop();

            if (words[node.first] == endWord){
                ans = min(ans, node.second);
                continue;
            }

            for (int x : graph[node.first]){
                if (!visited[x]){
                    q.push({x, node.second + 1});
                    visited[x] = true;
                }
            }
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};