class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k) return false;
        map <int, int> hash;
        for (int x : nums){
            hash[x]++;
        }
        auto it = hash.begin();
        while (it != hash.end()){
            if (it->second == 0){
                it++;
            }
            else{
                int start = it->first;
                int c = it->second;
                for (int i = 0; i < k; i++){
                    if (hash[start + i] < c) return false;
                    hash[start + i] -= c;
                }
                it++;
            }

        }
        return true;
    }
};