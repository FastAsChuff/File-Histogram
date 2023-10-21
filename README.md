# File-Histogram
This program prints out the histogram of bytes in a file. 

Usage ./filehist.bin filename

E.g. Output: 

Histogram of file filename

Hex  | Frequency 
---- | -----------
0x00 | 321
0x01 | 123...

In particular, sorted or shuffled files should give the same histogram as the original assuming no extra data was added or lost in the process.

echo "Hello World" >file.txt

./filehist.bin file.txt >hist1.txt

echo "Wollle rodH" >file.txt

./filehist.bin file.txt >hist2.txt

sha256sum hist1.txt hist2.txt

Output:

15d1619f1b5d1fe58ed1640193bf72675b1b9e3541ae55bdc7c7556ae49c4f9e  hist1.txt
15d1619f1b5d1fe58ed1640193bf72675b1b9e3541ae55bdc7c7556ae49c4f9e  hist2.txt
