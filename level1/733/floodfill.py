class Solution(object):
    def dfs(self, x, y, image, initPos, color):
        row = image.size()
        col = image[0].size()
        if row <= x < 0 or col <= y < 0 or image[x][y] != initPos or image[x][y] == color:
            return
        image[x][y] = color
        self.dfs(x, y + 1, image, initPos, color)
        self.dfs(x, y - 1, image, initPos, color)
        self.dfs(x + 1, y, image, initPos, color)
        self.dfs(x - 1, y, image, initPos, color)
        
    def floodFill(self, image, sr, sc, color):
        initPos = image[sr][sc]
        self.dfs(sr, sc, initPos, color)
        return image
