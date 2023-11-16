#include <stdio.h>

int main(){
  /*  int a[] = {1, 2, 3, 4, 5};
    int *p = &a[2];

    printf("%d\n", *p);
    p++;

    printf("%d\n", *p);

    p-= 2;
    printf("%d\n", *p);
*/

    int intarray[5] = {10,20,30,40,50};
    //-----------------------^
    int *pointer = &intarray[2];

    // Array of 3 pointers
    int *parray[3];

    // Copy last three addresses of intarray into parray
    // Use parray and pointer
    int i;
    for (i = 0; i < 3; i++) {
        // Insert code here
        parray[i] = &pointer[i];
    }

    // Test code
    for (i = 0; i < 3; i++) {
        if (parray[i] == &pointer[i]) {
            printf("Matched!\n");
        } else {
            printf("Fail\n");
        }
    }
    return 0;
}
