This project contains two programs. A cpu usage calculator for real-time systems, and a tester for this program.

For this project, it was needed the usage of a third-party library, for parsing YAML files, already included on the project, as a single header file.

How to use:
In the root folder of the project, type "make". It will compile both programs at the same time.

To use the Random Tasks Generator, in the root folder of the project, type "./Random-tasks-generator/bin/tasksGenerator ?xx ?zz". The first argument(?xx) should be the smaller targeted usage of cpu, the second argument(?zz) the greater.

To use the Cpu usage Calculator, in the root folder of the project, type "./Cpu-usage-calculator/bin/cpuUsage". No arguments required, the program will search on the "./Cpu-usage-calculator/data" folder for ALL of the "*.yaml" files, and calculate, for each file, a 2 CPU usage. It will balance the usage between cpu1 and cpu2, and inform the total usage of both cpus.

Beware that all files that terminate on ".yaml" will be acessed by the program , and if hey do not follow the pattern shown in the example.yaml on the root folder, the program will not work correctly.

Make commands available for use in the root folder:
make -> it will compile both programs.
make clean -> it will remove all the executable files generated by the compilator.

make docs -> generates de "./docs/doxygen/html" folder, containing the documentation of the project. To acess it, open the "index.html" file.

make cleanDocs -> remove all of the files generated by the documentation.

make cleanDataFiles -> Remove ALL of the "*.yaml" files in the "./Cpu-usage-calculator/data" folder.



Built on Ubuntu 22.04.1 LTS

requirements for running the program:

GCC 11;
Make;

