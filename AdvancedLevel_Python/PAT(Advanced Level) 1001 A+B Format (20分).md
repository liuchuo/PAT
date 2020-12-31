# PAT(Advanced Level) 1001 A+B Format (20分)

Calculate $a+b$ and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

### Input Specification:

Each input file contains one test case. Each case contains a pair of integers $a$ and $b$ where $−10^6\le a,b\le 10^6$. The numbers are separated by a space.

### Output Specification:

For each test case, you should output the sum of $a$ and $b$ in one line. The sum must be written in the standard format.

### Sample Input:

```in
-1000000 9
```

### Sample Output:

```out
-999,991
```

## format

```python
print(format(sum(map(int, input().split())), ','))
```

时间复杂度：$O(1)$。

空间复杂度：$O(1)$。

## 长度判断

```python
s = sum(map(int, input().split()))
if s < 0:
    print('-', end='')
    s = -s
s = str(s)
if len(s) <= 3:
    print(s)
elif len(s) <= 6:
    print(s[:-3] + ',' + s[-3:])
else:
    print(s[:-6] + ',' + s[-6:-3] + ',' + s[-3:])
```

时间复杂度：$O(1)$。

空间复杂度：$O(1)$。

## 参考链接

1. [PAT(Advanced Level) 1001 A+B Format (20分)](https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400)