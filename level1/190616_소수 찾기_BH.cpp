using namespace std;

int solution(int n) {

	bool IsComposite[1000001];
	int answer = 0;

	for (int i = 2; i <= n; i++)
	{
		if (!IsComposite[i])
		{
			for (int j = 2 * i; j <= n; j += i)
				IsComposite[j] = true;
			answer++;
		}
	}

	return answer;
}