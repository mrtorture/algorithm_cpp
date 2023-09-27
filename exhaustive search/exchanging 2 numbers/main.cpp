#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> get_vector(int num);
void get_vector_r(vector<int>& vo, int num);
void swap(set<vector<int>>& so, const set<vector<int>>& si, int e);
void print_vector(const vector<int>& v);
void print_vectors(const set<vector<int>> &so, int e);
int is_less_than(const vector<int>& a, const vector<int>& b);

//namespace
//pointer, reference, const
//recursive function
//vector, set
//iterator
//range-based loop, auto
//debugger
int main()
{
    freopen("../input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> vi(n);
    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        cin >> vi[i];
        cin >> e[i];
    }

    vector<vector<int>> vo(n);
    vector<set<vector<int>>> si(n);
    for (int i = 0; i < n; i++) {
        get_vector_r(vo[i], vi[i]);
        si[i].insert(vo[i]);
    }

    vector<set<vector<int>>> so(n);
    for (int i = 0; i < n; i++) {
        swap(so[i], si[i], e[i]);
    }

    for (int i = 0; i < n; i++) {
        vector<int> max = *(so[i].begin());
        for (const vector<int>& v: so[i]) {
            if (is_less_than(max, v)) {
                max = v;
            }
        }
        cout << "#" << i + 1 << " ";
        for (int num : max) {
            cout << num;
        }
        cout << endl;

    }

    return 0;
}

void print_vector(const vector<int>& v) {
    for (int num: v) {
        cout << num << " ";
    }
}

//recursive pattern 1 -> pass by value
//return value of vector -> pass by value
vector<int> get_vector(int num) {
    if (num < 10) {
        vector<int> v;
        v.push_back(num);
        return v;
    }

    int q = num / 10;
    int r = num % 10;
    vector<int> vo = get_vector(q);
    vo.push_back(r);
    return vo;
}

//recursive pattern 2 -> pass by reference
//explicit reference parameter -> pass by reference
void get_vector_r(vector<int>& vo, int num) {
    if (num < 10) {
        vo.push_back(num);
        return;
    }

    int q = num / 10;
    int r = num % 10;
    get_vector_r(vo, q);
    vo.push_back(r);
}

//recursive pattern 3 -> pass by reference
//vector<int>& get_vector_r2(int num)
//in this case reference variable is dangle when stack frame is clear

//const reference -> pass by reference
void swap(set<vector<int>>& so, const set<vector<int>>& si, int e) {
//    cout << e << " times swap function was called." << endl;
    if (e < 1) {
        for (const vector<int>& vi: si) {
//            container inserts copy of original
            so.insert(vi);
        }
//        print_vectors(so, e);
        return;
    }

    swap(so, si, e - 1);
    set<vector<int>> st;
//    range-based loop works using iterator(++) internally
//    range-based loop cannot be applied to the collection whose begin, end are not known
//    range in range-based loop must not change during loop
    for (const vector<int>& vi : so) {
        for (int i = 0; i < vi.size(); i++) {
            for (int j = i + 1; j < vi.size(); j++) {
                vector<int> vo = vi;
                int tmp = vo[i];
                vo[i] = vo[j];
                vo[j] = tmp;
//                container inserts copy of original
                st.insert(vo);
            }
        }
    }
    so.clear();
//    container inserts copy of original
    so.insert(st.begin(), st.end());

//    print_vectors(so, e);
}

void print_vectors(const set<vector<int>> &so, int e) {
    cout << "after " << e << " times swap, so.size() : " << so.size() << endl;
    int i = 1;
    for (const vector<int>& v: so) {
        cout << i++ << ": ";
        for (int num: v) {
            cout << num << " ";
        }
        cout << endl;
    }
}

//const reference -> pass by reference
int is_less_than(const vector<int>& a, const vector<int>& b) {
    int a1 = a.size();
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            a1 = i;
            break;
        }
    }
    int b1 = b.size();
    for (int i = 0; i < b.size(); i++) {
        if (b[i] != 0) {
            b1 = i;
            break;
        }
    }

    int a_size = a.size() - a1;
    int b_size = b.size() - b1;
    if (a_size > b_size) {
        return -1;
    } else if (b_size > a_size) {
        return 1;
    }

    for (int i = 0; i < a_size; i++) {
        if (a[a1 + i] > b[b1 + i]) {
            return -1;
        } else if (a[a1 + i] < b[b1 + i]) {
            return 1;
        }
    }

    return 0;
}
