#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int N, M, res;
bool bigv[100], smallv[100];
vector<int> big[100], small[100];

int big_DFS(int node) { // big ����Ʈ�� DFS

	bigv[node] = true;
	int sum = 0;

	// ��͸� ���� �� ����� �ڿ� ������ ��ִ��� ����
	for (int i = 0; i < big[node].size(); i++) {
		int next = big[node][i];
		if (!bigv[next]) sum += big_DFS(next) + 1;
	}

	return sum;
}

int small_DFS(int node) { // small ����Ʈ�� DFS

	smallv[node] = true;
	int sum = 0;

	// ��͸� ���� �� ����� �ڿ� ������ ��ִ��� ����
	for (int i = 0; i < small[node].size(); i++) {
		int next = small[node][i];
		if (!smallv[next])sum += small_DFS(next) + 1;
	}

	return sum;
}

int main() {
	cin >> N >> M;

	int s, e;
	int half = (N + 1) / 2;

	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		// ���� s���� e�� ���� ���̴�
		// ���ſ�� ������ ���� ��������Ʈ�� �ڷ� ���� ��������Ʈ�� ���� ����� ����

		big[s].push_back(e); // ���ſ�� �����ΰ��� ����Ʈ
		small[e].push_back(s); // ������� ������ ���� ����Ʈ
	}



	for (int i = 1; i <= N; i++) {

		// �湮 �迭 �ʱ�ȭ
		memset(smallv, false, sizeof(bigv));
		memset(bigv, false, sizeof(smallv));

		// i ��° ������ �� DFS�� ������
		int b = big_DFS(i);
		int s = small_DFS(i);

		// ���� �� ���� �ڿ� N/2 ���� ���� ������ �ִٸ� ���� �߰��ڸ��� �� �� ����
		if (b >= half || s >= half) res++;
	}

	cout << res << '\n';
	return 0;
}
