#include <stdio.h>
int main(int argc, char* argv[]) {
int a;
a = 1;
do {
printf("%d", a);

a = (a) + (1);
} while((a)<=(0));
printf("\n");


return 0; 
}