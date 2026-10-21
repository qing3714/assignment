#include <iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

struct list {
	int age = 0;
	string name;
	string job;
};
struct lista {
	string name1;
	string kind;
	int level = 0;
};
struct listb {
	string cname;
	int id = 0;
	int popnum=0;
	int pronum=0;
	struct list all[100] = {};
	struct lista structure[100] = {};
};
        listb city[50] = {};

int compute(lista* s, int k);
bool cmp(const listb& city1, const listb& city2);

int main() {
	int n = 0;int m = 0;int k = 0;
	lista* S = city[0].structure;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int cnt = 0;
		cin >> city[i].cname >> m;
		city[i].id = i;
		for (int j = 0;j < m;j++) {
			cin >> city[i].all[cnt].name >> city[i].all[cnt].age >> city[i].all[cnt].job;
			if (city[i].all[cnt].age >= 0)cnt++;
		}
		cin >> k;
		for (int t = 0;t < k;t++) {
			cin >> city[i].structure[t].name1 >> city[i].structure[t].kind >> city[i].structure[t].level;
		}
		S = city[i].structure;
		city[i].popnum = cnt;
		city[i].pronum = compute(S,k)-(2*cnt);
	}
	sort(city, city+n, cmp);
	if (n == 0) {
		cout << "空排行榜" << endl;
	}
	for (int fin = 0;fin < n;fin++) {
		cout << city[fin].cname << " " << city[fin].popnum << " " << city[fin].pronum << endl;
	}
	return 0;
}

int compute(lista* s, int k) {
	int outcome = 0;
	lista* tmp = s;
	for (;tmp < (s + k);tmp++) {
		if (tmp->kind == "farm")outcome += 4;
		else if (tmp->kind == "plantation")outcome += 3;
		else continue;
	}
	return outcome;
}

bool cmp(const listb& city1,const listb& city2) {
	if (city1.popnum != city2.popnum) return city1.popnum > city2.popnum;
	if (city1.pronum != city2.pronum)return city1.pronum > city2.pronum;
	return city1.id < city2.id;
 }