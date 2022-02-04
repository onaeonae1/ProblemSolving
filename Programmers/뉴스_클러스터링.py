from collections import Counter


def get_str_counter(target_str: str):
    str_counter = Counter()
    temp_list = []
    for index in range(len(target_str) - 1):
        head_str = target_str[index]
        tail_str = target_str[index + 1]

        # filtering
        if "a" <= head_str <= "z" and "a" <= tail_str <= "z":
            temp_list.append(head_str + tail_str)

    str_counter.update(temp_list)
    return str_counter


def get_total_value(counter_item):
    ret_value = 0
    for key, value in counter_item.items():
        ret_value += value
    return ret_value


def solution(str1: str, str2: str):
    answer = 0
    str1 = str1.lower()
    str2 = str2.lower()

    alpha_counter = get_str_counter(str1)
    beta_counter = get_str_counter(str2)

    intersection = alpha_counter & beta_counter

    intersection_size = get_total_value(intersection)
    alpha_size = get_total_value(alpha_counter)
    beta_size = get_total_value(beta_counter)

    if alpha_size == 0 and beta_size == 0:
        jac_value = 65536
    else:
        jac_value = intersection_size
        div_value = alpha_size + beta_size - intersection_size
        jac_value = int((jac_value / div_value) * 65536)
    answer = jac_value
    return answer
