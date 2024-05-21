# 教程 N(0) 如何才算安装 ?

## 1.下载压缩包并且解压

在此 GitHub 页面的 Code 选项中点击 Download ZIP,然后解压至任意文件夹

### 2.配置环境变量

如果你在使用 PowerShell ,你可以输入以下代码: 
```bash
$env:Path += 你的文件夹解压路径
```

或者：
- 右键 __文件资源管理器__ 中的 __计算机__ ,选择 __属性__
- 选择 __高级系统设置__
- 选择 __环境变量__
- 找到 __系统环境变量__ 中的 __Path__ 项 选中并且点击 __编辑__
- 点击 __新建__ 填写你的解压路径
- 一路 __确定__

### 3.第一个程序！

确认无误后，你就可以开始编写第一个程序了！

(
如果不确定是否安装，可以打开终端，输入
```bash
ning -v
```
若出现版本号，则代表安装成功。
)

你可以新建一个文本文件,并且写入以下内容：
```
var time;
var name;
input time,"- Will I say hello to you what times?\n-  ";
input name,"- Who are you?\n- ";
clear ;
loop time {print "Hello ",name,"!";}
```
(*example.ning*的内容)

然后，选择另存为，并且把`.txt`后缀改为`.ning`。

接着，按住`Shift`右键文件资源管理器，选择 __在终端中打开__，然后输入以下命令：
```bash
ning ./example.ning
```
(注：*example.ning*替换为你的文件名)