#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(string a, string b)
{
	return (a + b) > (b + a);
}

string solution(vector<int> numbers)
{
	string answer = "";

	vector<string> Temp;
	for (int i = 0; i < numbers.size(); i++)
		Temp.push_back(to_string(numbers[i]));

	sort(Temp.begin(), Temp.end(), compare);

	for (int i = 0; i < Temp.size(); i++)
		answer += Temp[i];

	if (answer[0] == '0')
		answer = "0";

	return answer;
}