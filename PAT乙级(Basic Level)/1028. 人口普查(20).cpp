1028. �˿��ղ�(20)
ʱ������
200 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
ĳ��������˿��ղ飬�õ���ȫ���������ա�������д�������ҳ��������곤����������ˡ�

����ȷ��ÿ����������ڶ��ǺϷ��ģ�����һ���Ǻ���ġ���������֪����û�г���200������ˣ���������2014��9��6�գ����Գ���200������պ�δ���������ն��ǲ�����ģ�Ӧ�ñ����˵���

�����ʽ��

�����ڵ�һ�и���������N��ȡֵ��(0, 105]�����N�У�ÿ�и���1���˵��������ɲ�����5��Ӣ����ĸ��ɵ��ַ��������Լ�����yyyy/mm/dd��������/��/�գ���ʽ���������ա���Ŀ��֤���곤�����������û�в��С�

�����ʽ��

��һ����˳�������Ч���յĸ��������곤�˺��������˵�����������Կո�ָ���

����������
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
���������
3 Tom John
#include <iostream>
#include <string>
using namespace std;
struct peo{
	string name;
	int year, mon, date, id;
	//id��ʾ�����֤һ�������ձ��;  
	//idԽСԽ��,Խ��Խ����; 
}t; 
int main() {
	int n, cnt = 0, maxn = 0, minn =20140907;
	string maxname,minname;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t.name;
		scanf("%d/%d/%d",&t.year, &t.mon, &t.date);
		t.id  = 10000* t.year + 100*t.mon + t.date ;//��дid���� 
		if(t.id >=18140906 && t.id <= 20140906) {
			cnt++;
			if(t.id > maxn) {
				maxn = t.id ;
				maxname = t.name ;
			}
			if(t.id < minn) {
				minn = t.id ;
				minname = t.name ;
			}
		}
	}
	cout << cnt ;
	if(cnt != 0)
		cout << ' ' << minname << ' ' << maxname;//idԽСԽ�� 
return 0;
}

