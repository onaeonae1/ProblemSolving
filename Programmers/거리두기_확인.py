def in_range(x,y):
    return 0<=x< 5 and 0<=y<5


def check_places(places):
    res = []
    for place in places:
        valid = 1
        people = [(i,j) for i in range(5) for j in range(5) if place[i][j] == 'P']
        for x, y in people:
            # 인접한 한 칸을 체크
            if valid!=0:
                for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                    nx = x+dx
                    ny = y+dy
                    if in_range(nx, ny) and place[nx][ny]=='P':
                        valid = 0
                        break
            
            if valid !=0:
                # 2칸 직선의 조사
                for dx, dy in [(2,0), (-2,0), (0,2), (0,-2)]:
                    nx = x+dx
                    ny = y+dy
                    if in_range(nx, ny) and place[nx][ny] =="P":
                        midX = (x+nx)//2
                        midY = (y+ny)//2
                        if place[midX][midY] !="X" :
                            valid = 0
                            break
            if valid!=0:
                # 대각선의 조사
                for dx, dy in [(1,1), (1,-1), (-1,-1), (-1,1)]:
                    nx = x+dx
                    ny = y+dy
                    if in_range(nx, ny) and place[nx][ny] == "P":
                        # 양쪽에 파티션이 있으셔야 함
                        if place[x][ny] !="X" or place[nx][y] !="X":
                            valid = 0
                            break

            
        res.append(valid)
    return res

def solution(places):
    answer = check_places(places)
    return answer
