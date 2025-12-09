class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map <int, int> hash;
        int l = 0, res = 0;
        int n = fruits.size();
        for (int r = 0; r < n; r++){
            hash[fruits[r]]++; 
            while (hash.size() > 2){
                hash[fruits[l]]--;
                if (hash[fruits[l]] == 0){
                    hash.erase(fruits[l]);
                    l++;
                    break;
                }
                l++;
            } 
            res = max(res, r - l + 1);
        }
        return res;
    }
};