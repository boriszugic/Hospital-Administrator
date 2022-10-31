Purpose: easy-to-use program for gathering and summarizing records of patients and employees of a hospital.

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

1. if user inputs a non-number when prompted to choose 1 of the 6 options, program enters an infinite loop.
2. when searching for patient by family name, user input is case-sensitive (i.e. Smith will work, but smith won't)
3. when asked "Are you sure you want to quit (y/n)?", the input has to match one of the following formats in order to confirm quiting:
	- "yes"
	- "y"
	- "YES"
	- "Y"

	Inputs such as "yES" or "yess" and everything else will be considered as a no.


Instructions:

1. run makeFile to compile and run program 
2. select one of 5 menu options or enter 0 to quit
