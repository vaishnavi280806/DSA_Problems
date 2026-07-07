class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m < n) return false;

        vector<int> prefix(n, -1), suffix(n, -1);

        int j = 0;
        for (int i = 0; i < n; i++){
            while (j < m && t[j] != s[i]) j++;
            if (j == m) break;
            prefix[i] = j++;
        }
        if (prefix[n-1] != -1) return true;

        j = m-1;
        for (int i = n-1; i >= 0; i--){
            while (j >= 0 && t[j] != s[i]) j--;
            if (j < 0) break;
            suffix[i] = j--;
        }

        for (int i = 0; i < n; i++){
            if ((i == 0 || prefix[i-1] != -1) && (i == n-1 || suffix[i+1] != -1)){
                int l = (i == 0) ? -1 : prefix[i-1];
                int r = (i == n-1) ? m : suffix[i+1];

                if (r - l > 1) return true;
            }
        }
        return false;
    }
};