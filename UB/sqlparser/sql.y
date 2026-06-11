%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef enum {
    NODE_SELECT, NODE_INSERT, NODE_UPDATE, NODE_DELETE,
    NODE_CREATE_TABLE, NODE_DROP_TABLE, NODE_SHOW_TABLES
} NodeType;

typedef struct ASTNode {
    NodeType type;
    char *table;
    char *columns;
    char *where;
    char *col_defs;
    char *set_items;
    char *values;
    char *order_by;
    char *limit;
    char *group_by;
    char *having;
    char *join_clause;
    int distinct;
} ASTNode;

extern FILE *yyin;
extern int yylex();
extern int yylineno;
void yyerror(const char *s);
void print_ast(ASTNode *node);
void free_ast(ASTNode *node);

#define YYSTYPE char*

// 字符串拼接工具函数
char* concat(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    
    char *res = malloc(len + 1);
    va_start(args, fmt);
    vsnprintf(res, len + 1, fmt, args);
    va_end(args);
    return res;
}
%}

%token SELECT FROM WHERE AND OR NOT INSERT INTO VALUES UPDATE SET DELETE CREATE TABLE DROP SHOW TABLES
%token INT VARCHAR CHAR DATE FLOAT DOUBLE NULL_LITERAL
%token EQUALS NOT_EQUALS LT GT LTE GTE
%token LPAREN RPAREN COMMA STAR SEMICOLON DOT
%token NUMBER STRING IDENTIFIER
%token ORDER BY LIMIT DISTINCT COUNT SUM AVG MIN MAX LIKE BETWEEN ASC DESC AS
%token GROUP HAVING JOIN INNER LEFT RIGHT ON
%token CASE WHEN THEN ELSE END
%token INTERVAL YEAR
%token ANY ALL IN

%right NOT
%left OR
%left AND
%left EQUALS NOT_EQUALS IN
%left LT GT LTE GTE
%left BETWEEN
%left ANY ALL
%left PLUS MINUS
%left STAR DIV

%%

parse
    : statement_list
    ;

statement_list
    : sql_statement SEMICOLON
    | statement_list sql_statement SEMICOLON
    ;

sql_statement
    : select_statement
    | insert_statement
    | update_statement
    | delete_statement
    | create_statement
    | drop_statement
    | show_statement
    ;

select_statement
    : SELECT optional_distinct select_columns FROM table_reference join_clause optional_where optional_group_by optional_having optional_order_by optional_limit {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_SELECT;
        n->columns = strdup($3);
        n->table = strdup($5);
        n->distinct = ($2 != NULL);
        if ($6) n->join_clause = strdup($6);
        if ($7) n->where = strdup($7);
        if ($8) n->group_by = strdup($8);
        if ($9) n->having = strdup($9);
        if ($10) n->order_by = strdup($10);
        if ($11) n->limit = strdup($11);
        print_ast(n);
        free_ast(n);
    }
    ;

subquery
    : SELECT optional_distinct select_columns FROM table_reference join_clause optional_where optional_group_by optional_having optional_order_by optional_limit {
        if ($2) free($2);
        if ($3) free($3);
        if ($5) free($5);
        if ($6) free($6);
        if ($7) free($7);
        if ($8) free($8);
        if ($9) free($9);
        if ($10) free($10);
        if ($11) free($11);
        $$ = strdup("(subquery)");
    }
    ;

table_reference
    : IDENTIFIER { $$ = strdup($1); }
    | IDENTIFIER AS IDENTIFIER { 
        $$ = concat("%s AS %s", $1, $3);
        free($1); free($3);
    }
    | IDENTIFIER IDENTIFIER { 
        $$ = concat("%s %s", $1, $2);
        free($1); free($2);
    }
    ;

