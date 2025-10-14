#include "./main.h"
#include <unistd.h>

// ==========================================================
// FONCTIONS DE MENUS
// ==========================================================

int First_menu() {
    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        MENU PRINCIPAL        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("  1) Créer une forme\n");
    printf("  2) Charger une forme\n");
    printf("  3) Quitter\n\n");

    return Int_recup_verify("Votre choix : ");
}

int Second_menu() {
    printf("\n\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        MENU DE FORMES        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("  1) Modifier la forme\n");
    printf("  2) Styliser la forme\n");
    printf("  3) Exporter la forme\n");
    printf("  4) Supprimer la forme\n");
    printf("  5) Fermer la session\n");
    printf("  6) Quitter\n\n");

    return Int_recup_verify("Votre choix : ");
}

int Menu_shapes() {
    system("clear");
    printf("\n");
    printf(BOLD_WHITE_TEXT"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BOLD_WHITE_TEXT"│     CRÉATION DE FORMES       │\n"RESET_STYLE);
    printf(BOLD_WHITE_TEXT"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Cercle\n");
    printf("  2) Ellipse\n");
    printf("  3) Rectangle\n");
    printf("  4) Carré\n");
    printf("  5) Ligne\n");
    printf("  6) Polygone\n");
    printf("  7) Polyligne\n");
    printf("  8) Path\n");
    printf("  9) Groupe\n");

    return Int_recup_verify(BRIGHT_GREEN"\nChoisissez la forme à créer : "RESET_STYLE);
}

// ==========================================================
// ENUMS
// ==========================================================
typedef enum AllShapesEnum_E {
    SHAPE_CIRCLE = 1,
    SHAPE_ELLIPSE,
    SHAPE_RECTANGLE,
    SHAPE_SQUARE,
    SHAPE_LINE,
    SHAPE_POLYGON,
    SHAPE_POLYLINE,
    SHAPE_PATH,
    SHAPE_GROUP
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
    SUPPRIMER,
    FERMER_SESSION,
    QUITTER_SECOND
} SecondMenu;

// ==========================================================
// MAIN
// ==========================================================

void Circle_edit_universe() {

    Circle* circle = Create_circle(0, 0, 0);
    Style* style = Create_style();

    int second_choice = 0;
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

            case STYLISER: {
                Recup_style_data(style);
                // Display_circle(circle);
                // Display_style(style);
                // sleep(10);
                break;
            }

            case EXPORTER:
                Auto_write(BRIGHT_GREEN"\nExport de la forme en cours...\n"RESET_STYLE, 30000);
                sleep(1);
                break;

            case SUPPRIMER:
                Destroy_circle(circle);
                Destroy_style(style);
                Auto_write(RED"\nForme supprimée.\n"RESET_STYLE, 30000);
                sleep(1);
                break;

            case FERMER_SESSION: //C'est lui qui dead tout normalement
                Destroy_circle(circle);
                Destroy_style(style);
                Auto_write(YELLOW"\nSession fermée. Retour au menu principal...\n"RESET_STYLE, 30000);
                sleep(1);
                break;

            case QUITTER_SECOND:
                Destroy_circle(circle);
                Destroy_style(style);
                Auto_write(BRIGHT_RED"\nFermeture du programme d'édition de cercle...\n"RESET_STYLE, 50000);
                return;

            default:
                Print_in_bright_red("Choix invalide");
            break;


        }
    }
    
    
    // Destroy_circle(circle);
    // Destroy_style(style);
}

int main(void) {
    system("clear");
    Auto_write(BRIGHT_CYAN"\nBienvenue dans votre éditeur SVG en CLI.\n"RESET_STYLE, 5000);
    Auto_write("Chargement de l’environnement...", 40000);
    sleep(1);
    system("clear");

    int first_menu_choice = 0;
    int shape_choice = 0;
    

    while (1) {
        first_menu_choice = First_menu();

        switch (first_menu_choice) {
            // -----------------------------------------------
            // CREATION DE FORMES
            // -----------------------------------------------
            case CREER: {
                shape_choice = Menu_shapes();
                system("clear");
                switch (shape_choice) {
                    case SHAPE_CIRCLE: {
                       
                        Circle_edit_universe();
                        break;
                    }//FIN CERCLE

                    default:
                        Auto_write(BRIGHT_RED"\nCette forme n’est pas encore disponible.\n", 25000);
                        sleep(1);
                        break;
                }
            break;
            }

            // -----------------------------------------------
            // CHARGEMENT
            // -----------------------------------------------
            case CHARGER:
                Auto_write(BRIGHT_YELLOW"\nFonction de chargement en développement...\n"RESET_STYLE, 35000);
                sleep(1);
                break;

            // -----------------------------------------------
            // QUITTER
            // -----------------------------------------------
            case QUITTER_FIRST:
                Auto_write(BRIGHT_RED"\nFermeture du programme...\n"RESET_STYLE, 30000);
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
