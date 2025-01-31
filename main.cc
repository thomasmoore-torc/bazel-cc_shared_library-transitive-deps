#include <stdio.h>

#include "dep.h"

int main() {
    printf("42 is %d\n", dep_return42());
    printf("42 is also %d\n", dep_return42_inline());
}
