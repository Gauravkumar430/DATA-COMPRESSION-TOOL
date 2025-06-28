# DATA-COMPRESSION-TOOL

COMPANY: CODTECH IT SOLUTIONS

NAME: GAURAV KUMAR

INTERN ID: CT04DF963

DOMAIN: C PROGRAMMING

DURATION: 4 WEEKS

MENTOR: NEELA SANTOSH

*DESCRIPTION*: Data compression plays a vital role in efficient data storage and transmission. It reduces the size of files, thereby optimizing disk usage and improving data transfer rates. One of the most basic and widely taught techniques in this domain is Run-Length Encoding (RLE). This algorithm is particularly effective when dealing with data containing many repeating characters, such as simple image files or certain types of plain text files.

The goal of this project is to implement a simple compression-decompression tool using RLE in the C programming language. The program is designed to read a text file, compress its content by applying RLE, and then save the compressed data to a new file. It can also reverse the process by decompressing a previously compressed file back to its original form.

🔧 Compression Logic:
The compression process begins by reading characters from the input file one at a time. If a character is repeated consecutively, the algorithm counts the number of repetitions and stores the count followed by the character. For instance, the string aaabbccccd would be compressed as 3a2b4c1d.

The compression function in the program does the following:

Opens the input and output files using fopen().

Reads the first character using fgetc().

Iterates through the rest of the file, comparing the current character with the previous one.

If they are the same, it increments a count.

If not, it writes the count and character to the output file and resets the counter.

Finally, it writes the last counted character and closes the files.

This process ensures that repeated characters are stored in a compact form, significantly reducing file size for suitable content.

 Decompression Logic:
The decompression process reverses the compression. It reads the encoded format—pairs of numbers and characters—from the compressed file. For each pair, the character is written to the output file as many times as indicated by the number.

The decompression function works as follows:

Opens the compressed file and the file where decompressed content will be stored.

Reads number-character pairs using fscanf().

Writes the character the specified number of times using a loop.

Closes both files.

This ensures that the original data is reconstructed exactly as it was before compression.

 Benefits and Use Cases:
This RLE-based compression tool is ideal for:

Text files with long sequences of repeated characters.

Simple image formats (like monochrome bitmaps).

Demonstrating the basic concept of data compression in academic environments.

However, it is worth noting that RLE is not efficient for files with high entropy (i.e., little to no repetition), such as encrypted files or already compressed files like .zip or .mp4.

 Limitations:
Not effective for all types of data.

May increase file size for data with no repetition.

Cannot handle numeric characters properly without advanced logic (e.g., distinguishing between count and actual character).

 Conclusion:
This simple tool demonstrates the power and simplicity of Run-Length Encoding for basic compression tasks. It teaches students how compression works at a low level and provides insight into the importance of data patterns in achieving better compression rates. For real-world applications, more advanced algorithms like Huffman Coding or LZW would be needed, but RLE remains an excellent starting point for learning data compression techniques.

*OUTPUT*: ![Image](https://github.com/user-attachments/assets/b494d1c4-4aad-4553-82b4-d09e376610d2)
