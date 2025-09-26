	/* parseProcOptionList.h
	 * =====================
	 *
	 * External interface for structure ProcOptionList 
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

#ifndef PARSEPROCOPTIONLIST_H_
#define PARSEPROCOPTIONLIST_H_

#include "parseProcOptionListStructs.h"

extern struct ProcOptionList *newProcOptionList(void);
extern void showProcOptionList(struct ScopeNode *current,struct ProcOptionList *pol);


#endif /*PARSEPROCOPTIONLIST_H_*/
