/*
file name is hospital.c

purpose: tests employee.c, patient.c, && populateRecords.c functions

revision:
	Doron Naussbaum - Initial Code
	Boris Zugic, 2022-10-27
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
#define MENU "Please choose one of the following:\n\n1. Print all employees\n2. Search for all patients by Family Name\n3. Summary of Employees Data\n4. Summary of Patients Data\n5. Size of structures (PersonRec, PatientRec and EmployeeRec)\n0. Quit\n"

				 
/*********** FUNCTION PROTOTYPES *************/

int menu();
	


int main(int argc, char * argv[])
{
	
	
	//printf("%s", argv[1]);
	PersonRec *person;
	int numRecords = 0;         // number of records to be created
	char rc = 0;

	//printf("%d %d %d %d\n", sizeof(person->familyName), sizeof(person->firstName), sizeof(person->emplyeeOrPatient), sizeof(person->patient));

	PatientRec *patient = &(PatientRec){1, 2, 10, 3};
	EmployeeRec *employee = &(EmployeeRec){1, 2, 10, 3};
	
	/*
	printf("size of patient: %d\n", sizeof(*patient));
	printf("size of employee: %d\n", sizeof(*employee));
	printf("size of person: %d\n", sizeof(*person));
	*/
	
	// check the command line parameters for correct number of paramaters
	// if the number is wrong prompt for correct usage and quit
	if (argc < 2)
	{
		printf("Invoking the program: program_name number_of_records\nFor example: hospital 37\n");
		return 1;
	}

	numRecords = atoi(argv[1]);
	// add code to get the number of records to be created
	// if number of records is not given then insruct the user what is required.
	person = (PersonRec *)malloc(numRecords * sizeof(PersonRec));
	if (person == NULL)
		return 1;
	/*
	(person)->firstName[NAME_SIZE - 1] = '\0';
	strncpy(person->firstName, "Boris", NAME_SIZE - 1);
	
	(person)->familyName[NAME_SIZE - 1] = '\0';
	strncpy(person->familyName, "Zugic", NAME_SIZE - 1);
	
	person->emplyeeOrPatient = 1;
	*/
	
	// populating the array person with data of patients and employees
	populateRecords(person, numRecords);
	//printf("numRecords: %d\n", numRecords);

	/*
	for (int i = 0 ; i < numRecords ; i++)
	{
		printf("%s\n", person[i].familyName);
	}
	*/


	// add code here for menu handling
	
	while (1)
	{

	switch (menu()){

		case 0:
			;
			char temp[10];
			// warn user that they are quitting
			printf("Are you sure you want to quit (y/n)? ");
			scanf("%s", temp);
			
			// quit if answer is yes
			if (strcmp(temp, "yes") == 0 || strcmp(temp, "y") == 0  || strcmp(temp, "YES") == 0  || strcmp(temp, "Y") == 0 )
			{
				printf("\nBye.");
				exit(0);
			}
			// else display menu again (loop again)
		case 1:

			break;

		case 2:

			break;

		case 3:

			break;

		case 4:

			break;

		case 5: 

			break;

		case 6:

			break;
	}
	} 




	// release memory
	free(person);

	return 0;
}


int menu()
{
	int option;
	
	// print menu
	printf("%s", MENU);
	// get user choice
	scanf("%d", &option);
	
	// if choice is not a number within 0-6
	// display menu and get user input again
	while (option < 0 || option > 6)
	{
		printf("%s", MENU);
		scanf("%d", &option);
	}

	return option;
}



