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

  printf("---=== IPC Temperature Calculator V2.0 ===---\n");

    printf("Please enter the number of days, between 3 and 10, inclusive: ");
    scanf("%d", &days);

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
   
  }
  printf("\nDay  Hi  Low\n");
  for (day = 1; day < days + 1; day++) {
    printf("%d    %d    %d\n", day, high[day-1], low[day-1]);
  }
  return 0;
}