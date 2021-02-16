def spiralmatrix(m, n, mat):
    x = 0
    y = 0

    while (x < m and y < n):
        for i in range(y, n):
            print(mat[x][i], end=" ")
        x = x+1

        for i in range(x, m):
            print(mat[i][n - 1], end=" ")
        n = n-1

        if (x < m):
            for i in range(n - 1, (y - 1), -1):
                print(mat[m - 1][i], end=" ")
            m = m-1

        if (y < n):
            for i in range(m - 1, x - 1, -1):
                print(mat[i][y], end=" ")
            y = y+1

mat = [[1, 2, 3, 4, 5, 6],
      [7, 8, 9, 10, 11, 12],
      [13, 14, 15, 16, 17, 18]]

row = 3
col = 6

spiralmatrix(row, col, mat)
