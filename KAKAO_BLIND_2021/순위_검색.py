from itertools import combinations
from bisect import bisect_left

def replace_with_zeros(input_str):
    result_set = set()
    result_set.add(input_str)
    length = len(input_str)
    
    for i in range(1, length+1):
        for case in combinations(range(length), i):
            new_str = list(input_str)
            for idx in case:
                new_str[idx]="0"
            result_set.add("".join(new_str))
    
    return list(result_set)

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
