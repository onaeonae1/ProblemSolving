def make_day_list(pair_item):
    progress, speed = pair_item
    temp_value = (int)((100-progress) / speed)
    mod_value = (100 - progress) % speed
    if (100-progress) % speed != 0 :
        temp_value = temp_value + 1
        
    return temp_value
    
def parse_day_list(temp_list):
    max_val = temp_list[0]
    ret = 1
    ret_list = []
    temp_list.append(99999)
    for i in range(0, len(temp_list)-1):
        if temp_list[i+1] > max_val:
            max_val = temp_list[i+1]
            ret_list.append(ret)
            ret = 1
        else:
            ret = ret + 1
        
    return ret_list
    
def solution(progresses, speeds):
    temp_list = list(map(make_day_list, list(zip(progresses, speeds))))
    
    # parse_day_list(temp_list)
    
    answer = parse_day_list(temp_list)
    return answer
