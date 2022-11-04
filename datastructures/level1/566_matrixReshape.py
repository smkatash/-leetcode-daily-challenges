class Solution(object):
    def matrixReshape(self, mat, r, c):
        if len(mat) * len(mat[0]) != r * c:
            return mat
        else:
            result, row, col = [[]], 0, 0
            for i in range(len(mat)):
                for j in range(len(mat[i])):
                    result[row].append(mat[i][j])
                    col += 1
                    if col == c:
                        row, col = row + 1, 0
                        if row == r:
                            break
                        else:
                            result.append([])
            return result
        