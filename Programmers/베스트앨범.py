from typing import List, Dict


def add_index_by_play(index_list: List[Dict], play_item: int, current_index: int):
    temp_item = (play_item, current_index)

    index_list.append(temp_item)
    index_list = sorted(index_list, key=lambda item: -item[0])
    if len(index_list) >= 2:
        index_list = [index_list[0], index_list[1]]
    return index_list


def solution(genres, plays):
    answer = []

    sum_dict = {}
    index_dict = {}

    for index, (genre_item, play_item) in enumerate(list(zip(genres, plays))):
        sum_genre = sum_dict.get(genre_item)
        index_genre = index_dict.get(genre_item)
        if index_genre is None:
            index_dict[genre_item] = []

        if sum_genre is None:
            sum_dict[genre_item] = 0
        sum_dict[genre_item] += play_item
        index_dict[genre_item] = add_index_by_play(
            index_dict.get(genre_item), play_item, index
        )

    popular_sort = sorted(sum_dict.items(), key=lambda item: -item[1])
    for popular_genre, _ in popular_sort:
        index_items = index_dict.get(popular_genre)
        for index_item in index_items:
            index_val = index_item[1]
            answer.append(index_val)

    return answer

