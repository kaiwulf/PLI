#ifndef PARSEMISC_H_
#define PARSEMISC_H_

#include "parseMiscStructs.h"

extern int setTristateAttribute(int *variable, int data);
extern int setIntegerAttribute(int *variable, int data);
extern int setBooleanAttribute(int *variable, int data);
extern int setNstateAttribute(int *variable, int data);
extern char *sprintTristateAttribute(const char *name,int value);
extern char *sprintIntegerAttribute(const char *name, int value);
extern char *sprintBooleanAttribute(const char *name, int data);
extern char *sprintNstateAttribute(const char *name, int data);

#endif /*PARSEMISC_H_*/
