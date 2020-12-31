# PAT(Advanced Level) 1002 A+B for Polynomials (25分)

This time, you are supposed to find $A+B$ where $A$ and $B$ are two polynomials.

### Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

$K\ N_1\ a_{N_1}\ N_2\ a_{N_2}\ ...\ N_K\ a_{N_K}$

where $K$ is the number of nonzero terms in the polynomial, $N_i$ and $a_{N_i} (i=1,2,⋯,K)$ are the exponents and coefficients, respectively. It is given that $1\le K\le10$，$0\le N_K<⋯< N2<N_1\le 1000$.

### Output Specification:

For each test case you should output the sum of *A* and *B* in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

### Sample Input:

```in
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

### Sample Output:

```out
3 2 1.5 1 2.9 0 3.2
```

## defaultdict

```python
import collections

# 用 defaultdict 读取输入并进行相加计算
line_a, line_b = input().split(), input().split()
k_a, k_b = int(line_a[0]), int(line_b[0])
d = collections.defaultdict(float)
for i in range(k_a):
    n, a_n = int(line_a[2 * i + 1]), float(line_a[2 * i + 2])
    d[n] += a_n
for i in range(k_b):
    n, a_n = int(line_b[2 * i + 1]), float(line_b[2 * i + 2])
    d[n] += a_n

# 对结果进行格式化输出
result = []
count = 0
for key in sorted(d.keys(), reverse=True):
    if not d[key]:
        # 如果该项相加结果为 0.0，则跳过
        continue
    # 对非零项进行计数
    count += 1
    result += [key, '{:.1f}'.format(d[key])]
# 将非零项个数添加到结果里
result.insert(0, count)
print(' '.join(map(str, result)))
```

时间复杂度：$O((m+n)log(m+n))$。

空间复杂度：$O(m+n)$。

## 数组

```python
import collections

# 用一个长度为 1001 的列表读取输入并进行相加计算
line_a, line_b = input().split(), input().split()
k_a, k_b = int(line_a[0]), int(line_b[0])
size = 1001
array = [0.0] * size
for i in range(k_a):
    n, a_n = int(line_a[2 * i + 1]), float(line_a[2 * i + 2])
    array[n] += a_n
for i in range(k_b):
    n, a_n = int(line_b[2 * i + 1]), float(line_b[2 * i + 2])
    array[n] += a_n

# 对结果进行格式化输出
result = []
count = 0
for i in range(size - 1, -1, -1):
    if not array[i]:
        # 如果该项相加结果为 0.0，则跳过
        continue
    # 对非零项进行计数
    count += 1
    result += [i, '{:.1f}'.format(array[i])]
# 将非零项个数添加到结果里
result.insert(0, count)
print(' '.join(map(str, result)))
```

时间复杂度：$O(1)$，系数是 1000。

空间复杂度：$O(1)$，系数是 1000。

## 参考链接

1. [PAT(Advanced Level) 1002 A+B for Polynomials (25分)](https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000)