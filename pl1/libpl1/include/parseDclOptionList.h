#ifndef PARSEDCLOPTIONLIST_H_
#define PARSEDCLOPTIONLIST_H_

#include "parseDclOptionListStructs.h"

extern struct DclOptionList *newDclOptionList(void);
extern struct DclOptionNumeric *newDclOptionNumeric(void);
extern struct DclOptionPgm *newDclOptionPgm(void);
extern struct DclOptionChar *newDclOptionChar(void);

extern int initDclOptionNumeric(struct DclOptionList *dol);
extern int initDclOptionPgm(struct DclOptionList *dol);
extern int initDclOptionChar(struct DclOptionList *dol);

extern void showStructDclOptionList(struct DclOptionList *dol);
extern void showStructDclOptionNumeric(struct DclOptionNumeric *don);
extern void showStructDclOptionPgm(struct DclOptionPgm *dop);
extern void showStructDclOptionChar(struct DclOptionChar *doc);
extern char *sprintf_DclOptionList_short(struct DclOptionList *dol);

extern int setDclElementAttr(struct DclOptionList *old, struct DclOptionList *new);
#endif /*PARSEDCLOPTIONLIST_H_*/
