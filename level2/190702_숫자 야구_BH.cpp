#include <string>
#include <vector>

using namespace std;

class BaseBall
{
private:
	vector<string> Numbers;
	vector<bool> IsPossible;
	int Size = 0;
public:
	BaseBall();
	void Play(vector<int> v);
	int GetSize();
};

BaseBall::BaseBall()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (i == j)
				continue;
			for (int k = 1; k <= 9; k++)
			{
				if (i == k || j == k)
					continue;
				this->Numbers.push_back(to_string(i * 100 + j * 10 + k));
				this->IsPossible.push_back(true);
				this->Size++;
			}
		}
	}
}

void BaseBall::Play(vector<int> v)
{
	int v1 = v[0] / 100;
	int v2 = (v[0] / 10) % 10;
	int v3 = v[0] % 10;


	for (int i = 0; i < this->Numbers.size(); i++)
	{
		if (!this->IsPossible[i])
			continue;
		else
		{
			int Strike_Count = 0;
			int Ball_Count = 0;

			if (v1 == this->Numbers[i][0] - 48)
				Strike_Count++;
			else if (v1 == this->Numbers[i][1] - 48)
				Ball_Count++;
			else if (v1 == this->Numbers[i][2] - 48)
				Ball_Count++;

			if (v2 == this->Numbers[i][0] - 48)
				Ball_Count++;
			else if (v2 == this->Numbers[i][1] - 48)
				Strike_Count++;
			else if (v2 == this->Numbers[i][2] - 48)
				Ball_Count++;

			if (v3 == this->Numbers[i][0] - 48)
				Ball_Count++;
			else if (v3 == this->Numbers[i][1] - 48)
				Ball_Count++;
			else if (v3 == this->Numbers[i][2] - 48)
				Strike_Count++;

			if (Strike_Count != v[1] || Ball_Count != v[2])
			{
				this->IsPossible[i] = false;
				this->Size--;
			}
		}
	}
}

int BaseBall::GetSize()
{
	return this->Size;
}

int solution(vector<vector<int>> baseball)
{
	BaseBall Player;

	for (int i = 0; i < baseball.size(); i++)
		Player.Play(baseball[i]);

	return Player.GetSize();
}