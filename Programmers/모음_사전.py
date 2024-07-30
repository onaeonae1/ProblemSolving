def func(target_list, now, step, direct, word):
    if step == 6:
        return
    
    if now!="":
        target_list.append(now)
        if now == word:
            direct[now] = len(target_list)
        
    for item in ["A", "E", "I", "O", "U"]:
        func(target_list, "".join([now, item]), step+1, direct, word)


def solution(word):
    answer = 0
    answer_list = []
    direct = {}
    func(answer_list, "", 0, direct, word)
    answer = direct.get(word)
    
    return answer
