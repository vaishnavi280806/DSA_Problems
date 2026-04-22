class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        int n = queries[0].size();
        for (int i = 0; i < queries.size(); i++){
            int mini = INT_MAX;
            for (int j = 0; j < dictionary.size(); j++){
                int cnt = 0;
                for (int k = 0; k < n; k++){
                    if (queries[i][k] != dictionary[j][k]) cnt++;
                }
                mini = min(cnt, mini);
                if (mini <= 2) break;
            }
            if (mini <= 2) res.push_back(queries[i]);
        }
        return res;
    }
};