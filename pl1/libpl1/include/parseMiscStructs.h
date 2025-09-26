	/* parseMiscStructs.h
	 * ==================
	 *
	 * File for structures that does require its own module. 
	 *
	 * Copyright 2006, Henrik Sorensen
	 *
	 * This file is part of GCC front-end for the PL/I programming language, GCC PL/I.
	 *
	 * GCC PL/I is free software; you can redistribute it and/or modify
	 * it under the terms of the GNU General Public License as published by
	 * the Free Software Foundation; version 2.
	 *
	 * GCC PL/I is distributed in the hope that it will be useful,
	 * but WITHOUT ANY WARRANTY; without even the implied warranty of
	 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	 * GNU General Public License for more details.
	 *
	 * You should have received a copy of the GNU General Public License
	 * along with GCC PL/I; see the file COPYING.  If not, write to
	 * the Free Software Foundation, 59 Temple Place - Suite 330,
	 * Boston, MA 02111-1307, USA.
	 *
	 * 
	 */

#ifndef PARSEMISCSTRUCTS_H_
#define PARSEMISCSTRUCTS_H_

/* definition for lists of names */

struct NameNode
{ char * name;
  struct NameNode *next;
};

struct ListOfNames
{ struct NameNode *head, *tail;
  unsigned int labelno;  /* number of labels */
  unsigned int labellen; /* total length of all labels */
};

#endif /*PARSEMISCSTRUCTS_H_*/
