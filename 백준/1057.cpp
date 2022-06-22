#include <iostream>
#include<cmath>
using namespace std;

int main()
{
	int n, cnt = 0;
	double kim, im;
	cin >> n >> kim >> im;

	while (kim != im) 
	{
		kim = ceil(kim / 2);
		im = ceil(im / 2);
		cnt++;
	}
	cout << cnt;
}