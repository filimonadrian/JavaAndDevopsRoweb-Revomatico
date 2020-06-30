#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<pair<int, int>> arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid].first == x)
            return mid;

        if (arr[mid].first > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

void read(vector<int> &arr, vector<pair<int, int>> &arr_clone, int &n, int &m) {
    int to_read = 0;
    pair<int, int> p;
    cout << "Number of elements: ";
    cin >> n;
    cout << "Difference is: ";
    cin >> m;
    cout << "Elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> to_read;
        arr.push_back(to_read);
        /* pair of value and position in the original vector */
        p.first = to_read;
        p.second = i;
        arr_clone.push_back(p);
    }
}

/* complexity: O(n * logn) - for every element in the vector try to find a
    pair. The elements are unique( and sorted in the clone (value first)) */
vector<pair<int, int>> compute_pairs(vector<int> arr,
                                     vector<pair<int, int>> arr_clone,
                                     int n, int m) {

    vector<pair<int, int>> result;
    int sign = 1;
    int index = 0;
    sign = (m < 0) ? -1 : 1;

    /* for every number from array */
    for (int i = 0; i < n; i++) {
        /* we need a number equal to this diff */

        int diff = arr[i] + sign * m;
        pair<int, int> p;

        /* index of diff (if exists in the array) 
        O(binary_search) = logn */
        index = binarySearch(arr_clone, 0, n - 1, diff);
        /* if index is not negative => this number exists in the array */
        if (index >= 0) {
            p.first = i;
            p.second = arr_clone[index].second;
            result.push_back(p);
        }
    }

    return result;
}

void print_pairs(vector<pair<int, int>> arr) {
    for (auto elem : arr) {
        cout << elem.first << "-" << elem.second << endl;
    }
}

/* some hardcoded tests */
void auto_test() {
    vector<int> arr;
    vector<pair<int, int>> result;
    vector<pair<int, int>> arr_clone;

    int m = -1;
    int n = 5;

    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(11);
    arr.push_back(6);

    arr_clone.push_back(make_pair(4, 0));
    arr_clone.push_back(make_pair(5, 1));
    arr_clone.push_back(make_pair(10, 2));
    arr_clone.push_back(make_pair(11, 3));
    arr_clone.push_back(make_pair(6, 4));

    cout << "n = " << n << " m = " << m << "\n";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    sort(arr_clone.begin(), arr_clone.end());
    result = compute_pairs(arr, arr_clone, n, m);
    print_pairs(result);
}

int main() {
    /* vector with numbers */
    vector<int> arr;
    /* pairs of value, and position in the original array */
    vector<pair<int, int>> arr_clone;
    /* the result: pairs of indices */
    vector<pair<int, int>> result;
    int n = 0, m = 0;
    int option = 0;

    cout << "Press 0 for manual testing" << endl;
    cout << "Press 1 for auto testing" << endl;

    cin >> option;

    if (option == 0) {
        read(arr, arr_clone, n, m);

        /* sort the clone 
        Complexity: O(n * logn) */
        sort(arr_clone.begin(), arr_clone.end());

        /* complexity: O(n * logn) - for every element in the vector try to find a
        pair. The elements are unique( and sorted in the clone (value first)) */
        result = compute_pairs(arr, arr_clone, n, m);

        print_pairs(result);

    } else if (option == 1) {
        auto_test();
    } else {
        cout << "Invalid option :( \n";
    }

    return 0;
}
