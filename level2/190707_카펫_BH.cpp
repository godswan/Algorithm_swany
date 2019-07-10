#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;

	int Area = brown + red;
	int w = 3;
	int h = 3;

	for (; w <= Area / 3; w++)
	{
		h = Area / w;

		if (w >= h && Area % w == 0 && ((w - 2) * (h - 2) == red))
		{
			answer.push_back(w);
			answer.push_back(h);
			h = Area;
			break;
		}
	}
	w = 3;

	return answer;
}