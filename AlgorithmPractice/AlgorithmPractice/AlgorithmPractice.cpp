//
//  Test.cpp
//  AlgorithmPractice
//
//  Created by PointerTan on 2016/11/3.
//  Copyright © 2016年 PT. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
static const int MAX = 200000;

int maxGap() {
    int R[MAX], n;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> R[i];
    
    int maxGap = -200000000;
    int minValue = R[0];
    
    for (int i = 1; i < n; i++) {
        maxGap = max(maxGap, R[i] - minValue);
        minValue = min(minValue, R[i]);
    }
    
    cout << maxGap << endl;
    
    return 0;
}


int nubs[100000];
void shellSort() {
    auto shellSort = [](int A[], int length) -> int {
        int moveCount = 0;
        auto insertSort = [&moveCount] (int gap, int A[], int length) {
            for (int index = gap; index < length; index++) {
                int value = A[index];
                int previous = index - gap;
                while (previous >= 0 && A[previous] > value) {
                    A[previous + gap] = A[previous];
                    previous = previous - gap;
                    moveCount++;
                }
                
                A[previous + gap] = value;
            }
        };
        
        vector<int> Gap;

        for (int value = 1; ;) {
            if (value > length) break;
            Gap.push_back(value);
            value = 3*value+1;
        }
        
        cout << Gap.size() << endl;
        for (int i = (int)Gap.size()-1; i >= 0; i--) {
            printf("%d,,", Gap[i]);
        }
        printf("\n");
        
        for (int index = (int)Gap.size()-1; index >= 0; index--) {
            insertSort(Gap[index], A, length);
            
            for (int i = 0; i < length; i++) {
                printf("%d,", A[i]);
            }
            printf("\n");
            
        }
        
        return moveCount;
    };
    
    int length;
    cin >> length;
    
    for (int i = 0; i < length; i++) scanf("%d", &nubs[i]);
    
    printf("\n");
    printf("%d\n", shellSort(nubs, length));
    
    for (int i = 0; i < length; i++) {
        printf("%d,", nubs[i]);
    }
    printf("\n");
}





