# N.M.教程 I 「变量」

> 本文件最终更新时间: __2024/5/14__

### 词汇

variable <sup>n.</sup>变量&nbsp;<sup>adj.</sup>可变的

### 前言

> 哪个傻子当初想出了这一部分！————那个傻子

### 关键字/函数 一览

功能| 语句
-| -
建立变量| `var`

### 语法

`var `&nbsp;*变量名*&nbsp;` = `&nbsp;*值*

#### 注意点
- __1.等号(`=`)左右一定需要有空格__
- __2.一定不可以写分号(`;`)__
- __3.可以在`print`中使用变量__

### 对比(真的不是在水)

```
var a = "b"
```

C++:
```c++
#include <string>
using namespace std;

int main(void) {
    string a = "b";
    return 0;
}
```

C Language:
```c
int main(void) {
    char* a1 = "b";
    char a2 = "b";
    char a3[] = "b";
    char a4[114514] = "b";
    return 0;
}
```

Java(文件名: Untitled.java):
```java
public class Untitled {
    public static void main(String args[]) {
        String a = "b";
    }
}
```

JavaScript(Node.js):
```javascript
var a = "b";
```

PHP:
```php
<?php
    $a = "b";
```

Python:
```python
a = "b"
```

HTML: 无

Markdown: 无

Scratch: `将[我的变量]设为[b]`

Bash:
```bash
$a = "b"
```

Windows Batch:
```bat
set a=b
rem 使用 %a% 作为变量名
```