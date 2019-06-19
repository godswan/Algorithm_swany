#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int* Days = new int[progresses.size()];

	// 날짜 계산
	for (int i = 0; i < progresses.size(); i++)
	{
		int Remain_P = 100 - progresses[i];
		int Day = 0;
		while (Remain_P > 0)
		{
			Remain_P -= speeds[i];
			Day++;
		}

		Days[i] = Day;
	}

	int Max = Days[0];
	int Count = 0;

	// 순차적 answer에 담기
	for (int i = 0; i < progresses.size(); i++)
	{
		if (Days[i] > Max)
		{
			answer.push_back(Count);
			Max = Days[i];
			Count = 1;
		}
		else
		{
			Count++;
		}
	}
	answer.push_back(Count);


	return answer;
}