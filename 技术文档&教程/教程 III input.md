# 教程 III input.md

### 关键字一览
关键字| 描述
-| -
input| 获取用户输入

### 语法
`input `&nbsp;*变量名*&nbsp;*[`,提示语`]

#### 注意点
标`*`为可选参数

### 对比

```
var a;
input a;
print "Fuck ",a;
```

C++:
```c++
#include <iostream>
using namespace std;

int main(void) {
    string a;
    cin >> a;
    cout << "Fuck " << a << endl;
}
```

C Language:
```c
#include <stdio.h>

int main(void) {
    char a[114514];
    scanf("%s",&a);
    printf("Fuck %s\n",a);
}
```

JS:
无

PHP:
无

Scratch:
无

Python:
```python
a = input()
print(f"Fuck {a}")
```