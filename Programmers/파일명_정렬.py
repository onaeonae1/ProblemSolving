from functools import cmp_to_key

def parse(file:str):
    flag = False
    num_sti = -1
    num_edi = -1
    
    for idx, item in enumerate(file):
        if item.isdigit():
            if not flag:
                flag = True
                num_sti = idx
                num_edi = idx
            else:
                num_edi = num_edi if num_edi > idx else idx   
        elif flag: 
            break
    return num_sti, num_edi

def get_parse_str(file:str):
    num_sti, num_edi = parse(file)
    head = ""
    number = ""
    tail = ""
    
    
    if num_sti == -1:
        head = file
        number = "0"
        tail = ""
    else:
        head = file[:num_sti]
        number = file[num_sti:num_edi+1]
        tail = file[num_edi+1:]

    head = head.lower()
    number = number.lstrip("0").strip()
    number = number if number else "0"
    tail = tail.strip()
    
    #print(f"{file} [{head}] | [{number}] | [{tail}]")
    return head, number, tail

def compare(a:str, b:str):
    a_head, a_num, a_tail = get_parse_str(a)
    b_head, b_num, b_tail = get_parse_str(b)
    
    # HEAD 기준 (HEAD 문자열 순)
    if a_head > b_head:
        return 1 
    elif a_head == b_head:
        # NUMBER 기준 (num 작은 순)
        if int(a_num) == int(b_num):
            return 0
        elif int(a_num) > int(b_num):
            return 1
        else:
            return -1
    elif a_head < b_head:
        return -1
    
def solution(files):
    answer = []
    files.sort(key=cmp_to_key(compare))
    answer = files.copy()
        
        
    return answer
