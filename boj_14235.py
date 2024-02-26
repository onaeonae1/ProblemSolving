import heapq

N = int(input())

heap = []

for _ in range(N):
    ques = list(map(int, input().split()))
    retv = ques[0]
    if retv == 0:
        if len(heap) >=1:
            ans = heapq.heappop(heap)
            ans = ans * -1
            print(ans)
        else:
            print(-1)
    else:
        for item in ques[1:]:
            temp = item * -1
            heapq.heappush(heap, temp)



