//
//  NumberTriangle.c
//  liurujia_AlgorithmContest
//
//  Created by PointrerTan on 17/3/28.
//  Copyright © 2017年 PT. All rights reserved.
//

#include "NumberTriangle.h"

#include <stdio.h>
#include <string.h>

int maxV[105][105];
int data[105][105];
int n;

int maxij(int i, int j) {
    if (i == n - 1) {
        maxV[i][j] = data[i][j];
        return maxV[i][j];
    }
    
    if (maxV[i][j] != -1) return maxV[i][j];

    int valueA = maxij(i + 1, j);
    int valueB = maxij(i + 1, j + 1);
    maxV[i][j] = (valueA>valueB?valueA:valueB) + data[i][j];
    return maxV[i][j];
}

void round(int index) {
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for (int j=0; j<=i; j++) {
            scanf("%d", &data[i][j]);
        }
    }
    
    memset(maxV, -1, sizeof(maxV));
    printf("%d\n", maxij(0, 0));
}

int NumberTriangleOne() {
    int testCount;
    scanf("%d", &testCount);
    for (int i = 0; i < testCount; i++) {
        round(i);
    }
    
    return 0;
}

//#include <iostream>
//#include <string.h>
//#include <algorithm>
//
//using namespace std;
//int a[105][105], d[105][105], n;
//int dfs(int i, int j) {
//    if(i==n) return a[i][j];
//    if(d[i][j]!=-1) return d[i][j];
//    else return d[i][j]=a[i][j]+max(dfs(i+1,j),dfs(i+1,j+1));
//}
//int main() {
//    scanf("%d", &n);
//    for(int i=0; i<n; i++){
//        for (int j=0; j<=i; j++) {
//            scanf("%d", &a[i][j]);
//        }
//    }
//
//    memset(d, -1, sizeof(d));
//    printf("%d\n", dfs(0, 0));
//    return 0;
//}
