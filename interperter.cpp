#include <iostream>
#include <cstring> 


int isValid(char* program) {
    int counter = 0;
    for (int i = 0; i < strlen(program); i++) {
        if (program[i] == '[') counter++;
        else if (program[i] == ']') counter--;
        if (counter < 0) return false;
    }
    
    return counter == 0;
}
int main() {
    const int SIZE_OF_MEMORY = 30000;
    char* memo = new char[SIZE_OF_MEMORY];
    std::fill(memo, memo + SIZE_OF_MEMORY, 0);
    const int SIZE_OF_PROGRAM = 1000;
    std::cout << "Enter the program: " << std::endl;
    char* program = new char[30000];
    std::cin.getline(program, SIZE_OF_PROGRAM);
    
    std::cout << "Program: " << program << std::endl;
    char* data_pointer = memo;
    const char* program_pointer = program;


    while (program_pointer >= program && program_pointer < program + strlen(program) & isValid(program)) {
        switch (*program_pointer) {
            case '>':
                if (data_pointer < memo + SIZE_OF_MEMORY - 1) data_pointer++;
                else {
                    std::cerr << "Data pointer out of bounds!" << std::endl;
                    delete[] memo;
                    return -1;
                }
                program_pointer++;
                break;

            case '<':
                if (data_pointer > memo) data_pointer--;
                else {
                    std::cerr << "Data pointer out of bounds!" << std::endl;
                    delete[] memo;
                    return -1;
                }
                program_pointer++;
                break;

            case '+':
                (*data_pointer)++;
                program_pointer++;
                break;

            case '-':
                (*data_pointer)--;
                program_pointer++;
                break;

            case '.':
                std::cout << *data_pointer;
                program_pointer++;
                break;

            case ',':
                std::cin.get(*data_pointer);
                program_pointer++;
                break;

            case '[':
                if (*data_pointer == 0) {
                    int counter = 1;
                    while (counter > 0) {
                        program_pointer++;
                        if (*program_pointer == '[') counter++;
                        else if (*program_pointer == ']') counter--;
                    }
                } else {
                    program_pointer++;
                }
                break;

            case ']':
                if (*data_pointer != 0) {
                    int counter = 1;
                    while (counter > 0) {
                        program_pointer--;
                        if (*program_pointer == ']') counter++;
                        else if (*program_pointer == '[') counter--;
                    }
                } else {
                    program_pointer++;
                }
                break;

            default:
                program_pointer++;
        }
    }

    delete[] memo;
    return 0;
}
