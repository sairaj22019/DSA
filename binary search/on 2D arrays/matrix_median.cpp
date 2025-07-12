// given a 2d matrix which is row wise sorted. find the median of the matrix

#include<bits/stdc++.h>
using namespace std;

// brute   TC-O(n*m+n*mlog(n*m))  SC-O(n*m)
// store all elements in 1d vector, sort it and get the middle element


// optimal  TC-O(log(max-min)*n*logm)   SC-O(1)

int upperBound(vector<int> &arr, int x, int m) {
    int low = 0, high = m - 1;
    int ans = m;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += upperBound(matrix[i], x, m);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int n, int m) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);  // finding min element of array (min element lies in 1st column)
        high = max(high, matrix[i][m - 1]);  // finding max element of array (max element lies in last column)
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, n, m, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}



int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int n = matrix.size(), m = matrix[0].size();
    int ans = median(matrix, n, m);
    cout << "The median element is: " << ans << endl;
    return 0;
}