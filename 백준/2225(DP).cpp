#include<iostream>

using namespace std;
int N, K;
long long int dp[201][201];

int main()
{
	cin >> N >> K;
	for (int i = 0; i <= N; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= K; i++)
	{											//dp[3][30] = 3���� 30�� ������ �ϴ� ���
		for (int j = 0; j <= N; j++)			//�������� ���ϴ� ���� 0�̶�� 2���� 30�� ����� ��찡 �����װ�
		{										//�������� ���ϴ� ���� 1�̶�� 2���� 29�� ����� ��찡 �����װ�
			for (int k = 0; k <= j; k++)		//�������� ���ϴ� ���� 2��� 2���� 28�� ����� ��찡 ����
			{
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= 1000000000;
		}
	}
	cout << dp[K][N];
}