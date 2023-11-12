#include "table.h"
#include <stdio.h>

void print_table(int (*table)[3][3]) {
    printf(" %d | %d | %d\n", (*table)[0][0], (*table)[0][1], (*table)[0][2]);
    puts("-----------");
    printf(" %d | %d | %d\n", (*table)[1][0], (*table)[1][1], (*table)[1][2]);
    puts("-----------");
    printf(" %d | %d | %d\n", (*table)[2][0], (*table)[2][1], (*table)[2][2]);
}
