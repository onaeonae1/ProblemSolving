def solution(s):
    answer = []
    
    temp = s[2:-2].split("},{")
    temp = sorted(temp, key=lambda x: len(x))
    test_dict = {}
    for item in temp:
        ret = item.split(",")
        for t in ret:
            if test_dict.get(t) is None:
                answer.append(int(t))
                test_dict[t] = 1
                
    return answer
