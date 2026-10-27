n, q = list(map(int, input().strip().split()))
A = list(map(int, input().strip().split()))
Q = [tuple(map(int, input().strip().split())) for _ in range(q)]
C = {}  # current running count
F = {}  # frequencies

for i, a in enumerate(A):
    if a not in C:
        C[a] = 0
    C[a] += 1
    F[a, C[a]] = i + 1

for x, k in Q:
    print(F.get((x, k), -1))
