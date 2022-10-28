/*
    file name: patient.c

    purpose: holds implementations of functions used to handle patient records

    revision:
        Boris Zugic 2022-10-28

*/


/************ INCLUDE FILES **************/

#include "string.h"
#include "stdio.h"
#include "patient.h"

/*************** DEFINES ***************/



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

/* void printPatients(PersonRec *person, int numRecords)

    purpose: prints records of patients

    input: 
    person - pointer to array of person structs
    numRecords - number of person structs in array

    output: none

    side-effects: prints to terminal

*/
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


/*void printPatientSummary(PersonRec *person, int numRecords

    purpose: prints summary of patient records to terminal

    input:
    person - pointer to array of person structs
    numRecords - number of person structs in array

    output: none

    side-effects: prints to terminal


*/
void printPatientSummary(PersonRec *person, int numRecords)
{
        int numOfPatients[6], i;
        float costToDate[6];
        float dailyCost[6];

        for (i = 0 ; i < 6 ; i++)   // initialize values to 0
        {

            numOfPatients[i] = 0;
            costToDate [i] = 0;
            dailyCost[i] = 0;

        }
  
        for (i = 0 ; i < numRecords ; i++)
        {
            if (person[i].emplyeeOrPatient % 2)
            {

                numOfPatients[person[i].patient.department - 1]++;      // add 1 for each patient to corresponding department
                costToDate[person[i].patient.department - 1] += (person[i].patient.dailyCost * (person[i].patient.numDaysInHospital - 1));      // add cost to date for each patient to corresponding department
                dailyCost[person[i].patient.department - 1] += person[i].patient.dailyCost; 

            }
        }

        printf("---------------- Patient Summary ---------------------\n\n");
        printf("Total number of patients:%3d total cost to-date:%8.2f average cost per patient to-date:%7.2f\n\n", numOfPatients[0] + numOfPatients[1] + numOfPatients[2] + numOfPatients[3] + numOfPatients[4] + numOfPatients[5], costToDate[0] + costToDate[1] + costToDate[2] + costToDate[3] + costToDate[4] + costToDate[5],(costToDate[0] + costToDate[1] + costToDate[2] + costToDate[3] + costToDate[4] + costToDate[5])/(numOfPatients[0] + numOfPatients[1] + numOfPatients[2] + numOfPatients[3] + numOfPatients[4] + numOfPatients[5]));
        
        
        printf("---------------- Summary by Department ---------------\n\n");
        for (i = 0 ; i < 6 ; i++)
        {

            printf("Department[%d] - patients:%3d cost-to-date:%7.2f daily cost:%7.2f average daily cost per patient:%7.2f\n", i + 1, numOfPatients[i], costToDate[i], dailyCost[i], dailyCost[i]/numOfPatients[i]);

        }

}


/* void searchPatients(PersonRec *person, int numRecords)

    purpose: searches patient based on family name and prints their records if found

    input:
    person - pointer to array of person structs
    numRecords - number of person structs in array

    output: none

    side-effects: prints to terminal

*/
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
