1078. Hashing (25)
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.
Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.
Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (<=104) and N (<=MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.
Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -

题目大意：给出散列表长和要插入的元素，将这些元素按照读入的顺序插入散列表中，其中散列函数为h(key) = key % TSize，解决冲突采用只向正向增加的二次方探查法。如果题中给出的TSize不是素数，就取第一个比TSize大的素数作为TSize
分析：先解决size是否为素数，不是素数就要重新赋值的问题
然后根据二次方探查法：
- 如果hashTable里面key % size的下标对应的hashTable为false,说明这个下标没有被使用过，直接输出。否则step步长从1加到size-1，一次次尝试是否能使index = (key + step * step) % size;所对应的位置没有元素，如果都没有找到就输出“-”，否则就输出这个找到的元素的位置。~~~~~

#include <iostream>
bool isprime(int a) {
    if(a == 1) return false;
    for(int i = 2; i * i <= a; i++)
        if(a % i == 0)
            return false;
    return true;
}
int func(int a) {
    while(isprime(a) == false)
        a++;
    return a;
}
bool hashTable[10010];
int main() {
    int MSize, n, key;
    scanf("%d %d", &MSize, &n);
    int size = func(MSize);
    for(int i = 0; i < n; i++) {
        scanf("%d", &key);
        int index = key % size;
        if(hashTable[index] == false) {
            hashTable[index] = true;
            if(i != 0) printf(" ");
            printf("%d", index);
        } else {
            int flag = 0;
            for(int step = 1; step < size; step++) {
                index = (key + step * step) % size;
                if(hashTable[index] == false) {
                    hashTable[index] = true;
                    flag = 1;
                    if(i != 0) printf(" ");
                    printf("%d", index);
                    break;
                }
            }
            if(flag == 0) {
                if(i != 0) printf(" ");
                printf("-");
            }
        }
    }
    return 0;
}