//Algorithms and Data Structures for Problem-Solving Skills Problem 3.7

//string > size(), stoi()

#include <iostream>

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);

    string str;
    cin >> str;
    int iter = 1;
    for (int i = 0; i < str.size() - 1; i++) {
        iter *= 2;
    }
    int num = stoi(str);
    cout << "num: " << num << endl;
    cout << "iter: " << iter << endl;

    int sum = 0;
    for (int i = 0; i < iter; i++) {
        int tmp = num;
        int div = 1;
        for (int j = 0; j < str.size() - 1; j++) {
            div *= 10;
            if (i & (1 << j)){
                int rem = tmp % div;
                tmp /= div;
                sum += rem;
                div = 1;
                cout << rem << " + ";
            }
        }
        sum += tmp;
        cout << tmp << endl;
    }

    cout << "sum: " << sum << endl;

    return 0;
}
