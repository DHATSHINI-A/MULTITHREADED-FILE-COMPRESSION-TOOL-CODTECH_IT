#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <cctype>
using namespace std;

/* Function to compress a string using Run-Length Encoding */
string compressChunk(const string& data) {
    string result = "";
    int count = 1;

    for (size_t i = 1; i <= data.length(); i++) {
        if (i < data.length() && data[i] == data[i - 1]) {
            count++;
        } else {
            result += to_string(count) + data[i - 1];
            count = 1;
        }
    }
    return result;
}

/* Thread worker */
void compressWorker(const string& input, string& output) {
    output = compressChunk(input);
}

/* Function to display file contents */
void displayFile(const string& filename) {
    ifstream file(filename);
    string line;

    cout << "\n--- " << filename << " CONTENT ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {

    /* Step 1: Read input file */
    ifstream inFile("input.txt");
    if (!inFile) {
        cout << "input.txt not found. Please add the file.\n";
        return 0;
    }

    string data((istreambuf_iterator<char>(inFile)),
                 istreambuf_iterator<char>());
    inFile.close();

    /* Step 2: Split data for multithreading */
    int mid = data.size() / 2;
    string part1 = data.substr(0, mid);
    string part2 = data.substr(mid);

    string compressed1, compressed2;

    /* Step 3: Start timing */
    auto start = chrono::high_resolution_clock::now();

    /* Step 4: Multithreaded compression */
    thread t1(compressWorker, ref(part1), ref(compressed1));
    thread t2(compressWorker, ref(part2), ref(compressed2));

    t1.join();
    t2.join();

    auto end = chrono::high_resolution_clock::now();

    /* Step 5: Write compressed file */
    ofstream compFile("compressed.txt");
    compFile << compressed1 << compressed2;
    compFile.close();

    /* Step 6: Decompression (FULL file, spaces & newlines preserved) */
    ifstream readComp("compressed.txt");
    ofstream decompFile("decompressed.txt");

    string compData((istreambuf_iterator<char>(readComp)),
                     istreambuf_iterator<char>());

    for (size_t i = 0; i < compData.length(); i++) {
        if (isdigit(compData[i])) {
            int count = compData[i] - '0';
            char ch = compData[++i];
            decompFile << string(count, ch);
        }
    }

    readComp.close();
    decompFile.close();

    /* Step 7: Display results */
    chrono::duration<double> duration = end - start;

    cout << "Multithreaded Compression & Decompression Completed\n";
    cout << "Time Taken: " << duration.count() << " seconds\n";

    displayFile("compressed.txt");
    displayFile("decompressed.txt");

    return 0;
}
