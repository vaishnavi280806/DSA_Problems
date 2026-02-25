class Solution {
    static bool compare(int x, int y){
        int a = x, b = y;
        int c1 = 0, c2 = 0;
        while (a != 0){
            if (a & 1) c1++;
            a = a >> 1;
        }
        while (b != 0){
            if (b & 1) c2++;
            b = b >> 1;
        }
        if (c1 != c2) return c1 < c2;
        return x < y;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};