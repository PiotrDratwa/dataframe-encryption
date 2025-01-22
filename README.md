# About the Project

This project was created as an assignment for university security classes. It demonstrates how to encrypt **pandas dataframes** using an **RSA key** (currently supports only integer values).  

The **RSA key algorithm** is implemented in C (`encoder.c`) and applied to dataframes in Python.

---

## Dependencies

To run the project, make sure you have the following libraries installed:  
- **pandas**: For handling dataframes  
- **numpy**: For numerical operations  
- **ctypes**: To import the C library  
- **math**: To convert floating-point values to integers  
- **unittest**: For testing the implementation  

---

## How to Use It

1. **Pull the `encoder.so` File**  
   Ensure you have the compiled `encoder.so` file from the project repository.

2. **Import the Library in Your Python Code**  
   Use `ctypes` to import the `encoder.so` file in your Python script.

3. **Prepare the DataFrame**  
   Ensure all floating-point values are split into two separate columns (e.g., integer and decimal parts).

4. **Encode the DataFrame**  
   Pass the required variables to the imported library to encrypt the dataframe.

5. **Example of Usage**  
   Refer to the `show.ipynb` file included in the project for a detailed example.
