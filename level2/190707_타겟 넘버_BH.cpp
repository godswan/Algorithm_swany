#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<int>& numbers, vector<int>&b_Sum, int Value,int iIndex, int Target, int& answer)
{
	if (iIndex == b_Sum.size() + 1)
	{
		if (Value == Target)
			answer++;
		
		return;	
	}
	
	if (Value < 0)
	{
		if (Value + b_Sum[b_Sum.size() - iIndex] < Target)
			return;
	}
	else if(Value > 0)
	{
		if (Value - b_Sum[b_Sum.size() - iIndex] > Target)
			return;
	}

	DFS(numbers, b_Sum, Value + numbers[iIndex], iIndex + 1, Target, answer);
	DFS(numbers, b_Sum, Value - numbers[iIndex], iIndex + 1, Target, answer);

}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	sort(numbers.begin(), numbers.end());

	int Sum = 0;
	vector<int> Back_Sum;

	for (int i = numbers.size() - 1; i > 0; i--)
	{
		Sum += numbers[i];
		Back_Sum.push_back(Sum);
	}

	DFS(numbers, Back_Sum, 0, 0, target, answer);

	return answer;
}
