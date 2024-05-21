# `..\variables.h` 说明文档

| 函数名称 | 参数 | 返回值
| ------- | ---- | -----
| new_variable| 名称(string),是否为空(bool),值(string) | 无
| is_variable | 名称(string) | 变量是否已经声明(bool)

__*注：此头文件中还有一个`Variable`类，但是除非特殊情况，请不要直接实例化，而是使用`new_variable`函数*__