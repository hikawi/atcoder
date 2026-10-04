def main():
    n = int(input().strip()) - 1
    s = ""
    while n > 0:
        s += str((n % 5) * 2)
        n //= 5

    if len(s) == 0:
        print("0")
    else:
        print(s[::-1])


if __name__ == "__main__":
    main()
