using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w, int h) {
    long long W = w;
    long long H = h;
    long long answer = (W * H) - (w + h - gcd(w, h));

    return answer;
}