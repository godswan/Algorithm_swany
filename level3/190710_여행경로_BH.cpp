#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> DFS(vector<bool> visited, int index, vector<string> answer, vector<vector<string>> tickets, string depart, bool First)
{
	vector<pair<string, int>> Conform;

	if (!First)
	{
		answer.push_back(tickets[index][1]);
		visited[index] = true;
	}

	bool AllVisit = true;

	for (int i = 0; i < tickets.size(); i++)
	{
		if (visited[i])
			continue;
		else if (tickets[i][0] == depart)
			Conform.push_back(make_pair(tickets[i][1], i));
		AllVisit = false;
	}

	if (AllVisit)
		return answer;

	sort(Conform.begin(), Conform.end());

	vector<string> r_value;
	for (int i = 0; i < Conform.size(); i++)
	{
		r_value = DFS(visited, Conform[i].second, answer, tickets, Conform[i].first, false);

		if (r_value.size() == tickets.size() + 1)
			return r_value;
	}

	return vector<string> { {}};
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<bool> visited;

	for (int i = 0; i < tickets.size(); i++)
		visited.push_back(false);

	answer.push_back("ICN");

	return DFS(visited, 0, answer, tickets, "ICN", true);
}