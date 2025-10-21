#include "./groupe.h"

void Infos_group() {
    system("clear");
    printf(CYAN BOLD_WHITE_TEXT"\n╭─────────────────────────────╮\n");
    printf("│        INFOS : GROUPE       │\n");
    printf("╰─────────────────────────────╯\n\n"RESET_STYLE);
    printf("L'élément "BOLD_WHITE_TEXT"'Group'"RESET_STYLE" permet de regrouper plusieurs formes SVG en une seule entité logique.\n");
    printf("Cela vous permet de manipuler plusieurs formes ensemble : déplacement, suppression, etc.\n\n");
    printf("Chaque groupe peut contenir : cercles, rectangles, ellipses, lignes, chemins,\n");
    printf("polygones, polylignes ou même d'autres groupes.\n\n");
    printf(BRIGHT_BLACK"Exemple SVG :\n");
    printf("  <g>\n");
    printf("     <circle cx=\"50\" cy=\"50\" r=\"40\" />\n");
    printf("     <rect x=\"100\" y=\"100\" width=\"80\" height=\"40\" />\n");
    printf("  </g>\n\n"RESET_STYLE);
}

void Infos_group_usage() {
    printf(CYAN"\n╭────────────────────────────╮\n");
    printf("│     UTILISATION DU GROUPE  │\n");
    printf("╰────────────────────────────╯\n\n"RESET_STYLE);
    printf("Un groupe vous permet de créer des ensembles de plusieurs formes.\n");
    printf("Vous pouvez les afficher, les parcourir ou les supprimer facilement.\n\n");
}

int Menu_group_shapes() {
    system("clear");
    printf(CYAN BOLD_WHITE_TEXT"\n╭──────────────────────────╭\n");
    printf("│     MENU DES FORMES      │\n");
    printf("╰──────────────────────────╯\n\n"RESET_STYLE);
    printf(" "CYAN"1)"RESET_STYLE" Cercle\n");
    printf(" "CYAN"2)"RESET_STYLE" Ellipse\n");
    printf(" "CYAN"3)"RESET_STYLE" Rectangle\n");
    printf(" "CYAN"4)"RESET_STYLE" Carré\n");
    printf(" "CYAN"5)"RESET_STYLE" Ligne\n");
    printf(" "CYAN"6)"RESET_STYLE" Polygone\n");
    printf(" "CYAN"7)"RESET_STYLE" Polyligne\n");
    printf(" "CYAN"8)"RESET_STYLE" Path\n");
    printf(" "CYAN"9)"RESET_STYLE" Groupe imbriqué\n\n");

    return Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 9);
}

void Display_group_indent(Group* group, int indent_level) {
    if (!Does_group_exist(group)) return;

    GroupNode* node = group->start;
    int index = 1;

    // indentation
    for (int i = 0; i < indent_level; i++) printf("   ");

    printf(BRIGHT_CYAN"📁 Groupe : "RESET_STYLE BOLD_WHITE_TEXT"%s\n"RESET_STYLE, group->name);

    if (!node) {
        for (int i = 0; i <= indent_level; i++) printf("   ");
        printf(BRIGHT_BLACK"(vide)\n"RESET_STYLE);
        return;
    }

    while (node != NULL) {
        for (int i = 0; i <= indent_level; i++) printf("   ");
        printf(GREEN"├── "RESET_STYLE);

        switch (node->node->shapes) {
            case CIRCLE:
                printf(BRIGHT_MAGENTA"● Cercle\n"RESET_STYLE);
                break;
            case ELLIPSE:
                printf(BRIGHT_MAGENTA"⬭ Ellipse\n"RESET_STYLE);
                break;
            case RECTANGLE:
                printf(BRIGHT_MAGENTA"▭ Rectangle\n"RESET_STYLE);
                break;
            case SQUARE:
                printf(BRIGHT_MAGENTA"■ Carré\n"RESET_STYLE);
                break;
            case LINE:
                printf(BRIGHT_MAGENTA"─ Ligne\n"RESET_STYLE);
                break;
            case PATH:
                printf(BRIGHT_MAGENTA"⚙ Path\n"RESET_STYLE);
                break;
            case POLYGON:
                printf(BRIGHT_MAGENTA"⬡ Polygone\n"RESET_STYLE);
                break;
            case POLYLINE:
                printf(BRIGHT_MAGENTA"〰 Polyligne\n"RESET_STYLE);
                break;
            case GROUP:
                printf(BRIGHT_CYAN"📂 Sous-groupe :\n"RESET_STYLE);
                Display_group_indent(node->node->current_shapes.group, indent_level + 1);
                break;
            default:
                printf(RED"❓ Forme inconnue\n"RESET_STYLE);
                break;
        }
        node = node->next;
        index++;
    }

    for (int i = 0; i < indent_level; i++) printf("   ");
    printf(BRIGHT_BLACK"╰───────────────\n"RESET_STYLE);
}

