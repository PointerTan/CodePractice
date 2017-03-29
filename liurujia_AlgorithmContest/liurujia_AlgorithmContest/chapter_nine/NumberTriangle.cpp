//
//  NumberTriangle.c
//  liurujia_AlgorithmContest
//
//  Created by PointrerTan on 17/3/28.
//  Copyright © 2017年 PT. All rights reserved.
//

//数字三角形问题的递归解法，通过状态转移方程来计算结果。
#define main NumberTriangleOne
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

int main() {
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
//int input[105][105], result[105][105], n;
//int maxSum(int i, int j) {
//    if(i==n) return input[i][j];
//    if(result[i][j]!=-1) return result[i][j];
//    else return result[i][j]=input[i][j]+max(maxSum(i+1,j),maxSum(i+1,j+1));
//}
//int main() {
//    scanf("%d", &n);
//    for(int i=0; i<n; i++){
//        for (int j=0; j<=i; j++) {
//            scanf("%d", &input[i][j]);
//        }
//    }
//    
//    memset(result, -1, sizeof(result));
//    printf("%d\n", maxSum(0, 0));
//    return 0;
//}
