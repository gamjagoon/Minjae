#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
bool pushed[32001];
vector <int>Dag[32001];
vector<int>slave(32001);
queue <int>list;
stack<int>result;

/*
ptr �� ����Ű�� ���ڰ� �̹� ���ÿ� ���ų� 1���� ������ ���� return
ptr ���� �ڿ� �;��ϴ� �͵��� ����. �׳� �߰�
ptr ������ �˻��ؼ� ptr ���� �켱������ �ִ°ͺ��� ���� �켱�������ִٸ�
��ͷ� find ȣ��
*/
void find(int ptr) {
	if (pushed[ptr] || ptr < 1) {
		return;
	}
	if (Dag[ptr].empty()) {
		result.push(ptr);
		pushed[ptr] = true;
	}
	else {
		int dsize = Dag[ptr].size();
		for (int i = 0; i < dsize; ++i) {
			int tmp = Dag[ptr].back();
			Dag[ptr].pop_back();
			if (pushed[tmp])continue;
			if (Dag[tmp].empty()) {
				result.push(tmp);
				pushed[tmp] = true;
			}
			else {
				find(tmp);
			}
		}
		result.push(ptr);
		pushed[ptr] = true;
	}
	return;
}
//sort �񱳿� �Լ�
bool cmp(int a, int b) {
	return a < b;
}


int main()
{
	//�Է�********************
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int p, s;
	while (M--) {
		cin >> p >> s;
		Dag[p].push_back(s);
		slave[s]++;
	}
	// Dag �� �����߿� 1�� �̻��ΰ� ����
	for (int i = 1; i <= N; ++i) {
		if (Dag[i].size() > 1) {
			sort(Dag[i].begin(), Dag[i].end(), cmp);
		}
	}
	//�����ؼ� ���ÿ� �ִ´�*****************
	int ptr = N;
	int com = 0;
	while (result.size() < N) {
		for (int i = N; i >= 0; --i) {
			if (slave[i] == com) {
				list.push(i);
			}
		}
		while (!list.empty()) {
			int tmp = list.front();
			list.pop();
			find(tmp);
		}
		com++;
	}
	//���ÿ��� ����Ѵ�*****************
	while (!result.empty())
	{
		printf("%d ", result.top());
		result.pop();
	}
	return 0;
}