def solution(n):
    snail = [[0 for j in range(n)] for i in range(n)]
    row = 0  # y
    col = 0  # x
    todo = (n * (n + 1)) / 2

    val = 1
    snail[0][0] = val
    while val < todo:
        # left down => straight down in array; => row+1
        while row + 1 < n and snail[row + 1][col] == 0:
            row += 1
            val += 1
            snail[row][col] = val
        # straight right => straight right in array; => col+1
        while col + 1 < n and snail[row][col + 1] == 0:
            col += 1
            val += 1
            snail[row][col] = val
        # left up => left up in array; => row-1, col-1
        while col - 1 >= 0 and row - 1 >= 0 and snail[row - 1][col - 1] == 0:
            col -= 1
            row -= 1
            val += 1
            snail[row][col] = val

    answer = []

    for item in snail:
        for data in item:
            if data != 0:
                answer.append(data)
            else:
                break
    return answer
