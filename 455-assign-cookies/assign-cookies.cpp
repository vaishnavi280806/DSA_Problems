class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int c = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()){
            if (g[i] <= s[j]){
                c++;
                j++; i++;
            }
            else j++;
            
        }
        return c;
    }
};