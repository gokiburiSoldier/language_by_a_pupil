# N.M.教程 I 「输出」

> 本文件最终更新时间: __2024/5/10__

### 词汇 

output <sup>n./v.</sup> 输出<br>
print  <sup>v.</sup> 打印

### 前言:

> 很多编程语言都有 输出 的功能，这是毋庸置疑的。
当然，我们也要有。————张迦轩

> 上面是一句废话。————张迦轩

### 关键字/函数 一览

功能| 语句
-| -
输出| `print`
设置间隔(默认为空)| `set-step`
设置结尾(默认换行)| `set-end`

### 语法

`print `&nbsp;*字符串;整数;布尔值...*&nbsp;`;`<br>
`set-step `&nbsp;*字符串*&nbsp;`;`<br>
`set-end `&nbsp;*字符串*&nbsp;`;`<br>

#### 注意点

- __1.`print`与输出内容之间有一个空格__
- __2.输出内容可以有多个，使用空格或者逗号隔开__
- __3.`set-step`和`set-end`后面只可以写一个字符串,否则会报错__


### 例子
最初版(2024/5/9)：*`print Hello,World!`*<br>
(2024/5/10)： *`print "Hello,World!"`*<br>

### 对比(真的不是在水)

```
print "Hello,World!";
```

C++: 
```C++
#include <iostream>
using namespace std;

int main(void) {
    cout << "Hello,World!" << endl;
    return 0;
}
```

C language:
```C
#include <stdio.h>

int main(void) {
    printf("Hello,World!\n");
    return 0;
}
```

Java(文件名: Untitled.java):
```java
public class Untitled {
    public static void main(String args[]) {
        System.out.println("Hello,World!");
    }
}
```

JavaScript(Node.js):
```javascript
console.log("Hello,World!");
```

PHP:
```php
<?php
    echo "Hello,World!";
```

Python:
```python
print('Hello,World!')
```

HTML:
```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Document</title>
    </head>
    <body>
        <p>Hello,World!</p>
    </body>
</html>
```

Markdown:
```
Hello,World!
```

Scratch:<br>
__你认真的?__

Bash:
```bash
$echo Hello,World!
```

Windows Batch:
```bat
echo Hello,World!
```