def main():
    nums = list(map(int, input().strip().split()))
    c = {}
    for n in nums:
        if n not in c:
            c[n] = 0
        c[n] += 1

    vals = frozenset(c.values())
    if vals == frozenset([1, 3]) or vals == frozenset([2, 2]):
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
