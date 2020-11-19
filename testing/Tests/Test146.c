#include <stdio.h>
int main(int argc, char* argv[]) {
int var1;
var1 = 1;
do {
printf("%d", var1);

var1 = (var1) + (1);
} while((var1)<=(5));
printf("\n");


return 0; 
}
