from itertools import combinations


def solution(relation):
    answer = 0
    relation_rows = len(relation)
    relation_cols = len(relation[0])
    col_combinations = []
    for col_count in range(1, relation_cols + 1):
        col_combinations.extend(combinations(range(relation_cols), col_count))

    unique_combinations = []
    for combination in col_combinations:
        valid_key = False
        grab_count = len(
            set(
                tuple(rel_item[column_index] for column_index in combination)
                for rel_item in relation
            )
        )
        # 일단 전부 포함하는 조합임 -> 이제 subset 으로 최소성 깨야함
        if grab_count == relation_rows:
            valid_key = True
            for unique_item in unique_combinations:
                if set(unique_item).issubset(set(combination)):
                    valid_key = False
                    break
            if valid_key:
                unique_combinations.append(combination)

    answer = len(unique_combinations)
    return answer
