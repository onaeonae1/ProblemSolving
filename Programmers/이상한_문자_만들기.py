def solution(s):
    answer = ''
    items = s.split(" ")
    
    ret_list = []
    for item in items:
        ret_data = []
        for idx, value in enumerate(item):
            real_idx = idx+1
            if real_idx % 2 == 1:
                ret_data.append(value.upper())
            else:
                ret_data.append(value.lower())
        ret_list.append("".join(ret_data))
    answer = " ".join(ret_list)
    
    return answer