void Display_group(Group* group) {
    if(!Does_group_exist(group)) {
        Print_in_red("\nErreur : groupe inexistant.\n");
        return;
    }

    system("clear");
    printf("\n"CYAN BOLD_WHITE_TEXT"╭────────────────────────────────────────────╮\n"RESET_STYLE);
    printf(CYAN"│   "RESET_STYLE"Affichage du groupe : "BOLD_WHITE_TEXT"%s\n"RESET_STYLE, group->name);
    printf(CYAN BOLD_WHITE_TEXT"╰────────────────────────────────────────────╯\n\n"RESET_STYLE);

    Display_group_indent(group, 0);

    printf("\n"CYAN"─────────────── "RESET_STYLE BOLD_WHITE_TEXT"[ FIN DU GROUPE ]"RESET_STYLE CYAN" ───────────────\n\n"RESET_STYLE);
}



Group* Create_new_group() {
    Group* group = malloc(sizeof(Group));
    if(!group) return NULL;
    group->start = NULL;
    return group;
}

GroupElement* Create_new_group_element(Shapes shape_type) {
    GroupElement* element = malloc(sizeof(GroupElement));
    if(!element) return NULL;

    element->shapes = shape_type;

    switch(shape_type) {
        case CIRCLE:    element->current_shapes.circle = Create_circle(0,0,0); break;
        case ELLIPSE:   element->current_shapes.ellipse = Create_ellipse(0,0,0,0); break;
        case RECTANGLE: element->current_shapes.rect = Create_rect(0,0,0,0,0); break;
        case SQUARE:    element->current_shapes.square = Create_square(0,0,0,0); break;
        case LINE:      element->current_shapes.line = Create_line(0,0,0,0); break;
        case PATH:      element->current_shapes.path = Create_new_path(); break;
        case POLYGON:   element->current_shapes.polygone = Create_new_polyline(); break;
        case POLYLINE:  element->current_shapes.polyline = Create_new_polyline(); break;
        case GROUP:     element->current_shapes.group = Create_new_group(); break;

        default: free(element); return NULL;
    }

    return element;
}

GroupNode* Create_new_group_node(GroupElement* element) {
    if(!element) return NULL;
    GroupNode* node = malloc(sizeof(GroupNode));
    if(!node) return NULL;

    node->node = element;
    node->next = NULL;
    node->previous = NULL;

    return node;
}

int Does_group_exist(Group* group) {
    return (group != NULL);
}

int Does_group_node_exist(GroupNode* node) {
    return (node != NULL);
}

int Does_group_element_exist(GroupElement* element) {
    return (element != NULL);
}

void Add_shape_to_group(Group* group, GroupNode* new_node) {
    if(!Does_group_exist(group) || !Does_group_node_exist(new_node)) return;

    if(group->start == NULL) {
        group->start = new_node;
        return;
    }

    GroupNode* node = group->start;
    while(node->next != NULL)
        node = node->next;

    node->next = new_node;
    new_node->previous = node;
}

void Destroy_group_element(GroupElement* element) {
    if(!Does_group_element_exist(element)) return;

    switch(element->shapes) {
        case CIRCLE:    Destroy_circle(element->current_shapes.circle); break;
        case ELLIPSE:   Destroy_ellipse(element->current_shapes.ellipse); break;
        case RECTANGLE: Destroy_rect(element->current_shapes.rect); break;
        case SQUARE:    Destroy_square(element->current_shapes.square); break;
        case LINE:      Destroy_line(element->current_shapes.line); break;
        case PATH:      Destroy_path(element->current_shapes.path); break;
        case POLYGON:   Destroy_polyline(element->current_shapes.polygone); break;
        case POLYLINE:  Destroy_polyline(element->current_shapes.polyline); break;
        case GROUP:     Destroy_group(element->current_shapes.group); break;
        default: break;
    }
    free(element);
}

