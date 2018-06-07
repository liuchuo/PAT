1147. Heaps (30)
In computer science, a heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. A common implementation of a heap is the binary heap, in which the tree is a complete binary tree. (Quoted from Wikipedia at https://en.wikipedia.org/wiki/Heap_(data_structure))
Your job is to tell if a given complete binary tree is a heap.
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers: M (<= 100), the number of trees to be tested; and N (1 < N <= 1000), the number of keys in each tree, respectively. Then M lines follow, each contains N distinct integer keys (all in the range of int), which gives the level order traversal sequence of a complete binary tree.
Output Specification:
For each given tree, print in a line "Max Heap" if it is a max heap, or "Min Heap" for a min heap, or "Not Heap" if it is not a heap at all. Then in the next line print the trees postorder traversal sequence. All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line.

Sample Input:
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56
Sample Output:
Max Heap
50 60 65 72 12 23 86 98
Min Heap
60 58 52 38 82 70 25 8
Not Heap
56 12 34 28 9 8 15 10

题目大意：给一个树的层序遍历，判断它是不是堆，是大顶堆还是小顶堆。输出这个树的后序遍历～
分析：30分大题，一行代码一分……（(⊙o⊙)嗯） // 我为什么这么机智可爱又伶俐？
首先根据v[0]和v[1]的大小比较判断可能是大顶还是小顶，分别赋值flag为1和-1，先根据层序遍历，从0～(n-1)/2【所有有孩子的结点】判断他们的孩子是不是满足flag的要求，如果有一个结点不满足，那就将flag=0表示这不是一个堆。根据flag输出是否是堆，大顶堆还是小顶堆，然后后序遍历，根据index分别遍历index*2+1和index*2+2，即他们的左右孩子，遍历完左右子树后输出根结点，即完成了后序遍历～

#include <iostream>
#include <vector>
using namespace std;
int m, n;
vector<int> v;
void postOrder(int index) {
    if (index >= n) return;
    postOrder(index * 2 + 1);
    postOrder(index * 2 + 2);
    printf("%d%s", v[index], index == 0 ? "\n" : " ");
}
int main() {
    scanf("%d%d", &m, &n);
    v.resize(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &v[j]);
        int flag = v[0] > v[1] ? 1 : -1;
        for (int j = 0; j <= (n-1) / 2; j++) {
            int left = j * 2 + 1, right = j * 2 + 2;
            if (flag == 1 && (v[j] < v[left] || (right < n && v[j] < v[right]))) flag = 0;
            if (flag == -1 && (v[j] > v[left] || (right < n && v[j] > v[right]))) flag = 0;
        }
        if (flag == 0) printf("Not Heap\n");
        else printf("%s Heap\n", flag == 1 ? "Max" : "Min");
        postOrder(0);
    }
    return 0;
}

