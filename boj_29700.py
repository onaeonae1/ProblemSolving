N, M, K = map(int, input().split())

seats = [input() for _ in range(N)]


def main():
    found = 0
    for row in seats:
        is_linked = False
        linked_count = 0
        for item in row:
            if item == "1":
                temp = linked_count - K + 1
                if temp > 0:
                    found += temp
                is_linked = False
                linked_count = 0
            else:
                is_linked = True
                linked_count += 1
        # check after
        if is_linked:
            temp = linked_count - K + 1
            if temp > 0:
                found += temp

    return found


ans = main()
print(ans)
