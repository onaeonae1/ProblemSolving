
def solution(m, n, puddles):
    DP = [[1 for i in range(n+1)] for j in range(m+1)]
    modv = 1000000007
    answer = 0    
    for x,y in puddles:
        DP[x][y] = 0
        if x== 1:
            for i in range(y, n+1):
                DP[x][i] =0
        if y ==1:
            for i in range(x, m+1):
                DP[i][y] = 0
        
    for x in range(1, m+1):
        for y in range(1, n+1):
            if x==1 or y==1:
                continue
            if DP[x][y] == 0:
                continue
            DP[x][y] = DP[x-1][y] + DP[x][y-1]
            print(f"({x},{y}) -> {DP[x][y]}")
    
            
    answer = DP[m][n] % modv
    return answer
