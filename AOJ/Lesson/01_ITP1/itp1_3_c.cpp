#include <iostream>
using namespace std;

int main() {
    int x, y;

    while (cin >> x >> y) {
        // Stop when both are 0
        if (x == 0 && y == 0) {
            break;
        }

        // Swap if x is greater than y
        if (x > y) {
            swap(x, y);
        }

        cout << x << " " << y << endl;
    }

    return 0;
}



/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int flag;
	flag = 1;
	while (flag){
    	int a, b;
		cin >> a >> b;
		//int a[3];
    		//cin >> a[0] >> a[1] >> a[2];
    		//sort(a, a + 3);
    		//sort(a, a + 2);
    		//cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
		if (a < b){
			cout << a << ' ' << b << '\n';
		}
		else if (a > b){
			cout << b << ' ' << a << '\n';
		}
		else if (a==0 and b==0){
			flag = 0;
		}
	}
	return 0;
}
*/


