## C 语言学习指南

### 项目简介

本项目学习内容基本上都直接以 c 文件存在,用注释注解程序内容及解释.
配套的流程说明（如编译过程）以 Markdown 文档形式放在仓库根目录.

### 目录结构

```
CLearn/
├── README.md          # 项目说明（本文件）
├── 编译.md            # GCC 编译四步流程：预处理 → 编译 → 汇编 → 链接
├── .vscode/           # VS Code 编辑器配置
└── 函数/
    └── 输入函数.c     # 常见输入函数对比：fgets / scanf / getchar / sscanf
```

### 环境与工具链

- 编译器：GCC（GNU Compiler Collection，GNU 编译器集合），Windows 与 macOS 通用
- 编辑器：VS Code（Visual Studio Code，代码编辑器）
- 平台：Windows（华硕天选 6 Pro）/ macOS（MacBook）

### 编译与运行

单文件快速编译运行：

```bash
# macOS / Linux
gcc 函数/输入函数.c -o 输入函数
./输入函数

# Windows
gcc 函数/输入函数.c -o 输入函数.exe
输入函数.exe
```

补充说明：

- 多文件、分步编译（`.i` 预处理文件 / `.s` 汇编文件 / `.o` 目标文件 / 链接）见 [编译.md](./编译.md)
- Windows 控制台运行若中文乱码，先执行 `chcp 65001` 切换 UTF-8 代码页
- 编译产生的中间文件（`*.i`、`*.s`、`*.o`、可执行文件）已加入 `.gitignore`，不会误提交

### 学习内容索引

| 内容 | 对应文件 | 状态 |
| --- | --- | --- |
| C 语言编译流程（预处理 → 编译 → 汇编 → 链接） | [编译.md](./编译.md) | 已完成 |
| 常见输入函数对比（fgets / scanf / getchar / sscanf） | [函数/输入函数.c](./函数/输入函数.c) | 已完成 |

### 仓库地址

GitHub：<https://github.com/TongenShen/CLearn>
