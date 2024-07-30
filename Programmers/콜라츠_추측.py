def func(now, cnt):
    if cnt >= 500:
        return -1
    if now == 1:
        return cnt
    
    ret = now
    if ret %2 == 0:
        ret = ret / 2
    else:
        ret = (ret * 3) + 1
    
    return func(ret, cnt+1)
        
        
def solution(num):
    answer = 0
    answer = func(num, 0)
    
    
    
    return answer
