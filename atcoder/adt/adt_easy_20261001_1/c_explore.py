def main():
    n, m, t = list(map(int, input().strip().split()))
    costs = list(map(int, input().strip().split()))
    bonus = {}
    for _ in range(m):
        x, y = list(map(int, input().strip().split()))
        bonus[x] = y

    cur = 1
    while cur < n:
        if t <= costs[cur - 1]:
            print("No")
            return
        t -= costs[cur - 1]
        cur += 1
        t += bonus.get(cur, 0)
    print("Yes")


if __name__ == "__main__":
    main()
