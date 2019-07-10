#include <string>
#include <vector>

using namespace std;

void Permutation(vector<int>& perm, vector<char> digits, int length, int q_length)
{
	int Index[7] = { 0, };

	while (true)
	{
		bool IsOk = true;

		for (int i = length - 1; i > 0; i--)
		{
			if (Index[i] == q_length)
			{
				Index[i - 1]++;
				Index[i] = 0;
			}
		}

		for (int i = 0; i < length; i++)
		{
			if (Index[i] == q_length)
				IsOk = false;
		}

		if (!IsOk)
			break;

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (Index[i] == Index[j] && i != j)
				{
					IsOk = false;
					break;
				}
			}

			if (!IsOk)
				break;
		}

		if (IsOk)
		{
			string Temp = "";
			for (int i = 0; i < length; i++)
			{
				Temp += digits[Index[i]];
			}

			perm.push_back(stoi(Temp));
		}

		Index[length - 1]++;

	}
};

void IsSosu(vector<int> Np, int& answer)
{
	for (int i = 0; i < Np.size(); i++)
	{
		bool Sosu = true;
		for (int j = 2; j <= Np[i] / 2; j++)
		{
			if (!(Np[i] % j))
			{
				Sosu = false;
				break;
			}
		}
		if (Sosu && Np[i] != 1 && Np[i] != 0)
			answer++;
	}
};

int solution(string numbers)
{
	// 자릿수마다 모든 경우의 수 벡터에 담는다
	// 벡터에 담은 수 각자 소수인지 확인

	int answer = 0;

	vector<char> Digits;
	vector<int> Perm;
	vector<int> NotPrime;

	for (int i = 0; i < numbers.size(); i++)
		Digits.push_back(numbers[i]);

	for (int i = 0; i < numbers.size(); i++)
		Permutation(Perm, Digits, i + 1, numbers.size());

	for (int i = 0; i < Perm.size(); i++)
	{
		bool IsExist = false;

		for (int j = 0; j < NotPrime.size(); j++)
		{
			if (NotPrime[j] == Perm[i])
				IsExist = true;
		}

		if (!IsExist)
			NotPrime.push_back(Perm[i]);
	}

	IsSosu(NotPrime, answer);

	return answer;
}
