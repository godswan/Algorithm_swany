#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long MAX = 3333333333;
long long Heap[1000001] = { 0, -1, };
int iSize = 0;

void push(long long value)
{
	Heap[iSize] = value;

	int i = iSize;

	while (i != 1)
	{
		if (Heap[i / 2] > value)
			swap(Heap[i], Heap[i / 2]);
		else
			break;

		i /= 2;
	}
}

void pop()
{
	Heap[1] = MAX;

	swap(Heap[iSize], Heap[1]);

	int i = 1;
	while (i * 2 < iSize)
	{
		if (Heap[i] > Heap[i * 2] && Heap[i * 2] <= Heap[i * 2 + 1])
		{
			swap(Heap[i], Heap[i * 2]);
			i *= 2;
		}
		else if (Heap[i] > Heap[i * 2 + 1] && Heap[i * 2] > Heap[i * 2 + 1])
		{
			swap(Heap[i], Heap[i * 2 + 1]);
			i = i * 2 + 1;
		}
		else
			break;
	}
}

int solution(vector<int> scoville, int K) {

	int answer = 0;
	iSize = scoville.size();

	sort(scoville.begin(), scoville.end());

	for (int i = 0; i < iSize; i++)
		Heap[i + 1] = scoville[i];

	while (iSize > 1)
	{
		if (Heap[1] >= K)
			break;

		int A = Heap[1];
		pop();
		iSize--;

		int B = Heap[1];
		pop();
		iSize--;

		iSize++;
		push(A + (B * 2));

		answer++;
	}

	if (Heap[1] < K)
		answer = -1;

	return answer;
}