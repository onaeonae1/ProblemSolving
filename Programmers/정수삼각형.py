def solution(triangle):
    answer = 0
    DP = [[0 for j in range(505)] for i in range(505)]
    for i in range(0, len(triangle)):
        temp_list = triangle[i]
        for j in range(0, len(temp_list)):
            lpy = i-1
            lpx = j-1
            rpy = i-1
            rpx = j
            DP[i][j] = triangle[i][j]
            
            rv = 0
            lv = 0
            if lpy >=0 and lpx >= 0: 
                lv = DP[lpy][lpx]
            if rpy >=0 and rpx >=0:
                rv = DP[rpy][rpx]
            addValue = rv if rv > lv else lv
            DP[i][j] = DP[i][j] + addValue
            answer = answer if answer > DP[i][j] else DP[i][j]
            
    return answer
