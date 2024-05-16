/* 简要说明
 * 项目类型:  编程语言
 * 项目名称: NM-Language (柠檬语言)
 * 项目开发者: 张**
 * 附件: CNM,NMSL(包管理工具,脚本管理工具)
*/
#include "heads/data.h"
#include "heads/variables.h"
#include "heads/keywords.h"
#include "heads/colors.h"
using namespace keywords;

/* 函数 */

/* -报错 */
void raise_error(int error,string reason) {
    cout << RED;
    cout << "Error: " << errors[error] << " (Code: 0x"  << hex << error << "):" << endl;
    cout << "\t" << reason << endl;
    cout << "\tline: " << line_num << endl;
    cout << RESET_COLOR;
    exit(0);
}

/* -是否是字符串 */
bool is_string(string s) {
    bool res = regex_match(s,string_pattern1) || regex_match(s,string_pattern2);
    return res;
}

/* -输出 */
void print(vector<string> ary,string sep="",string end="\n") {
    for(string element : ary) {
        if(element == " " || element == ",") continue;
        else if(is_string(element)) element = element.substr(1,element.size()-2);
        else if(regex_match(element,int_pattern) || element == "true" || element == "false");
        else {
            if(count(variable_names.begin(),variable_names.end(),element) > 0) {
                element = global_variables[element].getValue();
            } else {
                raise_error(NAME_ERROR,"未找到合适变量");
            }
        }
        cout << element << sep;
    }
    cout << end;
}

/* -获取单元 */
vector<string> tokens(string sent) {
    /* 清空单元 */
    line_tokens.clear();
    one_token = "";
    /* 开始获取单元 */
    for(pointer = 0; pointer < sent.size(); pointer ++) {
        every_char = sent.at(pointer);
        if(in_string) {
            one_token += every_char;
            if(every_char == sign) {
                line_tokens.push_back(one_token);
                one_token = "";
                in_string = false;
                continue;
            }
            else continue;
        }
        if(every_char == ' ') {
            if(one_token != "") line_tokens.push_back(one_token);
            one_token = "";
        } else if(every_char == '\'' || every_char == '"') {
            sign = every_char;
            one_token += every_char;
            in_string = true;
        } else if(every_char == SPLIT) {
            if(one_token != "") line_tokens.push_back(one_token);
            line_tokens.push_back(",");
            one_token = "";
        } else if(every_char == ';') {
            if(one_token != "") line_tokens.push_back(one_token);
            line_tokens.push_back(";");
            one_token = "";
        } else one_token += every_char;
    }
    if(one_token != "") line_tokens.push_back(one_token);
    return line_tokens;
}

/* -分析语句 */
int analysis_sent(vector<string> line) {
    string keyword = line.at(0);
    switch(getKeywordCode(keyword)) {
        case print_code: 
            line.erase(line.begin());
            print(line,step,ending);
            break;
        case set_step_code: 
            if(is_string(line[1])) step = line[1].substr(1,line[1].size()-2);
            else raise_error(FORMAT_ERROR,"[set-step]必须设置为字符串");
            break;
        case set_end_code:
            if(is_string(line[1])) ending = line[1].substr(1,line[1].size()-2);
            else raise_error(FORMAT_ERROR,"[set-end]必须设置为字符串");
            break;
        case var_code:
            //cout << (line.size() < 4) << endl;
            if((line.size()) < 4) new_variable(line[1]);
            else 
                new_variable(line[1],false,line[3]);
            break;
        case key_error_code:
            raise_error(NO_FUNC_FOUND_ERROR,"关键字["+keyword+"]不存在");
    }
    return 0;
}

/* -运行 */
void run(string code) {
    if(code[code.size() - 1] == ';') code = code.substr(0,code.size() - 1);
    line_num ++;
    if(regex_match(code,keyword_pattern)) analysis_sent(tokens(code));
    else raise_error(SYNTAX_ERROR,"无法知道语句意思");
}

/* -主函数 */
int main(int argc,char* argv[]) {
    system("chcp 65001 >nul");
    errors[FORMAT_ERROR]        = "Format Error";
    errors[NO_FUNC_FOUND_ERROR] = "Found No Such Function or Keyword";
    errors[SYNTAX_ERROR]        = "Wrong Sentence";
    errors[NAME_ERROR]          = "No Such Variale";

    if(argc == 1) {
        run("var a = 'Hello World';");
        run("print a,' 你好!';");
    }
    else {
        for(int i = 1;i < argc;i++) run(argv[i]);
    }
    return 0;
}