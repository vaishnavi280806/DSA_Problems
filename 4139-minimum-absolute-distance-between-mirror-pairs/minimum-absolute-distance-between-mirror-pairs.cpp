class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map <string, int> hash;
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
            string str = to_string(nums[i]);
            if (hash.count(str)){
                mini = min(mini, abs(i - hash[str]));
                //continue;
            }
            reverse(str.begin(), str.end());
            int j = 0;
            while (j < str.size()){
                if (str[j] != '0') break;
                else j++;
            }
            hash[str.substr(j, str.size() - j)] = i;

            //for (auto it : hash) cout << it.first << endl;
        }
        if (mini == INT_MAX) return -1;
        return mini;
    }
};