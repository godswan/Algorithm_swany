#include <string>
#include <vector>

using namespace std;

int solution(string name) {
	int answer = 0;
	vector<bool> Search_A;

	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] != 'A')
		{
			if (name[i] <= 'M')
				answer += name[i] - 'A';
			else
				answer += -(name[i] - 'Z') + 1;
			if (i != 0)
				Search_A.push_back(false);
			else
				Search_A.push_back(true);
		}
		else
			Search_A.push_back(true);
	}

	int left = 0;
	int right = 0;
	bool IsGoing = true;

	while (IsGoing)
	{
		for (int i = 0; i < name.size(); i++)
		{
			if (Search_A[i] == true)
				IsGoing = false;
			else
			{
				IsGoing = true;
				break;
			}
		}

		if (!IsGoing)
			break;

		left--;
		right++;
		answer++;

		if (left < 0)
			left = name.size() - 1;
		if (right > name.size() - 1)
			right = 0;

		// ÀûÀº °÷
		if (!Search_A[left] && !Search_A[right])
		{
			int size = name.size() / 2;
			int left_Temp = left;
			int right_Temp = right;

			int left_A = 0;
			int right_A = 0;

			while (size--)
			{
				left_Temp--;
				right_Temp++;

				if (left_Temp < 0)
					left_Temp = name.size() - 1;
				if (right_Temp > name.size() - 1)
					right_Temp = 0;

				if (!Search_A[left_Temp])
					left_A++;
				if (!Search_A[right_Temp])
					right_A++;
			}

			if (left_A > right_A)
			{
				Search_A[right] = true;
				name[right] = 'A';
				left = right;
			}
			else
			{
				Search_A[left] = true;
				name[left] = 'A';
				right = left;
			}
		}
		else if (!Search_A[left])
		{
			name[left] = 'A';
			Search_A[left] = true;
			right = left;
		}
		else if (!Search_A[right])
		{
			name[right] = 'A';
			Search_A[right] = true;
			left = right;
		}
	}

	return answer;
}

int main()
{
	solution("CANAAAAANAN");
}