join_clause
    : join_type JOIN IDENTIFIER IDENTIFIER ON expression {
        $$ = concat("%s JOIN %s %s ON %s", $1, $3, $4, $6);
        free($1);
    }
    | join_type JOIN IDENTIFIER ON expression {
        $$ = concat("%s JOIN %s ON %s", $1, $3, $5);
        free($1);
    }
    | join_clause join_type JOIN IDENTIFIER IDENTIFIER ON expression {
        $$ = concat("%s %s JOIN %s %s ON %s", $1, $2, $4, $5, $7);
        free($1); free($2);
    }
    | join_clause join_type JOIN IDENTIFIER ON expression {
        $$ = concat("%s %s JOIN %s ON %s", $1, $2, $4, $6);
        free($1); free($2);
    }
    | { $$ = NULL; }
    ;

join_type
    : INNER { $$ = strdup("INNER"); }
    | LEFT { $$ = strdup("LEFT"); }
    | RIGHT { $$ = strdup("RIGHT"); }
    | { $$ = strdup(""); }
    ;

optional_distinct
    : DISTINCT { $$ = strdup("DISTINCT"); }
    | { $$ = NULL; }
    ;

select_columns
    : STAR { $$ = strdup("*"); }
    | select_list { $$ = $1; }
    ;

select_list
    : select_item { $$ = $1; }
    | select_list COMMA select_item {
        $$ = concat("%s, %s", $1, $3);
        free($1); free($3);
    }
    ;

select_item
    : expression { $$ = $1; }
    | expression AS IDENTIFIER {
        $$ = concat("%s AS %s", $1, $3);
        free($1);
    }
    ;

optional_where
    : WHERE expression { $$ = $2; }
    | { $$ = NULL; }
    ;

optional_group_by
    : GROUP BY expression_list { $$ = $3; }
    | { $$ = NULL; }
    ;

expression_list
    : expression { $$ = $1; }
    | expression_list COMMA expression {
        $$ = concat("%s, %s", $1, $3);
        free($1); free($3);
    }
    ;

optional_having
    : HAVING expression { $$ = $2; }
    | { $$ = NULL; }
    ;

optional_order_by
    : ORDER BY order_list { $$ = $3; }
    | { $$ = NULL; }
    ;

order_list
    : expression { $$ = $1; }
    | expression ASC { 
        $$ = concat("%s ASC", $1);
        free($1);
    }
    | expression DESC { 
        $$ = concat("%s DESC", $1);
        free($1);
    }
    | order_list COMMA expression {
        $$ = concat("%s, %s", $1, $3);
        free($1); free($3);
    }
    | order_list COMMA expression ASC {
        $$ = concat("%s, %s ASC", $1, $3);
        free($1); free($3);
    }
    | order_list COMMA expression DESC {
        $$ = concat("%s, %s DESC", $1, $3);
        free($1); free($3);
    }
    ;

optional_limit
    : LIMIT NUMBER { 
        $$ = concat("LIMIT %s", $2);
        free($2);
    }
    | LIMIT NUMBER COMMA NUMBER { 
        $$ = concat("LIMIT %s, %s", $2, $4);
        free($2); free($4);
    }
    | { $$ = NULL; }
    ;

insert_statement
    : INSERT INTO IDENTIFIER LPAREN column_list RPAREN VALUES LPAREN value_list RPAREN {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_INSERT;
        n->table = strdup($3);
        n->columns = strdup($5);
        n->values = strdup($9);
        print_ast(n);
        free_ast(n);
    }
    ;

column_list
    : IDENTIFIER { $$ = strdup($1); }
    | column_list COMMA IDENTIFIER {
        $$ = concat("%s, %s", $1, $3);
        free($1);
    }
    ;

value_list
    : literal { $$ = strdup($1); }
    | value_list COMMA literal {
        $$ = concat("%s, %s", $1, $3);
        free($1);
    }
    ;

update_statement
    : UPDATE IDENTIFIER SET set_clause {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_UPDATE;
        n->table = strdup($2);
        n->set_items = strdup($4);
        print_ast(n);
        free_ast(n);
    }
    | UPDATE IDENTIFIER SET set_clause WHERE expression {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_UPDATE;
        n->table = strdup($2);
        n->set_items = strdup($4);
        n->where = strdup($6);
        print_ast(n);
        free_ast(n);
    }
    ;

