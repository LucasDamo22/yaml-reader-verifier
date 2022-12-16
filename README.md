This program is tester program for the yaml-reader program. It was built to test the reliability of that code;
This project generates a series of yaml files with targeted cpu usages, defined by the user to test the yaml reader;

To compile the program, type "make" in the root directory.

After compiling, you can execute the program passing the arguments through the command line with "./bin/main ?xx ?zz". The first argument(?xx) should be the smaller targeted usage of cpu, the second argument(?zz) the greater.

To generate documentation, make sure you have installed the Doxygen in your system, then type "make docs" in the root folder



Built on Ubuntu 22.04.1 LTS

requirements for running the program:

GCC 11;
Make;

