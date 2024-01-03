import sys


def main():
    input = sys.stdin.readline
    N = int(input())
    M = 100
    ret = 0
    costs = list(map(int, input().split()))
    values = list(map(int, input().split()))
    dp_list = [0 for _ in range(105)]
    temp_list = [0 for _ in range(105)]

    for i in range(N):
        current_cost = costs[i]
        current_value = values[i]
        for j in range(M + 1):
            if j - current_cost > 0:
                now = dp_list[j]
                next = dp_list[j - current_cost] + current_value
                temp_list[j] = max(now, next)

        for j in range(M + 1):
            dp_list[j] = max(dp_list[j], temp_list[j])
            ret = max(dp_list[j], ret)
        temp_list = [0 for _ in range(105)]

    return ret


ans = main()
print(ans)
