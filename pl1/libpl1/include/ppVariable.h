#ifndef PPVARIABLE_H_
#define PPVARIABLE_H_

#include "ppVariableStructs.h"

/* prototypes */
extern int ppSetIntValue(char *name,int value,YYLTYPE *locp);
extern int ppSetStringValue(char *name,char *value,YYLTYPE *locp);
extern int ppDefineLabel(char *name,int type, YYLTYPE *location);
extern int ppDefineVariable(char *name,int type, YYLTYPE *llocp);
extern int ppDefineVariableList(struct namelist *,int type);
extern struct namelist *ppInitList(char *name, YYLTYPE *llocp);
extern struct namelist *ppAddName(struct namelist *,char *name, YYLTYPE *llocp);
extern int ppShowNameList(struct namelist *);
extern int ppGetIntValue(char *name,YYLTYPE *locp) ;
extern char * ppGetStringValue(char *name,YYLTYPE *locp);
extern struct ppDCLelement * ppFindDCLName(char *name);
extern struct ppDCLelement * ppFindDCLNameInList(struct ppDCLelement *head ,char *name);
extern char * ppGetValueAsString(struct ppDCLelement *,YYLTYPE *locp) ;

extern int ppSetActivateStmt(char *name);
extern int ppSetDeactivateStmt(char *name);

extern int ppSetGotoStmt(char *label, YYLTYPE *llocp);
extern int ppSetIncludeStmt(char *fileName, char *environmentVariable, YYLTYPE *llocp);

extern int ppSetNoteStmt(char *level, char *msgtext);
extern int ppSetDoStmt(char *loopvarname, int fromexpr, int toexpr, YYLTYPE *llocp);
extern int ppSetEndStmt(YYLTYPE *llocp);

extern struct ppDCLLabelStack * ppPushDCLLabelStack(struct ppDCLLabelStack *tail);
extern struct ppDCLLabelStack * ppPopDCLLabelStack(struct ppDCLLabelStack *tail);
extern int ppDisposeDCLLabelStackElement(struct ppDCLLabelStack *work);

extern int ppAnalyseStmt(char *labelName,  struct anyTokenList *inTokensList,  struct anyTokenList *outTokensList );

extern struct ppContextAnchor *newppContextAnchor(void);


#endif /*PPVARIABLE_H_*/
