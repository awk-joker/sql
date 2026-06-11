cd sqlparser
bison -d sql.y
flex sql.l
gcc -o sqlparser sql.tab.c lex.yy.c
.\sqlparser.exe
每次编译运行命令只能按照此格式按顺序进行