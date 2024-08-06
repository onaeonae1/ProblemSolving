def solution(brown, yellow):
    answer = []

    total = brown + yellow
    limit = 2500000

    for height in range(3, limit):
        width = total // height
        if width < height:
            break
        if height * width == total:
            # print(f"{height} | {width} [{total}]")
            yellow_height = height - 2
            yellow_width = width - 2

            if yellow_height * yellow_width == yellow:
                answer.append(width)
                answer.append(height)
                break

    return answer


# solution(10, 2)  # 4,3
# solution(8, 1)  # 3,3
