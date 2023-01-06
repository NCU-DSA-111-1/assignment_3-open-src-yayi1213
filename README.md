### This is assignment 4

# ARITHMETIC

## for arithmetic
* go to the path:   cd Arithmetic-main
* compile:   g++ -o Arithmetic-main main.cpp Arithmetic.cpp
## encode and decode for arithmetic
* ./Arithmetic-main
## Result for Test1
壓縮總bit數48</br>
其中為0的數為27</br>
其中為1的數為21

bit0出現的機率  0.5625000000
bit1出現的機率  0.4375000000

time cost of arithmeric encoding :0.0030150000/s</br>
time cost of arithmeric decoding :0.0000750000/s
</br>

## Result for Test2
壓縮總bit數3312</br>
其中為0的數為1802</br>
其中為1的數為1510

bit0出現的機率  0.5440821256

bit1出現的機率  0.4559178744

time cost of arithmeric encoding :0.0024240000/s</br>
time cost of arithmeric decoding :0.0000840000/s</br>
# HUFFMAN

## for huffman

* go to the path:   cd Huffman-main
* compile:   gcc -o huffman huffcode.c huffman.c huffman.h 
## encode and decode for huffman
* ./huffman -i test1 -o encodingtext -c

* ./huffman -i encodingtext -o decodingtext -d
## Result for Test1 
time cost of huffman coding: 0.001279 /s.
time cost of huffman coding: 0.000558 /s.

## Result for Test2
time cost of huffman coding: 0.001030 /s.
time cost of huffman coding: 0.000396 /s.