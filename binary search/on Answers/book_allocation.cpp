// Q)  given an array in which ith element is no of pages in the ith book.
    // Each student receives atleast one book.
    // Each student is assigned a contiguous sequence of books.
    // No book is assigned to more than one student.
    // find min of max pages assigned to any student.


#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}


// // brute -O(n*(sum(a)-max(a)))
// int findPages(vector<int>& arr, int m) {
//     int n=arr.size();
//     //book allocation impossible:
//     if (m > n) return -1;

//     int low = *max_element(arr.begin(), arr.end());
//     int high = accumulate(arr.begin(), arr.end(), 0); //calculates sum of all elements

//     for (int pages = low; pages <= high; pages++) {
//         if (countStudents(arr, pages) <= m) {
//             return pages;
//         }
//     }
//     return low;
// }


// binery search - O(nlog(sum(a)-max(a)))
int findPages(vector<int>& arr, int m) {
    int n=arr.size();
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    int ans = findPages(arr, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}


// 2Q)painter's partition
// 3Q)split array-largest sum
// refer the question from geeksforgeeks


// Ans) the solution for all 3 question are same