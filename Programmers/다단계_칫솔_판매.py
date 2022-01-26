def find(parents, money, index, answer):
    if parents[index] == index or int(money / 10) == 0:
        answer[index] += money
        return

    fees = int(money / 10)
    profit = money - fees
    answer[index] += profit
    find(parents, fees, parents[index], answer)
    return


def solution(enroll, referral, seller, amount):
    length = len(enroll)
    answer = [0] * (length + 1)
    name_index = {}
    parents = [index for index in range(length + 1)]
    for i in range(length):
        name_index[enroll[i]] = i + 1

    for i in range(length):
        # center 와 직접 연결
        if referral[i] == "-":
            parents[i + 1] = 0
        else:
            ref_index = name_index.get(referral[i])
            parents[i + 1] = ref_index

    for seller_item, amount_item in zip(seller, amount):
        find(parents, amount_item * 100, name_index.get(seller_item), answer)

    answer = answer[1:]  # 0번 인덱스는 제외(Center)
    return answer
