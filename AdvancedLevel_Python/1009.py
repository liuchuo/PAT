a = list(map(float, input().split()))

b = list(map(float, input().split()))

arr1 = [[a[2*i +1], a[2*i+2]] for i in range(int(a[0]))]

arr2 = [[b[2*i + 1], b[2*i+2]] for i in  range(int(b[0]))]

def conv(arr1, arr2):

    matrix = {}

    for x in arr1:
        def dot(x, arr2):
            ans = []
            for y in arr2:
                ans.append([x[0]+y[0],x[1]*y[1]])
            return ans

        vector = dot(x, arr2)

        for z in vector:
            if z[0] in matrix:
                matrix[z[0]] += z[1]
            else:
                matrix[z[0]] = z[1]
    matrix_ = sorted(matrix, key=lambda x:-x)
    return str(len([key for key in iter(matrix) if matrix[key] != 0 ])) + ' ' + ''.join([str(int(key)) + ' ' + str(round(matrix[key] *10) / 10) +' ' for key in matrix_ if matrix[key] != 0])

print(conv(arr1, arr2)[:-1])
