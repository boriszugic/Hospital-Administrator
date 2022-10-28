#include "employee.h"
#include "stdio.h"


/* void printEmployee(PersonRec person)

    purpose: prints employee records in a readable format

    input: 
        person - person struct
    
    output: none

    side-effects: prints to terminal

*/
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

    purpose: prints all hospital employees records in a readable format

    input: 
        person - pointer to a list of person structs
        numRecords - number of elements in list
    
    output: none

    side-effects: prints to terminal
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

}

/* void printEmployeesSummary(PersonRec *person, int numRecords)
    
    purpose: prints summary of employee records 

    input:
    person - pointer to person struct array
    numRecords - num of person structs in array

    output: none

    side-effects: prints to terminal
*/
void printEmployeesSummary(PersonRec *person, int numRecords)
{
    int numOfEmployeesByPosition[4], i;
    float totalSalaryByPosition[4];
    
    // initialize array with 0's
    for (i = 0 ; i < 4 ; i++)
    {
        numOfEmployeesByPosition[i] = 0;
        totalSalaryByPosition[i] = 0;
    }

    for (i = 0 ; i < numRecords ; i++)
    {

        
        if (person[i].emplyeeOrPatient == 0)    // if person is an employee
        {
            numOfEmployeesByPosition[(person[i].emp.position)]++;       // increase value at index corresponding to emp position
            totalSalaryByPosition[(person[i].emp.position)] += person[i].emp.salary;        // add salary to value at index corresponding to emp pos
        }
    }

    // OVERALL SUMMARY
    printf("\n----------Overall Summary------------------\nTotal number of employees:%3d total salary:%10.2f average salary:%8.2f\n-----------------------------------\n", (numOfEmployeesByPosition[0] + numOfEmployeesByPosition[1] + numOfEmployeesByPosition[2] + numOfEmployeesByPosition[3]), (totalSalaryByPosition[0] + totalSalaryByPosition[1] + totalSalaryByPosition[2] + totalSalaryByPosition[3]),  (totalSalaryByPosition[0] + totalSalaryByPosition[1] + totalSalaryByPosition[2] + totalSalaryByPosition[3])/(numOfEmployeesByPosition[0] + numOfEmployeesByPosition[1] + numOfEmployeesByPosition[2] + numOfEmployeesByPosition[3]));

    // SUMMARY BY POSITION
    printf("\n----------Summary by Position--------------\n");
    for (i = 0 ; i < 4 ; i++)
    {
        printf("position[%d] - employees:%2d total salary:%9.2f average salary:%8.2f\n", i, numOfEmployeesByPosition[i], totalSalaryByPosition[i], totalSalaryByPosition[i]/numOfEmployeesByPosition[i]);
    }
}
