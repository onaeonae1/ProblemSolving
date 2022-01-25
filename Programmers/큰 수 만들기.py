def solution(number, k):
    answer = ""
    max_stack = []
    len_limit = len(number) - k
    add_count = 0

    for num_char in number:
        while (
            max_stack and max_stack[-1] < num_char and k > 0 and add_count <= len_limit
        ):
            max_stack.pop()
            add_count -= 1
            k -= 1

        if add_count < len_limit:
            max_stack.append(num_char)
            add_count += 1

    answer = "".join(max_stack)
    return answer

