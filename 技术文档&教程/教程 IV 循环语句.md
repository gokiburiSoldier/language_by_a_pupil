# 教程 IV 循环语句

## 总览
语句名称 | 语句关键字 | 语句作用
------- | --------- | -------
次数循环 | `loop`   | 循环`n`次

## 语法
`loop `*`n`*` {`*`语句`*`}`

解释：
*`n`* 为一个正整数<br>

## 对比

### loop 语句

```
loop 5 {print "Hello,World!";}
```

C++:
```c++
#include <iostream>
using namespace std;

int main(void) {
    int i;
    for(i = 0; i < 5; i ++) 
        cout << "Hello,World!" << endl;
    return 0;
}
```

C Language:
```c
#include <stdio.h>

int main(void) {
    int i;
    for(int i = 0; i < 5; i ++)
        printf("Hello,World!\n");
    return 0;
}
```

JavaScript(Node.js):
```javascript
var i;
for(i = 0; i < 5; i ++) console.log("Hello,World!");
```

Python:
```python
for i in range(5):
    print("Hello,World!")
```

Java(文件名：Untitled.java):
```java
public class Untitled {
    public static void main(String args[]) {
        int i;
        for(i = 0; i < 5; i ++) {
            System.out.println("Hello,World!");
        }
    }
}
```