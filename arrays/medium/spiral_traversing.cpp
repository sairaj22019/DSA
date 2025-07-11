#include<bits/stdc++.h>
using namespace std;

// void spiral_matrix(vector<vector<int>>& a, int n,int m) {
//     int left=0,right=m-1,up=0,down=n-1;
//     string dir="u";
//     int i=0,j=0;
//     int num=1;
//     while(num<=n*m){
//         a[i][j]=num;
//         num++;
//         if(i==up && dir=="u"){
//             dir="r";
//             up++;
//         }else if(j==right && dir=="r"){
//             dir="d";
//             right--;
        
//         }else if(i==down && dir=="d"){
//             dir="l";
//             down--;
        
//         }else if(j==left && dir=="l"){
//             dir="u";
//             left++;
//         }

//         if(dir=="r"){j++;}
//         else if(dir=="d"){i++;}
//         else if(dir=="l"){j--;}
//         else if(dir=="u"){i--;}

//     }
// }

// OR

void spiral_matrix(vector<vector<int>>& a, int n,int m) {
    int left=0,right=m-1,up=0,down=n-1;
    string dir="u";
    int i=0,j=0;
    int num=1;
    while(num<=n*m){
        a[i][j]=num;
        num++;
        if(i==up && dir=="u"){
            dir="r";
            up++;
        }else if(j==right && dir=="r"){
            dir="d";
            right--;
        
        }else if(i==down && dir=="d"){
            dir="l";
            down--;
        
        }else if(j==left && dir=="l"){
            dir="u";
            left++;
        }

        if(dir=="r"){j++;}
        else if(dir=="d"){i++;}
        else if(dir=="l"){j--;}
        else if(dir=="u"){i--;}

    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    spiral_matrix(a, n,m);
    for (int i = 0; i <n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}