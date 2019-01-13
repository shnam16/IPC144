//--------------------------------------------------
// Name: Seung Ho Nam           
// Student Number: 148151178
// Email: shnam@myseneca.ca         
// Section: IPC144SHH        
// Workshop: Workshop 04       
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#include <stdio.h>
int main(void) {

  int days;
  int high[10];
  int low[10];
  int day;
  int highest;
  int lowest;
  int lowestDay;
  int highestDay;
  int averageDay;
  double totalTemp;
  double average;

  printf("---=== IPC Temperature Calculator V2.0 ===---\n");

  printf("Please enter the number of days, between 3 and 10, inclusive: ");
  scanf("%d", &days);
  printf("\n");

  while (days < 3 || days > 10) {

    printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
    scanf("%d", &days);
    printf("\n");

  }

  for (day = 1; day < days + 1; day++) {
    printf("Day %d - High: ", day);
    scanf("%d", &high[day - 1]);
    printf("Day %d - Low: ", day);
    scanf("%d", &low[day - 1]);

    lowest = 0;
    highest = 0;
    if (lowest > low[day - 1]) {
      lowest = low[day - 1];
      lowestDay = day;
    }
    if (highest < high[day - 1]) {
      highest = high[day - 1];
      highestDay = day;
    }

  }
  printf("\nDay  Hi  Low\n");
  for (day = 1; day < days + 1; day++) {
    printf("%d    %d    %d\n", day, high[day - 1], low[day - 1]);
  }

  printf("\n");
  printf("The highest temperature was %d, on day %d\n", highest, highestDay);
  printf("The lowest temperature was %d, on day %d\n", lowest, lowestDay);

  averageDay = 0;
  while (averageDay >= 0) {

    printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
    scanf("%d", &averageDay);
    printf("\n");

    totalTemp = 0;
    if (averageDay < 0) break;
    else if (averageDay < 1 || averageDay > days) {
      printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", days);
      scanf("%d", &averageDay);
      printf("\n");
    }
    if (averageDay >= 1 && averageDay <= days) {
      for (day = 0; day < averageDay; day++) {
        totalTemp = totalTemp + (double)(high[day] + low[day]);
      }
      average = totalTemp / (averageDay * 2);
      printf("The average temperature up to day %d is: %.2lf", averageDay, average);
      printf("\n");
    }
  }

  printf("Goodbye!\n");

  return 0;
}