#include <iostream>;



int main(){
    const int SIZE_OF_MEMORY = 30000;
    char* memo = new char[SIZE_OF_MEMORY];
    
    char* program = "<>+-";
    char* data_pointer = memo;
    char* program_pointer = program;
    
    while(program_pointer < memo + SIZE_OF_MEMORY - 1 && program_pointer >= program){
        switch(*program_pointer){
            case '>':
                data_pointer++;
                program_pointer++;
                break;

            case '<':
                data_pointer--;
                program_pointer++;
                break;

            case '+':
                *data_pointer++;
                program_pointer++;
                break;

            case '-':
                *data_pointer--;
                program_pointer++;
                break;

            case '.':
                std::cout<<*data_pointer;
                program_pointer++;
                break;

            case ',':
                char input;
                std::cin.get(input);
                *data_pointer = input;
                program_pointer++;
                break;

            case '[':
               if( *data_pointer == 0){
                    program_pointer++;
                    int counter = 1;
                    while(counter != 0){
                        if(*program_pointer != '[' && *program_pointer != ']'){
                            program_pointer++;
                        }
                        else if (*program_pointer == '[')
                        {
                            counter++;
                            program_pointer++;
                        }
                        else if (*program_pointer == ']')
                        {
                            counter--;
                            program_pointer++;
                        }
                        
                    }



               }
               break;
            case ']':
               if( *data_pointer == 0){
                    program_pointer--;
                    int counter = 1;
                    while(counter != 0){
                        if(*program_pointer != '[' && *program_pointer != ']'){
                            program_pointer--;
                        }
                        else if (*program_pointer == '[')
                        {
                            counter++;
                            program_pointer--;
                        }
                        else if (*program_pointer == ']')
                        {
                            counter--;
                            program_pointer--;
                        }
                        
                    }


               }
               break;

        }
        
    }
    delete[] memo;  
}






