#include <stdlib.h>
#include <stdio.h>

void drillPrint(const char* p, const int x) {
    printf("p is \"%s\" and x is %i\n", p, x);
}

int main() {
    printf("Hello World!\n");

    char* hello = "Hello";
    char* world = "World!";
    printf("%s %s\n", hello, world);

    drillPrint("foo", 7);
    drillPrint("kiskutya", 356);
    drillPrint("színház", -5);

    return 0;
}
