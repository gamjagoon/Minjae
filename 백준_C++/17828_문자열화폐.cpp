#include <stdio.h>
#include <string.h>
char A[5000000000];
char B[5000000000];
int main()
{
	int N, X, Z, middle = 0;
	scanf("%d %d", &N, &X);
	memset(A, 'A', N);
	memset(B, 'Z', N);
	if (N * 26 < X || N > X) {
		printf("!");
		return 0;
	}
	else
		{
			X -= N;//A �� �̸� ��ġ
			Z = X / 25;//Z�� ������ ���Ѵ�.
			N -= Z;
			middle = X % 25;//25 ��ġ�� ������
			if (middle == 0)//�߰��� ����
			{
				A[N] = '\0';
				B[Z] = '\0';
				printf("%s%s", A, B);
				return 0;
			}
			else
			{
				N--;
				A[N] = '\0';
				B[Z] = '\0';
				printf("%s", A);
				printf("%c", middle + 'A');
				printf("%s", B);
				return 0;
			}
		}
}