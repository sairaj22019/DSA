// given array consist of all integers from 1 to n, but of of the integer is missing and other appears twice.

#include<bits/stdc++.h>
using namespace std;


// brute - O(n^2)
// for every element traverse in array again to find freq.  if freq=0 it is missing, or if freq=2 it is repeating.

// better1   TC-O(nlogn +n)  SC-(n)
// traverse the array and store all frequencies in map from 1 to n, traverse map and for any element if freq=0 it is missing, or if freq=2 it is repeating.

// better2   TC-O(nlogn+n)  SC-O(1)
// sort array.then traverse linearly , if diff of consecutive numbers is 0 , it repeating or if diff is 2, it is missing

// optimal 1 (by math)   TC-O(N) SC-O(1)
vector<int> findMissingRepeatingNumbers(vector<int>& a){
    int n=a.size();
    long long Sn = (n*(n+1))/2; // sum of first n numbers
    long long S2n = (n*(n+1)*(2*n+1))/6; // sum of squares of first n numbers
    int S=0; //sum of elements of array
    int S2=0; //sum of squares of elements of array
    for (int i = 0; i <n; i++) {
        S+=a[i];
        S2+= (long long)a[i]*(long long)a[i];
    }
    int val1= S-Sn;  //repeating-missing
    int val2= S2-S2n;  //repeating^2 - missing^2
    val2=val2/val1;  //repeating+missing
    long long repeating=(val1+val2)/2;
    long long missing=repeating-val1;

    return {(int)repeating,(int)missing};
}



// optimal 1 (by XOR)    TC-O(N) SC-O(1)
// refer strivers video for better clarity
vector<int> findMissingRepeatingNumbers(vector<int>& a){
    int n=a.size();
    int xr=0;
    for (int i = 0; i <n; i++) {
        xr=xr^a[i]; // taking xor with all elements
        xr=xr^(i+1); // taking xor of all numbers from 1 to n
    }
    // the finall xr contains xor of missing and repeating element


    // find bit number which is 1 in xor, this bit number is differentiating bit of missing and repeating number and can be used to seperate them:
    int bitNo=0;
    while(1){
        if(xr & (1<<bitNo) != 0){break;}
        bitNo++;
    }

    // separating number into 2 groups depending on bitnumber is 0 or 1 and taking their xor;
    int zero=0,one=0;
    //  for elements of array
    for (int i = 0; i <n; i++) {
        if(a[i] &  (1<<bitNo) !=0){one= one^a[i];}
        else{zero=zero^a[i];}
    }
    //  for numbers from 1 to n
    for (int i = 1; i <=n; i++) {
        if(i &  (1<<bitNo) !=0){one= one^i;}
        else{zero=zero^i;}
    }
    // now missing and repeating numbers are stored in zero and one
     // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};

}


int main(){
    vector<int> a= {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}