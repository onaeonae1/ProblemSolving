input = __import__("sys").stdin.readline
from functools import reduce

N, S = map(int, input().split())
numbers = list(map(int, input().split()))

max_sum = reduce(lambda x, y: x + y, numbers)
min = 100005
p1 = 0
p2 = 0
sum = 0
while True:
    # 사전 체크
    if p2 == len(numbers) - 1 and p1 == len(numbers) - 1:
        break
    # 위치 이동 적용
    if sum >= S:
        # 크기가 크므로 왼쪽 줄임
        min = p2 - p1 if min >= p2 - p1 else min
        if p1 <= len(numbers) - 1:
            sum = sum - numbers[p1]
            p1 = p1 + 1
        else:
            # 더 못 줄임
            break
    else:
        # 크기가 작으므로 오른쪽 늘림
        if p2 <= len(numbers) - 1:
            sum = sum + numbers[p2]
            p2 = p2 + 1
        else:
            # 더 못 늘림
            break

if min == 100005:
    print(0)
else:
    print(min)
