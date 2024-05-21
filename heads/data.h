/* 变量声明 初始化 */
#include "used-head.h"
#include <regex>
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
string pre_value;
char buffer[114514];

bool in_string = false;
bool need_add = true;
char sign;
char every_char;

map<int,string> errors;

regex blank_sent(R"([\s]*)");

void raise_error(int error,string reason);

bool is_string(string s);

vector<string> tokens(string sent);

int analysis_sent(vector<string> line);

void run(string code,int place,bool new_line);