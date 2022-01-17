import heapq
from collections import deque

def solution(jobs):
    answer = 0
    jobs = deque(sorted(jobs))

    current_time = 0
    total_time = 0

    cnt = len(jobs)

    temp_cnt = 0
    temp_index = 0
    temp_pq = []
    
    while temp_cnt < cnt:
        
        # 예쁜 반복문 때려치고 인덱스로 접근하자
        # 인덱스 문제 없고, 시작 시간에 문제 없을 때
        while(temp_index < cnt and jobs[temp_index][0] <= current_time):
            heapq.heappush(temp_pq, (jobs[temp_index][1], jobs[temp_index][0]))
            temp_index +=1
        
        # 작업 다 끝났는데(혹은 앞에서 찾아봤는데) pending 된게 없다 -> 이동
        if(len(temp_pq)==0):
            current_time = jobs[temp_index][0]
        else:
            work_time, start_time = heapq.heappop(temp_pq)
            current_time += work_time
            answer += current_time - start_time
            temp_cnt+=1

    return int(answer/cnt)
