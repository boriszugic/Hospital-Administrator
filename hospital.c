/*
file name is hospital.c

purpose: tests employee.c, patient.c, && populateRecords.c functions

revision:
	Doron Naussbaum - Initial Code
	Boris Zugic, 2022-10-27
	Boris Zugic, 2022-10-30
*/

/********* INCLUDES ***********/

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"

/*********** DEFINES **********/

#define NUM_RECORDS 20
#define MENU "\n-----------------------------------\nPlease choose one of the following:\n\n1. Print all employees\n2. Search for all patients by Family Name\n3. Summary of Employees Data\n4. Summary of Patients Data\n5. Size of structures (PersonRec, PatientRec and EmployeeRec)\n0. Quit\n"

/*********** FUNCTION PROTOTYPES *************/

int menu();

int main(int argc, char *argv[])
{

	PersonRec *person;
	int numRecords = 0; // number of records to be created
	char rc = 0;

	if (argc < 2) // if the number of command-line args is less than 2 (i.e. only filename)
	{
		printf("Invoking the program: program_name number_of_records\nFor example: hospital 37\n");
		return 1;
	}

	numRecords = atoi(argv[1]); // get # of person records to be created

	person = (PersonRec *)malloc(numRecords * sizeof(PersonRec)); // dynamically allocate memory for person structs
	if (person == NULL)
		return 1; // exit program if allocation is unsuccessful

	populateRecords(person, numRecords); // populating the array person with data of patients and employees

	/* menu handling */

	while (1)
	{

		switch (menu())
		{

		case 0: // quit
			;
			char temp[10];

			printf("Are you sure you want to quit (y/n)? "); // warn user that they are quitting
			scanf("%s", temp);

			if (strcmp(temp, "yes") == 0 || strcmp(temp, "y") == 0 || strcmp(temp, "YES") == 0 || strcmp(temp, "Y") == 0) // if answer is yes,
			{
				printf("\nBye.");
				exit(0); // quit
			}
			break;

		case 1: // print all employees
			printEmployees(person, numRecords);
			break;

		case 2: // search for all patients by family name
			searchPatients(person, numRecords);
			break;

		case 3: // summary of employees records
			printEmployeesSummary(person, numRecords);
			break;

		case 4: // summary of patient records
			printPatientSummary(person, numRecords);
			break;

		/*
		case 5: // size of structs

			printf("Size of structures\nSize of PersonRec = %d\nSize of EmployeeRec = %d\nSize of PatientRec = %d\n", sizeof(PersonRec), sizeof(EmployeeRec), sizeof(PatientRec));
			break;
		*/
		}
	}

	free(person); // release memory

	return 0;
}


/*int menu()

purpose: display menu to user and gets user choice

input: none

output: user choice

side-effects: prints to terminal

*/
int menu()
{
	int option;

	
	printf("%s", MENU);		// print menu
	scanf("%d", &option);	// get user choice

	
	while (option < 0 || option > 6)	// if choice is NOT a number within 0-6
	{
		printf("%s", MENU);		// display menu and 
		scanf("%d", &option);	// get user input again
	}

	return option;
}