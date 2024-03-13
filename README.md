# my_ls

## Description
my_ls is a simple reproduction of the Unix command ls, implemented in C. It provides a basic functionality to list directory contents and file information.

## Installation
To use my_ls, follow these steps:

1. Clone the repository:
    ```
    git clone https://github.com/EnzoDubeaurepaire/my_ls.git
    ```
   
2. Navigate to the my_ls directory:
    ```
    cd my_ls
    ```

3. Build the project using make:
    ```
    make
    ```

## Usage
Once the project is built, you can use my_ls from the command line. Here are some common usage examples:

- List contents of the current directory:
    ```
    ./my_ls
    ```

- List contents of a specific directory:
    ```
    ./my_ls /path/to/directory
    ```

- List contents with detailed information:
    ```
    ./my_ls -l
    ```

- List contents including hidden files:
    ```
    ./my_ls -a
    ```

- Combine options:
    ```
    ./my_ls -la /path/to/directory
    ```
