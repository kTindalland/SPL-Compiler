#include <stdio.h>
int main(int argc, char* argv[]) {
int var2,var1;
char var3;
double var5,var4;
scanf(" %d",&var1);
scanf(" %d",&var2);
if ((var1)>(var2)) {
printf("A");
}else {
printf("B");
}
printf("\n");

scanf(" %lf",&var4);
var5 = (var4) * (2.3);
printf("%lf", var5);

printf("\n");

scanf(" %c",&var3);
printf("%c", var3);

printf("\n");


return 0; 
}
