from collections import deque


def solution(priorities, location):
    priority_deque = deque(
        [priority, index] for index, priority in enumerate(priorities)
    )
    answer = 0
    printed_count = 0
    while priority_deque:
        now = priority_deque.popleft()
        is_printable = True
        for item in priority_deque:
            p_value, p_index = item
            if p_value > now[0]:
                is_printable = False
                priority_deque.extend([now])
                break
        if is_printable:
            printed_count += 1
            if now[1] == location:
                answer = printed_count
                break

    return answer
