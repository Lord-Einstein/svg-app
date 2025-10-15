#include "./main.h"
#include <unistd.h>

int First_menu() {
    system("clear");
    printf("\n");
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

typedef enum AllShapesEnum_E {
    SHAPE_CIRCLE = 1,
    SHAPE_ELLIPSE,
    SHAPE_RECTANGLE,
    SHAPE_SQUARE,
    SHAPE_LINE,
    SHAPE_POLYGON,
    SHAPE_POLYLINE,
    SHAPE_PATH,
    SHAPE_GROUP,
    OUT
} AllShapesEnum;

typedef enum FirstMenu_E {
    CREER = 1,
    CHARGER,
    QUITTER_FIRST
} FirstMenu;

typedef enum SecondMenu_E {
    MODIFIER = 1,
    STYLISER,
    EXPORTER,
    SUPPRIMER
} SecondMenu;

void Circle_edit_universe() {
    Circle* circle = Create_circle(0, 0, 0);
    Style* style = Create_style();

    int second_choice = 0;
    system("clear");
    Recup_circle_data(circle);
   
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

void Ellipse_edit_universe() {
    Ellipse* ellipse = Create_ellipse(0, 0, 0, 0);
    Style* style = Create_style();

    int second_choice = 0;
    system("clear");
    Recup_ellipse_data(ellipse);
   
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
    Auto_write(BRIGHT_CYAN"\nBienvenue dans l'éditeur en CLI NOAH-SVG.\n"RESET_STYLE, 35000);
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
                Auto_write(BRIGHT_YELLOW"\nFonction de chargement en développement...\n"RESET_STYLE, 35000);
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
