#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int Supoza_Count[3] = { 0,0,0 };
	int Supoza_2[4] = { 1,3,4,5 };
	int Supoza_3[5] = { 3,1,2,4,5 };

	for (int i = 0; i < answers.size(); i++)
	{
		// 1
		if ((i % 5) + 1 == answers[i])
			Supoza_Count[0]++;

		// 2
		if (!(i % 2) && answers[i] == 2)
			Supoza_Count[1]++;
		else if (i % 2 && Supoza_2[(i % 8) / 2] == answers[i])
			Supoza_Count[1]++;

		// 3
		if (Supoza_3[(i % 10) / 2] == answers[i])
			Supoza_Count[2]++;
	}

	int Max = max(Supoza_Count[0], max(Supoza_Count[1], Supoza_Count[2]));

	for (int i = 0; i < 3; i++)
		if (Max == Supoza_Count[i])
			answer.push_back(i + 1);

	return answer;
}