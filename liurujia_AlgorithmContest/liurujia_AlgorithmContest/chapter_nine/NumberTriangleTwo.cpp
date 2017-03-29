//
//  NumberTriangleTwo.cpp
//  liurujia_AlgorithmContest
//
//  Created by PointrerTan on 17/3/29.
//  Copyright © 2017年 PT. All rights reserved.
//

#ifdef DEBUG
#define main numberTriangleTwo
#include "NumberTriangleTwo.hpp"
#endif

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

static int input[105][105], result[105][105], n;
int maxSumFrom00() {
    for (int i=0; i<n-1; i++) {
        result[n-1][i] = input[n-1][i];
    }
    for (int i=n-2; i>=0; i--) {
        for (int j=0; j<=i; j++) {
            result[i][j] = max(result[i+1][j], result[i+1][j+1]) + input[i][j];
        }
    }
   return result[0][0];
}

int main() {
    int testCount;
    scanf("%d", &testCount);
    for (int i = 0; i < testCount; i++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            for (int j=0; j<=i; j++) {
                scanf("%d", &input[i][j]);
            }
        }
        
        memset(result, -1, sizeof(result));
        printf("%d\n", maxSumFrom00());
    }
    return 0;
}
