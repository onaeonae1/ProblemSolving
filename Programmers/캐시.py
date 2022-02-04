from typing import List
from collections import deque


def solution(cacheSize, cities: List[str]):
    answer = 0
    cache_queue = deque()
    cities = list(map(lambda x: x.lower(), cities))

    total_time = 0
    for city in cities:
        in_cache = cache_queue.count(city)
        if in_cache == 1:
            total_time += 1
            cache_queue.remove(city)
            cache_queue.append(city)

        else:
            total_time += 5
            if cacheSize != 0:
                if len(cache_queue) == cacheSize and cacheSize != 0:
                    cache_queue.popleft()
                cache_queue.append(city)

    answer = total_time
    return answer
