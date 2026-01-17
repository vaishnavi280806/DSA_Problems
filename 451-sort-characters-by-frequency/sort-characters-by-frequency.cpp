class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> hash;
        for (int i = 0; i < s.size(); i++){
            hash[s[i]]++;
        }
        vector<pair<int, char>> v;
        for (auto &x : hash){
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end(), greater<>());

        string ans = "";
        for (int i = 0; i < v.size(); i++){
            for (int j = 0; j < v[i].first; j++){
                ans += v[i].second;
            }
        }
        return ans;
    }
};