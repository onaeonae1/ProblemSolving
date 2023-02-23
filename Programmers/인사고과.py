# typing
from typing import List

def solution(scores:List[List[int]]):
    answer = 1
    target = scores[0]
    target_alpha = target[0]
    target_beta = target[1]

    target_sum = target_alpha + target_beta

    # alpha 기준으로 큰 것부터 근데 같은 alpha 면 beta 작은거 우선
    scores = sorted(scores, key=lambda x: (-x[0], x[1]))
    # print(scores)

    temp_beta = 0
    for score in scores:
        alpha = score[0]
        beta = score[1]
        # 주인공이 잘리는 경우
        current_sum = alpha + beta
        if target_alpha < alpha and target_beta < beta:
            answer = -1
            return answer
        
        # beta 기준 확인
        if temp_beta <= beta:
            # print(f"{target} || {score} -> {current_sum} || {target_sum}")
            if current_sum > target_sum:
                answer = answer + 1
            temp_beta = beta
        

    # print(answer)
    
    return answer
