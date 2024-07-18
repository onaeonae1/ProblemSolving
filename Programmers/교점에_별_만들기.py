def solution(line):
    answer = []
    
    # 모든 선들에 대해 교점을 구한다
    minX = int(1e15)
    maxY = -int(1e15)
    minY = int(1e15)
    maxX = -int(1e15)
    items = len(line)
    points = []
    
    for i in range(0, items):
        A,B,E = line[i]
        for j in range(i, items):
            C,D,F = line[j]
            if i != j:
                diff = (A*D) - (B*C)
                if diff!=0:
                    tx = ((B*F) - (E*D)) / diff
                    ty = ((E*C) - (A*F)) / diff
                    if tx == int(tx) and ty == int(ty):
                        tx = int(tx)
                        ty = int(ty)
                        points.append([ty,tx])
                        minX = minX if minX < tx else tx
                        minY = minY if minY < ty else ty
                        maxX = tx if maxX < tx else maxX
                        maxY = ty if maxY < ty else maxY
                    
    
    x_range = maxX - minX + 1
    y_range = maxY - minY + 1
    
    board = [["."] * x_range for _ in range(y_range)]
    for targetY, targetX in points:
        tx = targetX + abs(minX) if minX<0 else targetX-minX
        ty = targetY + abs(minY) if minY<0 else targetY-minY
        board[ty][tx] = "*"
    
    
    for item in board:
        answer.append("".join(item))
        
    answer.reverse()
            
    return answer
