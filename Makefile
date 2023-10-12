CC = gcc
	CFLAGS = -Wall
	DEPS = patient.h employee.h struct.h populateRecords.h
	OBJ = hospital.c patient.c employee.c populateRecords.c
	%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

	hospital: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)
