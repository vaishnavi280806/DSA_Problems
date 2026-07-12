class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int l = 0;
        int n = fruits.size();
        unordered_map<int, int> mp;

        for (int r = 0; r < n; r++){
            mp[fruits[r]]++;

            while(mp.size() >= 3){
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};