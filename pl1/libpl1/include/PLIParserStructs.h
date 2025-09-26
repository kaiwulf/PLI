#ifndef PLIPARSERSTRUCTS_H_
#define PLIPARSERSTRUCTS_H_


struct PLIParserParms
{ char * fileName ;
  FILE * inputFile;
  int debugParser;
  int debugScanner;
  int debugScannerPreprocessor;
  int preprocessOnly;
  int messageLevel;
  char * includePath; 
  char * includeSuffix;
  struct PLIMessage *msgErrors;
  struct PLIMessage *msgWarns;
  struct PLIMessage *msgInfos;
  struct ScopeNode *scopeRoot;
  void *flexScanner;
  struct PLIParserIncludeFileList *includefilelist;
};

struct PLIParserIncludeFile
{ char * name;
  int type;
#define INCTYPE_FILE 0
#define INCTYPE_PPVAR 1
  YYLTYPE *location;
  struct PLIParserIncludeFile *includedFrom;
  struct PLIParserIncludeFile *next;
  int refno; // include file enumeration 
};

struct PLIParserIncludeFileList
{
	struct PLIParserIncludeFile *head;
	struct PLIParserIncludeFile *tail;
    int count[2] ; // one count per type
};


#endif /*PLIPARSERSTRUCTS_H_*/
