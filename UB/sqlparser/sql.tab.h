
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SELECT = 258,
     FROM = 259,
     WHERE = 260,
     AND = 261,
     OR = 262,
     NOT = 263,
     INSERT = 264,
     INTO = 265,
     VALUES = 266,
     UPDATE = 267,
     SET = 268,
     DELETE = 269,
     CREATE = 270,
     TABLE = 271,
     DROP = 272,
     SHOW = 273,
     TABLES = 274,
     INT = 275,
     VARCHAR = 276,
     CHAR = 277,
     DATE = 278,
     FLOAT = 279,
     DOUBLE = 280,
     NULL_LITERAL = 281,
     EQUALS = 282,
     NOT_EQUALS = 283,
     LT = 284,
     GT = 285,
     LTE = 286,
     GTE = 287,
     LPAREN = 288,
     RPAREN = 289,
     COMMA = 290,
     STAR = 291,
     SEMICOLON = 292,
     DOT = 293,
     NUMBER = 294,
     STRING = 295,
     IDENTIFIER = 296,
     ORDER = 297,
     BY = 298,
     LIMIT = 299,
     DISTINCT = 300,
     COUNT = 301,
     SUM = 302,
     AVG = 303,
     MIN = 304,
     MAX = 305,
     LIKE = 306,
     BETWEEN = 307,
     ASC = 308,
     DESC = 309,
     AS = 310,
     GROUP = 311,
     HAVING = 312,
     JOIN = 313,
     INNER = 314,
     LEFT = 315,
     RIGHT = 316,
     ON = 317,
     CASE = 318,
     WHEN = 319,
     THEN = 320,
     ELSE = 321,
     END = 322,
     INTERVAL = 323,
     YEAR = 324,
     ANY = 325,
     ALL = 326,
     IN = 327,
     MINUS = 328,
     PLUS = 329,
     DIV = 330
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


