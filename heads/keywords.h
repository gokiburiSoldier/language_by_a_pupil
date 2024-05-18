#include <string>
using namespace std;

namespace keywords {
    const int key_error_code    = 0xe00;
    const int print_code    = 0xe01;
    const int var_code      = 0xe02;
    const int set_end_code  = 0xe03;
    const int set_step_code = 0xe04;
    const int if_code       = 0xe05;
    const int input_code    = 0xe06;
    int getKeywordCode(string keyword) {
        if(keyword == "print" || keyword == "out") return print_code;
        else if(keyword == "var") return var_code;
        else if(keyword == "set-end") return set_end_code;
        else if(keyword == "set-step") return set_step_code;
        else if(keyword == "input" || keyword == "in") return input_code;
        else return key_error_code;
    }
}