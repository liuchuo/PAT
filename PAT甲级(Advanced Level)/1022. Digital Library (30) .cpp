1022. Digital Library (30)
A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:
Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.
After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:
1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:
For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.
Sample Input:
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
Sample Output:
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found

题目大意：模拟数字图书馆的查询功能。会给出n本书的信息，以及m个需要查询的命令，数字标号对应相应的命令，数字编号后面的字符串是查询的搜索词，要求输出这行命令以及输出满足条件的书的id，如果一个都没有找到，输出Not Found
分析：
- 对除了id之外的其他信息都建立一个map<string, set<int>>，把相应的id插入对应搜索词的map的集合里面，形成一个信息对应一个集合，集合里面是复合条件的书的id。
- 因为对于输入的关键词（可以重复，算是书本对应的tag标签吧~~）没有给定关键词的个数，可以使用while(cin >> s)并且判断c = getchar()，c是否等于\n，如果是再退出循环~~~~
- 建立query，通过传参的形式可以将不同的map名称统一化，先要判断map.find()和m.end()是否相等，如果不等再去遍历整个map，输出所有满足条件的id，如果相等就说明不存在这个搜索词对应的id，那么就要输出Not Found。
- 传参一定要用引用，否则最后一组数据可能会超时。

#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, set<int> > title, author, key, pub, year;
void query(map< string, set<int> > &m, string &str) {
    if(m.find(str) != m.end()) {
        for(set<int>::iterator it = m[str].begin(); it != m[str].end(); it++)
            printf("%07d\n", *it);
    } else
        cout << "Not Found\n";
}
int main() {
    int n, m, id, num;
    scanf("%d", &n);
    string ttitle, tauthor, tkey, tpub, tyear;
    for(int i = 0; i < n; i++) {
        scanf("%d", &id);
        getchar();
        getline(cin, ttitle);
        title[ttitle].insert(id);
        getline(cin, tauthor);
        author[tauthor].insert(id);
        while(cin >> tkey) {
            key[tkey].insert(id);
            char c;
            c = getchar();
            if(c == '\n') break;
        }
        getline(cin, tpub);
        pub[tpub].insert(id);
        getline(cin, tyear);
        year[tyear].insert(id);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << "\n";
        if(num == 1) query(title, temp);
        else if(num == 2) query(author, temp);
        else if(num == 3) query(key, temp);
        else if(num == 4) query(pub,temp);
        else if(num ==5) query(year, temp);
    }
    return 0;
}