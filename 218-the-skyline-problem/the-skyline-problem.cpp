class Solution {
    // Merge two skylines
vector<vector<int>> mergeSkyline(vector<vector<int>> &left,
                                   vector<vector<int>> &right) {
    int h1 = 0, h2 = 0;
    int i = 0, j = 0;
    vector<vector<int>> result;

    while (i < left.size() && j < right.size()) {
        int x;

        if (left[i][0] < right[j][0]) {
            x = left[i][0];
            h1 = left[i][1];
            i++;
        }
        else if (right[j][0] < left[i][0]) {
            x = right[j][0];
            h2 = right[j][1];
            j++;
        }
        else {
            x = left[i][0];
            h1 = left[i][1];
            h2 = right[j][1];
            i++;
            j++;
        }

        int maxH = max(h1, h2);

        // Avoid duplicate heights
        if (result.empty() || result.back()[1] != maxH) {
            result.push_back({x, maxH});
        }
    }

    // Add remaining points
    while (i < left.size()) {
        result.push_back(left[i++]);
    }
    while (j < right.size()) {
        result.push_back(right[j++]);
    }

    return result;
}


// Divide & Conquer function
vector<vector<int>> divide(vector<vector<int>> &buildings, int l, int r) {
    if (l == r) {
        return {
            {buildings[l][0], buildings[l][2]},
            {buildings[l][1], 0}
        };
    }

    int mid = (l + r) / 2;

    vector<vector<int>> leftSky = divide(buildings, l, mid);
    vector<vector<int>> rightSky = divide(buildings, mid + 1, r);

    return mergeSkyline(leftSky, rightSky);
}
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        int n = buildings.size();
        return divide(buildings, 0, n - 1);
    }
};