set_clause
    : IDENTIFIER EQUALS expression {
        $$ = concat("%s = %s", $1, $3);
        free($3);
    }
    | set_clause COMMA IDENTIFIER EQUALS expression {
        $$ = concat("%s, %s = %s", $1, $3, $5);
        free($1); free($5);
    }
    ;

delete_statement
    : DELETE FROM IDENTIFIER {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_DELETE;
        n->table = strdup($3);
        print_ast(n);
        free_ast(n);
    }
    | DELETE FROM IDENTIFIER WHERE expression {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_DELETE;
        n->table = strdup($3);
        n->where = strdup($5);
        print_ast(n);
        free_ast(n);
    }
    ;

create_statement
    : CREATE TABLE IDENTIFIER LPAREN column_definitions RPAREN {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_CREATE_TABLE;
        n->table = strdup($3);
        n->col_defs = strdup($5);
        print_ast(n);
        free_ast(n);
    }
    ;

column_definitions
    : column_definition { $$ = strdup($1); }
    | column_definitions COMMA column_definition {
        $$ = concat("%s, %s", $1, $3);
        free($1);
    }
    ;

column_definition
    : IDENTIFIER type_name {
        $$ = concat("%s %s", $1, $2);
        free($1); free($2);
    }
    | IDENTIFIER type_name LPAREN NUMBER RPAREN {
        $$ = concat("%s %s(%s)", $1, $2, $4);
        free($1); free($2); free($4);
    }
    | IDENTIFIER type_name NOT NULL_LITERAL {
        $$ = concat("%s %s NOT NULL", $1, $2);
        free($1); free($2);
    }
    | IDENTIFIER type_name LPAREN NUMBER RPAREN NOT NULL_LITERAL {
        $$ = concat("%s %s(%s) NOT NULL", $1, $2, $4);
        free($1); free($2); free($4);
    }
    ;

type_name
    : INT { $$ = strdup("INT"); }
    | VARCHAR { $$ = strdup("VARCHAR"); }
    | CHAR { $$ = strdup("CHAR"); }
    | DATE { $$ = strdup("DATE"); }
    | FLOAT { $$ = strdup("FLOAT"); }
    | DOUBLE { $$ = strdup("DOUBLE"); }
    ;

drop_statement
    : DROP TABLE IDENTIFIER {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_DROP_TABLE;
        n->table = strdup($3);
        print_ast(n);
        free_ast(n);
    }
    ;

show_statement
    : SHOW TABLES {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_SHOW_TABLES;
        print_ast(n);
        free_ast(n);
    }
    ;

