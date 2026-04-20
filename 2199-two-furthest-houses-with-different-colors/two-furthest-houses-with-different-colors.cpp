class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        while(colors[0] == colors[j]) j--;
        ans = j;
        while (colors[n-1] == colors[i]) i++;
        ans = max(ans, n-i-1);
        return ans;
    }
};