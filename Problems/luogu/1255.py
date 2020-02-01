n = int(input()) + 1
if n == 1:
    print(0)
    exit(0)
a = [0, 1]
for i in range(2, n + 1):
    a.append(a[i - 1] + a[i - 2])
print(a[n])
