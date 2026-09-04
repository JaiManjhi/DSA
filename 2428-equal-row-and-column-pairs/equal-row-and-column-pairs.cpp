class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size();

        map<vector<int>, int> rowMap;

        for(auto &row : grid)
            rowMap[row]++;

        int ans = 0;

        for(int col = 0; col < n; col++)
        {
            vector<int> currentCol;

            for(int row = 0; row < n; row++)
                currentCol.push_back(grid[row][col]);

            ans += rowMap[currentCol];
        }

        return ans;
    }
};
