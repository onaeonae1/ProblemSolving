def solution(n):
    answer = 0
    DP = [0 for _ in range(n+1)]
    DP[0] = 1
    DP[2] = 3
    if n <= 2:
        return 
    
    for i in range(4, n+1, 2):
        DP[i] += (DP[i-2] * 3)
        for j in range(0, i-3, 2):
            DP[i] += (DP[j] * 2)
            
        DP[i] = DP[i] % 1000000007
        
    answer = DP[n]
            
    return answer
