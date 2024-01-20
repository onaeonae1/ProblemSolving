import sys

# DP[k] = 남은 비용이 k 일때 가능한 동전의 수

N = int(input())
line = sys.stdin.readline()

cnt_dict = {}
cnt_dict["u"] = 0
cnt_dict["o"] = 0
cnt_dict["s"] = 0
cnt_dict["p"] = 0
cnt_dict["c"] = 0

interests = ["u", "o", "s", "p", "c"]

for symbol in line:
    if symbol in interests:
        cnt_dict[symbol] += 1

ans = 999999
for k, v in cnt_dict.items():
    ans = min(ans, v)

print(ans)
