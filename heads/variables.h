#include "used-head.h"
#include <map>
#include <regex>
#include <typeinfo>

regex keyword_pattern(R"(.* [\s\S]*)");
regex func_pattern(R"(\w+\((\w*\)))");
regex int_pattern(R"(^[0-9]*$)");
regex string_pattern1(R"(\"[\s\S]*\")");
regex string_pattern2(R"('[\s\S]*')");

regex var_pattern_1(R"([^\d\W][\w\D]*)");
regex var_pattern_2(R"(@[^\d\W][\w\D]*)");
regex var_pattern_3(R"(@\(.+\))");

/* 变量的基本结构 */

class Variable {
    public:
        int type = UNDEF;
        string name;
        string value;
    public:
        Variable() {}
        Variable(int type,string name) {
            this->type = type;
            this->name = name;
        }
        ~Variable() {}
        void setValue(string v) {
            this->value = v;
        }
        
        void getValue(void) {
            /* string bool_true = "true"; */
            if(this->type == TYPE_INT)         cout << stoi(value);
            else if(this->type == TYPE_STRING) cout << value.substr(1,value.size()-2);
            else if(this->type == UNDEF)       cout << UNDEF;
            else if(this->type == TYPE_BOOL)   cout << (value == "true");
        }
        int getType(void) {
            return this->type;
        }
};

/* 变量 */

map<string,Variable> global_variables;

/* 函数 */
void new_variable(string name,bool isUNDEF=true,string value="") {
    int type;
    if(isUNDEF) type = UNDEF;
    else if(regex_match(value,string_pattern1) || regex_match(value,string_pattern2)) type = TYPE_STRING;
    else if(value == "true" || value == "false") type = TYPE_BOOL;
    else if(regex_match(value,int_pattern)) type = TYPE_INT;
    Variable v(type,name);
    if(type != UNDEF) v.setValue(value);
    global_variables[name] = v;
}