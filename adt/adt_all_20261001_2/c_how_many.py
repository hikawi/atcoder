s, t = list(map(int, input().strip().split()))

i = 0
for a in range(101):
    for b in range(101):
        for c in range(101):
            if a + b + c <= s and a * b * c <= t:
                i += 1
print(i)
