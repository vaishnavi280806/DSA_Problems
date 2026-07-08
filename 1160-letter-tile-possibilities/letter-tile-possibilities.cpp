class Solution {
    void helper(string tiles, string& ds, unordered_set<string>& res, vector<bool>& used){
        res.insert(ds);

        for (int i = 0; i < tiles.size(); i++){
            if (!used[i]){
                used[i] = true;
                ds.push_back(tiles[i]);
                helper(tiles, ds, res, used);
                used[i] = false;
                ds.pop_back();
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
       unordered_set<string> res;
       vector<bool> used(tiles.size(), false);
       string ds = "";
       helper(tiles, ds, res, used);

       return res.size() -1;
    }
};