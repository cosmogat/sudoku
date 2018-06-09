# sudoku
Sudoku solver in C++
# How to install
You can compile this code using the make command:
```
make
```
and you obtain an executable file called *sudoku*.
# Resolve sudoku
This program need special input. You can write the numbers of one sudoku in one line in a txt file changing the empty spaces by zeros like this:
```
007000300000638000900000004080506090060040050050301040600000002000973000005000900
```
If this line of numbers is in a file called "sud.txt" you can solve it with:
```
./sudoku sud.txt
```
and you obtain this output:
```
+-----------------------+
| 8 1 7 | 4 9 5 | 3 2 6 | 
| 5 4 2 | 6 3 8 | 7 1 9 | 
| 9 3 6 | 2 1 7 | 5 8 4 | 
+-----------------------+
| 7 8 4 | 5 2 6 | 1 9 3 | 
| 3 6 1 | 7 4 9 | 2 5 8 | 
| 2 5 9 | 3 8 1 | 6 4 7 | 
+-----------------------+
| 6 9 3 | 1 5 4 | 8 7 2 | 
| 1 2 8 | 9 7 3 | 4 6 5 | 
| 4 7 5 | 8 6 2 | 9 3 1 | 
+-----------------------+
```
# Examples
In the "sud" folder you have sudoku files to test this program and in the "res" folder you have the solutions of this sudoku files.
You can run all the test with the "test.sh" script.
