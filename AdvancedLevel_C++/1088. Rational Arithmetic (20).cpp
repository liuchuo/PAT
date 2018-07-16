1088. Rational Arithmetic (20)
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.
Input Specification:
Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.
Output Specification:
For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.
Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

#include <iostream>
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