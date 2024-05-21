# `../file_system.h`说明文档

__*文件所有内容均放在命名空间 `fs` 中*__

| 函数名 | 参数 | 返回值 |
| ------ | --- | ------ |
`fs::is_file` | 文件路径(string) | 文件是否存在(bool)
`fs::read_file` | 文件路径(string) | 文件内容(string,每行末尾有 `\n`)
`fs::read_lines` | 文件路径(string) | 文件内容(`vector<string>`,每行末尾有`\n`)
`fs::write_file` | 文件路径(string),写入内容(string) | 无