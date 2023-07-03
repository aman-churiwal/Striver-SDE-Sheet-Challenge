class Solution {

private:

    bool isValid(int& row, int& col, int& m, int& n){
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int& m, int& n){
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({row, col});
        vis[row][col] = 1;

        vector<int> delRow{-1, 0, 1, 0};
        vector<int> delCol{0, 1, 0, -1};

        while(! bfsQueue.empty()){
            int currRow = bfsQueue.front().first;
            int currCol = bfsQueue.front().second;
            bfsQueue.pop();

            for(int i = 0; i < 4; i++){
                int r = currRow + delRow[i];
                int c = currCol + delCol[i];

                if(isValid(r, c, m ,n) && ! vis[r][c] && grid[r][c] == '1'){
                    vis[r][c] = 1;
                    bfsQueue.push({r, c});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int islands = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, int>> bfsQueue;
        
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == '1' && ! vis[row][col]){
                    bfs(row, col, vis, grid, m, n);
                    islands++;
                }
            }
        }

        return islands;
    }
};