//given an array of size n. each element from 1 to (n+1) appear exactly once execpt 1 missing number
//find missing number

#include<bits/stdc++.h>
using namespace std;

//1)brute force-O(n^2) space-O(1)
//we can tranverse the array and check whether each number(from 1 to n+1) is present in array or not and find missing number

// //2) bettter(by creating hash array)  time-O(2n) space-O(n)
// int missingNumber(vector<int>& a){
//     int n=a.size();
//     vector<int> hash(n+2,0);//here ith index says whether i is present or not in 'a'.{ignore 0th index}
//     for (int i = 0; i <n; i++) {
//         hash[a[i]]=1;
//     }
//     for (int i = 1; i <=n+1; i++) {
//         if(hash[i]==0){
//             return i; 
//         }
//     }
// }

// OR
//3)better  time-O(nlogn+n)   space-O(1)
// we can sort array and traverese the array to find missing element

// //4)optimal   time-O(n)  space-O(1)
// int missingNumber(vector<int>& a){
//     int n=a.size();
//     int sum1=0;
//     for (int i = 0; i <n; i++) {
//         sum1+=a[i];
//     }
//     int sum2=((n+1)*(n+2))/2;  //sum of first n+1 natural numbers
//     return sum2-sum1;  //difference is missing element
// }

// 5)super optimised
//explaination: xor1=1^2^3^4^5  {xor of all numbers from 1 to (n+1)}
//              xor2=1^4^2^5  {xor of all elements in array}
//          now xor1^xor2=(1^1)^(2^2)^(3)^(4^4)^(5^5) 
//                       =0^0^3^0^0    {a^a=0}
//                       =3   {a^0=a}   {therefore 3 is missing element}
int missingNumber(vector<int>& a){
    int n=a.size();
    int xor1=0;
    int xor2=0;
    for (int i = 0; i <n; i++) {
        xor1=xor1^(i+1);
        xor2=xor2^a[i];
    }
    xor1=xor1^(n+1);
    int sum2=((n+1)*(n+2))/2;  
    return xor1^xor2;  
}

//** here sum method and xor method has same time and space complexity
// if n=10^5, sum goes till 10^10(large value) so we have to use long long(slightly higher memory)
// but xor does not go cross 10^5 
// therfore xor method is slightly optimal than sum method

int main(){
    vector<int> a={1,4,2,5};
    int ans = missingNumber(a);
    cout<<ans<<endl;
    return 0;
}