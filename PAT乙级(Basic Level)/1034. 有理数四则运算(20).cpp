1034. 有理数四则运算(20)
本题要求编写程序，计算2个有理数的和、差、积、商。
输入格式：
输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。
输出格式：
分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式“k a/b”，其中k是整数部分，a/b是最简分数部分；若为负数，则须加括号；若除法分母为0，则输出“Inf”。题目保证正确的输出中没有超过整型范围的整数。
输入样例1：
2/3 -4/2
输出样例1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例2：
5/3 0/6
输出样例2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

#include <iostream>
#include <cstdio>
using namespace std;
long long int a, b, c, d;

long long int gcd(long long int t1, long long int t2) {
    return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}

void func(long long int m, long long int n) {
    int flag1 = 0;
    int flag2 = 0;
    if (n == 0) {
        cout << "Inf";
        return ;
    }
    if (m == 0) {
        cout << 0;
        return ;
    }
    
    if (m < 0) {
        m = 0 - m;
        flag1 = 1;
    }
    if (n < 0) {
        n = 0 - n;
        flag2 = 1;
    }
    int flag = 0;
    if (flag1 == 1 && flag2 == 1) {
        flag = 0;
    } else if (flag1 == 1 || flag2 == 1) {
        flag = 1;
    }
    if (m == n) {
        if (flag == 1)
            cout << "(-1)";
        else
            cout << "1";
        return;
    }
            
    long long int x = m % n;
    long long int y = m / n;
    if (x == 0) {
        if (flag == 0)
            cout << y;
        else
            cout << "(-" << y << ")";
        return ;
    } else {
        long long int t1 = m - y * n;
        long long int t2 = n;
        long long int t = gcd(t1, t2);
        t1 = t1 / t;
        t2 = t2 / t;
        if (flag == 1) {
            cout << "(-";
        if (y != 0)
            cout << y << " " << t1 << "/" << t2;
            else
                cout << t1 << "/" << t2;
        cout << ")";
        } else {
            if (y != 0)
                cout << y << " " << t1 << "/" << t2;
            else
                cout << t1 << "/" << t2;
        }
    }
}

void add() {
    long long int m, n;
    m = a * d + b * c;
    n = b * d;
    func(a, b);
    cout << " + ";
    func(c, d);
    cout << " = ";
    func(m, n);
    cout << endl;
}

void min() {
    long long int m, n;
    m = a * d - b * c;
    n = b * d;
    func(a, b);
    cout << " - ";
    func(c, d);
    cout << " = ";
    func(m, n);
    cout << endl;
}

void multi() {
    long long int m, n;
    m = a * c;
    n = b * d;
    func(a, b);
    cout << " * ";
    func(c, d);
    cout << " = ";
    func(m, n);
    cout << endl;
}

void div() {
    long long int m, n;
    m = a * d;
    n = b * c;
    func(a, b);
    cout << " / ";
    func(c, d);
    cout << " = ";
    func(m, n);
    cout << endl;
}

int main() {
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    add();
    min();
    multi();
    div();
    return 0;
}