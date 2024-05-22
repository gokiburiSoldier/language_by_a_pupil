#include <string>
using namespace std;

namespace keywords {
    const int key_error_code= 0xe00;
    const int print_code    = 0xe01;
    const int var_code      = 0xe02;
    const int set_end_code  = 0xe03;
    const int set_step_code = 0xe04;
    const int if_code       = 0xe05;
    const int input_code    = 0xe06;
    const int loop_code     = 0xe07;
    const int clear_code    = 0xe08;
    const int exit_code     = 0xe09;
    int getKeywordCode(string keyword) {
        if(keyword == "print" || keyword == "out") return print_code;
        else if(keyword == "var") return var_code;
        else if(keyword == "set-end") return set_end_code;
        else if(keyword == "set-step") return set_step_code;
        else if(keyword == "input" || keyword == "in") return input_code;
        else if(keyword == "loop") return loop_code;
        else if(keyword == "clear" || keyword == "cls") return clear_code;
        else if(keyword == "exit" || keyword == "quit") return exit_code;
        else if(keyword == "if") return if_code;
        else return key_error_code;
    }
}