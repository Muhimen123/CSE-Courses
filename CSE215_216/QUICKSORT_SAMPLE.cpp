#include <iostream>
#include <vector>

using namespace std;

struct student {
    string name;
    int roll;
    int dsa_marks;
    int c_programming;
    int total_credit;
};

vector<student> students;

int default_partition() {
    int marker = -1;
    int n = students.size();

    for(int i = 1; i < n; i++) {
        if(students[i].total_credit < 40) {
            marker++;
            swap(students[i], students[marker]);
        }
    }
    return marker;
}

int conquer(int left, int right) {
    int pivot = right;

    int marker = left - 1;
    for(int i = left; i < right; i++) {
        if(students[i].dsa_marks <= students[pivot].dsa_marks) {
            marker++;
            swap(students[marker], students[i]);
        }
    }
    marker++;
    swap(students[marker], students[pivot]);
    return marker;
}

void quicksort(int left, int right) {
    if(left >= right) return;

    int pivot = conquer(left, right);
    quicksort(left, pivot-1);
    quicksort(pivot+1, right);

}

int main() {
    struct student std;
    std.name = "adsf";
    std.c_programming = 30;
    return 0;
}