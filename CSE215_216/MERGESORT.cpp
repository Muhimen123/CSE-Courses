#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> val;
int inversion = 0;

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> ret;
    int i = 0;
    int j = 0;
    int n = left.size();
    int m = right.size();

    int local_inv = 0;

    while(i < n and j < m) {
        if(left[i] <= right[j]) {
            ret.push_back(left[i++]);
        } else {
            ret.push_back(right[j++]);
            inversion += (n - i);
        }
    }

    while(i < n) {
        ret.push_back(left[i]);
        i++;
    }

    while(j < m) {
        ret.push_back(right[j]);
        j++;
    }

    return ret;
}

void merge_sort(int left, int right) {
    if(left >= right) return;

    
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);

    vector<int> left_array;
    vector<int> right_array;

    for(int i = left; i <= mid; i++) left_array.push_back(val[i]);
    for(int i = mid + 1; i <= right; i++) right_array.push_back(val[i]);

    vector<int> merged = merge(left_array, right_array);
    int j = 0;
    for(int i = left; i <= right; i++) {
        val[i] = merged[j++];
    }

}

int main() {
    vector<int> lft = {5, 4, 3, 2, 1};
    vector<int> right = {2, 3, 4, 1};

    val = lft;
    merge_sort(0, val.size()-1);
    for(auto v: val) cout << v << " ";
    cout << endl;

    cout << "Number of inversion: " << inversion << endl;

    return 0;
}