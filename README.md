# MULTITHREADED-FILE-COMPRESSION-TOOL-CODTECH_IT

*COMPANY *: CODTECH IT SOLUTIONS

NAME: DHATSHINI A

INTERN ID: CTIS2275

DOMAIN: C++ PROGRAMMING

DURATION: 4 WEEEKS

MENTOR: NEELA SANTHOSH

# DESCRIPTION
The Multithreaded File Compression Tool is a C++ console-based application designed to demonstrate efficient file processing using multithreading and Run-Length Encoding (RLE) compression techniques. The primary objective of this project is to improve file compression performance by dividing the workload across multiple threads while ensuring accurate compression and decompression of text data.

The program begins by reading the contents of an input text file (input.txt) using file input streams. It reads the entire file into a single string using stream buffer iterators, allowing the application to handle all characters—including spaces and newline characters—without data loss. This approach ensures that the original file structure is preserved during compression and decompression.

To leverage multithreading, the input data is split into two equal parts. Each part is processed independently by separate threads using the C++ <thread> library. This parallel execution reduces processing time for large files and demonstrates how multithreading can enhance performance in compute-intensive tasks. Each thread invokes a worker function that compresses its assigned data segment.

The compression logic is implemented using Run-Length Encoding (RLE), a simple yet effective lossless compression algorithm. The algorithm works by replacing consecutive repeating characters with a count followed by the character itself. For example, a sequence like aaa is compressed into 3a. The compressChunk() function iterates through each character in the string, counts repetitions, and constructs the compressed output accordingly.

Execution time is measured using the <chrono> library to evaluate the efficiency of multithreaded processing. The program records the start and end time surrounding the compression phase and calculates the total time taken. This performance measurement highlights the advantage of parallel execution compared to single-threaded processing.

Once compression is complete, the compressed outputs from both threads are merged and written into a file named compressed.txt. The program then proceeds to decompression to verify data integrity. During decompression, the program reads the compressed file character by character, identifies numeric counts, and reconstructs the original text by repeating characters based on the stored count values. The decompressed output is written to decompressed.txt, ensuring that the original data is fully restored.

To enhance usability, the program includes a file display function that outputs the contents of both the compressed and decompressed files to the console. This allows users to visually verify the correctness of the compression and decompression processes.

Overall, this project demonstrates key C++ concepts such as file handling, multithreading, string manipulation, performance measurement, and lossless data compression. It provides practical exposure to parallel programming and efficient data processing techniques, making it a strong example of real-world system-level programming in C++.
