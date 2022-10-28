Purpose: program for manipulating records of patients and employees of a hospital.

Developer full name and date: Boris Zugic, 2022-10-26

Organization: 
	hospital.c - file containing main function
	patient.c && patient.h - contains implementations and declarations of functions for handling patient records, respectively.
	employee.c && employee.h - contains implementations and declarations of functions for handling employee records, respectively.
	struct.h - contains declarations of the three structs used, namely patient, employee and person.
	populateRecords.c && populateRecords.h - contains implementations and declarations of functions used to populate the array of persons, respectively.

makeFile:
	CC = gcc
	CFLAGS = -Wall
	DEPS = patient.h employee.h struct.h populateRecords.h
	OBJ = hospital.c patient.c employee.c populateRecords.c
	%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

	hospital: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)


Issues/Limitations: 


Instructions:
 