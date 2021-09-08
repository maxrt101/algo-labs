# Lab 1
### Task:
Implement Quick Sort / Merge Sort / Heap Sort algoirithm. The application must
accept imput through command line arguments. The input is a 1d, comma separated
array of integers. The application must support choosing between ascending and
descending sorting orders.
The output of the application must be:
 - Algorithm name
 - Execution time (ms)
 - Comparisons count
 - Swaps count
 - Sorted array

Tests must be present fot such cases:
 - Input array sorting
 - Sorting by ASC order of an array, sorted by ASC
 - Sorting by DESC order of an array, sorted by ASC
 - Sorting by ASC order of an array, sorted by DESC
 - Sorting by DESC order of an array, sorted by DESC

When sorting sorted array, there should be no swaps.

### How to run:
Unix like OSs (Linux, MacOS):  
Dependencies: `make`, `gcc` or `clang`  
Run:  
 - Clone the repo
 - `cd algo_labs && git chekout lab1`
 - `make`
 - `./bin/sort`

Widows: unsupported  

Note: usage is writted to the terminal if you run `bin/sort`  

### Tests:
Dependencies: `python3`, `unittest` pip module
Run: `python3 -m unittest`

