import itertools


def check_is_prime(target: int):
    cnt = 0
    is_prime = False
    if target < 2:
        return is_prime
    for i in range(2, target):
        # print(f"{target} % {i} -> {target%i}")
        if target % i == 0:
            cnt = cnt + 1
        if cnt >= 1:
            is_prime = False
            break

    is_prime = cnt == 0
    return is_prime


def solution(numbers: str):
    answer = 0

    number_list = [num for num in numbers]
    number_length = len(number_list)
    target_numbers = set()

    for i in range(1, number_length + 1):
        number_perms = itertools.permutations(number_list, i)
        for item in number_perms:
            target_str = "".join(item)
            target_num = int(target_str)
            target_numbers.add(target_num)

    for num in target_numbers:
        if check_is_prime(num):
            answer = answer + 1

    return answer

