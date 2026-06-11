%option noyywrap

%{
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "sql.tab.h"
extern char *yytext;

// 字符串转义处理函数
char* escape_string(const char *s) {
    int len = strlen(s);
    char *res = malloc(len);
    int i, j = 0;
    for (i = 1; i < len-1; i++) {  // 跳过首尾的单引号
        if (s[i] == '\'' && s[i+1] == '\'') {
            res[j++] = '\'';
            i++;
        } else {
            res[j++] = s[i];
        }
    }
    res[j] = '\0';
    return res;
}

// 行号跟踪
int yylineno = 1;
%}

DIGIT       [0-9]
LETTER      [a-zA-Z_]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT})*
NUMBER      {DIGIT}+(\.{DIGIT}+)?
STRING      '([^']|'')*'
COMMENT     --[^\n]*

%%

[Ss][Ee][Ll][Ee][Cc][Tt]          { return SELECT; }
[Ff][Rr][Oo][Mm]                  { return FROM; }
[Ww][Hh][Ee][Rr][Ee]              { return WHERE; }
[Aa][Nn][Dd]                      { return AND; }
[Oo][Rr]                          { return OR; }
[Nn][Oo][Tt]                      { return NOT; }
[Ii][Nn][Ss][Ee][Rr][Tt]          { return INSERT; }
[Ii][Nn][Tt][Oo]                  { return INTO; }
[Vv][Aa][Ll][Uu][Ee][Ss]          { return VALUES; }
[Uu][Pp][Dd][Aa][Tt][Ee]          { return UPDATE; }
[Ss][Ee][Tt]                      { return SET; }
[Dd][Ee][Ll][Ee][Tt][Ee]          { return DELETE; }
[Cc][Rr][Ee][Aa][Tt][Ee]          { return CREATE; }
[Tt][Aa][Bb][Ll][Ee]              { return TABLE; }
[Dd][Rr][Oo][Pp]                  { return DROP; }
[Ss][Hh][Oo][Ww]                  { return SHOW; }
[Tt][Aa][Bb][Ll][Ee][Ss]          { return TABLES; }
[Ii][Nn][Tt]                      { return INT; }
[Vv][Aa][Rr][Cc][Hh][Aa][Rr]      { return VARCHAR; }
[Cc][Hh][Aa][Rr]                  { return CHAR; }
[Dd][Aa][Tt][Ee]                  { return DATE; }
[Ff][Ll][Oo][Aa][Tt]              { return FLOAT; }
[Dd][Oo][Uu][Bb][Ll][Ee]          { return DOUBLE; }
[Nn][Uu][Ll][Ll]                  { return NULL_LITERAL; }
[Oo][Rr][Dd][Ee][Rr]              { return ORDER; }
[Bb][Yy]                          { return BY; }
[Ll][Ii][Mm][Ii][Tt]              { return LIMIT; }
[Dd][Ii][Ss][Tt][Ii][Nn][Cc][Tt]  { return DISTINCT; }
[Cc][Oo][Uu][Nn][Tt]              { return COUNT; }
[Ss][Uu][Mm]                      { return SUM; }
[Aa][Vv][Gg]                      { return AVG; }
[Mm][Ii][Nn]                      { return MIN; }
[Mm][Aa][Xx]                      { return MAX; }
[Ll][Ii][Kk][Ee]                  { return LIKE; }
[Bb][Ee][Tt][Ww][Ee][Ee][Nn]      { return BETWEEN; }
[Aa][Ss][Cc]                      { return ASC; }
[Dd][Ee][Ss][Cc]                  { return DESC; }
[Aa][Ss]                          { return AS; }
[Gg][Rr][Oo][Uu][Pp]              { return GROUP; }
[Hh][Aa][Vv][Ii][Nn][Gg]          { return HAVING; }
[Jj][Oo][Ii][Nn]                  { return JOIN; }
[Ii][Nn][Nn][Ee][Rr]              { return INNER; }
[Ll][Ee][Ff][Tt]                  { return LEFT; }
[Rr][Ii][Gg][Hh][Tt]              { return RIGHT; }
[Oo][Nn]                          { return ON; }
[Cc][Aa][Ss][Ee]                  { return CASE; }
[Ww][Hh][Ee][Nn]                  { return WHEN; }
[Tt][Hh][Ee][Nn]                  { return THEN; }
[Ee][Ll][Ss][Ee]                  { return ELSE; }
[Ee][Nn][Dd]                      { return END; }
[Ii][Nn][Tt][Ee][Rr][Vv][Aa][Ll]  { return INTERVAL; }
[Yy][Ee][Aa][Rr]                  { return YEAR; }
[Aa][Nn][Yy]                      { return ANY; }
[Aa][Ll][Ll]                      { return ALL; }
[Ii][Nn]                          { return IN; }

"<>"            { return NOT_EQUALS; }
"!="            { return NOT_EQUALS; }
"<="            { return LTE; }
">="            { return GTE; }
"<"             { return LT; }
">"             { return GT; }
"="             { return EQUALS; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return STAR; }
"/"             { return DIV; }

"("             { return LPAREN; }
")"             { return RPAREN; }
","             { return COMMA; }
";"             { return SEMICOLON; }
"."             { return DOT; }
{NUMBER}        { yylval = strdup(yytext); return NUMBER; }
{STRING}        { yylval = escape_string(yytext); return STRING; }
{IDENTIFIER}    { yylval = strdup(yytext); return IDENTIFIER; }
{COMMENT}       { }
[ \t\r]+        { }
\n              { yylineno++; }
.               { fprintf(stderr, "Line %d: Unknown character: %c\n", yylineno, *yytext); }

%%