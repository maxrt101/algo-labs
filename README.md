# Lab 3 (Discount)
## Task:  
The fashion store has started a seasonal sale, and offers customers a discount for every 3rd purchased product. You have chosen the goods you want to buy and want take advantage of this offer to save as much money as possible.  

Of course, the amount you have to pay depends on how much order you will buy the goods. Knowing the price of each product, as well as the percentage discounts, calculate the most advantageous amount for which you can buy all the goods.  

### Input data:  
The input file `discnt.in` consists of two lines.  
 - The first line contains a list of integers from 0 to 1,000,000,000 (10^9) inclusive, separated by a space - the prices of individual products that you want to buy. General number of goods - from 1 to 10000.  
 - The second line contains discount - an integer from 0 to 100 inclusive, which means percentage discount for every third product.  

### Output data:  
The output `discnt.out` file must contain one number - the minimum amount that you need to spend to buy all the goods. The number must always have two fractional signs, and rounded to the second sign after the dot.  

## How to run:  
Unix like OSs (Linux, MacOS):  
Dependencies: `make`, `gcc` or `clang`  
Run:  
 - Clone the repo  
 - `cd algo_labs && git chekout lab3 && git submodule update --init`  
 - `make`  
 - `./build/bin/discount`
 - Run `./build/bin/discount -h` to get help

Widows: unsupported  

## Tests:
To Run:
 - Do first 3 steps of 'How To Run' section
 - `make test`

