#include "./main.h"
#include <unistd.h>

int First_menu() {
    system("clear");
    printf("\n");
    if (kbhit()) while(kbhit()) getchar();
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        MENU PRINCIPAL        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Créer une forme\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Charger une forme\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Quitter\n\n");

    return Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 3);
}

int Second_menu() {
    printf("\n\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        MENU DE FORMES        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier la forme\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Styliser la forme\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Exporter la forme\n");
    printf(BRIGHT_CYAN"  4)"RESET_STYLE" Supprimer la forme\n\n");

    return Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 4);
}
int Second_menu_incomplete() {
    printf("\n\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        MENU DE FORMES        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    // printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier la forme\n");
    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Styliser la forme\n");
    // printf(BRIGHT_CYAN"  3)"RESET_STYLE" Exporter la forme\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Supprimer la forme\n\n");

    return Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 2);
}

int Menu_shapes() {
    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     CRÉATION DE FORMES       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Cercle\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Ellipse\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Rectangle\n");
    printf(BRIGHT_CYAN"  4)"RESET_STYLE" Carré\n");
    printf(BRIGHT_CYAN"  5)"RESET_STYLE" Ligne\n");
    printf(BRIGHT_CYAN"  6)"RESET_STYLE" Polygone\n");
    printf(BRIGHT_CYAN"  7)"RESET_STYLE" Polyligne\n");
    printf(BRIGHT_CYAN"  8)"RESET_STYLE" Path\n");
    printf(BRIGHT_CYAN"  9)"RESET_STYLE" Groupe\n");
    printf(BRIGHT_CYAN" 10)"RESET_STYLE" Retour\n\n");

    return Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez la forme à créer : "RESET_STYLE, 1, 10);
}

