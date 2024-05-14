def solution(answers):
    answer = []
    
    scores = [0,0,0]
    
    a_list = "12345"
    b_list = "21232425"
    c_list = "3311224455"
    
    max_val = 0
    for idx, val in enumerate(answers):
        temp_list =  list(map(int, [
            a_list[idx%len(a_list)],
            b_list[idx%len(b_list)],
            c_list[idx%len(c_list)],
        ]))
        
        for stdn, stdv in enumerate(temp_list):
            if stdv == val:
                scores[stdn] = scores[stdn]+1
        for score in scores:
            if score >= max_val:
                max_val = score
                
    for idx, val in enumerate(scores):
        if val == max_val:
            answer.append(idx+1)
    
    return answer
