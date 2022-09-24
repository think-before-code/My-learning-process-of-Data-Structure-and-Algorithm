#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int price;
	int weight;
}rice, * riceptr;
bool cmp(rice a, rice b) {
	return a.price < b.price;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int money, type;
		float buyweight = 0;
		cin >> money >> type;
		riceptr p = new rice[type];
		for (int i = 0; i < type; i++) {//¶ÁÈëÊý¾Ý
			cin >> p[i].price >> p[i].weight;
		}
		sort(p, p + type, cmp);
		for (int i = 0; i < type && money; i++) {
			if (money > p[i].price * p[i].weight) {
				money -= p[i].price * p[i].weight;
				buyweight += p[i].weight;
				continue;
			}
			buyweight += money * 1.0 / p[i].price;
			money = 0;
		}
		printf("%.2f\n", buyweight);
		delete[]p;
	}
	return 0;
}