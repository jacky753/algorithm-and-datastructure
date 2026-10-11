#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int count = 0;

    for (int i = a; i <= b; ++i) {
        if (c % i == 0) {
            ++count;
        }
    }

    cout << count << endl;//'\n';

    return 0;
}



//#include <iostream>
//using namespace std;

//int main() {
    //int x, y;
	//int a, b, c;
    	//cin >> a >> b >> c;
	//vector<int> vec(c);
	//for (int i = 0; i < c; i++){
	//	if ( c%i == 0){
	//       		vec.at(i) = i;
 	//	}		
	//}
	//std::vector<int> sub_vector(vec.begin() + a, vec.begin() + b + 1);
	// 0の要素を取り除き、有効な要素の末尾を指すイテレータを取得
	//auto it = std::remove(sub_vector.begin(), sub_vector.end(), 0);
	// 不要になった末尾の要素を実際に削除してサイズを詰める
	//sub_vector.erase(it, sub_vector.end());
	//std::size_t length = std::size(sub_vector); // 要素数は 5
	//std::cout << length << std::endl;
    //while (cin >> x >> y) {
        // Stop when both are 0
        //if (x == 0 && y == 0) {
        //    break;
        //}
        // Swap if x is greater than y
        //if (x > y) {
        //    swap(x, y);
        //}
        //cout << x << " " << y << endl;
    //}

//	return 0;
//}



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


