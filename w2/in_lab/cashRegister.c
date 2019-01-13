/*
Name:      <Seung Ho Nam>
Student#:  <148151178>
Section:   <IPC144SHH>
*/

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include <stdio.h>
int main(void){
  double amount;
  int noOFloonies;
  int noOFquarters;
  double result1;
  double result2;
  printf("Please enter the amount to be paid: $");
  scanf("%lf", &amount);
  noOFloonies = amount / 1;
  result1 = amount - noOFloonies;
  noOFquarters = result1 / 0.25;
  result2 = result1 - (noOFquarters * 0.25);
  printf("Loonies required: %d, balance owing $%.2lf\n", noOFloonies, result1);
  printf("Quarters required: %d, balance owing $%.2lf\n", noOFquarters, result2);
  return 0;
}