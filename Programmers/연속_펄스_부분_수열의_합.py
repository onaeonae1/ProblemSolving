def solution(sequence):
    answer = 0
    n = len(sequence)
    
    arr1 = [
        item * -1 if index % 2 ==1 else item
        for index, item in enumerate(sequence)
    ]
    arr2 = [
        item * -1 if index%2==0 else item
        for index, item in enumerate(sequence)
    ]
     
    
    num1 = [item for index, item in enumerate(arr1)]
    num2 = [item for index, item in enumerate(arr2)]
    
    for i in range (0, n):
        if i > 0:
            num1[i] = max(num1[i], num1[i] + num1[i-1])
            num2[i] = max(num2[i], num2[i] + num2[i-1])
        
        answer = answer if answer > num1[i] else num1[i]
        answer = answer if answer > num2[i] else num2[i]
        
    
    
    return answer
