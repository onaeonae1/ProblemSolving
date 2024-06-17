def solution(citations):
    answer = len(citations)
    citations.sort(reverse=True)
    for idx, citation in enumerate(citations):
        if citation <= idx:
            answer = idx
            break
    return answer
