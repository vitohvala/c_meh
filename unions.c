#include <math.h>
#include <stdio.h>

union int_parts {
    int Int;
    char bytes[sizeof(int)];
};

struct operator {
    int type;
    union {
        int int_num;
        float float_num;
        double double_num;
    }Types;
};
union p{
    int arr[6];
    char chars[21];
};

int main() {

    // initializer lists like this are assigned to the first member of the union/struct!
    // There are 6 ints here so...
    union p intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};

    /* testing code */
    printf("[");
    // only go to 18 because 1 byte is for the terminating 0 and we don't print the last in the loop
    for(int i = 0; i < 19; ++i)
        printf("%d, ", intCharacters.chars[i]);
    printf("%c]\n", intCharacters.chars[19]);

    printf("%s\n", intCharacters.chars);
    union int_parts parts;
    parts.Int = 5968145;
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
            parts.Int, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);



    union p ime = {{1699888702, 1987017316, 1226859369, 2053204588, 0, 0}};
    puts(ime.chars);
    return 0;
}
