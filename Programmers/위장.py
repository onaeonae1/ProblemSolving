def solution(clothes):
    answer = 1
    clothes_dict = {}
    for cloth in clothes:
        cloth_value, cloth_key = cloth
        clothes_dict[cloth_key] = 1 if clothes_dict.get(cloth_key) == None else clothes_dict.get(cloth_key)+1
    
    for cloth_key, cloth_value in clothes_dict.items():
        answer = answer * (cloth_value+1)    
    
    answer = answer - 1
    
    return answer
