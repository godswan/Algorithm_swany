#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	vector<int> Student;
	for (int i = 0; i < n; i++)
		Student.push_back(0);

	for (int i = 0; i < lost.size(); i++)
		Student[lost[i]-1] = 1;
	
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] == reserve[j])
			{
				Student[reserve[j]-1] = 0;
				reserve[j] = 0;
			}
		}
	}

	for (int j = 0; j < reserve.size(); j++)
	{
		if (reserve[j] != 0)
		{
			if (reserve[j] == 1)
			{
				if (Student[reserve[j]] == 1)
					Student[reserve[j]] = 0;
			}
			else if (reserve[j] != 1 && reserve[j] != n)
			{
				if (Student[reserve[j] - 1 - 1] == 1)
					Student[reserve[j] - 1 - 1] = 0;
				else if (Student[reserve[j]] == 1)
					Student[reserve[j]] = 0;
			}
			else if (reserve[j] == n)
			{
				if (Student[reserve[j] - 1 - 1] == 1)
					Student[reserve[j] - 1 - 1] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (Student[i] == 0)
			answer++;

	return answer;
}