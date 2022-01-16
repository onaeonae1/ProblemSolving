import heapq as hq

def solution(scoville, k):
    answer = 0
    hq.heapify(scoville)    
    is_smaller = True
    cnt = 0

    while(is_smaller and len(scoville) >=2):
        alpha = hq.heappop(scoville)
        beta = hq.heappop(scoville)
        gamma = alpha + (beta*2)
        hq.heappush(scoville, gamma)
        cnt = cnt +1
        
        test_value = scoville[0]
        if test_value >=k:
            is_smaller = False
            break
        
    answer = -1 if is_smaller else cnt
    return answer
