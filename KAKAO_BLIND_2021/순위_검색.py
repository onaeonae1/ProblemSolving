from itertools import combinations
from bisect import bisect_left

def replace_with_zeros(input_str):
    length = len(input_str)
    results = set()  # 중복을 피하기 위해 set 사용
    results.add(input_str)
    for i in range(length):
        new_str = input_str[:i] + '0' + input_str[i+1:]
        results.add(new_str)

    for i, j in combinations(range(length), 2):
        new_str = input_str[:i] + '0' + input_str[i+1:j] + '0' + input_str[j+1:]
        results.add(new_str)

    for i, j, k in combinations(range(length), 3):
        new_str = input_str[:i] + '0' + input_str[i+1:j] + '0' + input_str[j+1:k] + '0' + input_str[k+1:]
        results.add(new_str)

    # 모든 자리를 0으로 바꾸기
    results.add('0' * length)

    return list(results)

def solution(info, query):
    answer = []
    
    dict_list = [
        {"cpp":"1", "java":"2", "python":"3"},
        {"backend":"1", "frontend":"2"},
        {"junior":"1", "senior":"2"},
        {"chicken":"1", "pizza":"2"},
    ]
    
    search_dict = {}
    
    for item in info:
        temp = item.split(" ")        
        parsed = "".join(dict_list[i].get(temp[i], "0") for i in range(0,4))
        parsed = replace_with_zeros(parsed)
        score = int(temp[4])
        for pa in parsed:
            exist = search_dict.get(pa)
            if exist is None:
                search_dict[pa] = []
            search_dict[pa].append(score)
    
    for value in search_dict.values():
        value.sort()
    
    for item in query:
        temp = item.replace("and", "")
        temp = temp.split(" ")
        parsed = "".join([dict_list[i].get(temp[i*2], "0") for i in range(0,4)])
        score = int(temp[7])
        target = search_dict.get(parsed)
        if target:
            ret = bisect_left(target, score)
            answer.append(len(target)-ret)
        else:
            answer.append(0)
        
        
    return answer
