// Name: Seung Ho Nam
// Student Number: 148151178
// Email: SHNAM@myseneca.ca
// Section: IPC144SHH
// Workshop: ws03

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 3
int main(void) {
  int high;
  int low;
  int day;
  int lowTotal = 0, highTotal = 0;
  double average;


  printf("---=== IPC Temperature Analyzer ===---\n");

  for (day = 0; day < NUMS; day++) {

	  do {
		  printf("Enter the high value for day %d: ", day + 1);
		  scanf("%d", &high);
		  printf("\n");
		  printf("Enter the low value for day %d: ", day + 1);
		  scanf("%d", &low);
		  printf("\n");
		  if ((high > 40 || low < -40) || (high < low))
			  printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
	  } while ((high > 40 || low < -40) || high < low);

	  lowTotal += low;
	  highTotal += high;
  }
  
  average = (double)(lowTotal + highTotal) / (NUMS * 2);

  printf("The average (mean) temperature was: %.2lf\n", average);
  return 0;
}
