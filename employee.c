#include "employee.h"
#include "stdio.h"


// ADD DOCUMENTATION 
//
void printEmployee(PersonRec person)

{

    if (person.emplyeeOrPatient == 0)
    {
        char temp [33];
        sprintf(temp, "%s %s", person.firstName, person.familyName);
        printf("%-33s dept:%2d salary:%9.2f position:%2d years of service:%4d salary to date:%11.2f\n", temp, person.emp.department, person.emp.salary, person.emp.position, person.emp.yearsService, person.emp.salary*(person.emp.yearsService - 1));
    }


}

/* void printEmployees(struct person *person, int numRecords)

    purpose: prints all hospital employees in a readable format

    input: 
        person - pointer to a list of person structs
        numRecords - number of elements in list
    
    output: none

    side-effects: prints formatted employee records
*/
void printEmployees(PersonRec *person, int numRecords)
{
    int i;

    printf("-------------------------------------\n");
    for (i = 0 ; i < numRecords ; i++)
    {
        printEmployee(person[i]);
    }
    printf("-------------------------------------\n\n");

    // add code

}


void printEmployeesSummary(PersonRec *person, int numRecords)
{

    // add code

}
