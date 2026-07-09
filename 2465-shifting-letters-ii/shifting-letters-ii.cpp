class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n, 0);

        for (int i = 0; i < shifts.size(); i++){
            if (shifts[i][2] == 1){
                diff[shifts[i][0]] += 1;
                if (shifts[i][1] + 1 < n) diff[shifts[i][1] + 1] -=1;
            }
            else{
                diff[shifts[i][0]] -= 1;
                if (shifts[i][1] + 1 < n) diff[shifts[i][1] + 1] +=1;
            }  
        }
        for (int i = 1; i < n; i++){
            diff[i] += diff[i-1];
        }

        for (int i = 0; i < n; i++){
            diff[i] %= 26;
            int x = s[i] - 'a';
            x = (x + diff[i] + 26) % 26;
            s[i] = x + 'a';
        }
        return s;
    }
};