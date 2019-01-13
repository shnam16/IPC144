/*
Name:      <Seung Ho Nam>
Student#:  <148151178>
Section:   <IPC144SHH>
*/

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include <stdio.h>
int main(void) {
  double amount;
  int noOFloonies;
  int noOFquarters;
  int noOFdimes;
  int noOFnickels;
  int noOFpennies;
  double Owing;
  double GST;
  double result1;
  double result2;
  double result3;
  double result4;
  double result5;

  printf("Please enter the amount to be paid: $");
  scanf("%lf", &amount);

  GST = (amount * 0.13) + 0.005;
  Owing = amount + GST;
  noOFloonies = (int)Owing;
  result1 = Owing - noOFloonies;
  noOFquarters = (int)(result1 * 100) / 25;
  result2 = ((int)(result1 * 100) % 25) * 0.01;
  noOFdimes = ((int)(result2 * 100) / 10);
  result3 = ((int)(result2 * 100) % 10) * 0.01;
  noOFnickels = (int)(result3 * 100) / 5;
  result4 = ((int)(result3 * 100) % 5) * 0.01;
  noOFpennies = (int)(result4 *100) / 1;
  result5 = ((int)(result4 * 100) % 1) * 0.01;

  printf("GST: %.2lf\n", GST);
  printf("Balance owing: $%.2lf\n", Owing);
  printf("Loonies required: %d, balance owing $%.2lf\n", noOFloonies, result1);
  printf("Quarters required: %d, balance owing $%.2lf\n", noOFquarters, result2);
  printf("Dimes required: %d, balance owing $%.2lf\n", noOFdimes, result3);
  printf("Nickels required: %d, balance owing $%.2lf\n", noOFnickels, result4);
  printf("Pennies required: %d, balance owing $%.2lf\n", noOFpennies, result5);
  return 0;
}