#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lin(int arr[], int n, int m) {
    int i;
    for(i = 0; i < n; i++) {
        del();
        if(arr[i] == m) {
            printf("Found\n");
            return;
        }
    }
    printf("Not Found\n");
}

void bin(int arr[], int n, int m){
    int start = 0, end = n-1, mid;
    while(start<=end) {
        mid = (start+end)/2;
        if(arr[mid] == m) {
            printf("Element found at position %d\n", mid+1);
            exit(0);
        }
        else if(m > arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }

    printf("Element not found\n");
}

void del() {
    int m, i, j;
    for(j = 0; j < 700; j++) {
        for(i = 0; i < 700; i++) {
            m = 3+4+5;
        }
    }
}

int main() {
    int n, i, j, arr[100000], m = 100;
    clock_t start, end;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        arr[i] = rand()/100;
    }

    int c;
    while(1) {
        printf("1.Linear Search\n2.Binary Search\n3.Exit\n");
        scanf("%d", &c);
        switch(c) {
        case 1:
            start = clock();


            lin(arr, n, m);

            end = clock();
            break;

        case 2:
            start = clock();


            bin(arr, n, m);

            end = clock();
            break;

        default: exit(0);
        }
        printf("Time taken: %.10f", (end-start)/(double)CLOCKS_PER_SEC);
    }
    return 0;
}
