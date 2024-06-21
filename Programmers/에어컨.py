import sys
INF = sys.maxsize

def do_dp(temperature, t1, t2, a, b, onboard):
    temp_range = range(0,60)
    temperature = temperature+10
    t1 = t1 + 10
    t2 = t2 + 10
    n = len(onboard)
    
    dp = [[INF] * 1001 for _ in range(51)]
    dp[temperature][0] = 0
    
    for i in range(n - 1):  # 현재 i분, i+1분으로 넘어감.
        for t in range(51):  # 현재 t도, nt도로 넘어감.
            nt = t

            # 에어컨 껐음(0원 소모)
            if temperature < t:
                nt -= 1
            elif temperature > t:
                nt += 1

            if not (onboard[i + 1] and (nt < t1 or t2 < nt)): 
                dp[nt][i + 1] = min(dp[nt][i + 1], dp[t][i])

            # 희망온도 설정했음(a or b원 소모)
            for d in range(-1, 2):
                nt = t + d
                if nt < 0 or nt > 50:
                    continue

                add = b if d == 0 else a
                if not (onboard[i + 1] and (nt < t1 or t2 < nt)):
                    dp[nt][i + 1] = min(dp[nt][i + 1], dp[t][i] + add)

    answer = INF
    for t in range(51):
        answer = min(answer, dp[t][n - 1])

    return answer

def solution(temperature, t1, t2, a, b, onboard):
    answer = 0
    answer = do_dp(temperature, t1, t2, a, b, onboard)
    return answer
