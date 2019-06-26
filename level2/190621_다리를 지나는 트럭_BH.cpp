#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	queue<int> bridge_queue;
	int weights_on_bridge = 0;
	int TotalTime = 0;
	int Time = 0;
	int truck_index = 0;

	while (true)
	{
		if (TotalTime++ >= bridge_length)
		{
			weights_on_bridge -= bridge_queue.front();
			bridge_queue.pop();
		}

		if (truck_index == truck_weights.size())
		{
			if (bridge_queue.size() == 0)
				break;
		}
		else
		{
			if (weights_on_bridge + truck_weights[truck_index] <= weight)
			{
				weights_on_bridge += truck_weights[truck_index];
				bridge_queue.push(truck_weights[truck_index]);
				truck_index++;
			}
			else
				bridge_queue.push(0);
		}
	}

	return TotalTime;
}