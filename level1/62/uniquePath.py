class Solution(object):
    def uniquePaths(self, m, n):
        map = [[0 for x in range(n)] for y in range(m)]
        for i in range(m):
            map[i][0] = 1
        for j in range(n):
            map[0][j] = 1
        for x in range(1, m):
            for y in range(1, n):
                map[x][y] = map[x - 1][y] + map[x][y - 1]
        return map[m - 1][n - 1]