//1Q) given 2 sorted arrays, find median of the combined array.

#include<bits/stdc++.h>
using namespace std;

// // brute(by merge sort)    TC-O(n1+n2) SC-O(n1+n2)
// double median(vector<int>& a, vector<int>& b) {
//     int n1 = a.size(), n2 = b.size();

//     vector<int> arr3;
//     int i = 0, j = 0;
//     while (i < n1 && j < n2) {
//         if (a[i] < b[j]) arr3.push_back(a[i++]);
//         else arr3.push_back(b[j++]);
//     }

//     //copy the left-out elements:
//     while (i < n1) arr3.push_back(a[i++]);
//     while (j < n2) arr3.push_back(b[j++]);

//     //Find the median:
//     int n = n1 + n2;
//     if (n % 2 == 1) {
//         return (double)arr3[n / 2];
//     }

//     double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
//     return median;
// }



// optimal TC-O(log(min(n1,n2)))  SC-O(1)
double median(vector<int>& a,vector<int>& b){
    int n1=a.size();
    int n2=b.size();
    if (n1>n2){return median(b,a);}  //here we want the smaller array to be first array . so swap the arrays ,we can just run same function in reverse order.
    int low=0,high=n1;
    int leftSection=(n1+n2+1)/2;
    while(low<=high){
        int mid1=(low+high)/2; // no of elements to be taken from array 'a' to be placed in left section(i.e before median)
        int mid2=leftSection-mid1; // no of elements to be taken from array 'b' to be placed in left section(i.e before median)
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n1){r1=a[mid1];}
        if(mid2<n2){r2=b[mid2];}
        if(mid1-1>=0){l1=a[mid1-1];}
        if(mid2-1>=0){l2=b[mid2-1];}
        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2==1){return (double)max(l1,l2);}
            return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
        }else if(l1>r2){high=mid1-1;}
        else{low=mid1+1;}
    }
    return 0; 
}



int main(){
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1) << median(a, b) << '\n';
}

//2Q) find the kth element of combined sorted arrays.
// A)brute and better are same as 1Q.
//   optimzal is also the same as 1Q but just change the following:
//     1)leftsection=k;
//     2)low=max(k-n2,0),high=min(n,1,k);
//     3)if(l1<=r2 && l2<=r1)  ==>  we dont have to check whether n1+n2 is divisble by 2 or not . we directly have to return max(l1,l2);