#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#define KEYWORD  0x1001
#define FUNCTION 0x1002
#define VARIABLE 0x1003

#define TYPE_INT      0x2001
#define TYPE_STRING   0x2002
#define TYPE_BOOL     0x2003
#define UNDEF         0x2004

#define FORMAT_ERROR        0x3001
#define NO_FUNC_FOUND_ERROR 0x3002
#define SYNTAX_ERROR        0x3003
#define NAME_ERROR          0x3004

#define SPLIT ','