def solution(s, n):
    answer = ''
    ret_list = []
    
    for item in s:
        asc_value = ord(item)
        if item!=" ":
            start = ord("A") if item.isupper() else ord("a")
            asc_value = (asc_value-start+n) % 26 + start
            
        ret_list.append(chr(asc_value))
        
    answer = "".join(ret_list)
    return answer
