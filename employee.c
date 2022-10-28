#include "employee.h"
#include "stdio.h"


// ADD DOCUMENTATION 
//
void printEmployee(PersonRec person)

{

    // add code

}

void printEmployees(PersonRec *person, int numRecords)
{
    int i;

    printf("-------------------------------------\n");
    for (i = 0 ; i < numRecords ; i++)
    {
        if (person[i].emplyeeOrPatient == 0)
        {
            char temp [33];
            sprintf(temp, "%s %s", person[i].firstName, person[i].familyName);
            printf("%-33s dept:%2d salary:%9.2f position:%2d years of service:%4d salary to date:%11.2f\n", temp, person[i].emp.department, person[i].emp.salary, person[i].emp.position, person[i].emp.yearsService, person[i].emp.salary*(person[i].emp.yearsService - 1));
        }
    }
    printf("-------------------------------------\n\n");

    // add code

}


void printEmployeesSummary(PersonRec *person, int numRecords)
{

    // add code

}
