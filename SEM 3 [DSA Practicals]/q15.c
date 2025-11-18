// Question 15:
// Implement binary search and linear search algorithms on arrays.

#include <stdio.h>

int linearSearch(int a[], int n, int key) {
    for (int i=0;i<n;i++) if (a[i]==key) return i;
    return -1;
}

int binarySearch(int a[], int n, int key) {
    int l=0, r=n-1;
    while (l<=r){
        int mid = (l+r)/2;
        if (a[mid]==key) return mid;
        else if (a[mid] < key) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

int main() {
    int n, i, key;
    printf("Array size: "); scanf("%d",&n);
    int a[n];
    printf("Enter elements (for binary search, enter sorted array):\n");
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    printf("Key: "); scanf("%d",&key);
    int p = linearSearch(a,n,key);
    if (p>=0) printf("Linear found at index %d\n", p); else printf("Linear: Not found\n");
    p = binarySearch(a,n,key);
    if (p>=0) printf("Binary found at index %d\n", p); else printf("Binary: Not found or array unsorted\n");
    return 0;
}
