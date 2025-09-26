/*  GCC PL/I Compiler common definitions (pl1lang.h)

    Copyright 2002, 2003-2004 Henrik Sorensen

    This file is part of GCC front-end for the PL/I programming language, GCC PL/I.

    GCC PL/I is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; version 2.

    GCC PL/I is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GCC PL/I; if not, write to the Free Software
    Foundation, 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.

    ---------------------------------------------------------------------------

    Largely based on treelang/treelang.h Tim Josling 1999, 2000, 2001.


*/

#include "input.h"

/* Parse structure type.  */
enum category_enum 
{ /* These values less likely to be there by chance unlike 0/1,
      make checks more meaningful */
  token_category = 111,
  production_category = 222,
  parameter_category = 333
};

/* Input file FILE.  */
extern FILE* yyin;

/* Forward references to satisfy mutually recursive definitions.  */
struct token_part;
struct production_part;
struct prod_token_parm_item;
typedef struct prod_token_parm_item item;

/* A token from the input file.  */

struct token_part
{
  location_t location;
  unsigned int charno;
  unsigned int length; /* The value.  */
  unsigned char* chars;
};

/* Definitions for fields in production.  */
#define NESTING_LEVEL(a) a->tp.pro.info[0]  /* Level used for variable definitions.  */
/* Numeric type used in type definitions and expressions.  */
#define NUMERIC_TYPE(a)  a->tp.pro.info[1]  
#define SUB_COUNT 5
#define SYMBOL_TABLE_NAME(a) (a->tp.pro.sub[0]) /* Name token.  */
#define EXPRESSION_TYPE(a) (a->tp.pro.sub[1]) /* Type identifier.  */
#define OP1(a) (a->tp.pro.sub[2]) /* Exp operand1.  */
#define PARAMETERS(a) (a->tp.pro.sub[2]) /* Function parameters.  */
#define VARIABLE(a) (a->tp.pro.sub[2]) /* Parameter variable ptr.  */
#define VAR_INIT(a) (a->tp.pro.sub[2]) /* Variable init.  */
#define OP2(a) (a->tp.pro.sub[3]) /* Exp operand2.  */
/* Function parameters linked via struct tree_parameter_list.  */
#define FIRST_PARMS(a) (a->tp.pro.sub[3])
#define OP3(a) (a->tp.pro.sub[4]) /* Exp operand3.  */
#define STORAGE_CLASS_TOKEN(a) (a->tp.pro.sub[4]) /* Storage class token.  */
#define STORAGE_CLASS(a) a->tp.pro.flag1 /* Values in treetree.h.  */

struct production_part
{
  struct prod_token_parm_item *main_token; /* Main token for error msgs; variable name token.  */

  unsigned int info[2]; /* Extra information.  */

  struct prod_token_parm_item *sub[SUB_COUNT]; /* Sub productions or tokens.  */
  tree code; /* Back end hook for this item.  */
  struct prod_token_parm_item *next; /* Next in chains of various types.  */

  unsigned int flag1:2;
  unsigned int flag2:1;
  unsigned int flag3:1;
  unsigned int flag4:1;
  unsigned int flag5:1;
  unsigned int flag6:1;
  unsigned int flag7:1;

};

/* Storage modes.  */
#define STATIC_STORAGE 0
#define AUTOMATIC_STORAGE 1
#define EXTERNAL_REFERENCE_STORAGE 2
#define EXTERNAL_DEFINITION_STORAGE 3

/* Numeric types.  */
#define SIGNED_CHAR 1
#define UNSIGNED_CHAR 2
#define SIGNED_INT 3 
#define UNSIGNED_INT 4
#define VOID_TYPE 5

/* Expression types.  */
#define EXP_PLUS 0 /* Addition expression.  */
#define EXP_REFERENCE 1 /* Variable reference.  */
#define EXP_ASSIGN 2 /* Assignment.  */
#define EXP_FUNCTION_INVOCATION 3  /* Call function.  */
#define EXP_MINUS 4  /* Subtraction.  */
#define EXP_EQUALS 5  /* Equality test.  */

/* Parameter list passed to back end.  */
struct parameter_part
{
  struct prod_token_parm_item *next; /* Next entry.  */
  unsigned char* variable_name; /* Name. */
  tree * where_to_put_var_tree; /* Where to save decl.  */
};

/* A production or a token.  */
struct prod_token_parm_item
{
  enum category_enum category; /* Token or production. */
  unsigned int type; /* Token or production type.  */
  union t_or_p
  {
    struct token_part tok;
    struct production_part pro;
    struct parameter_part par;
  } tp;
};


/* For parser. Alternatively you can define it using %union (bison) or
   union. */
#define YYSTYPE void *

void *my_malloc (size_t size);
int insert_tree_name (struct prod_token_parm_item *prod);
struct prod_token_parm_item *lookup_tree_name (struct prod_token_parm_item *prod);
struct prod_token_parm_item *make_production (int type, struct prod_token_parm_item *main_tok);
void mark_production_used (struct prod_token_parm_item *pp);
void mark_token_used (struct prod_token_parm_item *tt);
void pl1_debug (void);

void sanity_check (struct prod_token_parm_item *item);