void Destroy_group_node(GroupNode* node) {
    if(!Does_group_node_exist(node)) return;
    Destroy_group_element(node->node);
    free(node);
}

void Destroy_group(Group* group) {
    if(!Does_group_exist(group)) return;

    GroupNode* node = group->start;
    GroupNode* temp;

    if(node != NULL) {
        while(node->next != NULL) {
            temp = node;
            node = node->next;
            Destroy_group_node(temp);
        }
        Destroy_group_node(node);
    }
    free(group);
}

void Display_group_element(GroupElement* element) {
    if(!Does_group_element_exist(element)) return;

    switch(element->shapes) {
        case CIRCLE:    Display_circle(element->current_shapes.circle); break;
        case ELLIPSE:   Display_ellipse(element->current_shapes.ellipse); break;
        case RECTANGLE: Display_rect(element->current_shapes.rect); break;
        case SQUARE:    Display_square(element->current_shapes.square); break;
        case LINE:      Display_line(element->current_shapes.line); break;
        case PATH:      Display_path(element->current_shapes.path); break;
        case POLYGON:   Display_polygone(element->current_shapes.polygone); break;
        case POLYLINE:  Display_polyline(element->current_shapes.polyline); break;
        case GROUP:     Display_group(element->current_shapes.group); break;
        default: break;
    }
}


void Recup_group_name(Group* group) {
    if(!Does_group_exist(group)) return;

    system("clear");
    printf(BOLD_WHITE_TEXT CYAN"\n=== Création d’un nouveau groupe ===\n"RESET_STYLE);
    printf(BOLD_WHITE_TEXT"\nEntrez le nom de votre groupe : "RESET_STYLE);

    int i = 0;
    char c;
    while(i < 63 && (c = getchar()) != '\n' && c != EOF) {
        group->name[i++] = c;
    }
    group->name[i] = '\0';

    if (group->name[0] == '\0') {
        // Un nom par defaut.
        group->name[0] = 'G';
        group->name[1] = 'r';
        group->name[2] = 'o';
        group->name[3] = 'u';
        group->name[4] = 'p';
        group->name[5] = '\0';
    }

    system("clear");
    printf(GREEN"\n→ Groupe \"%s\" créé avec succès !\n\n"RESET_STYLE, group->name);
}


void Recup_group_data(Group* group) {
    if(!Does_group_exist(group)) return;

    
    Recup_group_name(group);

    int choice = 0;
    int continuer = 1;

    printf("Souhaitez-vous lire la documentation sur les Groupes ? \n");
    printf("Tapez une touche avant la fin du chrono pour skip :  ");
    Chrono(5);
    if (kbhit()) getchar(); else Infos_group();
    
    do {
        choice = Menu_group_shapes();
        system("clear");

        choice--;

        GroupElement* element = Create_new_group_element(choice);
        if(!element) {
            Print_in_red("Erreur de création de la forme.\n");
            return;
        }

        switch(choice) {
            case CIRCLE:    Recup_circle_data(element->current_shapes.circle); break;
            case ELLIPSE:   Recup_ellipse_data(element->current_shapes.ellipse); break;
            case RECTANGLE: Recup_rect_data(element->current_shapes.rect); break;
            case SQUARE:    Recup_square_data(element->current_shapes.square); break;
            case LINE:      Recup_line_data(element->current_shapes.line); break;
            case PATH:      Recup_path_data(element->current_shapes.path); break;
            case POLYGON:   Recup_polygone_data(element->current_shapes.polygone); break;
            case POLYLINE:  Recup_polyline_data(element->current_shapes.polyline); break;
            case GROUP:     Recup_group_data(element->current_shapes.group); break;

            default: Print_in_red("OUT OF RANGE !"); break;
        }

        GroupNode* new_node = Create_new_group_node(element);
        Add_shape_to_group(group, new_node);

        printf("\nSouhaitez-vous ajouter une autre forme au groupe "BRIGHT_CYAN" %s "RESET_STYLE" ?\n", group->name);
        printf(BRIGHT_GREEN"Tapez une touche avant la fin du chrono pour continuer :  "RESET_STYLE);
        continuer = Chrono_assassin(5);

        system("clear");

    } while(!continuer);
}


//  int main(void) {

//      Group* group = Create_new_group();
//      Recup_group_data(group);
//      Display_group(group);
//      Destroy_group(group);

//      return EXIT_SUCCESS;
//   }