expression
    : literal { $$ = strdup($1); }
    | IDENTIFIER { $$ = strdup($1); }
    | YEAR { $$ = strdup("YEAR"); }
    | INTERVAL expression YEAR { 
        $$ = concat("INTERVAL %s YEAR", $2);
        free($2);
    }
    | IDENTIFIER DOT IDENTIFIER {
        $$ = concat("%s.%s", $1, $3);
        free($1); free($3);
    }
    | function_call { $$ = $1; }
    | aggregate_function { $$ = $1; }
    | case_expression { $$ = $1; }
    | LPAREN select_statement RPAREN { $$ = strdup("(subquery)"); }
    | expression EQUALS expression {
        $$ = concat("%s = %s", $1, $3);
        free($1); free($3);
    }
    | expression NOT_EQUALS expression {
        $$ = concat("%s <> %s", $1, $3);
        free($1); free($3);
    }
    | expression LT expression {
        $$ = concat("%s < %s", $1, $3);
        free($1); free($3);
    }
    | expression GT expression {
        $$ = concat("%s > %s", $1, $3);
        free($1); free($3);
    }
    | expression LTE expression {
        $$ = concat("%s <= %s", $1, $3);
        free($1); free($3);
    }
    | expression GTE expression {
        $$ = concat("%s >= %s", $1, $3);
        free($1); free($3);
    }
    | expression LIKE expression {
        $$ = concat("%s LIKE %s", $1, $3);
        free($1); free($3);
    }
    | expression BETWEEN expression AND expression {
        $$ = concat("%s BETWEEN %s AND %s", $1, $3, $5);
        free($1); free($3); free($5);
    }
    | expression AND expression {
        $$ = concat("%s AND %s", $1, $3);
        free($1); free($3);
    }
    | expression OR expression {
        $$ = concat("%s OR %s", $1, $3);
        free($1); free($3);
    }
    | expression IN LPAREN value_list RPAREN {
        $$ = concat("%s IN (%s)", $1, $4);
        free($1); free($4);
    }
    | expression IN LPAREN subquery RPAREN {
        $$ = concat("%s IN (subquery)", $1);
        free($1);
    }
    | expression LT ANY LPAREN subquery RPAREN {
        $$ = concat("%s < ANY (subquery)", $1);
        free($1);
    }
    | expression GT ANY LPAREN subquery RPAREN {
        $$ = concat("%s > ANY (subquery)", $1);
        free($1);
    }
    | expression LT ALL LPAREN subquery RPAREN {
        $$ = concat("%s < ALL (subquery)", $1);
        free($1);
    }
    | expression GT ALL LPAREN subquery RPAREN {
        $$ = concat("%s > ALL (subquery)", $1);
        free($1);
    }
    | expression PLUS expression {
        $$ = concat("%s + %s", $1, $3);
        free($1); free($3);
    }
    | expression MINUS expression {
        $$ = concat("%s - %s", $1, $3);
        free($1); free($3);
    }
    | expression STAR expression {
        $$ = concat("%s * %s", $1, $3);
        free($1); free($3);
    }
    | expression DIV expression {
        $$ = concat("%s / %s", $1, $3);
        free($1); free($3);
    }
    | LPAREN expression RPAREN {
        $$ = $2;
    }
    | NOT expression {
        $$ = concat("NOT %s", $2);
        free($2);
    }
    ;

case_expression
    : CASE case_when_list ELSE expression END {
        $$ = concat("CASE %s ELSE %s END", $2, $4);
        free($2); free($4);
    }
    | CASE expression case_when_list ELSE expression END {
        $$ = concat("CASE %s %s ELSE %s END", $2, $3, $5);
        free($2); free($3); free($5);
    }
    ;

case_when_list
    : WHEN expression THEN expression {
        $$ = concat("WHEN %s THEN %s", $2, $4);
        free($2); free($4);
    }
    | case_when_list WHEN expression THEN expression {
        $$ = concat("%s WHEN %s THEN %s", $1, $3, $5);
        free($1); free($3); free($5);
    }
    ;

aggregate_function
    : COUNT LPAREN STAR RPAREN { $$ = strdup("COUNT(*)"); }
    | COUNT LPAREN IDENTIFIER RPAREN { 
        $$ = concat("COUNT(%s)", $3);
        free($3);
    }
    | SUM LPAREN expression RPAREN { 
        $$ = concat("SUM(%s)", $3);
        free($3);
    }
    | AVG LPAREN expression RPAREN { 
        $$ = concat("AVG(%s)", $3);
        free($3);
    }
    | MIN LPAREN expression RPAREN { 
        $$ = concat("MIN(%s)", $3);
        free($3);
    }
    | MAX LPAREN expression RPAREN { 
        $$ = concat("MAX(%s)", $3);
        free($3);
    }
    ;

