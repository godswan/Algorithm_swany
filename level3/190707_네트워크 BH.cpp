#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& Network, bool Visited[], int Index, int First)
{
	for (int i = 0; i < Network.size(); i++)
	{
		if (Network[Index][i] && i != First && !Visited[i])
		{
			Visited[i] = true;
			DFS(Network, Visited, i, First);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	bool Visited[200] = { false, };

	for (int i = 0; i < computers.size(); i++)
	{
		if (!Visited[i])
			DFS(computers, Visited, i, i);
	}

	for (int i = 0; i < computers.size(); i++)
		if (!Visited[i])
			answer++;

	return answer;
}