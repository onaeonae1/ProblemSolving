def solution(arr1, arr2):
    x1, y1 = len(arr1[0]), len(arr1)
    x2, y2 = len(arr2[0]), len(arr2)
    
    answer = [[0 for _ in range(x2)] for __ in range(y1)]
    for i in range(y1):
        for j in range(x2):
            sum=0
            for k in range(x1):
                sum = sum+ (arr1[i][k] * arr2[k][j])
            answer[i][j] = sum
    return answer
