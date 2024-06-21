def solution(land):
    answer = 0
    
    height = len(land)
    width = len(land[0])
    
    DP = [[0 for _ in range(width)] for __ in range(height)]
    for index, item in enumerate(land[0]):
        DP[0][index] = item
        
    for h in range(1, height):
        for w in range(0, width):
            for upper_w in range(0, width):
                if w != upper_w:
                    DP[h][w] = max(DP[h][w], DP[h-1][upper_w] + land[h][w])
            
    for item in DP[height-1]:
        answer = answer if answer > item else item
            
    return answer
