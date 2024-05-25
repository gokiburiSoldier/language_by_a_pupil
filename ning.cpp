/* 简要说明
 * 项目类型:  编程语言
 * 项目名称: NM-Language (柠檬语言)
 * 项目开发者: 张**
 * 附件: CNM,NMSL(包管理工具,脚本管理工具)
*/
#include "heads/data.h"
#include "heads/keywords.h"
#include "heads/colors.h"
#include "heads/bool_sent.h"
#include "heads/file_system.h"
using namespace keywords;

/* 函数 */

/* -报错 */
void raise_error(int error,string reason) {
    cout << RED;
    cout << "Error: " << errors[error] << " (Code: 0x"  << hex << error << "):" << endl;
    cout << "\t" << reason << endl;
    cout << "\t\tline: " << line_num << endl;
    cout << RESET_COLOR;
    exit(0);
}

/* -统计字符个数 */
int count_char(string str,char chr) {
    int ctr = 0;
    for(char c : str) if(c == chr) ctr ++;
    return ctr;
}

/* -输出 */
void print(vector<string> ary,string sep="",string end="\n") {
    for(string element : ary) {
        if(regex_match(element,blanks) || element == ",") continue;
        else if(is_string(element)) element = element.substr(1,element.size()-2);
        else if(regex_match(element,int_pattern) || element == "true" || element == "false");
        else {
            if(is_variable(element)) 
                element = global_variables[element].getValue();
            else 
                raise_error(NAME_ERROR,"未找到合适变量");
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
            if(!need_add) {
                need_add = true;
                continue;
            }
            if(every_char == sign) {
                one_token += every_char;
                line_tokens.push_back(one_token);
                one_token = "";
                in_string = false;
                continue;
            } else if(every_char == '\\') {
                if(sent[pointer + 1] == 'n') one_token += "\n";
                need_add = false;
                continue;
            } else {
                one_token += every_char;
                continue;
            }
        }
        switch(every_char) {
            case ' ':
                if(one_token != "") line_tokens.push_back(one_token);
                one_token = "";
                break;
            case '\'':
                sign = every_char;
                one_token += every_char;
                in_string = true;
                break;
            case '"':
                sign = every_char;
                one_token += every_char;
                in_string = true;
                break;
            case SPLIT:
                if(one_token != "") line_tokens.push_back(one_token);
                line_tokens.push_back(",");
                one_token = "";
                break;
            case ';':
                if(one_token != "") line_tokens.push_back(one_token);
                line_tokens.push_back(";");
                one_token = "";
                break;
            case '(':
                if(one_token != "") line_tokens.push_back(one_token);
                line_tokens.push_back("(");
                one_token = "";
                break;
            case ')':
                if(one_token != "") line_tokens.push_back(one_token);
                line_tokens.push_back(")");
                one_token = "";
                break;
            case '{':
                if(one_token != "") line_tokens.push_back(one_token);
                line_tokens.push_back("{");
                one_token = "";
                break;
            case '}':
                if(one_token != "") line_tokens.push_back(one_token);
                line_tokens.push_back("}");
                one_token = "";
                break;
            default:
                one_token += every_char;
                break;
        }
    }
    if(one_token != "") line_tokens.push_back(one_token);
    return line_tokens;
}

/* -分析语句 */
int analysis_sent(vector<string> line) {
    string keyword = line.at(0);
    int num;
    int time;
    string codes,else_codes;
    bool add_codes,add_if;
    vector<string> to_true;
    switch(getKeywordCode(keyword)) {
        case exit_code:
            exit(0);
            break;
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
            if((line.size()) < 4) new_variable(line[1],false,"''");
            else 
                new_variable(line[1],false,line[3]);
            break;
        case input_code:
            if(count(variable_names.begin(),variable_names.end(),line[1]) > 0) {
                if(line.size() >= 3) {
                    if(line[2] != ",") cout << line[2].substr(1,line[2].size()-2);
                    else               cout << line[3].substr(1,line[3].size()-2);
                }
                cin.getline(buffer,114514);
                pre_value = buffer;
                global_variables[line[1]].setValue("\""+pre_value+"\"");
            } else 
                raise_error(NAME_ERROR,"未找到合适变量");
            break;
        case loop_code:
            if(regex_match(line[1],int_pattern))
                num = stoi(line[1]);
            else if(is_variable(line[1]))
                try {
                    num = stoi(global_variables[line[1]].getValue());
                } catch(...) {
                    raise_error(FORMAT_ERROR,"变量数据非法");
                }
            else
                raise_error(FORMAT_ERROR,"填入数据非整数 或 无合适变量");
            add_codes = false;
            for(string i : line) {
                if(i == "}") break;
                else if(add_codes) codes += i + " ";
                else if(i == "{") if(!add_codes) add_codes = true;
            }
            for(time = 0; time < num; time ++) run(codes,2,false);
            break;
        case if_code:
            add_codes = false;
            add_if = false;
            for(string i : line) {
                if(add_if) to_true.push_back(i);
                if(add_codes && i != "}") codes += i + " ";
                if(i == "}") break;
                else if(i == "{") {add_if = false;if(!add_codes) add_codes = true;}
                else if(i == "if") if(!add_if) add_if = true;
            }
            num = calc_bool(to_true);
            if(num == UNDEF) raise_error(FORMAT_ERROR,"我不知道");
            else if(!num);
            else run(codes,2,false);
            break;
        case clear_code:
            system("cls");
            break;
        case key_error_code:
            raise_error(NO_FUNC_FOUND_ERROR,"关键字["+keyword+"]不存在");
            break;
    }
    return 0;
}

/* -运行 */
void run(string code,int place,bool new_line = true) {
    if(regex_match(code,blank_sent)) return ;
    if(code[code.size() - place] == ';') code = code.substr(0,code.size() - place);
    if(new_line) line_num ++;
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
    errors[FILE_ERROR]          = "File Error";

    if(argc == 1) {
        run("var a = 'Hello World';",1);
        run("print a,' 你好!';",1);
    }  else {
        string address = argv[1];
        if(address == "-v") {
            cout << "测试版 1.0.0.0" << endl;
            exit(0);
        } if(fs::is_file(address)) {
            if(regex_match(address,ning_script)) {
                vector<string> document = fs::read_lines(address);
                string code;
                for(string i : document) {
                    code += i.substr(0,i.size()-1);
                    if(count_char(code,'{') <= count_char(code,'}')) {
                        run(code,1);
                        code = "";
                    }else line_num ++;
                }
            }
            else
                raise_error(FILE_ERROR,"不是N.M.源代码");
        } else
            raise_error(FILE_ERROR,"没有找到文件");
    }
    return 0;
}