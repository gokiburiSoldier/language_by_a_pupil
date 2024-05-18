#include <string>
#include "variables.h"
#include "used-head.h"
using namespace std;

int calc_bool(string sent) {
    vector<string> values;
    smatch vars;
    string op = sent;
    size_t pos;
    bool res;
    regex_search(sent,vars,var_pattern_1);
    for(auto i : vars) values.push_back(i);
    regex_search(sent,vars,var_pattern_2);
    for(auto i : vars) values.push_back(i);
    regex_search(sent,vars,var_pattern_3);
    for(auto i : vars) values.push_back(i);
    for(int i = 0; i < values.size(); i ++) {
        pos = sent.find(values[i]);
        op.replace(pos,values[i].length(),"");
    }
    if(op == "==") 
        res = global_variables[values[0]].getValue() == global_variables[values[1]].getValue();
    else if(op == "!=") 
        res = global_variables[values[0]].getValue() != global_variables[values[1]].getValue();
    else if(op == ">") 
        res = global_variables[values[0]].getValue() > global_variables[values[1]].getValue();
    else if(op == "<") 
        res = global_variables[values[0]].getValue() < global_variables[values[1]].getValue();
    else if(op == ">=") 
        res = global_variables[values[0]].getValue() >= global_variables[values[1]].getValue();
    else if(op == "<=") 
        res = global_variables[values[0]].getValue() <= global_variables[values[1]].getValue();
    if(res) return 1;
    else return 0;
}