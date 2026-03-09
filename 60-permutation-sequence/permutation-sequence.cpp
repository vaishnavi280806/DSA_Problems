class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        int fact = 1;
        for (int i = 1; i < n; i++){
            fact *= i;
            arr.push_back(i);
        }
        arr.push_back(n);
        string res = "";
        k = k - 1;
        while (true){
            res += to_string(arr[k / fact]);
            arr.erase(arr.begin() + k / fact);
            if (arr.size() == 0) break;
            k = k % fact;
            fact /= arr.size();
        }
        return res;
    }
};