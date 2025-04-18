#include <stdio.h>

int main(){

char key, choice;
int num, count;
long date;
float yield;
double price;

printf("%lu\n", sizeof(key)*8); 
printf("%lu\n", sizeof(choice)*8);
printf("%lu | %lu\n", sizeof(num)*8, sizeof(count)*8);
printf("%lu\n", sizeof(date)*8);
printf("%lu\n", sizeof(yield)*8);
printf("%lu\n", sizeof(price)*8);

printf("----------\n");

printf("%p | %p\n", key, choice);
printf("%p | %p\n", num, count);
printf("%p\n", date);
printf("%p\n", yield);
printf("%p", price);

}