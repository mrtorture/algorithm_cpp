//Algorithms and Data Structures for Problem-Solving Skills Problem 4.6
//exhaustive search, recursion
//dynamic programming, memoization
//set, find(), end(), count()

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool check(int n, int s, const vector<int>& vi, set<vector<int>>& st);

int main() {
    freopen("../input.txt", "r", stdin);
    int n;
    int s;
    cin >> n >> s;
    cout << "subtotal: " << s << endl;
    vector<int> vi(n);
    cout << "array: ";
    for (int i = 0; i < n; i++) {
        cin >> vi[i];
        cout << vi[i] << " ";
    }
    cout << endl;
    cout << "Can make the subtotal using the array?" << endl;

    set<vector<int>> st;
    if (check(n, s, vi, st)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

bool check(int n, int s, const vector<int>& vi, set<vector<int>>& st) {
    if (n == 0) {
        if (s == 0) {
            return true;
        }
        return false;
    }

    vector<int> no_select = {n - 1, s};
    if (st.find(no_select) == st.end()) {
        if (check(n - 1, s, vi, st)) {
            cout << "{" << n - 1 << ", " << s << "} is true!" << endl;
            return true;
        } else {
            st.insert(no_select);
            cout << "{" << n - 1 << ", " << s << "} is false" << endl;
        }
    }

    vector<int> select = {n - 1, s - vi[n - 1]};
    if (st.find(select) == st.end()) {
        if (check(n - 1, s - vi[n - 1], vi, st)) {
            cout << "{" << n - 1 << ", " << s - vi[n - 1] << "} is true!" << endl;
            return true;
        } else {
            st.insert(select);
            cout << "{" << n - 1 << ", " << s - vi[n - 1] << "} is false" << endl;
        }
    }

    return false;
}