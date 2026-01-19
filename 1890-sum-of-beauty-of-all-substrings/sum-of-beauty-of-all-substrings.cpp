class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++){
            vector<int> freq(26);
            for (int j = i; j < s.size(); j++){
                freq[s[j] - 'a']++;
                int maxi = 0, mini = INT_MAX;
                for (auto x : freq){
                    if (x > 0){
                        maxi = max(maxi, x);
                        mini = min(mini, x);
                    }
                }
                sum += maxi - mini;
            }
            

        }
        return sum;
    }
};