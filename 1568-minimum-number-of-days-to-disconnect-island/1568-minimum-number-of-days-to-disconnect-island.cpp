int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
bool valid(int i, int j, int n, int m, vector<vector<int>> &grid) {
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1);
}

class Solution {
public:
    vector<vector<int>> vis;
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid) {
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            if(valid(i + dx[k], j + dy[k], n, m, grid) && vis[i + dx[k]][j + dy[k]] == 0) {
                dfs(i + dx[k], j + dy[k], n, m, grid);
            }
        }
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis = vector<vector<int>> (n, vector<int>(m));
        int cc = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    dfs(i, j, n, m, grid);
                    cc++;
                }
            }
        }
        int ans = 2;
        if(cc != 1) {
            ans = 0;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    for(int r = 0; r < n; r++) {
                        for(int c = 0; c < m; c++) {
                            vis[r][c] = 0;
                        }
                    }
                    int tcc = 0;
                    for(int r = 0; r < n; r++) {
                        for(int c = 0; c < m; c++) {
                            if(grid[r][c] == 1 && vis[r][c] == 0) {
                                dfs(r, c, n, m, grid);
                                tcc++;
                            }
                        }
                    }
                    if(tcc != 1) {
                        ans = min(ans, 1);
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return ans;
    }
};