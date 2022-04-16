#include<iostream>
#include<string>

using namespace std;

int main()
{	
	string A, B, C, D;
	cin >> A >> B >> C >> D;
	string X, Y;
	X = A + B;
	Y = C + D;
	long long x, y;
	x = stoll(X);
	y = stoll(Y);
	cout << x+y;
}
