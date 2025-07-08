#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];  // Initial color of the starting pixel

        // If color is already same, no work needed
        if (iniColor == color) return image;

        int n = image.size();
        int m = image[0].size();

        // Queue for BFS
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;  // Fill the starting pixel

        // Direction vectors (up, right, down, left)
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                // Check bounds and color match
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == iniColor) {
                    
                    // Fill and add to queue
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }

        return image;
    }
};