function_call
    : IDENTIFIER LPAREN RPAREN { 
        $$ = concat("%s()", $1);
        free($1);
    }
    | IDENTIFIER LPAREN expression RPAREN { 
        $$ = concat("%s(%s)", $1, $3);
        free($1); free($3);
    }
    | YEAR LPAREN expression RPAREN { 
        $$ = concat("YEAR(%s)", $3);
        free($3);
    }
    | IDENTIFIER LPAREN expression COMMA expression RPAREN { 
        $$ = concat("%s(%s, %s)", $1, $3, $5);
        free($1); free($3); free($5);
    }
    | IDENTIFIER LPAREN expression COMMA expression COMMA expression RPAREN { 
        $$ = concat("%s(%s, %s, %s)", $1, $3, $5, $7);
        free($1); free($3); free($5); free($7);
    }
    | IDENTIFIER LPAREN expression COMMA expression COMMA expression COMMA expression RPAREN { 
        $$ = concat("%s(%s, %s, %s, %s)", $1, $3, $5, $7, $9);
        free($1); free($3); free($5); free($7); free($9);
    }
    ;

literal
    : STRING { $$ = strdup($1); }
    | NUMBER { $$ = strdup($1); }
    | NULL_LITERAL { $$ = strdup("NULL"); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Line %d: Error: %s\n", yylineno, s);
    yyclearin;  // 清除当前的 lookahead token
}

void print_ast(ASTNode *node) {
    switch (node->type) {
        case NODE_SELECT:
            printf("SELECT Statement:\n");
            if (node->distinct) printf("  Distinct: YES\n");
            printf("  Columns: %s\n", node->columns);
            printf("  From: %s\n", node->table);
            if (node->join_clause) printf("  Join: %s\n", node->join_clause);
            if (node->where) printf("  Where: %s\n", node->where);
            if (node->group_by) printf("  Group By: %s\n", node->group_by);
            if (node->having) printf("  Having: %s\n", node->having);
            if (node->order_by) printf("  Order By: %s\n", node->order_by);
            if (node->limit) printf("  Limit: %s\n", node->limit);
            break;
            
        case NODE_INSERT:
            printf("INSERT Statement:\n");
            printf("  Into: %s\n", node->table);
            printf("  Columns: %s\n", node->columns);
            printf("  Values: %s\n", node->values);
            break;
            
        case NODE_UPDATE:
            printf("UPDATE Statement:\n");
            printf("  Table: %s\n", node->table);
            printf("  Set: %s\n", node->set_items);
            if (node->where) printf("  Where: %s\n", node->where);
            break;
            
        case NODE_DELETE:
            printf("DELETE Statement:\n");
            printf("  From: %s\n", node->table);
            if (node->where) printf("  Where: %s\n", node->where);
            break;
            
        case NODE_CREATE_TABLE:
            printf("CREATE TABLE:\n");
            printf("  Table: %s\n", node->table);
            printf("  Columns: %s\n", node->col_defs);
            break;
            
        case NODE_DROP_TABLE:
            printf("DROP TABLE:\n");
            printf("  Table: %s\n", node->table);
            break;
            
        case NODE_SHOW_TABLES:
            printf("SHOW TABLES\n");
            break;
    }
    printf("\n");
}

void free_ast(ASTNode *node) {
    if (!node) return;
    if (node->table) free(node->table);
    if (node->columns) free(node->columns);
    if (node->where) free(node->where);
    if (node->col_defs) free(node->col_defs);
    if (node->set_items) free(node->set_items);
    if (node->values) free(node->values);
    if (node->order_by) free(node->order_by);
    if (node->limit) free(node->limit);
    if (node->group_by) free(node->group_by);
    if (node->having) free(node->having);
    if (node->join_clause) free(node->join_clause);
    free(node);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) { perror("Cannot open file"); return 1; }
        yyin = file;
        yyparse();
        fclose(file);
    } else {
        printf("SQL Parser - Enter SQL statements (type 'exit' to quit)\n");
        char line[4096];
        while (1) {
            printf("sql> ");
            if (!fgets(line, sizeof(line), stdin)) break;
            if (strcmp(line, "exit\n") == 0) break;
            
            FILE *tmp = tmpfile();
            fputs(line, tmp);
            rewind(tmp);
            yyin = tmp;
            yyparse();
            yyrestart(yyin);  // 重置解析器状态，避免错误状态污染
            fclose(tmp);
        }
    }
    return 0;
}