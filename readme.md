# Sudoku Solver

> C++ program to solve sudoku using backtracking.

The program takes a Sudoku problem as input. For blanks 0 is provided as input.

|   |   | 9 |   | 4 |   | 7 |   |   |
|---|---|---|---|---|---|---|---|---|
| 1 |   |   | 6 | 8 |   |   |   |   |
|   | 4 |   | 2 |   |   | 6 |   | 1 |
| 9 |   |   |   |   |   |   |   | 8 |
|   | 8 |   |   |   |   |   | 6 |   |
| 6 |   |   |   |   |   |   |   | 7 |
| 4 |   | 3 |   |   | 5 |   | 9 |   |
|   |   |   |   |   | 3 | 1 |   | 6 |
|   |   | 6 |   | 7 |   | 5 |   |   |

A sample sudoku like above is inputted as.

0 0 9 0 4 0 7 0 0  
1 0 0 6 8 0 0 0 0  
0 4 0 2 0 0 6 0 1  
9 0 0 0 0 0 0 0 8  
0 8 0 0 0 0 0 6 0  
6 0 0 0 0 0 0 0 7  
4 0 3 0 0 5 0 9 0  
0 0 0 0 3 1 0 0 6  
0 0 6 0 7 0 5 0 0  

> 0 to represent blanks.

The program first displays the input and then the output as follows.
<pre>
2 1 9  3 4 6  7 8 5 
1 3 4  6 8 7  2 5 9 
3 4 5  2 9 8  6 7 1 

9 2 7  5 6 3  1 4 8 
7 8 2  1 5 9  3 6 4 
6 5 1  8 2 4  9 3 7 

4 6 3  7 1 5  8 9 2 
5 7 8  9 3 1  4 2 6 
8 9 6  4 7 2  5 1 3 
</pre>