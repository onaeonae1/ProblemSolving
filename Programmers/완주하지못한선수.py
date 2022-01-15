def solution(participant, completion):
    answer = ''
    parti_dict = {}
    
    for parti_item in participant:
        if parti_dict.get(parti_item) is None:
            parti_dict[parti_item] = 1
        else:
            parti_dict[parti_item] = parti_dict.get(parti_item) + 1
            
    for comp_item in completion:
        if parti_dict.get(comp_item) is not None:
            parti_dict[comp_item] = parti_dict.get(comp_item) - 1
            
            
        
    ret_value = ""
    for key, value in parti_dict.items():
        if value != 0:
            ret_value = key
            
            
    answer = ret_value 
    return answer
