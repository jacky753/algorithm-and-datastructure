#include <iostream>
using namespace std;

int main() {
    //int a, b;
	int get_s;
	//cin >> a >> b;
	cin >> get_s;
	//int area = a * b;
	//int perimeter = 2 * (a + b);
	int h = get_s/60/60;
	int m = get_s/60 - h*60;
	int s = get_s%60;
    	//cout << area << " " << perimeter << endl;
    	cout << h << ":" << m << ":" << s << endl; 
	return 0;
}


