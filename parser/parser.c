#include "./parser.h"


int my_strlen(const char* s) {
    int len = 0;
    while (s && s[len]) len++;
    return len;
}

int my_strcmp(const char* s1, const char* s2) {
    if (!s1 || !s2) return s1 == s2 ? 0 : (s1 ? 1 : -1);
    while (*s1 && *s2 && *s1 == *s2) { s1++; s2++; }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

char* my_strdup(const char* s) {
    if (!s) return NULL;
    int len = my_strlen(s);
    char* dup = malloc(len + 1);
    if (!dup) return NULL;
    for (int i = 0; i <= len; i++) dup[i] = s[i];
    return dup;
}

// :) Sexy-jutsu de strcpy
void my_strcpy_n(char* dest, const char* src, int n) {
    if (!dest || !src) return;
    for (int i = 0; i < n && src[i]; i++) dest[i] = src[i];
    dest[n] = '\0';
}

int Is_Svg_File(const char* filename) {
    if (!filename) return 0;
    int len = my_strlen(filename);
    return len >= 4 && 
           filename[len-4] == '.' &&
           filename[len-3] == 's' &&
           filename[len-2] == 'v' &&
           filename[len-1] == 'g';
}


void Skip_Whitespace(const char* content, int* pos) {
    while (content[*pos] && (content[*pos] == ' ' || content[*pos] == '\t' || content[*pos] == '\n' || content[*pos] == '\r')) {
        (*pos)++;
    }
}


void Skip_Until_Char(const char* content, int* pos, char c, long size) {
    while (*pos < size && content[*pos] && content[*pos] != c) {
        (*pos)++;
    }
}


int Extract_Attribute(const char* content, int* pos, char* attr_name, char* attr_value, int max_len) {
    Skip_Whitespace(content, pos);
    // Pour extract mes attributs SVG
    
    int name_len = 0; //Longueur de l'attribut à rechercher
    while (content[*pos] && content[*pos] != '=' && !isspace(content[*pos]) && 
           name_len < max_len - 1) {
        attr_name[name_len++] = content[(*pos)++];
    }
    attr_name[name_len] = '\0';
    
    Skip_Whitespace(content, pos);
    
    
    if (content[(*pos)++] != '=') return 0; // Find my EGAL please !!!
    Skip_Whitespace(content, pos);
    
    
    char quote = content[(*pos)++];
    if (quote != '"' && quote != '\'') return 0;
    
    int val_len = 0;
    while (content[*pos] && content[*pos] != quote && val_len < max_len - 1) {
        attr_value[val_len++] = content[(*pos)++];
    }
    attr_value[val_len] = '\0';
    
    if (content[(*pos)++] != quote) return 0;
    return 1;
}

//Conversion d'une chaîne en entier (clone de atoi :p)
int Parse_Int(const char* str) {
    if (!str) return 0;
    int num = 0, neg = 0;
    if (*str == '-') { neg = 1; str++; }
    while (*str && isdigit(*str)) {
        num = num * 10 + (*str - '0');
        str++;
    }
    return neg ? -num : num;
}



Rect* Parse_Rect_Element(const char* content, int* pos, long size) {
    Rect* rect = Create_rect(0, 0, 0, 0, 0);
    if (!rect) return NULL;

    char attr_name[128], attr_value[256];

    while (*pos < size && content[*pos] && content[*pos] != '>') {
        if (Extract_Attribute(content, pos, attr_name, attr_value, sizeof(attr_value))) {
            if (my_strcmp(attr_name, "x") == 0)
                rect->x = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "y") == 0)
                rect->y = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "width") == 0)
                rect->width = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "height") == 0)
                rect->height = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "rx") == 0)
                rect->round = Parse_Int(attr_value);
        } else {
            (*pos)++;
        }
    }

    if (*pos < size && content[*pos] == '>') (*pos)++;
    return rect;
}

Circle* Parse_Circle_Element(const char* content, int* pos, long size) {
    Circle* circle = malloc(sizeof(Circle));
    if (!circle) return NULL;

    circle->cx = 0;
    circle->cy = 0;
    circle->rx = 0;

    char attr_name[128], attr_value[256]; //Ap je mets les longueurs de mes pseudo-string en #define...

    while (*pos < size && content[*pos] && content[*pos] != '>') {
        if (Extract_Attribute(content, pos, attr_name, attr_value, sizeof(attr_value))) {
            if (my_strcmp(attr_name, "cx") == 0)
                circle->cx = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "cy") == 0)
                circle->cy = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "r") == 0)
                circle->rx = Parse_Int(attr_value);
        } else {
            (*pos)++;
        }
    }

    if (*pos < size && content[*pos] == '>') (*pos)++;
    return circle;
}

