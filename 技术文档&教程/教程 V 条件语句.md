# 教程 V 条件语句

## 单词
if <sup>conj.</sup> 如果

## 关键字/符号一览
关键字/符号 | 描述
-| -
if| 判断条件并且执行语句
a == b| a,b是否 __相等__
a != b| a,b是否 __不等__
a > b| a是否 __大于__ b
a >= b| a是否 __大于等于__ b
a < b| a是否 __小于__ b
a <= b| a是否 __小于等于__ b

## 语法
`if ` *`条件`* `{` *`语句`* `}`

## 对比
```
var name;
input name;
if name == 'Jason' {print "We have a same name!";}
```

C++:
```c++
#include <iostream>
using namespace std;

int main(void) {
    string name;
    cin >> name;
    if(name == "Jason") 
        cout << "We have a same name!" << endl;
    return 0;
}
```

C Language:
```c
#include <stdio.h>

int main(void) {
    char name[114514];
    scanf("%s",name);
    if(name == "Jason") 
        printf("We have a same name!");
    return 0;
}
```

Python:
```python
name = input()
if name == 'Jason':
    print('We have a same name!')
```

JS: 无

Java(老规矩):
```java
import java.util.Scanner;

public class Untitled {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();
        if(name == "Jason") {
            System.out.println("We have same name!");
        }
        s.close();
    }
}
```