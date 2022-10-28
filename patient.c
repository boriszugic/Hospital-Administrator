/*
    file name: patient.c

    purpose: holds implementations of functions used to handle patient records

    revision:
        Boris Zugic 2022-10-28

*/


#include "string.h"
#include "stdio.h"
#include "patient.h"

// ADD DOCUMENTATION



/* void printPatient(PersonRec person)

    purpose: prints records of given patient

    input: 
    person - person struct whose records are to be printed to screen if it is a patient

    output: none

    side-effects: prints to terminal

*/
void printPatient(PersonRec person)

{

    if (person.emplyeeOrPatient == 1)
    {
        char temp [33];
        sprintf(temp, "%s %s", person.firstName, person.familyName);
        printf("%-33s dept:%2d in hospital:%3d severity:%2d daily cost:%3d total cost:%5d\n", temp, person.patient.department, person.patient.numDaysInHospital - 1, person.patient.severity, person.patient.dailyCost, person.patient.dailyCost*(person.patient.numDaysInHospital - 1));
    }

}

/********************************************************************/
void printPatients(PersonRec *person, int numRecords)
{

    int i;

    printf("-------------------------------------\n");
    for (i = 0 ; i < numRecords ; i++)
    {
        printPatient(person[i]);
    }
    printf("-------------------------------------\n\n");


}


/********************************************************************/
void printPatientSummary(PersonRec *person, int numRecords)
{

    // add code 

}


/********************************************************************/
void searchPatients(PersonRec *person, int numRecords)
{
    char familyName[15];
    int i, found = 0;

    printf("Enter the family name of patient: ");
    // get family name of patient from user
    scanf("%s", familyName);
    // clear the buffer
    fflush(stdin);

    // search records for matching family name
    for (i = 0 ; i < numRecords ; i++)
    {
        if (strcmp(person[i].familyName, familyName) == 0)  // if match is found
        { 
            printPatient(person[i]);    // print patient records
            found = 1;
        }
    }

    if (!found)
        printf("No patients with family name %s.\n", familyName);

}
