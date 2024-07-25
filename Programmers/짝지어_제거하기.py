def solution(s):
    answer = -1
    stack = []
            
    for item in s:
        if stack and stack[-1] == item:
            stack.pop()
        else:
            stack.append(item)
            
    
    answer = 1 if len(stack)==0 else 0

    return answer
