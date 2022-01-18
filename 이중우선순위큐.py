import heapq as hq


def solution(operations):
    answer = []

    priority_queue = []
    for raw_operation in operations:
        operation: str
        num_value: str
        operation, num_value = raw_operation.split(" ")
        if operation == "I":
            hq.heappush(priority_queue, int(num_value))
        elif priority_queue:
            if num_value.startswith("-"):
                hq.heappop(priority_queue)
            else:
                priority_queue.remove(max(priority_queue))

    if priority_queue:
        answer = [max(priority_queue), min(priority_queue)]
    else:
        answer = [0, 0]
    return answer
