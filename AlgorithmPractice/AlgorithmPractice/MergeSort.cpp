//
//  MergeSort.cpp
//  AlgorithmPractice
//
//  Created by PointerTan on 2016/11/24.
//  Copyright © 2016年 PT. All rights reserved.
//

#include "MergeSort.hpp"

#include <iostream>
using namespace std;

#define MAX 50000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt;

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1 + n2; i++) {
        if (i < n1) {
            L[i] = A[left + i];
        }
        if (i < n2) {
            R[i] = A[mid + i];
        }
        if (i > n1 && i > n2) {
            break;
        }
    }
    
    L[n1] = R[n2] = SENTINEL;
    
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void mergeSort(int A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

void mergeMain() {
    int A[MAX], n, i;
    cnt = 0;
    
//    cin >> n;
//    for (i = 0; i < n; i++) cin >> A[i];
    
    n = 12;
    A[0] = 123;
    A[1] = 1233;
    A[2] = 23;
    A[3] = 123123;
    A[4] = 3;
    A[5] = 243;
    A[6] = 13;
    A[7] = 313323;
    A[8] = 61723;
    A[9] = 1237;
    A[10] = 5123;
    A[11] = 1623;
    
    
    mergeSort(A, 0, n);
    
    for (i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    
    cout << cnt << endl;
}



