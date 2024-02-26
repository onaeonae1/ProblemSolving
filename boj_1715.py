import heapq
N = int(input())

heap = []
ans = 0 
for _ in range(N):
    value = int(input())
    heapq.heappush(heap, value)

while len(heap) >1:
    first = heapq.heappop(heap)
    second = heapq.heappop(heap)

    ans = ans + (first + second)

    heapq.heappush(heap, first+second)

print(ans)

