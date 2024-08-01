import sys

# typing
from typing import List, Dict
sys.setrecursionlimit(3000)

def func(exp, status_dict: Dict):
    # 현재 방이 가능함? 그럼 바로 return 해
    if status_dict.get(exp) is None:
        status_dict[exp] = exp + 1
        return exp

    else:
        next = func(status_dict.get(exp), status_dict)
        status_dict[exp] = next + 1
        return next


def solution(k: int, room_number: List[int]):
    answer = []
    status_dict = {}

    for book in room_number:
        ret = func(book, status_dict)
        answer.append(ret)

    return answer

