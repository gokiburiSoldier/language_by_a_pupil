#include <string>
#include "variables.h"
#include "used-head.h"
using namespace std;

int calc_bool(vector<string> sent) {
    string v1,v2;
    if(is_string(sent[0])) v1 = sent[0].substr(1,sent[0].size()-2);
    else if(is_num(sent[0]) || sent[0] == "true" || sent[0] == "false") v1 = sent[0];
    else if(is_variable(sent[0])) v1 = global_variables[sent[0]].getValue();
    else return UNDEF;
    if(is_string(sent[2])) v2 = sent[2].substr(1,sent[2].size()-2);
    else if(is_num(sent[2]) || sent[2] == "true" || sent[2] == "false") v2 = sent[2];
    else if(is_variable(sent[2])) v2 = global_variables[sent[2]].getValue();
    else return UNDEF;
    if(sent[1] == "==") return (v1 == v2);
    else if(sent[1] == "!=") return (v1 != v2);
    else {
        if(is_num(v1) && is_num(v2)) {
            if(sent[1] == ">") return (stoi(v1) > stoi(v2));
            else if(sent[1] == ">=") return (stoi(v1) >= stoi(v2));
            else if(sent[1] == "<") return (stoi(v1) < stoi(v2));
            else if(sent[1] == "<=") return (stoi(v1) <= stoi(v2));
        }
        else return UNDEF;
    }
}