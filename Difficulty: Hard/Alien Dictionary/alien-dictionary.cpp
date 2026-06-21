class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<bool> alphabet(26, false);
        for (int i = 0; i < words.size(); i++){
            for (int j = 0; j < words[i].size(); j++) alphabet[words[i][j] - 97] = true;
        }
        
        vector<pair<char, char>> pre;
        for (int i = 0; i < words.size() - 1; i++){
            int j = 0;
            int flag = 0;
            int n = min(words[i].size(), words[i+1].size());
            while (j < n){
                if (words[i][j] != words[i+1][j]){
                    pre.push_back({words[i][j], words[i+1][j]});
                    flag = 1;
                    break;
                }
                j++;
            }
            if (flag == 0 && words[i].size() > words[i+1].size()) return "";
        }
        
        
        vector<int> indegree(26);
        vector<bool> present(26, false);
        vector<vector<int>> graph(26);
        
        for (int i = 0; i < pre.size(); i++){
            //cout << pre[i].first << " " << pre[i].second << endl;
            present[pre[i].first - 97] = true;
            present[pre[i].second - 97] = true;
            graph[pre[i].first - 97].push_back(pre[i].second - 97);
            indegree[pre[i].second - 97]++;
        }
        
        queue<int> q;
        vector<int> res;
        int n = 0;
        
        for (int i = 0; i < 26; i++){
            if (present[i]) n++;
            if (present[i] && indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            
            for (int x : graph[node]){
                if (--indegree[x] == 0){
                    q.push(x);
                    res.push_back(x);
                }
            }
        }
        //cout << res.size();
        if (res.size() != n) return "";
        //cout << "hi";
        string str = "";
        for (int x : res){
            str += (x + 97);
        }
        
        for (int i = 0; i < 26; i++){
            if (alphabet[i] && !present[i]) str += (i + 97);
        }
        
        return str;
        
    }
};