#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 3진수 변환
// 3 이하 -> 자릿수 1
// 12 (3 + 9) 이하 -> 자릿수 2
// 39 (3 + 9 + 27) 이하 -> 자릿수 3
// 120 (3 + 9 + 27 + 81) 이하 -> 자릿수 4

string solution(int n) {
	string answer = "";

	// 5억 -> 3진수 최대 자릿수 20
	vector<int> Ternary;

	// n의 자릿수 구하기

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

	// 모든 자리에 1을 더하되, 2는 4로 전환
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