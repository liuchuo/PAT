#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string name;
    int year, month, day, count = 0;
    int maxyear = 0, maxmonth = 0, maxday = 0, minyear = 9999, minmonth = 9999, minday = 9999;
    string maxname, minname;
    for (int i = 0; i < n; i++) {
        cin >> name;
        scanf("%d/%d/%d",&year, &month, &day);
        if((year < 2014 || (year == 2014 && month < 9) || (year == 2014 && month == 9 && day <= 6)) &&
           (year > 1814 || (year == 1814 && month > 9) || (year == 1814 && month == 9 && day >= 6))) {
            count++;
            if(year > maxyear || (year == maxyear && month > maxmonth) || (year == maxyear && month == maxmonth && day > maxday)) {
                maxyear = year;
                maxmonth = month;
                maxday = day;
                maxname = name;
            }
            if(year < minyear || (year == minyear && month < minmonth) || (year == minyear && month == minmonth && day < minday)) {
                minyear = year;
                minmonth = month;
                minday = day;
                minname = name;
            }
        }
    }
    cout << count;
    if (count != 0)
        cout << " " << minname << " " << maxname;
    return 0;
}