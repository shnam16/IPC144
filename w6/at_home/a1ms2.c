/* -------------------------------------------
Name: Seung Ho Nam
Student number: 148151178
Email: shnam@myseneca.ca
Section: IPC144SHH
Date: 07/05/2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


int main (void)
{
    // Declare variables here:
  struct Name name = { "\0" };
  struct Address ad = { "\0" };
  struct Numbers num = { "\0" };
  char answer;
  
  


    // Display the title
  printf("Contact Management System\n");
  printf("-------------------------\n");


    // Contact Name Input:
  printf("Please enter the contact's first name: ");
  scanf("%s", name.firstName);
  printf("Do you want to enter a middle initial(s)? (y or n): ");
  scanf(" %c", &answer);
  if (answer == 'y' || answer == 'Y') {
    printf("Please enter the contact's middle initial(s): ");
    scanf("%s", name.middleInitial);
    printf("Please enter the contact's last name: ");
    scanf("%s", name.lastName);
  }
  else if (answer == 'n' || answer == 'N') {
    printf("Please enter the contact's last name: ");
    scanf("%s", name.lastName);
  }


    // Contact Address Input:
  printf("Please enter the contact's street number: ");
  scanf("%s", ad.streetNumber);
  printf("Please enter the contact's street name: ");
  scanf("%s", ad.street);
  printf("Do you want to enter an apartment number? (y or n): ");
  scanf(" %c", &answer);
  
  if (answer == 'y' || answer == 'Y') {
    printf("Please enter the contact's apartment number: ");
    scanf("%s", ad.apartmentNumber);
    printf("Please enter the contact's postal code: ");
    scanf(" %[^\n]7s", ad.postalCode);
  }
  else if (answer == 'n' || answer == 'N') {
    printf("Please enter the contact's postal code: ");
    scanf("%[^\n]7s", ad.postalCode);
  }
  
  printf("Please enter the contact's city: ");
  scanf("%s", ad.city);


    // Contact Numbers Input:
  printf("Do you want to enter a cell phone number? (y or n): ");
  scanf(" %c", &answer);
  
  if (answer == 'y' || answer == 'Y') {
    printf("Please enter the contact's cell phone number: ");
    scanf("%s", num.cell);
    printf("Do you want to enter a home phone number? (y or n): ");
    scanf(" %c", &answer);
  }
  else if (answer == 'n' || answer == 'N') {
    printf("Do you want to enter a home phone number? (y or n): ");
    scanf(" %c", &answer);
  }
  if (answer == 'y' || answer == 'Y') {
    printf("Please enter the contact's home phone number: ");
    scanf("%s", num.home);
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c", &answer);
  }
  else if (answer == 'n' || answer == 'N') {
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c", &answer);
  }
  if (answer == 'y' || answer == 'Y') {
    printf("Please enter the contact's business phone number: ");
    scanf("%s", num.business);
  }
  else if (answer == 'n' || answer == 'N') {

  }
  printf("\n");

    // Display Contact Summary Details
  printf("Contact Details\n");
  printf("---------------\n");
  printf("Name Details\n");
  printf("First name: %s\n", name.firstName);
  printf("Middle initial(s): %s\n", name.middleInitial);
  printf("Last name: %s\n", name.lastName);
  printf("\n");
  printf("Address Details\n");
  printf("Street number: %s\n", ad.streetNumber);
  printf("Street name: %s\n", ad.street);
  printf("Apartment: %s\n", ad.apartmentNumber);
  printf("Postal code: %s\n", ad.postalCode);
  printf("City: %s\n", ad.city);
  printf("\n");
  printf("Phone Numbers:\n");
  printf("Cell phone number: %s\n", num.cell);
  printf("Home phone number: %s\n", num.home);
  printf("Business phone number: %s\n", num.business);
  printf("\n");
  printf("Structure test for Name, Address, and Numbers Done!\n");



    // Display Completion Message



    return 0;
}

/*  SAMPLE OUTPUT:
    
Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/