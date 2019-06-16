#include <string>

using namespace std;

enum Day { SUN, MON, TUE, WED, THU, FRI, SAT };

string solution(int a, int b) {

	int MonthPerDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int Sum = 5;

	for (int i = 0; i < a - 1; i++)
		Sum += MonthPerDay[i];
	Sum += b;

	Sum = Sum % 7;
	
	switch (Sum)
	{
		case SUN: return "SUN";
		case MON: return "MON";
		case TUE: return "TUE";
		case WED: return "WED";
		case THU: return "THU";
		case FRI: return "FRI";
		case SAT: return "SAT";
	}
}