#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Heap
{
private:
	int Space[20001] = {};
	int N;
public:
	Heap(int n);
	void Push(int supplies);
	void Pop();
	int GetSize();
	int Front();
};

Heap::Heap(int n)
{
	this->N = n;
}

void Heap::Push(int supplies)
{
	this->N++;
	Space[this->N] = supplies;
	int i = this->N;

	while (i != 1)
	{
		if (Space[i] >= Space[i / 2])
			swap(Space[i], Space[i / 2]);
		else
			break;

		i /= 2;
	}
}

void Heap::Pop()
{
	Space[1] = -1;
	swap(Space[1], Space[this->N]);
	int i = 1;

	while (i * 2 <= this->N)
	{
		if (Space[i] < Space[i * 2] && Space[i * 2] >= Space[i * 2 + 1])
		{
			swap(Space[i], Space[i * 2]);
			i *= 2;
		}
		else if (Space[i] < Space[i * 2 + 1] && Space[i * 2] < Space[i * 2 + 1])
		{
			swap(Space[i], Space[i * 2 + 1]);
			i = i * 2 + 1;
		}
		else
			break;
	}

	this->N--;
}

int Heap::GetSize()
{
	return this->N;
}

int Heap::Front()
{
	return Space[1];
}

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {

	//가장 큰것
	int answer = 0;
	int Day = 0;
	int Index = 0;
	
	Heap H(0);
	
	while (true)
	{
		Day += stock;
		stock = 0;

		if (Day >= k)
			break;

		for (int i = Index; i < dates.size(); i++)
		{
			if (Day < dates[i])
				break;
			H.Push(supplies[i]);
			Index++;
		}

		if (H.GetSize())
		{
			stock += H.Front();
			H.Pop();
			answer++;
		}
	}

	return answer;
}
