#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double x, y, h;
	while (cin >> x >> y >> h)
	{
		if (x == 0 && y == 0 && h == 0)
			break;
		h = pow(h, 2);
		x = pow(x, 2);
		y = pow(y, 2);
		if (h == x + y||x==h+y||y==h+x)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
}