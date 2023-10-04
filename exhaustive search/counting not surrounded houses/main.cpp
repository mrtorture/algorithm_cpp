//SW Expert Academy #1206. View
//exhaustive search, iteration

#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int ti = 1;
    int n;
    while (cin >> n) {
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        vector<int> m(n, 0);
        for (int i = 2; i < n - 2; i++) {
            int max = 0;
            for (int j = i - 2; j <= i + 2; j++) {
                if (i != j && max < h[j]) {
                    max = h[j];
                }
            }
            m[i] = max;
        }

        int total = 0;
        for (int i = 2; i < n - 2; i++) {
            if (m[i] < h[i]) {
                total += (h[i] - m[i]);
            }
        }

        cout << "#" << ti++ << " " << total << endl;

    }

    return 0;
}