Ellipse* Parse_Ellipse_Element(const char* content, int* pos, long size) {
    Ellipse* ellipse = malloc(sizeof(Ellipse));
    if (!ellipse) return NULL;

    ellipse->circle = malloc(sizeof(Circle));
    if (!ellipse->circle) {
        free(ellipse);
        return NULL;
    }
    ellipse->circle->cx = 0;
    ellipse->circle->cy = 0;
    ellipse->circle->rx = 0;
    ellipse->ry = 0;

    char attr_name[128], attr_value[256];

    while (*pos < size && content[*pos] && content[*pos] != '>') {
        if (Extract_Attribute(content, pos, attr_name, attr_value, sizeof(attr_value))) {
            if (my_strcmp(attr_name, "cx") == 0)
                ellipse->circle->cx = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "cy") == 0)
                ellipse->circle->cy = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "rx") == 0)
                ellipse->circle->rx = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "ry") == 0)
                ellipse->ry = Parse_Int(attr_value);
        } else {
        (*pos)++;
        }
    }

    if (*pos < size && content[*pos] == '>') (*pos)++;
    return ellipse;
}

Line* Parse_Line_Element(const char* content, int* pos, long size) {
    Line* line = malloc(sizeof(Line));
    if (!line) return NULL;

    line->x1 = line->y1 = line->x2 = line->y2 = 0;

    char attr_name[128], attr_value[256];

    while (*pos < size && content[*pos] && content[*pos] != '>') {
        if (Extract_Attribute(content, pos, attr_name, attr_value, sizeof(attr_value))) {
            if (my_strcmp(attr_name, "x1") == 0)
                line->x1 = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "y1") == 0)
                line->y1 = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "x2") == 0)
                line->x2 = Parse_Int(attr_value);
            else if (my_strcmp(attr_name, "y2") == 0)
                line->y2 = Parse_Int(attr_value);
        } else {
            (*pos)++;
        }
    }

    if (*pos < size && content[*pos] == '>') (*pos)++;
    return line;
}

Head* Parse_Polyline_Element(const char* content, int* pos, long size) {
    if (!content || !pos || *pos >= size)
    return NULL;

    Head* head = malloc(sizeof(Head));
    if (!head)
    return NULL;
    head->start = NULL;

    char attr_name[128], attr_value[1024];

    while (*pos < size && content[*pos] && content[*pos] != '>') {
        if (Extract_Attribute(content, pos, attr_name, attr_value, sizeof(attr_value))) {

            if (my_strcmp(attr_name, "points") == 0) {
                int i = 0;
                while (attr_value[i]) {

                    // Saut des espaces et des seps...
                    while (attr_value[i] && (isspace(attr_value[i]) || attr_value[i] == ',')) i++;

                    int start = i;
                    while (attr_value[i] && attr_value[i] != ',' && !isspace(attr_value[i])) i++;
                    if (attr_value[i] == '\0') break;
                    attr_value[i] = '\0';
                    int x = Parse_Int(&attr_value[start]); //le x
                    attr_value[i] = ','; // on restaure pour la suite
                    i++;

                    //Encore un saut d'espace..faut rev'nir ap pour faire une fonction pour cà du coup
                    while (attr_value[i] && (isspace(attr_value[i]) || attr_value[i] == ',')) i++;

                    start = i;
                    while (attr_value[i] && !isspace(attr_value[i]) && attr_value[i] != ',') i++;
                    char temp = attr_value[i];
                    attr_value[i] = '\0';
                    int y = Parse_Int(&attr_value[start]);
                    attr_value[i] = temp;

                    LinkPoint* new_point = malloc(sizeof(LinkPoint));
                    if (!new_point) break;
                    new_point->x = x;
                    new_point->y = y;
                    new_point->next = NULL;
                    new_point->previous = NULL;

                    if (!head->start) {
                        head->start = new_point;
                    } else {
                        LinkPoint* current = head->start;
                        while (current->next)
                            current = current->next;
                        current->next = new_point;
                        new_point->previous = current;
                    }
                }
            }

        } else {
            (*pos)++;
        }
    }

    if (*pos < size && content[*pos] == '>') (*pos)++;

    return head;
}

