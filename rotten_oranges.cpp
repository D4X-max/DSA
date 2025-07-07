class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();  // Get number of rows in the grid
        int m = grid[0].size();  // Get number of columns in the grid

        // Queue to perform BFS; each element stores: ((row, col), time)
        queue<pair<pair<int, int>, int>> q;

        // 2D visited array to keep track of rotten oranges
        // 0 = unvisited, 1 = visited (fresh turned rotten), 2 = initially rotten
        vector<vector<int>> vis(n, vector<int>(m, 0)); 

        int cntFresh = 0;  // Count of fresh oranges

        // Traverse the grid to find initial rotten oranges and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    // If the orange is rotten, add it to the queue with time = 0
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;  // Mark it as visited (already rotten)
                } else {
                    vis[i][j] = 0;  // Mark as unvisited
                }

                if (grid[i][j] == 1)
                    cntFresh++;  // Count fresh oranges
            }
        }

        int tm = 0;  // To store the time required to rot all oranges
        int cnt = 0;  // To count how many fresh oranges turned rotten

        // Direction arrays for top, right, bottom, left
        int drow[] = {-1, 0, +1, 0}; 
        int dcol[] = {0, 1, 0, -1};

        // Start BFS traversal
        while (!q.empty()) {
            // Get the front element from the queue
            int r = q.front().first.first;   // Row index
            int c = q.front().first.second;  // Column index
            int t = q.front().second;        // Time taken to rot this orange
            tm = max(tm, t);  // Update max time so far
            q.pop();  // Remove the front element

            // Explore all 4 adjacent directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];  // Calculate new row
                int ncol = c + dcol[i];  // Calculate new column

                // Check bounds, and if the adjacent cell has a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {

                    // Push the fresh orange into the queue as it becomes rotten
                    q.push({{nrow, ncol}, t + 1});

                    // Mark it as rotten in visited
                    vis[nrow][ncol] = 2;

                    // Increment the count of rotten oranges
                    cnt++;
                }
            }
        }

        // If number of rotten oranges is less than number of fresh, return -1
        if (cnt != cntFresh) return -1;

        // Otherwise, return the time taken to rot all oranges
        return tm;
    }
};
