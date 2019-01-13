/* -------------------------------------------
Name: Seung Ho Nam
Student number: 148151178
Email: shnam@myseneca.ca
Section: IPC144SHH
Date: 30/07/2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
  while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void) {
  printf("(Press Enter to Continue)");
  clearKeyboard();

}

// getInt:
int getInt(void) {
  char NL = 'x';
  int Value;
  while (NL != '\n') {
    scanf("%d%c", &Value, &NL);
    if (NL != '\n') {
      clearKeyboard();
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");
      scanf("%d%c", &Value, &NL);
    }
  }
  return Value;
}

// getIntInRange:
int getIntInRange(int num1, int num2) {
  int Value = getInt();
  while (Value < num1 || Value > num2) {
    printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", num1, num2);
    Value = getInt();
  }

  return Value;

}

// yes:
int yes(void) {
  int Value;
  char answer;
  char NL;
  Value = 0;
  do {
    
    scanf(" %c%c", &answer, &NL);
    if (NL != '\n') {
      clearKeyboard();
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
    }
    else if (answer == 'Y' || answer == 'y') {
      Value = 1;
    }
    else {
      Value = 0;
    }
  } while (NL != '\n');
  return Value;
}

// menu:
int menu(void) {
  int option;
  printf("Contact Management System\n");
  printf("-------------------------\n");
  printf("1. Display contacts\n");
  printf("2. Add a contact\n");
  printf("3. Update a contact\n");
  printf("4. Delete a contact\n");
  printf("5. Search contacts by cell phone number\n");
  printf("6. Sort contacts by cell phone number\n");
  printf("0. Exit\n");
  printf("\n");
  printf("Select an option:> ");
  option = getIntInRange(0, 6);
  return option;

}

// ContactManagerSystem:
void ContactManagerSystem(void) {
  struct Contact contacts[MAXCONTACTS] = {
    {
      {"Rick", {'\0'}, "Grimes"},
      {11, "Trailer Park", 0, "A7A 2J2", "King City"},
      {"4161112222", "4162223333", "4163334444"} },
    {
      {"Maggie", "R.", "Greene"},
      {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
      {"9051112222", "9052223333", "9053334444"} },
    {
      {"Morgan", "A.", "Jones"},
      {77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"},
      {"7051112222", "7052223333", "7053334444"} },
    {
      {"Sasha", {'\0'}, "Williams"},
      {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
      {"9052223333", "9052223333", "9054445555"} },
  };
  int option;
  int end = 0;
  do {
    option = menu();
    switch (option) {
    case 1:
      printf("\n");
      displayContacts(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;

    case 2:
      printf("\n");
      addContact(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;

    case 3:
      printf("\n");
      updateContact(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;

    case 4:
      printf("\n");
      deleteContact(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;

    case 5:
      printf("\n");
      searchContacts(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;

    case 6:
      printf("\n");
      sortContacts(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;

    case 0:
      printf("\n");
      printf("Exit the program? (Y)es/(N)o: ");
      if (yes() == 1) {
        end = 1;
      }
      printf("\n");
      break;

    }


  } while (end != 1);
  printf("Contact Management System: terminated\n");
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
  int needInput = 1;

  while (needInput == 1) {
    scanf("%10s", telNum);
    clearKeyboard();

    // (String Length Function: validate entry of 10 characters)
    if (strlen(telNum) == 10)
      needInput = 0;
    else
      printf("Enter a 10-digit phone number: ");
  }
}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
  int i;
  int result = -1;
  for (i = 0; i <= size; i++) {
    if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
      result = i;
      break;
    }
  }
  return result;
}

// displayContactHeader
void displayContactHeader(void) {
  printf("+-----------------------------------------------------------------------------+\n");
  printf("|                              Contacts Listing                               |\n");
  printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int total) {
  printf("+-----------------------------------------------------------------------------+\n");
  printf("Total contacts: %d\n\n", total);
}


// displayContact:
void displayContact(const struct Contact* contacts) {
  if (strcmp((*contacts).name.middleInitial, "") == 0) {
    printf(" %s %s\n", (*contacts).name.firstName, (*contacts).name.lastName);
  }
  else {
    printf(" %s %s %s\n", (*contacts).name.firstName, (*contacts).name.middleInitial, (*contacts).name.lastName);

  }
  printf("    C: %-10s   H: %-10s   B: %-10s\n", (*contacts).numbers.cell, (*contacts).numbers.home, (*contacts).numbers.business);
  if ((*contacts).address.apartmentNumber > 0) {
    printf("       %d %s, Apt# %d, %s, %s\n", (*contacts).address.streetNumber, (*contacts).address.street, (*contacts).address.apartmentNumber, (*contacts).address.city, (*contacts).address.postalCode);
  }
  else {
    printf("       %d %s, %s, %s\n", (*contacts).address.streetNumber, (*contacts).address.street, (*contacts).address.city, (*contacts).address.postalCode);
  }

  }



// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {
  int i;
  int count = 0;
  displayContactHeader();
  for (i = 0; i < size; i++) {
    if (strlen(contacts[i].numbers.cell) > 0) {
      count++;
      displayContact(&contacts[i]);
    }
  }
  displayContactFooter(count);

}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size) {
  char number[11];
  int result;
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(number);
  result = findContactIndex(contacts, size, number);
  if (result == -1) {
    printf("*** Contact NOT FOUND ***\n");
  }
  else {
    printf("\n");
    displayContact(&contacts[result]);
    printf("\n");
  }
}


// addContact:
void addContact(struct Contact contacts[], int size) {
  int i;
  int available = -1;
  for (i = 0; i < size; i++) {
    if (strlen(contacts[i].numbers.cell) == 0) {
      available = i;
    }
    
  }
  if (available == -1) {
    printf("*** ERROR: The contact list is full! ***\n");
  }
  else {
    getContact(&contacts[available]);
    printf("--- New contact added! ---\n");
  }

}


// updateContact:
void updateContact(struct Contact contacts[], int size) {
  char number[11];
  int index;
  int answer;
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(number);
  index = findContactIndex(contacts, size, number);

  if (index == -1) {
    printf("*** Contact NOT FOUND ***\n");
  }
  else {
    printf("\nContact found:\n");
    displayContact(&contacts[index]);
    printf("\n");
    printf("Do you want to update the name? (y or n): ");
    answer = yes();
    if (answer == 1) {
      getName(&contacts[index].name);
    }
    printf("Do you want to update the address? (y or n): ");
    answer = yes();
    if (answer == 1) {
      getAddress(&contacts[index].address);
    }
    printf("Do you want to update the numbers? (y or n): ");
    answer = yes();
    if (answer == 1) {
      getNumbers(&contacts[index].numbers);
    }
    printf("--- Contact Updated! ---\n");
  }

}

// deleteContact:
void deleteContact(struct Contact contacts[], int size) {
  char number[11];
  int index;
  int answer;
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(number);
  index = findContactIndex(contacts, size, number);

  if (index == -1) {
    printf("*** Contact NOT FOUND ***\n");
  }
  else {
    printf("\nContact found:\n");
    displayContact(&contacts[index]);
    printf("\n");
    printf("CONFIRM: Delete this contact? (y or n): ");
    answer = yes();
    if (answer == 1) {
      contacts[index].numbers.cell[0] = '\0';
        printf("--- Contact deleted! ---\n");
    }
  }
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size) {
  int i, j;
  struct Contact temp;
  for (i = size - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0) {
        temp = contacts[j];
        contacts[j] = contacts[j + 1];
        contacts[j + 1] = temp;
      }
    }
  }
  printf("--- Contacts sorted! ---\n");
}