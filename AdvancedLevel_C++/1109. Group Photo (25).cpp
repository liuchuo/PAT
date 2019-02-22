#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

struct Person {
    string name;
    int height;
};

vector<Person> people;
deque<string> q;
int i = 0;

void Formate(int num) {
    q.push_back(people[i++].name);
    while (q.size() < num) {
        if (q.size() % 2) q.push_front(people[i].name);
        else              q.push_back (people[i].name);
        i++;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    people.resize(n);
    for (int i = 0; i < n; i++)
        cin >> people[i].name >> people[i].height;
    sort(people.begin(), people.end(), [](Person a, Person b) {
        return a.height != b.height ? a.height > b.height : a.name < b.name;
    });
    while (i < n) {
        if (i == 0) Formate(n / k + n % k);
        else        Formate(n / k);
        for (int i = 0; i < q.size(); i++)
            cout << q[i] << (i < q.size() - 1 ? ' ' : '\n');
        q.clear();
    }
    return 0;
}