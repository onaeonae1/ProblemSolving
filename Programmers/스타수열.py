def solution(a):
    from collections import Counter
    
    if not a:
        return 0
    
    # 각 숫자의 빈도를 계산
    freq = Counter(a)
    max_length = 0
    
    for key in freq:
        if freq[key] * 2 <= max_length:
             continue  # 가능한 최대 길이가 이미 구한 길이보다 작으면 건너뛴다.
        
        length = 0
        i = 0
        while i < len(a) - 1:
            now = a[i]
            next = a[i+1]
            
            if (now==key or next == key) and (now!=next):
                length = length + 2
                i = i +2
            
            else:
                i += 1
        
        max_length = max(max_length, length)
    
    return max_length
