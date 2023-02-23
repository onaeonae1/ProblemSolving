INF = 99999998
def solution(x, y, n):
    #print(f"x: {x} | y: {y} | n: {n}")
    dp_arr = [INF for i in range(0, y+5)]
    answer = 0
    dp_arr[x] = 0
    for i in range(x, y+1, 1):
        n_val = i + n 
        two_val = i * 2
        three_val = i * 3
        if n_val <= y:
            dp_arr[n_val] = min(dp_arr[i+n], dp_arr[i]+1)
        if two_val <= y:
            dp_arr[two_val] = min(dp_arr[two_val], dp_arr[i]+1)
        if three_val <= y:
            dp_arr[three_val] = min(dp_arr[three_val], dp_arr[i]+1)


    answer = dp_arr[y]
    answer = -1 if answer == INF else answer

    return answer
