#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {

	vector<vector<string>> a_to_z;
	vector<string> answer;

	// 공간 확보
	for (int i = 0; i < 26; i++)
	{
		vector<string> temp;
		a_to_z.push_back(temp);
	}

	// 알파벳별로 담아준다
	for (int i = 0; i < strings.size(); i++)
		a_to_z[strings[i][n] - 97].push_back(strings[i]);

	// 알파벳별 정렬
	for (int i = 0; i < 26; i++)
		sort(a_to_z[i].begin(), a_to_z[i].end());

	// 반환할 answer에 순차적 push
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < a_to_z[i].size(); j++)
			answer.push_back(a_to_z[i][j]);

	return answer;
}