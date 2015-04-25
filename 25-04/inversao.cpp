#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int inverte(int a){
	int result = 0, size = 0, x = a;
	while(x>=1){
		x = x/10;
		++size;
	}
	while(size > 0){
		result += (a%10) * pow(10, size-1);
		a = a/10;
		--size;
	}
	return result;
}

int min(int x, int y){
	if (x >= y)
		return x;
	else
		return y;
}

int findPath(int a, int b, int count){
	int aS, aI, p1, p2;
	if (a == b)
		return count;
	else{
		aS = a+1;
		aI = inverte(a);
		if(aS == b || aI == b)
			return count +1;
		else{
			p1 = findPath(aS, b, count+1);
			p2 = findPath(aI, b, count+1);
			return (min(p1, p2));
		}
	}
}


int main(){
	int t, a, b, count;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		count = 0;
		cin >> a;
		cin >> b;
		count = findPath(a, b , count);
		cout << count << endl;
	}

	return 0;
}
