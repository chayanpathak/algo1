#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
int man_gcd (int a, int b){
    if (a == 0){
        return b;
    }
    if (b == 0){
        return a;
    }
    if (a == b) {
        return a;
    }
    if (a>b)
        return man_gcd(a-b,b);
    return man_gcd(a,b-a);

}
int gcd1(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd1(a-b, b);
    return gcd1(a, b-a);
}
int mat_uniques (int a[100000][100000], int depth, int width, int vert1, int vert2){
    int uniques[10000000000];
    int count=0;
    int start_vert, end_vert;
    if (vert1 < vert2){
        start_vert = vert1;
        end_vert = vert2;
    }
    else {
        start_vert = vert2;
        end_vert = vert1;
    }
    for (int i = start_vert; i<end_vert; i++){
        for (int j = start_vert; j<end_vert; j++){
            if (count == 0){
                uniques[0] == a[i][j];
                count++;
            }
            else {
                int iter=0;
                for (int l=0; l<count; l++){
                    if (a[i][j] == uniques[l]){
                        break;
                    }
                    else iter++;
                }
                if (iter == count){
                    count++;
                    uniques[count] = a[i][j];
                }
            }
        }
    }
    return count;
}
int main () {
    int ar1[100000],ar2[100000];
    int gcd[100000][100000];
    int ques[10][4];
    int n,m,q;
    int num_uniques[10];
    cin >> n;
    cin >> m;
    cin >> q;
    for (int i=0; i<n; i++) {
        cin >> ar1[i];
    }
    for (int j=0; j<m; j++) {
        cin >> ar2[j];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            gcd[i][j] = man_gcd(ar1[i],ar2[j]);
            //cout <<"\t " << gcd[i][j];
        }
        cout << "\n";
    }
    for (int k=0; k<q; k++){
        for(int l=0; l<4; l++){
            cin >> ques[k][l];
        }
    }
    for (int k=0; k<q; k++){
        num_uniques[k] = mat_uniques(gcd,n,m,ques[q][0],ques[q][2]);
        if(k!=0){
            cout <<"\n";
        }
        cout<<num_uniques[k];
    }
    return 0;
}
