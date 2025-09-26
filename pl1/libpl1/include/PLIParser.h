#ifndef PL1PARSER_H_
#define PL1PARSER_H_

#include "TokenLocationStructs.h"
#include "PLIParserStructs.h"

extern struct PLIParserParms *initPL1ParserParms(void); 
extern int pl1_parser (struct PLIParserParms *pl1parserparms); // NOTE: defined in pl1-parser.y

extern struct PLIParserIncludeFileList *newPLIParserIncludeFileList(void);
extern struct PLIParserIncludeFile * addIncludeFile(struct PLIParserIncludeFileList *list,int type ,char *name,struct PLIParserIncludeFile *current, YYLTYPE *location);

extern void produceXrefList(struct ScopeNode *current);
extern void produceIncludeList(struct PLIParserIncludeFileList *list);

extern int showWelcome(struct PLIParserParms *ppp);

#endif /*PL1PARSER_H_*/
