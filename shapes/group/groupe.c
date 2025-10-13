#include "./groupe.h"

// /HOLALA

void Infos_group() {
    system("clear");
    printf("\nL'élément 'Group' permet de regrouper plusieurs formes SVG en une seule entité logique.\n");
    printf("Cela vous permet de manipuler plusieurs formes ensemble : déplacement, suppression, etc.\n\n");
    printf("Chaque groupe peut contenir : cercles, rectangles, ellipses, lignes, chemins, polygones, polylignes ou même d'autres groupes.\n\n");
    printf("Exemple d'équivalent SVG :\n");
    printf("  <g>\n");
    printf("     <circle cx=\"50\" cy=\"50\" r=\"40\" />\n");
    printf("     <rect x=\"100\" y=\"100\" width=\"80\" height=\"40\" />\n");
    printf("  </g>\n\n");
}

void Infos_group_usage() {
    printf("Un groupe vous permet de créer des ensembles de plusieurs formes.\n");
    printf("Vous pouvez les afficher, les parcourir ou les supprimer facilement.\n\n");
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

void Display_group(Group* group) {
    if(!Does_group_exist(group)) {
        Print_in_red("\nGroup not found\n");
        return;
    }

    // system("clear");
    printf("\n\n");
    printf(BOLD_WHITE_TEXT"\n======== "UNDERLINE_WHITE_TEXT CYAN" GROUP "RESET_STYLE BOLD_WHITE_TEXT" ========\n\n"RESET_STYLE);

    GroupNode* node = group->start;
    int index = 1;
    while(node != NULL) {
        printf(GREEN"\nForme n°%d :\n"RESET_STYLE, index++);
        Display_group_element(node->node);
        node = node->next;
    }

    printf(CYAN"\n======================================\n\n"RESET_STYLE);
}

int Menu_group_shapes() {
    printf("\n\r"BOLD_WHITE_TEXT""UNDERLINE_WHITE_TEXT" MENU DE TOUTES LES FORMES DU GROUPE "RESET_STYLE BOLD_WHITE_TEXT"\n\n"RESET_STYLE);
    printf("1) Cercle\n2) Ellipse\n3) Rectangle\n4) Carré\n5) Ligne\n6) Polygone\n7) Polyligne\n8) Path\n9) Groupe imbriqué\n\n");

    return Int_recup_verify("Choisissez la forme à ajouter dans le groupe : ");
}

void Recup_group_data(Group* group) {
    if(!Does_group_exist(group)) return;

    int choice = 0;
    int continuer = 1;

    printf("Souhaitez-vous lire la documentation sur les Groupes ? \n");
    printf("Tapez une touche avant la fin du chrono pour skip :  ");
    Chrono(5);
    if (kbhit()) getchar(); else Infos_group();

    do {
        choice = Menu_group_shapes();

        //Marge en dur.
        if(choice > 9) choice = 9;
        if(choice < 1) choice = 1;

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

        printf("\nSouhaitez-vous ajouter une autre forme au groupe ?\n");
        printf("Tapez une touche avant la fin du chrono pour skip :  ");
        continuer = Chrono_assassin(5);
        // system("clear");

    } while(continuer);

}

int main(void) {

    Group* group = Create_new_group();
    Recup_group_data(group);
    Display_group(group);
    Destroy_group(group);

    return EXIT_SUCCESS;
 }
