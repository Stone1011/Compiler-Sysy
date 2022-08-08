# 项目说明

## 文件说明

本项目文件文件结构如下：

```shell
.
├── Build
│   ├── 0
│   ├── 1
│   ├── 2
│   ├── 3
│   └── 4
├── Generator.hpp
├── grammar.y
├── lex.yy.c
├── Makefile
├── Output
│   ├── 0.s
│   ├── 1.s
│   ├── 2.s
│   ├── 3.s
│   ├── 4.s
├── readme.md
├── show.sh
├── sysyc
├── Test
│   ├── 0.sy
│   ├── 1.sy
│   ├── 2.sy
│   ├── 3.sy
│   ├── 4.sy
├── tree.cpp
├── tree.h
├── wordAnalysis.l
├── y.tab.c
└── y.tab.h
```

* y.tab.\*为YACC生成的C语言源文件和头文件
* lex.yy.c为FLEX生成的C语言源文件
* Makefile为项目make文件，其中，main目标为本项目的生成
* show.sh为分别编译五个测试样例为汇编语言，并用gcc编译生成Build目录下的可执行文件的shell脚本
* sysyc为本项目生成的编译器可执行二进制文件
* Generator.hpp、grammar.y、tree.h/cpp、wordAnalysis.l为本项目的源文件和头文件。

**[注意]**  项目文件中的3.sy在Linux Ubuntu 20.04上由于未知错误，无法生成3.s。这里的3.s是在macOS 12.4中生成的；可执行文件3是在Linux Ubuntu 20.04上根据macOS生成的3.s文件使用gcc编译、链接产生的。

## 变量含义

* isNum = 1表示普通数
* isNum = 0表示一般变量
* isNum = 2表示寄存器
* isNum = 3表示数组，内存寻址
* isNum = 4表示bool表达式

## 编译器实现细节

- [x] 多层变量
- [x] 全局变量
- [x] 函数调用
- [x] while
- [x] if
- [x] 寄存器分配
- [x] 数组寻址
- [x] 乘法
- [x] 减法
- [x] 加法

### 不支持：

错误处理

scanf(a[1]);

int a [] = {…};

int a [N * 2];

连续两层有嵌套变量，最后一层有break：
while (...) {
if(...){int x; if(...){int x; break;}
}
}

int main()
{
    ...
    no-return; or return;
}

### 测试代码：

1. 加减乘测试
```cpp
const int a = 1;

int main()
{
int a = 2, b = 0x11;
int c = 3+ a * b;
int d = a*2+3;
int e = a*b-c*c;
int f = a*c-d*e+1;
//    a = 2;
//    a = b;
//    a = 2-a+b;
//    int c;
//    c = 022;
//    b = a+2+b+c;
}
```

2. 数组测试

```cpp
const int N = 10;

int main()
{
int a[N][N];
a[2*3][3*2] = 2*2+2*a[2][2];
}
```

3. if测试

```
const int N = 100;
int main()
{
int a = 2;
if(1+1==2*a+1){a=1; a = a * 2;};
}
```

4. and、or测试

```cpp
const int N = 100;
int main()
{
int a = 2, b[2][3];

    if(a > 1 && a > 2 || a > 3)
    {
        a = 1;
    }
    else b[1][1] = 2;
}
```

5. while测试

```cpp
   const int N = 10;
   int main()
   {
   int i = 0, sum = 0;
   while(1)
   {
   if(i == 0)
   {
   i = i + 1;
   continue;
   }
   if(i > N)
   break;
   else
   {
   sum = sum + i;
   i = i + 1;
   }
   }
   return sum;
   }
```

6. 函数调用测试

```cpp
   // const int N = 10;
   int calc_sum(int N)
   {
   int i = 0, sum = 0;
   while(1)
   {
   if(i == 0)
   {
   i = i + 1;
   continue;
   }
   if(i > N)
   break;
   else
   {
   sum = sum + i;
   i = i + 1;
   }
   }

   return sum;
   }

int main()
{
int x;
scanf(x);
printf(calc_sum(x));
return 0;
}
```

7. 全局变量测试

```cpp
   int a = 2, b = 3;
   int M[2][2];

int main()
{
scanf(b);

    int a[2];
    a[1] = b*2;
    b = b + 2;
    M[1][1] = b+3;
    int p = b + M[1][1] + a[1];
    printf(p);
    return 0;
}
```