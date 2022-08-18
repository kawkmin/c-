#include <iostream>
using namespace std;

int main() 
{
	int n, x1, y1, x2, y2,nn, cnt, cx, cy, r;
	int a, b, c;

	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> nn;
		for (int j = 0; j < nn; j++) 
		{
			cin >> cx >> cy >> r;
			a = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
			b = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
			c = r * r;
			if (a < c && b < c)
				continue;
			else if (a < c || b < c)
				cnt++;
		}
		cout << cnt << '\n';
	}
}