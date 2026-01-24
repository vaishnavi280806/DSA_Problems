class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        int Xor = 0;
        for (auto x : arr) Xor = Xor ^ x;
        int right = Xor & (Xor - 1) ^ Xor;
        int set1 = 0, set2 = 0;
        for (auto x : arr){
            if (x & right) set1 = set1 ^ x;
            else set2 = set2 ^ x;
        }
        return {max(set1, set2), min(set1, set2)};
    }
};