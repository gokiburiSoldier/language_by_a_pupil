#include <iostream>
#include "variables.h"
#include <regex>
using namespace std;

regex equation(R"(.+(\s)?==(\s)?.+)");
regex not_qua(R"(.+(\s)?!=(\s)?.+)");
regex bigger(R"(.+(\s)?\>(\s)?.+)");
regex smaller(R"(.+(\s)?\<(\s)?.+)");
regex bigger_qua(R"(.+(\s)?\>=(\s)?.+)");
regex smaller_qua(R".+(\s)?\<=(\s)?.+");

bool calc_bool(string sent) {
    if(regex_match)
}