#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    //sort(a, a + 3);
    sort(a, a + 2);

    cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    return 0;
}

/*#include <iostream>
using namespace std;

int main() {
    int a, b, c;
	cin >> a >> b >> c;
    int temp, temp2;

    int flag = 1;
    while (flag){
        if (a < b and c < b){
            temp = c;
            c = b;
            b = temp;
        }
        else if (b < a and a < c){
            temp = b;
            b = a;
            a = temp;
        }
        else if (b < c and c < a){
            temp = a;
            temp2 = c;
            a = b;
            b = temp2;
            c = temp;
        }
        else if (c < a and a < b){
            temp = c;
            temp2 = b;
            b = a;
            c = temp2;
            a = temp;
        }
        else if (c < b and b < a){
            temp = a;
            a = c;
            c = temp;
        }
        //abc, acb
        //bac, bca
        //cab, cba
        if (a < b and b < c) {
            //cout << "Yes" << endl;
            cout << a << " " << b << " " << c;
            flag = 0
        }
        //else if (a > b) {
        //    cout << "a > b" << endl;
        //}
        else{
            //cout << "No" << endl;
            flag = 1;
        }
    }
	return 0;
}*/


