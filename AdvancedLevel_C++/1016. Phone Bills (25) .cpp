1016. Phone Bills (25)
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:

Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".

For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct record{
    string name;
    int month, day;
    long int time;
    bool status;
};
struct call{
    record* start;
    record* end;
    long int time;
    double fee;
};
struct person{
    string name;
    vector<call*> calls;
    vector<record*> records;
    double total_cost;
};
bool cmp(record *a, record *b) {
    if (strcmp(a->name.c_str(), b->name.c_str()) != 0)
        return strcmp(a->name.c_str(), b->name.c_str()) < 0;
    if (a->day != b->day)
            return a->day < b->day;
    return a->time < b->time;
}
void resetList(vector<record*> & v){
    vector<record*> v2;
    int start = 0;
    int end = (int)v.size() - 1;
    while (start <= (int)v.size() - 1 && !v[start]->status) start++;
    while (end >= 0 && v[end]->status) end--;
    if (start < end) {
        for (int i = start; i <= end; i++) {
            if ((i != end && v[i]->status == v[i + 1]->status && v[i]->status == true) || (i != start && v[i - 1]->status == v[i]->status && v[i]->status == false))
                continue;
            else
                v2.push_back(v[i]);
        }
    }
    v = v2;
}
double getPrice(double* pay, double* hour_pay, double day_pay, record* start, record* end){
    double total = 0;
    int start_day = start->day;
    int end_day = end->day;
    long int start_time = start->time;
    long int end_time = end->time;
    total += day_pay * (end_day - start_day);
    if(start_time < end_time){
        for (int i = (int)(start_time/60); i < end_time/60; i++)
            total += hour_pay[i];
        total -= pay[start_time/60]*(start_time%60);
        total += pay[end_time/60]*(end_time%60);
    }else if(start_time > end_time){
        for (int i = (int)(end_time/60); i < start_time/60; i++)
            total -= hour_pay[i];
        total -= pay[start_time/60]*(start_time%60);
        total += pay[end_time/60]*(end_time%60);
    }
    return total;
}
int main(int argc, const char * argv[]) {
    double pay[24], hour_pay[24];
    for (int i = 0; i < 24; i++) {
        double pay_temp;
        scanf("%lf", &pay_temp);
        pay[i] = pay_temp/100;
    }
    double day_pay;
    for (int i = 0; i < 24; i++) {
        hour_pay[i] = pay[i]*60;
        day_pay += hour_pay[i];
    }
    int recordNum;
    scanf("%d", &recordNum);
    vector<record*> lst_main;
    for (int i = 0; i < recordNum; i++) {
        string name, status;
        int month, day, hour, min;
        cin >> name;
        scanf("%d:%d:%d:%d",  &month, &day, &hour, &min);
        cin >> status;
        record* r = new record();
        r->name = name;
        r->status = status == "on-line";
        r->month = month;
        r->day = day;
        r->time = hour * 60 + min;
        lst_main.push_back(r);
    }
    sort(lst_main.begin(), lst_main.end(), cmp);
    vector<person*> persons;
    string tempString;
    for (int i = 0; i < lst_main.size(); i++) {
        if (tempString != lst_main[i]->name) {
            person* p = new person();
            p->name = lst_main[i]->name;
            persons.push_back(p);
            tempString = p->name;
        }
        persons.back()->records.push_back(lst_main[i]);
    }
    for (int i = 0; i < persons.size(); i++) {
        resetList(persons[i]->records);
        persons[i]->total_cost = 0;
        for (int j = 0; j < persons[i]->records.size(); j = j + 2){
            call* c = new call();
            c->start = persons[i]->records[j];
            c->end = persons[i]->records[j + 1];
            c->time = (c->end->day - c->start->day)*24*60 + c->end->time - c->start->time;
            c->fee = getPrice(pay, hour_pay, day_pay, c->start, c->end);
            persons[i]->total_cost += c->fee;
            persons[i]->calls.push_back(c);
        }
    }
    for (int i = 0; i < persons.size(); i++) {
        if (persons[i]->total_cost > 0) {
            printf("%s %02d\n", persons[i]->name.c_str(), persons[i]->records[0]->month);
            for (int j = 0; j < persons[i]->calls.size(); j++) {
                if (persons[i]->calls[j]->time <= 0)
                    continue;
                printf("%02d:%02d:%02d %02d:%02d:%02d %ld $%.2f\n", persons[i]->calls[j]->start->day, (int)(persons[i]->calls[j]->start->time/60), (int)(persons[i]->calls[j]->start->time%60), (int)(persons[i]->calls[j]->end->day), (int)(persons[i]->calls[j]->end->time/60), (int)(persons[i]->calls[j]->end->time%60), persons[i]->calls[j]->time, persons[i]->calls[j]->fee);
            }
            printf("Total amount: $%.2f\n", persons[i]->total_cost);
        }
    }
    return 0;
}