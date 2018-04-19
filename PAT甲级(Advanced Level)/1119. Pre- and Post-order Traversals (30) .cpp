1119. Pre- and Post-order Traversals (30)
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences, or preorder and inorder traversal sequences. However, if only the postorder and preorder traversal sequences are given, the corresponding tree may no longer be unique.
Now given a pair of postorder and preorder traversal sequences, you are supposed to output the corresponding inorder traversal sequence of the tree. If the tree is not unique, simply output any one of them.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.
Output Specification:
For each test case, first printf in a line "Yes" if the tree is unique, or "No" if not. Then print in the next line the inorder traversal sequence of the corresponding binary tree. If the solution is not unique, any answer would do. It is guaranteed that at least one solution exists. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
Sample Input 1:
7
1 2 3 4 6 7 5
2 6 7 4 5 3 1
Sample Output 1:
Yes
2 1 6 4 7 3 5
Sample Input 2:
4
1 2 3 4
2 4 3 1
Sample Output 2:
No
2 1 3 4

题目大意：给出一棵树的结点个数n，以及它的前序遍历和后序遍历，输出它的中序遍历，如果中序遍历不唯一就输出No，且输出其中一个中序即可，如果中序遍历唯一就输出Yes，并输出它的中序
分析：用unique标记是否唯一，如果为true就表示中序是唯一的。
已知二叉树的前序和后序是无法唯一确定一颗二叉树的，因为可能会存在多种情况，这种情况就是一个结点可能是根的左孩子也有可能是根的右孩子，如果发现了一个无法确定的状态，置unique = 0，又因为题目只需要输出一个方案，可以假定这个不可确定的孩子的状态是右孩子，接下来的问题是如何求根结点和左右孩子划分的问题了，首先我们需要知道树的表示范围，需要四个变量，分别是前序的开始的地方prel，前序结束的地方prer，后序开始的地方postl，后序结束的地方postr，前序的开始的第一个应该是后序的最后一个是相等的，这个结点就是根结点，以后序的根结点的前面一个结点作为参考，寻找这个结点在前序的位置，就可以根据这个位置来划分左右孩子，递归处理。

#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
bool unique = true;
void getIn(int preLeft, int preRight, int postLeft, int postRight) {
	if(preLeft == preRight) {
		in.push_back(pre[preLeft]);
		return;
	}
	if (pre[preLeft] == post[postRight]) {
		int i = preLeft + 1;
		while (i <= preRight && pre[i] != post[postRight-1]) i++;
		if (i - preLeft > 1)
			getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
		else
			unique = false;
		in.push_back(post[postRight]);
		getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n), post.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	getIn(0, n-1, 0, n-1);
	printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
	for (int i = 1; i < in.size(); i++)
		printf(" %d", in[i]);
	printf("\n");
	return 0;
}