//���� ���� 3���� ������ 10, 000�� + (���� ��) * 1, 000���� ����� �ް� �ȴ�.
//���� ���� 2���� ������ ��쿡�� 1, 000�� + (���� ��) * 100���� ����� �ް� �ȴ�.
//��� �ٸ� ���� ������ ��쿡��(�� �� ���� ū ��) * 100���� ����� �ް� �ȴ�.
#include <iostream>
#include <stdio.h>
using namespace std;

int A, B, C;
int main()
{
	cin >> A >> B >> C;
	if (A == B && B == C) {
		printf("%d", 10000 + A * 1000);
	}
	else if (A == B) {
		printf("%d", 1000 + A * 100);
	}
	else if(B==C) {
		printf("%d", 1000 + B * 100);
	}
	else if (A == C) {
		printf("%d", 1000 + A * 100);
	}
	else {
		if (A > C&& A > B)printf("%d", A*100);
		else if (B > C&& B > A)printf("%d", B*100);
		else printf("%d", C*100);
	}
	return 0;
}