# default

# typing
from typing import List

visited_dict = {}


def calculate(alpha: str, beta: str):
    idx = len(alpha)
    cnt = 0
    for i in range(0, idx):
        alpha_item = alpha[i]
        beta_item = beta[i]
        if alpha_item != beta_item:
            cnt = cnt + 1
        if cnt > 1:
            break
    return cnt == 1


def dfs(current: str, target: str, value: int, words: List[str]):
    if current == target:
        return
    candidates = list(filter(lambda x: calculate(current, x), words))
    for candidate_item in candidates:
        cost = visited_dict.get(candidate_item)
        if cost is None:
            # new
            visited_dict[candidate_item] = value + 1
            dfs(candidate_item, target, value + 1, words)
        elif value + 1 < cost:
            # visited; but more effective
            visited_dict[candidate_item] = value + 1
            dfs(candidate_item, target, value + 1, words)


def solution(begin: str, target: str, words: List[str]):
    is_valid = target in words
    if not is_valid:
        answer = 0
        return answer
    answer = 0

    dfs(begin, target, 0, words)
    answer = visited_dict.get(target, 0)
    return answer

