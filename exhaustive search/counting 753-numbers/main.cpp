//Algorithms and Data Structures for Problem-Solving Skills Problem 4.5
//exhaustive search, divide and conquer, recursion

#include <iostream>
#include <set>

using namespace std;

void make_753(int n, set<int>& s);
void check_753(bool& three, bool& five, bool& seven, int num);

int main() {
    freopen("../input.txt", "r", stdin);
    int k;
    cin >> k;
    cout << "input: " << k << endl;

    int n = 0;
    int kt = k;
    while (kt > 0) {
        n++;
        kt /= 10;
    }
    cout << "digit: " << n << endl;

    set<int> s;
    make_753(n, s);

    int count = 0;
    for (const int& num: s) {
        if (num <= k) {
            bool three = false;
            bool five = false;
            bool seven = false;
            check_753(three, five, seven, num);
            if (three && five && seven) {
                count++;
                cout << "#" << count << ": " << num << endl;
            }
        }
    }
    cout << "count: " << count;

    return 0;
}

void make_753(int n, set<int>& s) {
    if (n < 1) {
        return;
    }

    if (n == 1) {
        s.insert(3);
        s.insert(5);
        s.insert(7);

        return;
    }

    make_753(n - 1, s);

    set<int> st = s;
    for (const int& num: st) {
        s.insert(num * 10 + 3);
        s.insert(num * 10 + 5);
        s.insert(num * 10 + 7);
    }
}

void check_753(bool& three, bool& five, bool& seven, int num) {
    if (num == 0 || three && five && seven) {
        return;
    }

    int quo = num / 10;
    check_753(three, five, seven, quo);
    int rem = num % 10;
    switch (rem) {
        case 3:
            three = true;
            break;
        case 5:
            five = true;
            break;
        case 7:
            seven = true;
            break;
        default:
            break;
    }
}
