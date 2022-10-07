class Solution(object):
    def dfs(self, grid, x, y, rows, cols):
        if x < 0 or y < 0:
            return
        if x >= rows or y >= cols:
            return
        if grid[x][y] == '0':
            return
        grid[x][y] = '0'
        self.dfs(grid, x - 1, y, rows, cols)
        self.dfs(grid, x + 1, y, rows, cols)
        self.dfs(grid, x, y - 1, rows, cols)
        self.dfs(grid, x, y + 1, rows, cols)
    def numIslands(self, grid):
        numIsland = 0
        rows = len(grid)
        cols = len(grid[0])
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    numIsland += 1
                    self.dfs(grid, i, j, rows, cols)
        return numIsland
    