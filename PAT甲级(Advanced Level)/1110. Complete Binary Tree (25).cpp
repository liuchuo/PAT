1110. Complete Binary Tree (25)
Given a tree, you are supposed to tell if it is a complete binary tree.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=20) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.
Output Specification:
For each case, print in one line "YES" and the index of the last node if the tree is a complete binary tree, or "NO" and the index of the root if not. There must be exactly one space separating the word and the number.
Sample Input 1:
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
Sample Output 1:
YES 8
Sample Input 2:
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -
Sample Output 2:
NO 1

题目大意：给出一个n表示有n个结点，这n个结点为0~n-1，给出这n个结点的左右孩子，求问这棵树是不是完全二叉树
分析：先用结构体tree[i].left和tree[i].right保存第i结点的左右孩子，然后遍历找出没有出现过的结点，这个结点就是根节点
已知根结点和每个结点的左右孩子，根据二叉树的层序遍历的方法（广度优先搜索，使用队列）遍历这棵二叉树，每遍历一个结点就cnt++，如果发现有-1，判断当前cnt是否和n相等，如果不等，说明该结点不是最后一个结点，返回NO，否则YES

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct TREE {
    int left, right;
};
int main() {
    int n, root = 0;
    scanf("%d", &n);
    vector<TREE> tree(n);
    vector<int> book(n);
    for(int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if(l == "-") {
            tree[i].left = -1;
        } else {
            tree[i].left = stoi(l);
            book[tree[i].left] = 1;
        }
        if(r == "-"){
            tree[i].right = -1;
        } else {
            tree[i].right = stoi(r);
            book[tree[i].right] = 1;
        }   
    }
    for(int i = 0; i < n; i++) {
        if(book[i] == 0) {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    int cnt = 0, lastnode = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node != -1) {
            lastnode = node;
            cnt++;
        }else {
            if(cnt != n)
                printf("NO %d", root);
            else
                printf("YES %d", lastnode);
            return 0;
        }
        q.push(tree[node].left);
        q.push(tree[node].right);
    }
    return 0;
}