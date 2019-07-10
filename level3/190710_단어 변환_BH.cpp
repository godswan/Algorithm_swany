#include <string>
#include <vector>

using namespace std;

void DFS(vector<bool> visited, int level, int& min, string begin, string target, vector<string> words)
{
	if (begin == target)
	{
		if(min > level)
			min = level;
		return;
	}
	else
	{
		for (int i = 0; i < words.size(); i++)
		{
			if (visited[i])
				continue;

			int count = 0;

			for (int j = 0; j < words[i].size(); j++)
			{
				if (begin[j] != words[i][j])
					count++;
			}

			if (count == 1)
			{
				visited[i] = true;
				DFS(visited, level + 1, min, words[i], target, words);
			}
		}
	}
}

int solution(string begin, string target, vector<string> words)
{
	vector<bool> Visited;
	
	for (int i = 0; i < words.size(); i++)
		Visited.push_back(false);
	
	int Min = words.size();
	
	DFS(Visited, 0, Min, begin, target, words);

	if (Min == words.size())
		return 0;
	else
		return Min;
}