void Parse_Path_Command(char cmd, const char* data, HeadPath* path) {
    if (!path || !data) return;

    Node* node = NULL;
    int x = 0, y = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    switch (cmd) {
        case 'M': case 'm':
            if (sscanf(data, "%d %d", &x, &y) == 2) {
                node = Create_new_path_element(MOVE_TO);
                if (node) {
                    node->path_element->current_command.move_to->p->x = x;
                    node->path_element->current_command.move_to->p->y = y;
                }
            }
            break;

        case 'L': case 'l':
            if (sscanf(data, "%d %d", &x, &y) == 2) {
                node = Create_new_path_element(LINE_TO);
                if (node) {
                    node->path_element->current_command.line_to->p->x = x;
                    node->path_element->current_command.line_to->p->y = y;
                }
            }
            break;

        case 'H': case 'h':
            if (sscanf(data, "%d", &x) == 1) {
                node = Create_new_path_element(H_LINE_TO);
                if (node) node->path_element->current_command.h_line_to->x = x;
            }
            break;

        case 'V': case 'v':
            if (sscanf(data, "%d", &y) == 1) {
                node = Create_new_path_element(V_LINE_TO);
                if (node) node->path_element->current_command.v_line_to->x = y;
            }
            break;

        case 'C': case 'c':
            if (sscanf(data, "%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x, &y) == 6) {
                node = Create_new_path_element(CUBIC_CURVE);
                if (node) {
                    node->path_element->current_command.cubic_curve->point1->x = x1;
                    node->path_element->current_command.cubic_curve->point1->y = y1;
                    node->path_element->current_command.cubic_curve->point2->x = x2;
                    node->path_element->current_command.cubic_curve->point2->y = y2;
                    node->path_element->current_command.cubic_curve->point3->x = x;
                    node->path_element->current_command.cubic_curve->point3->y = y;
                }
            }
            break;

        case 'S': case 's':
            if (sscanf(data, "%d %d %d %d", &x2, &y2, &x, &y) == 4) {
                node = Create_new_path_element(SMOOTH_CUBIC_CURVE);
                if (node) {
                    node->path_element->current_command.smooth_cubic_curve->point1->x = x2;
                    node->path_element->current_command.smooth_cubic_curve->point1->y = y2;
                    node->path_element->current_command.smooth_cubic_curve->point2->x = x;
                    node->path_element->current_command.smooth_cubic_curve->point2->y = y;
                }
            }
            break;

        case 'Q': case 'q':
            if (sscanf(data, "%d %d %d %d", &x1, &y1, &x, &y) == 4) {
                node = Create_new_path_element(QUADRA_CURVE);
                if (node) {
                    node->path_element->current_command.quadra_curve->point1->x = x1;
                    node->path_element->current_command.quadra_curve->point1->y = y1;
                    node->path_element->current_command.quadra_curve->point2->x = x;
                    node->path_element->current_command.quadra_curve->point2->y = y;
                }
            }
            break;

        case 'T': case 't': 
            if (sscanf(data, "%d %d", &x, &y) == 2) {
                node = Create_new_path_element(SMOOTH_QUADRA_CURVE);
                if (node) {
                    node->path_element->current_command.smooth_quadra_curve->p->x = x;
                    node->path_element->current_command.smooth_quadra_curve->p->y = y;
                }
            }
            break;

        case 'Z': case 'z':
            node = Create_new_path_element(CLOSE);
            break;
    }

    if (node) Add_path_element(path, node);
}

HeadPath* Parse_Path_Attribute(const char* path_data) {
    if (!path_data) return NULL;

    int len = 0;
    while (path_data[len] != '\0') {
        len++;
    }


    HeadPath* path = Create_new_path();
    if (!path) return NULL;

    int pos = 0;

    while (pos < len) {
        Skip_Whitespace(path_data, &pos);
        if (pos >= len) break;

        char cmd = path_data[pos++];
        if (!isalpha(cmd)) continue;

        char data[512];
        int data_len = 0;
        while (pos < len && !isalpha(path_data[pos]) && data_len < (int)sizeof(data) - 1) {
            data[data_len++] = path_data[pos++];
        }
        data[data_len] = '\0';

        Parse_Path_Command(cmd, data, path);
    }

    return path;
}



Svg* Parse_Svg_File(const char* filename) {
    if (!Is_Svg_File(filename)) {
        printf("LE fichier '%s' n'est pas un fichier SVG\n", filename);
        return NULL;
    }
    
    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("échec d'ouverture ! '%s'\n", filename);
        return NULL;
    }

    Parser_progress_bar_animation(2);
    sleep(1);
    // system("clear");
    
    fseek(f, 0, SEEK_END);
    long size = ftell(f); //Taille du fichier
    fseek(f, 0, SEEK_SET);
    
    
    char* content = malloc(size + 1);
    if (!content) {
        fclose(f);
        return NULL;
    }
    fread(content, 1, size, f);
    content[size] = '\0';
    fclose(f);
    
    Svg* svg = Create_new_svg();
    if (!svg) { free(content); return NULL; }
    
    int pos = 0;
    
    Skip_Until_Char(content, &pos, '<', size);
    pos++;
    
    if (content[pos] == '!' || content[pos] == '?') {
        Skip_Until_Char(content, &pos, '>', size); //Faut l'mettre en fonction après.. histoire de skip les caractères de comms
        pos++;
    }
    
    char tag[32];
    int tag_len = 0;
    while (content[pos] && !isspace(content[pos]) && content[pos] != '>') {
        tag[tag_len++] = content[pos++];
    }tag[tag_len] = '\0';
    
    //Parsing de l'SVG m^me
    if (my_strcmp(tag, "svg") == 0) {
        char attr_name[128], attr_value[256];
        while (content[pos] && content[pos] != '>') {
            if (Extract_Attribute(content, &pos, attr_name, attr_value, 256)) {
                if (my_strcmp(attr_name, "width") == 0)
                    svg->width = Parse_Int(attr_value);
                else if (my_strcmp(attr_name, "height") == 0)
                    svg->height = Parse_Int(attr_value);
            }
        }
    }
    
    pos++;  //Juste histoire d'être sur que je passe au dessus du dernier >.

    Style* style = Create_style();
    
    while (pos < size) {
        Skip_Whitespace(content, &pos);
        
        if (pos >= size || content[pos] != '<') break;
        pos++;
        
        if (pos >= size || content[pos] == '/') break;
        
        //là il vaut mieux prendre le mot clé pour faire la reccherche au lieu de tout reprendre à chaque fois
        tag_len = 0;
        while (pos < size && content[pos] && !isspace(content[pos]) && content[pos] != '>') {
            tag[tag_len++] = content[pos++];
        }
        tag[tag_len] = '\0';
        
        
        if (my_strcmp(tag, "rect") == 0) {
            Rect* rect = Parse_Rect_Element(content, &pos, size);
            if (rect) {
               Rect_loop(rect, style);
            }
        }
        else if (my_strcmp(tag, "circle") == 0) {
            Circle* circle = Parse_Circle_Element(content, &pos, size);
            if (circle) {
                Circle_loop(circle, style);
            }
        }
        else if (my_strcmp(tag, "ellipse") == 0) {
            Ellipse* ellipse = Parse_Ellipse_Element(content, &pos, size);
            if (ellipse) {
                Ellipse_loop(ellipse, style);
            }
        }
        else if (my_strcmp(tag, "line") == 0) {
            Line* line = Parse_Line_Element(content, &pos, size);
            if (line) {
                Line_loop(line, style);
            }
        }

        else if (my_strcmp(tag, "polyline") == 0) {
            Head* polyline = Parse_Polyline_Element(content, &pos, size);
            if (polyline && polyline->start) {
                Polyline_loop(polyline, style);
            }
        }

        else if (my_strcmp(tag, "polygon") == 0) {
            Head* polyline = Parse_Polyline_Element(content, &pos, size);
            if (polyline && polyline->start) {
                Polygone_loop(polyline, style);
            }
        }

        else if (my_strcmp(tag, "path") == 0) {
            char attr_name[128], attr_value[1024];
            HeadPath* path = NULL;
            
            while (content[pos] && content[pos] != '>' && pos < size) {
                if (Extract_Attribute(content, &pos, attr_name, attr_value, 1024)) {
                    if (my_strcmp(attr_name, "d") == 0) {
                        path = Parse_Path_Attribute(attr_value);
                    }
                }
            }
            if(path)
            Path_loop(path, style);
        }
        
        Skip_Until_Char(content, &pos, '>', size);
        if (pos < size) pos++; 
    }
    
    free(content);
    return svg;
}




void Parser() {

    system("clear");

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│         P A R S E R.         │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
    
 
    char name[50];
    char access[100];

    printf(BRIGHT_GREEN"\nEntrez le nom du fichier : ");
    scanf("%49s", name);

    snprintf(access, sizeof(access), "../Generated_Files/%s.svg", name);

    
    Svg* svg = Parse_Svg_File(access);
    if (svg) {
        // printf("\nParsing réussi!\n");
        Destroy_svg(svg);
        
    } else {
       return;
    }

    system("clear");

}