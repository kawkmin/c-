#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> v = progresses;
	while (v.size() != 0)
	{
		for (int i = 0; i < v.size(); i++) {
			if (v[i] >= 100)
				continue;
			v[i] += speeds[i];
		}
		int cnt = 0;
		int size = v.size();
		for (int i = 0; i < size; i++)
		{
			if (v.front() >= 100)
			{
				cnt++;
				speeds.erase(speeds.begin());
				v.erase(v.begin());
				continue;
			}
			break;
		}
		if (cnt > 0)
			answer.push_back(cnt);
	}

	return answer;
}