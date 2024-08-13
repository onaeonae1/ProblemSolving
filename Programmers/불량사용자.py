from itertools import product

def check(str1, str2):
    is_valid = True
    if len(str1) != len(str2):
        return False
        
    for u, b in list(zip(str1,str2)):
        if b!="*" and u!=b:
            return False
            
    return is_valid
        
def solution(user_id, banned_id):
    answer = 0
    temp = [[] for _ in range(len(banned_id))] # ban 하나 당 가능한 애들을 몰빵
    res = set()
    for idx, ban in enumerate(banned_id):
        for usr in user_id:
            is_valid = check(usr, ban)
            if is_valid:
                temp[idx].append(usr)

    # 각 ban 당 가능한 애들 뽑아둔거를 다 join
    for item in list(product(*temp)):
        item_set = set(item)
        if len(item_set) == len(banned_id):
            res.add("".join(sorted(item_set))) # 정렬 안해주면 틀린다
    
    answer = len(res)
    return answer
