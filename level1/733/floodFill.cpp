#include <iostream>
#include <vector>

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        dfs(sr, sc, image, initColor, color);
        return image;
    }
private:
    void dfs(int x, int y, vector<vector<int>> &image, int initColor, int color)
    {
        int row_size = image.size();
        int col_size = image[0].size();
        if (x<0 || x>=row_size || y < 0 || y >= col_size || image[x][y] != initColor || image[x][y] == color)
                return ;
        image[x][y] = color;
        dfs(x, y + 1, image, initColor, color);
        dfs(x, y - 1, image, initColor, color);
        dfs(x - 1, y, image, initColor, color);
        dfs(x + 1, y, image, initColor, color);
    }
};