#include <math.h>

using namespace std;
long long solution(int w, int h) {
	long long answer = 1;
	answer = (long long)w*(long long)h;
	long long to_delete = 0;
	double m = (long long)h / (double)w;
	double last = 0;
	for (int i = 1; i <= w; i++) {
		to_delete += ceil((long long)h*i / (double)w) - floor(last);
		last = (double)h*i / (double)w;
	}
	answer -= to_delete;
	return answer;
}