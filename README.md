# WordCount Project

A C-based application designed for counting words in text files. The project showcases the use of process management and inter-process communication in C. It includes two main components: a program for counting words in a single file (`wordcount.c`) and another for counting words across multiple files concurrently (`multiple_wordcount.c`).

## Features

- **Single File Word Count**: Counts the number of words in a single text file.
- **Multiple File Word Count**: Utilizes multiple processes to count words in several files simultaneously, demonstrating basic process creation and management in C.

## Getting Started

### Prerequisites

Ensure you have a C compiler installed, such as `gcc`, and `make` for running the Makefile.

### Compiling

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Run `make` to compile the project. This will generate executable files for both components.

### Usage

- **Single File Word Count**:
./wordcount <filename>

Replace `<filename>` with the path to your text file.

- **Multiple File Word Count**:

Replace `<filename1> <filename2> ...` with the paths to the text files you want to process.

## Output

The programs will output the number of words counted in each file. For the multiple file version, it also reports the number of successfully processed files and any failures.

## Contribution

This project was developed in collaboration with two other individuals, focusing on the implementation of the Makefile and ensuring seamless functionality across different parts of the project.

## Challenges

The primary challenge faced during development was integrating the Makefile with the code and overcoming communication errors when working with mobaxterm.

## License

This project is open source and available for educational and learning purposes.

