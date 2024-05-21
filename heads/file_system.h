#include <fstream>
#include <vector>
using namespace std;

namespace fs {
    bool is_file(string address) {
        ifstream file(address);
        return file.is_open();
    }
    string read_file(string address) {
        string result,line;
        ifstream out_file(address);
        if(!out_file.is_open()) return "";
        while(getline(out_file,line)) result += line + "\n";
        out_file.close();
        return result;
    }
    vector<string> read_lines(string address) {
        vector<string> res;
        string line;
        ifstream out_file(address);
        if(!out_file.is_open()) return res;
        while(getline(out_file,line)) res.push_back(line + "\n");
        return res;
    }
    void write_file(string address,string text) {
        ofstream in_file(address);
        if(!in_file.is_open()) return;
        in_file << text;
    }
}