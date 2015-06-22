# merge-bubble-sort-compare
An appilcation that compares the performance of merge sort and bubble sort directly, by running them in parallel. An example for the appilcation of the algo-compare-framework.

##Librarys
merge-bubble-sort-compare uses <a href='https://github.com/DevWurm/algo-compare-framework'>algo-compare-framework</a>. You can find the current version of algo-compare-framework on <a href='https://github.com/DevWurm/algo-compare-framework'>GutHub</a><br>
It also uses <a href='https://github.com/DevWurm/csv-library'>csv-library</a> and <a href='https://github.com/DevWurm/error-library'>error-library</a>.

## Repository structure
 + headers: headers, of the program itself
 + sources: implementations of the program itself (also header files, because the software is based on templates)
 + libcompare: library files of the algo-compare-framework
 + libcsv: library files of the csv-library
 + liberror: library files of the error-library
 + license: license information
 + compare.cpp: main program

## Building the program
For building the software you can use the `make` command on linux. (On windows try to install mingw and use `mingw32_make`)<br>
For building a release version just change into the project directory and use

    make

or

    make release
The program will be build into the top directory of the project as `./compare`.

<br>For building a debug version, use

    make debug

The program will be build into the top directory of the project as `./compare_debug`.

## Running the program
Call the built executable file with `./compare` and the needed commandline arguments:
+ -t [data type] / --type [data type]: data type of the data that need to be sorted (short/int, long, float)

+ -d / --display: Show the beginning and ending of the two sorting processes, the length of the list and the process times in the command line (recomended)

+ -O [file path] / --output-information [file path]: Write the process parameters (list length, duration of both algorithms) into a CSV File

+ -i [file path] / --input [file path]: Use a CSV File as input (each line will be sorted). Dont use with the -r argument.

+ -o [file path] / --output [file path]: Write the sorted lists into a CSV File

+ -r [length] [min] [max] / --random [length] [min] [max]: Randomly generate the input list with a specified length (as int / long int) in a specified range (as the given type). Recomended for demonstrations. Dont use with the -i argument.

##Documentation
There is no documentation yet. (Email me if you have any questions)

##License
Copyright 2015 DevWurm<br>
'merge-bubble-sort-compare' is offered under GPL 3 License (Read ./license/gpl-3.0.txt)

##Authors
DevWurm<br>
Email: <a href='mailto:devwurm@gmx.net'>devwurm@gmx.net</a><br>
Feel free to contact me, if you have any questions or ideas about the project :)

##Collaborating
You can use the GitHub issue tracker for bugs and feature requests or create a pull request to submit
changes and forks are welcome, too.
If you don't want to use these possibilities, you can also write me an email at
<a href='mailto:devwurm@gmx.net'>devwurm@gmx.net</a>.
