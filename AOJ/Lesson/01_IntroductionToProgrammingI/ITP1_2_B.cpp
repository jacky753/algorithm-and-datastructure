#include <iostream>
using namespace std;

int main() {
    int a, b, c;
	cin >> a >> b >> c;
	if (a < b and b < c) {
        cout << "Yes" << endl;
    }
    //else if (a > b) {
    //    cout << "a > b" << endl;
    //}
    else{
        cout << "No" << endl;
    }
	return 0;
}

