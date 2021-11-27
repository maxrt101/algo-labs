# Lab 6

## Task:
In search of the Holy Grail, Indiana Jones faced a dangerous ordeal.  
He needs to go through a rectangular corridor, which consists of fragile slabs  
(recall a scene from the movie "Indiana Jones and the Last Crusade"). On each  
one letter is written on the plate:  
```
 a a a 
 c a b
 d e f
```  
You can start with any plate in the leftmost column. There is an exit from the corridor  
upper right and lower right of the plate (for example above - a and f).  
Indiana is agile, and can not only go to the next plate, but also jump through  
several plates. However, in order not to fall through the floor, he must adhere  
such rules:  
 1. After each step, Indiana must be more right than he was before.
 2. You can always switch to one plate on the right.
 3. In addition to moving one plate to the right, you can jump, but only on that the letter itself. For example, you can jump from the letter a to any other the letter a, provided that we move to the right in this course.

For a given corridor, calculate how many ways there are to pass it successfully.  

### Input data:
The input file ijones .in consists of H + 1 lines.
 - The first line contains two numbers W and H, separated by a space: W - width of the corridor, H - height of the corridor, 1 <= W, H <= 2000.
 - Each of the next H lines contains a word of character length W, which is composed from lowercase Latin letters from a to z.

### Output data:
The source file ijones .out must contain one integer - the number of different ways out of the corridor.

## CLI Options:
 - `-h`, `--help` - Show help message
 - `-t`, `--test` - Runs tests
 - `-i`, `--infile` - Specifies input file (default: `ijones.in`)
 - `-o`, `--outfile` - Specifies output file (default: `ijones.out`)

## How to run:
Unix like OSs (Linux, MacOS):  
Dependencies: `make`, `gcc` or `clang`  
Run:  
 - Clone the repo  
 - `cd algo_labs && git checkout lab6 && git submodule update --init`  
 - `make`  
 - `./build/bin/ijones`  

Windows: unsupported
