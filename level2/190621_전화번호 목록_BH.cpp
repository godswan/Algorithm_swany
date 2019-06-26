#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {

	for (int i = 0; i <phone_book.size(); i++)
	{
		for (int j = 0; j < phone_book.size(); j++)
		{
			if (i == j)
				continue;
			if (phone_book[i].size() <= phone_book[j].size())
			{
				if (phone_book[i] == phone_book[j].substr(0, phone_book[i].size()))
					return false;
			}
			else
			{
				if (phone_book[j] == phone_book[i].substr(0, phone_book[j].size()))
					return false;
			}
		}
	}

	return true;
}