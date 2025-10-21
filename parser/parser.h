#ifndef PARSER__PARSER_H
#define PARSER__PARSER_H


#include <ctype.h>

#include "../CLI_UI/main.h"
#include "../shapes/common-fonctions/fonctions.h"

#include "../shapes/circle/main.h"
#include "../shapes/ellipse/main.h"
#include "../shapes/line/main.h"
#include "../shapes/path/path.h"
#include "../shapes/polygone/main.h"
#include "../shapes/polyline/main.h"
#include "../shapes/rectangle/main.h"
#include "../shapes/square/main.h"

#include "../svg/main.h"

int my_strlen(const char* s);

int my_strcmp(const char* s1, const char* s2);

char* my_strdup(const char* s);

void my_strcpy_n(char* dest, const char* src, int n);

int Is_Svg_File(const char* filename);

void Skip_Whitespace(const char* content, int* pos);

void Skip_Until_Char(const char* content, int* pos, char c, long size);

int Extract_Attribute(const char* content, int* pos, char* attr_name, char* attr_value, int max_len);

int Parse_Int(const char* str);

Rect* Parse_Rect_Element(const char* content, int* pos, long size);

Circle* Parse_Circle_Element(const char* content, int* pos, long size);

Ellipse* Parse_Ellipse_Element(const char* content, int* pos, long size);

Line* Parse_Line_Element(const char* content, int* pos, long size);

Head* Parse_Polyline_Element(const char* content, int* pos, long size);

void Parse_Path_Command(char cmd, const char* data, HeadPath* path);

HeadPath* Parse_Path_Attribute(const char* path_data);

Svg* Parse_Svg_File(const char* filename);

void Parser();

#endif