void Circle_loop(Circle* circle, Style* style) {
    int second_choice = 0;
    while (1)
    {
        system("clear");
        Display_circle(circle);
        Display_style(style);
        second_choice = Second_menu();
        switch (second_choice) {
            case MODIFIER:
                Modify_circle(circle);
                break;

            case STYLISER:
                Recup_style_data(style);
                break;

            case EXPORTER:
                Auto_write(BRIGHT_GREEN"\nLancement de l'exportation...\n"RESET_STYLE, 30000);
                sleep(1);
                Export_circle(circle, style);
                break;

            case SUPPRIMER:
                Destroy_circle(circle);
                Destroy_style(style);
                Auto_write(BRIGHT_RED"\nForme supprimée."RESET_STYLE, 30000);
                Auto_write(BRIGHT_YELLOW"\n\nRetour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
                return;

            default:
                printf("INVALID ! Comment t'as fait pour atterir ici ?");
            break;
        }
    }
}
void Circle_edit_universe() {
    Circle* circle = Create_circle(0, 0, 0);
    Style* style = Create_style();

    system("clear");
    Recup_circle_data(circle);
   
    Circle_loop(circle, style);
    
}


void Ellipse_loop(Ellipse* ellipse, Style* style) {
    int second_choice = 0;
    while (1)
    {
        system("clear");
        Display_ellipse(ellipse);
        Display_style(style);
        second_choice = Second_menu();
        switch (second_choice) {
            case MODIFIER:
                Modify_ellipse(ellipse);
                break;

            case STYLISER:
                Recup_style_data(style);
                break;

            case EXPORTER:
                Auto_write(BRIGHT_GREEN"\nLancement de l'exportation...\n"RESET_STYLE, 30000);
                sleep(1);
                Export_ellipse(ellipse, style);
                break;

            case SUPPRIMER:
                Destroy_ellipse(ellipse);
                Destroy_style(style);
                Auto_write(BRIGHT_RED"\nForme supprimée."RESET_STYLE, 30000);
                Auto_write(BRIGHT_YELLOW"\n\nRetour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
                return;

            default:
                printf("INVALID ! Comment t'as fait pour atterir ici ?");
            break;
        }
    }
}
void Ellipse_edit_universe() {
    Ellipse* ellipse = Create_ellipse(0, 0, 0, 0);
    Style* style = Create_style();

    system("clear");
    Recup_ellipse_data(ellipse);
   
    Ellipse_loop(ellipse, style);
}


void Rect_loop(Rect* rect, Style* style) {
    int second_choice = 0;
    while (1)
    {
        system("clear");
        Display_rect(rect);
        Display_style(style);
        second_choice = Second_menu();
        switch (second_choice) {
            case MODIFIER:
                Modify_rect(rect);
                break;

            case STYLISER:
                Recup_style_data(style);
                break;

            case EXPORTER:
                Auto_write(BRIGHT_GREEN"\nLancement de l'exportation...\n"RESET_STYLE, 30000);
                sleep(1);
                Export_rect(rect, style);
                break;

            case SUPPRIMER:
                Destroy_rect(rect);
                Destroy_style(style);
                Auto_write(BRIGHT_RED"\nForme supprimée."RESET_STYLE, 30000);
                Auto_write(BRIGHT_YELLOW"\n\nRetour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
                return;

            default:
                printf("INVALID ! Comment t'as fait pour atterir ici ?");
            break;
        }
    }
}
void Rect_edit_universe() {
    Rect* rect = Create_rect(0, 0, 0, 0, 0);
    Style* style = Create_style();

    system("clear");
    Recup_rect_data(rect);
   
    Rect_loop(rect, style);
}


void Square_edit_universe() {
    Rect* square = Create_square(0, 0, 0, 0);
    Style* style = Create_style();

    int second_choice = 0;
    system("clear");
    Recup_square_data(square);
   
    while (1)
    {
        system("clear");
        Display_square(square);
        Display_style(style);
        second_choice = Second_menu();
        switch (second_choice) {
            case MODIFIER:
                Modify_square(square);
                break;

            case STYLISER:
                Recup_style_data(style);
                break;

            case EXPORTER:
                Auto_write(BRIGHT_GREEN"\nLancement de l'exportation...\n"RESET_STYLE, 30000);
                sleep(1);
                Export_square(square, style);
                break;

            case SUPPRIMER:
                Destroy_square(square);
                Destroy_style(style);
                Auto_write(BRIGHT_RED"\nForme supprimée."RESET_STYLE, 30000);
                Auto_write(BRIGHT_YELLOW"\n\nRetour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
                return;

            default:
                printf("INVALID ! Comment t'as fait pour atterir ici ?");
            break;
        }
    }
}


void Line_loop(Line* line, Style* style) {
    int second_choice = 0;

    while (1)
    {
        system("clear");
        Display_line(line);
        Display_style(style);
        second_choice = Second_menu();
        switch (second_choice) {
            case MODIFIER:
                Modify_line(line);
                break;

            case STYLISER:
                Recup_style_data(style);
                break;

            case EXPORTER:
                Auto_write(BRIGHT_GREEN"\nLancement de l'exportation...\n"RESET_STYLE, 30000);
                sleep(1);
                Export_line(line, style);
                break;

            case SUPPRIMER:
                Destroy_line(line);
                Destroy_style(style);
                Auto_write(BRIGHT_RED"\nForme supprimée."RESET_STYLE, 30000);
                Auto_write(BRIGHT_YELLOW"\n\nRetour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
                return;

            default:
                printf("INVALID ! Comment t'as fait pour atterir ici ?");
            break;
        }
    }
}
void Line_edit_universe() {
    Line* line = Create_line(0, 0, 0, 0);
    Style* style = Create_style();

    system("clear");
    Recup_line_data(line);
   
    Line_loop(line, style);
}


void Polyline_loop(Head* head, Style* style) {
    int second_choice = 0;
    while (1)
    {
        system("clear");
        Display_polyline(head);
        Display_style(style);
        second_choice = Second_menu();
        switch (second_choice) {
            case MODIFIER:
                Modify_polyline(head);
                break;

            case STYLISER:
                Recup_style_data(style);
                break;

            case EXPORTER:
                Auto_write(BRIGHT_GREEN"\nLancement de l'exportation...\n"RESET_STYLE, 30000);
                sleep(1);
                Export_polyline(head, style);
                break;

            case SUPPRIMER:
                Destroy_polyline(head);
                Destroy_style(style);
                Auto_write(BRIGHT_RED"\nForme supprimée."RESET_STYLE, 30000);
                Auto_write(BRIGHT_YELLOW"\n\nRetour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
                return;

            default:
                printf("INVALID ! Comment t'as fait pour atterir ici ?");
            break;
        }
    }
}
void Polyline_edit_universe() {
    Head* head = Create_new_polyline();
    Style* style = Create_style();

    system("clear");
    Recup_polyline_data(head);
   
    Polyline_loop(head, style);
}


void Path_loop(HeadPath* head, Style* style) {
    int second_choice = 0;
    while (1)
    {
        system("clear");
        Display_path_list(head);
        Display_style(style);
        second_choice = Second_menu();
        switch (second_choice) {
            case MODIFIER:
                Modify_path(head);
                break;

            case STYLISER:
                Recup_style_data(style);
                break;

            case EXPORTER:
                Auto_write(BRIGHT_GREEN"\nLancement de l'exportation...\n"RESET_STYLE, 30000);
                sleep(1);
                Export_path(head, style);
                break;

            case SUPPRIMER:
                Destroy_path(head);
                Destroy_style(style);
                Auto_write(BRIGHT_RED"\nForme supprimée."RESET_STYLE, 30000);
                Auto_write(BRIGHT_YELLOW"\n\nRetour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
                return;

            default:
                printf("INVALID ! Comment t'as fait pour atterir ici ?");
            break;
        }
    }
}
void Path_edit_universe() {
    HeadPath* head = Create_new_path();
    Style* style = Create_style();

    system("clear");
    
    Recup_path_data(head);
   
    Path_loop(head, style);
}

void Polygone_loop(Head* head, Style* style) {
    int second_choice = 0;
    while (1)
    {
        system("clear");
        Display_polygone(head);
        Display_style(style);
        second_choice = Second_menu();
        switch (second_choice) {
            case MODIFIER:
                Modify_polygone(head);
                break;

            case STYLISER:
                Recup_style_data(style);
                break;

            case EXPORTER:
                Auto_write(BRIGHT_GREEN"\nLancement de l'exportation...\n"RESET_STYLE, 30000);
                sleep(1);
                Export_polygone(head, style);
                break;

            case SUPPRIMER:
                Destroy_polyline(head);
                Destroy_style(style);
                Auto_write(BRIGHT_RED"\nForme supprimée."RESET_STYLE, 30000);
                Auto_write(BRIGHT_YELLOW"\n\nRetour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
                return;

            default:
                printf("INVALID ! Comment t'as fait pour atterir ici ?");
            break;
        }
    }
}
void Polygone_edit_universe() {
    Head* head = Create_new_polyline();
    Style* style = Create_style();

    system("clear");
    Recup_polygone_data(head);
   
    Polygone_loop(head, style);
}


void Group_loop(Group* group, Style* style) {
    int second_choice = 0;
    while (1)
    {
        system("clear");
        Display_group(group);
        Display_style(style);
        second_choice = Second_menu_incomplete();
        switch (second_choice) {

            case 1:
                Recup_style_data(style);
                break;

            case 2:
                Destroy_group(group);
                Destroy_style(style);
                Auto_write(BRIGHT_RED"\nForme supprimée."RESET_STYLE, 30000);
                Auto_write(BRIGHT_YELLOW"\n\nRetour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
                return;

            default:
                printf("INVALID ! Comment t'as fait pour atterir ici ?");
            break;
        }
    }
}
void Group_edit_universe() {
    Group* group = Create_new_group();
    Style* style = Create_style();

    system("clear");
    
    Recup_group_data(group);
   
    Group_loop(group, style);
}


void Create_bloc() {
    int shape_choice = 0;
    while (1)
    {
        shape_choice = Menu_shapes();
        // system("clear");
        switch (shape_choice) {
            case SHAPE_CIRCLE:
                Circle_edit_universe();
            break;

            case SHAPE_ELLIPSE:
                Ellipse_edit_universe();
            break;

            case SHAPE_RECTANGLE:
                Rect_edit_universe();
            break;

            case SHAPE_SQUARE:
                Square_edit_universe();
            break;

            case SHAPE_LINE:
                Line_edit_universe();
            break;

            case SHAPE_POLYGON:
                Polygone_edit_universe();
            break;

            case SHAPE_POLYLINE:
                Polyline_edit_universe();
            break;

            case SHAPE_PATH:
                Path_edit_universe();
            break;

            case SHAPE_GROUP:
                Group_edit_universe();
            break;

            case OUT:
                Auto_write(BRIGHT_YELLOW"\nRetour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
            return;

            default:
                Auto_write(BRIGHT_RED"\nCette forme n’est pas encore disponible.\n", 25000);
                sleep(1);
            break;
        }
    }
}

int main(void) {

    system("clear");
    Auto_write(BRIGHT_CYAN"Bienvenue dans l'éditeur en CLI NOAH-SVG.\n"RESET_STYLE, 35000);
    Auto_write("Chargement de l’environnement...", 40000);
    sleep(1);
    system("clear");

   int first_menu_choice = 0;
   while (1) {
       first_menu_choice = First_menu();

       switch (first_menu_choice) {
           case CREER:
               Create_bloc();
               break;

           case CHARGER:
                Parser();
            //    Auto_write(BRIGHT_YELLOW"\nFonction de chargement en développement...\n"RESET_STYLE, 35000);
               sleep(1);
               break;

           case QUITTER_FIRST:
               Auto_write(BRIGHT_RED"\nFermeture du programme...\n\n"RESET_STYLE, 30000);
               sleep(1);
               return 0;

           default:
               Print_in_red("Choix invalide. Réessayez.\n");
               sleep(1);
               break;
       }
   }

    return EXIT_SUCCESS;
}
