from functools import cmp_to_key

def compare(a,b):
    if a+b > b+a:
        return -1
    elif a+b < b+a:
        return 1
    else:
        return 0

def solution(numbers):
    answer = ''
    numbers = list(map(str, numbers))
    numbers.sort(key=cmp_to_key(compare))
    answer = ''.join(numbers)
    
    return str(int(answer))
