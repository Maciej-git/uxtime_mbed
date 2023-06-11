# uxtime_mbed - Unix timestamp to date conversion
### **Video Demo: https://youtu.be/xsXo0zG3gag**
### **Description:**

Project core functionality is to perform conversion between Unix timestamp and human-readable date form. 
Module is created with Arm Keil Studio Cloud to implement with NUCLEO F401RE (ARM Cortex M4) as a hardware platform. Project contains test written to use with Pytest framework to perform test of C source functions. Additionally, test run of project functionality were performed with Arm Mbed Simulator (video capture of simulation can be found here: https://youtu.be/xsXo0zG3gag).

### **Description of project files:**

### **BUILD folder**

Contains mbed_config.h file created to implement project with NUCLEO F401RE

#### **uxtime.c**

Source file, contains following functions:

#### char *uxtime2date(time_t uxtime)

Convert Unix timestamp to human-readable string date.

#### int uxtime2day(time_t uxtime)

Get the day name of the week from Unix timestamp.

#### time_t date_t2uxtime(struct date_t t)

Get Unix timestamp of date passed by date_t struct

##### float count_days(time_t t1, time_t t2)

Calculate days between two Unix timestamps

### **test folder**

uxtime_c.so: 

Complied library with C functions from uxtime.c 

test_uxtime.py:

Tests to run with Pytest framework   

Note: Test of date_t2uxtime fuction is not reliable due to ctypes time_t issue and need to be fix!

### **main.cpp**

Functions implementation to use with NUCLEO F401RE, mbed API
