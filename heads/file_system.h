#include <fstream>
using namespace std;

namespace fs {
    /* ifstream in_file; */
    string read_file(string address) {
        string result,line;
        ifstream out_file(address);
        if(!out_file.is_open()) return "";
        while(getline(out_file,line)) result += line + "\n";
        out_file.close();
        return result;
    }
}