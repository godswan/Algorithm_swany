#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 3���� ��ȯ
// 3 ���� -> �ڸ��� 1
// 12 (3 + 9) ���� -> �ڸ��� 2
// 39 (3 + 9 + 27) ���� -> �ڸ��� 3
// 120 (3 + 9 + 27 + 81) ���� -> �ڸ��� 4

string solution(int n) {
	string answer = "";

	// 5�� -> 3���� �ִ� �ڸ��� 20
	vector<int> Ternary;

	// n�� �ڸ��� ���ϱ�

	int Digits = 1;
	int Prev_Pow_3 = 0;
	int Pow_3 = 3;

	n = n - 1;

	while (n >= Pow_3)
	{
		Prev_Pow_3 = Pow_3;
		Pow_3 = Prev_Pow_3 + pow(3, ++Digits);
	}

	n -= Prev_Pow_3;

	while (Digits--)
	{
		if (n > 0)
		{
			Ternary.push_back(n % 3);
			n /= 3;
		}
		else
			Ternary.push_back(0);
	}

	// ��� �ڸ��� 1�� ���ϵ�, 2�� 4�� ��ȯ
	reverse(Ternary.begin(), Ternary.end());

	for (int i = 0; i < Ternary.size(); i++)
	{
		if (Ternary[i] == 2)
			answer += '4';
		else
			answer += (Ternary[i] + 48 + 1);
	}

	return answer;
}