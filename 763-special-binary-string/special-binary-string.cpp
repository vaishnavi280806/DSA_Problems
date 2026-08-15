class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt = 0;
        int start = 0;
        vector<string> blocks;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1') cnt++;
            else cnt--;

            if (cnt == 0){
                string sub = s.substr(start+1, i-start-1);
                blocks.push_back("1" + makeLargestSpecial(sub) + "0");
                start = i+1;
            }
        }
        sort(blocks.rbegin(), blocks.rend());
        string res = "";
        for (string &x : blocks){
            res += x;
        }
        return res;
    }
};