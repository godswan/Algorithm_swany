#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++)
	{
		string Assume = "";

		for (int j = 0; j < skill_trees[i].size(); j++)
		{
			string::size_type Exist;
			Exist = skill.find(skill_trees[i][j]);

			if (Exist != string::npos)
				Assume += skill_trees[i][j];
		}

		string Compare = skill.substr(0, Assume.size());

		if (Compare == Assume)
			answer++;
	}

	return answer;
}