The project was made as an assignment for university security classes.
It encrypts pandas dataframes using RSA key (currently only integers).
The RSA key alghoritm is made in C in encoder.c and it is applied to dataframes in python.

dependencies:
- pandas
- numpy
- ctypes (to import the library)
- math (to convert floating values to integers)
- unittest (for testing of course)
