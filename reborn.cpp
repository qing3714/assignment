#include <iostream>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;

struct list {
	int age = 0;
	string name;
	string job;
};
struct lista {
	string name1;
	string kind;
	int level =0;
	int time =0;
};

bool repeat(lista* str, string tkind);//检查有无重复
bool check(string tkind, int* f, int* m, int* s, lista* st); //如果有空位,则判断对应职工
int replace(lista* str);   //如果无空位,则返回替换位置的下标
bool empty(lista* stru);  //检查有无空位
int emptyloc(lista* stru); //有空位则返回空位下标
int visitloc(lista* stru, string tkind);//visit位置下标

int main() {
	list all[100] = {  };//人口
	lista structure[3] = {};lista* S = structure;//建筑
	string city;int n = 0;
	cin >> city >> n;
	int f = 0;int m = 0;int s = 0;int* fp = &f;int* mp = &m;int* sp = &s;//职业人口
	int cnt = 0;int currentTime = 1;string order;
	string tname;string tkind;int tlevel;

	for (int i = 0;i < n;i++) {
		cin >> all[cnt].name >> all[cnt].age >> all[cnt].job;

		if ((all[cnt].age < 0))continue;
		else {
			switch (all[cnt].job[0]) {
			case 'F':
				f++;
				break;
			case 'M':
				m++;
				break;
			case 'S':
				s++;
				break;
			}
			cnt++;
		}
	}

	//build检查:重复(true)->人口->空位->补空or替代
	//visit检查:重复(false)->成功

	while (cin >> order && order != "quit") {
		if (order == "build") {
			cin >> tname >> tkind >> tlevel;
			if (repeat(S, tname)) { // 重复
				if (empty(S)) { // 空位
					if (check(tkind, fp, mp, sp, S)) {
						int nowemptyloc = emptyloc(S);
						structure[nowemptyloc].name1 = tname;
						structure[nowemptyloc].kind = tkind;
						structure[nowemptyloc].level = tlevel;
						structure[nowemptyloc].time = currentTime++;
					}
				}
				else { 
					int nowreplace = replace(S);

					// 1.
					if (structure[nowreplace].kind == "farm") f++;
					else if (structure[nowreplace].kind == "mine") m++;
					else if (structure[nowreplace].kind == "academy") s++;

					// 2.
					if (check(tkind, fp, mp, sp, S)) {
						structure[nowreplace].name1 = tname;
						structure[nowreplace].kind = tkind;
						structure[nowreplace].level = tlevel;
						structure[nowreplace].time = currentTime++;
					}
					else {
						// 3
						if (structure[nowreplace].kind == "farm") f--;
						else if (structure[nowreplace].kind == "mine") m--;
						else if (structure[nowreplace].kind == "academy") s--;
					}
				}
			}
			else continue;
		}
		if (order == "visit") {
			cin >> tname;
			if (repeat(S,tname) == false) {
				structure[visitloc(S, tname)].time = currentTime;
				currentTime++;
			}
			else continue; //找不到
		}
	}

	for (int i = 0;i < 3;i++) {
		if (structure[i].level != 0) {
			cout << structure[i].name1 << " " << structure[i].kind << " " << structure[i].level<<endl;
		}
		else
		{
			cout << "无建筑"<<endl;

		}
	}

	return 0;
}


bool repeat(lista* str,string tname) {
	lista* end = str + 3;
	for (;str < end;str++) {
		if (str->name1 == tname) return false;
	}return true;
}
bool check(string tkind,int* f, int* m,int* s,lista* st) {
	if (tkind == "farm") { 
		if ((*f) < 1)return false;
		(*f)--;

	}
	else if (tkind == "mine") {
		if ((*m) < 1)return false;
		(*m)--;
	}
	else if (tkind == "academy") {
		if ((*s) < 1)return false;
		(*s)--;
	}
	return true;
}

int replace(lista* str) {
	lista* start = str; 
	lista* tmp = str;
	for (str = start + 1; str < start + 3; str++) { 
		if (str->time < tmp->time) {
			tmp = str;
		}
	}
	return tmp - start;
}
bool empty(lista* stru) {
	bool sign = false;
	lista* end = stru + 3;
	for (;stru < end;stru++) {
		if (stru->time == 0) { sign = true;break; }
	}
	return sign;
}
int emptyloc(lista* stru) {
	lista* tmp = stru;
	for (;stru < (tmp + 3);stru++) {
		if (stru->time == 0) { return stru-tmp;break; }
	}
	return -1;
}
int visitloc(lista* stru, string tname) {
	lista* tmp = stru;
	for (;stru < (tmp+3);stru++) {
		if (stru->name1 == tname) { return stru - tmp;break; }
	}
	return -1;
}