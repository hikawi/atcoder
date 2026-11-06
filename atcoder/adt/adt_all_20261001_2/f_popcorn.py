from itertools import combinations

n, m = list(map(int, input().strip().split()))
S = [[c == "o" for c in input().strip()] for _ in range(n)]


def run():
    # Check for case i = 1
    for s in S:
        if all(s):
            print("1")
            return

    # n, m is smol so we can loop
    for i in range(2, n + 1):
        for comb in combinations(S, i):
            if all(any(c) for c in zip(*comb)):
                print(i)
                return

    print("-1")


run()
