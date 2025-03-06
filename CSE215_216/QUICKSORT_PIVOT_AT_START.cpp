#include <iostream>
#include <vector>
using namespace std;

vector<int> val;


int conquer(int left, int right) {
    int pivot = left;
    for(auto v: val) cerr << v << " ";
    cerr << endl;
    int marker = right + 1;
    for(int i = right; i >= left +1; i--) {
        if(val[i] >= val[pivot]) {
            marker--;
            swap(val[marker], val[i]);
        }
    }
    marker--;
    swap(val[marker], val[pivot]);
    return marker;
}

void quicksort(int left, int right) {
    if(left >= right) return;

    int pivot = conquer(left, right);
    quicksort(left, pivot-1);
    quicksort(pivot+1, right);

}

int main() {
    val = {3, 13, 5, 21, 55, 1, 5, 44, 12};
    int left = 0, right = val.size() - 1;
    quicksort(left, right);
    for(int v: val) cout << v << " ";
    cout << endl;
    return 0;
}