import sys

N, M = map(int, input().split())

temp_list = list(map(int, input().split(" ")))
sum_list = [0] * (N + 1)

maxValue = -10005

for i in range(0, N):
    sum_list[i] = sum_list[i - 1] + temp_list[i]
    if i >= (M - 1):
        maxValue = max(maxValue, sum_list[i] - sum_list[i - M])


print(maxValue)
