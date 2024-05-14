/* 变量声明 初始化 */
#include "used-head.h"
#include <map>

const int max_len = 0xff;

vector<string> keyword_law;
vector<string> funct_law;
vector<string> line_tokens;

int pointer;
int line_num = 0;

string every_line;
string one_token;
string step = "";
string ending = "\n";

bool in_string = false;
char sign;
char every_char;

map<int,string> errors;