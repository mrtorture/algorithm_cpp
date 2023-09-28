//SW Expert Academy #1244. Maximum Reward(Exhaustive Search)

//namespace > using namespace means that copy and paste definitions
//function prototype > declare before use
//pointer, reference, const > use reference and const reference
//recursive function > patterns shallow or deep copy of input and output
//vector, set
//copy type of =, insert(), push_back() > deep copy
//allocation in memory > stack(info), heap(data)
//data structure in memory > array(vector), tree(set), hash(unordered_set)
//vector use case(using array) > set size and use position
//vector use case(using reallocation) > set no size and use push_back()
//set use case(using tree): set no size and use insert()
//what if data is stored in stack and shallow copied and the stack frame is over
//what if data is stored in heap and deep copied each time over and over
//iterator > pointer
//range-based loop > must not change range during loop
//recursive from/to loop
//debugger

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> get_vector(int num);
void get_vector_r(vector<int>& vo, int num);
void swap(set<vector<int>>& svo, const vector<int>& vi, int e);
void print_vector(const vector<int>& v);
void print_vectors(const set<vector<int>> &sv, int e);
int is_less_than(const vector<int>& a, const vector<int>& b);

int main()
{
    freopen("../input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> ii(n);
    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        cin >> ii[i];
        cin >> e[i];
    }

//    stored in stack(info), heap(array)
//    set enough size to avoid reallocation and copy
//    set size means that set capacity and initialize elements in array 0
    vector<vector<int>> vi(n);
    for (int i = 0; i < n; i++) {
        vector<int> v;
        get_vector_r(v, ii[i]);
//        vector use case: set size and use position
        vi[i] = v;
    }

    vector<set<vector<int>>> svo(n);
    for (int i = 0; i < n; i++) {
        swap(svo[i], vi[i], e[i]);
    }

    for (int i = 0; i < n; i++) {
//        iterator is pointer
        vector<int> max = *(svo[i].begin());
        for (const vector<int>& v: svo[i]) {
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
//        vector use case: set no size and use push_back()
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
void swap(set<vector<int>>& svo, const vector<int>& vi, int e) {
//    cout << e << " times swap function was called." << endl;
    if (e < 1) {
//        stored in stack and deep copy
        svo.insert(vi);
//        print_vectors(svo, e);
        return;
    }

    swap(svo, vi, e - 1);
//    stored in stack(info), heap(tree)
//    no constructor getting size as parameter
    set<vector<int>> svt;
//    range-based loop works using iterator(++) internally
//    range-based loop cannot be applied to the collection whose begin, end are not known
//    range in range-based loop must not change during loop
    for (const vector<int>& vi2 : svo) {
        for (int i = 0; i < vi2.size(); i++) {
            for (int j = i + 1; j < vi2.size(); j++) {
//                deep copy
                vector<int> vo = vi2;
                int tmp = vo[i];
                vo[i] = vo[j];
                vo[j] = tmp;
//                stored in stack and deep copy
//                set use case: set no size and use insert()
                svt.insert(vo);
            }
        }
    }
//    stored in stack and deep copy
    svo = svt;
//    print_vectors(svo, e);
}

void print_vectors(const set<vector<int>> &sv, int e) {
    cout << "after " << e << " times swap, sv.size() : " << sv.size() << endl;
    int i = 1;
    for (const vector<int>& v: sv) {
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
