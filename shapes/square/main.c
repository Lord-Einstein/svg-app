#include "./main.h"

void Infos_square() {
    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        INFOS CARRE           │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Le saviez-vous ?\n");
    printf("Le 'square' en SVG n'est pas un élément à part, il se base sur "BOLD_WHITE_TEXT"<rect>"RESET_STYLE" avec largeur = longueur.\n\n");

    printf(BRIGHT_CYAN"Paramètres nécessaires :\n"RESET_STYLE);
    printf("  • "BOLD_WHITE_TEXT"x"RESET_STYLE" : Position X du carré (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"y"RESET_STYLE" : Position Y du carré (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"side"RESET_STYLE" : Longueur d'un côté (entier non signé)\n");
    printf("\nParamètre facultatif :\n");
    printf("  • "BOLD_WHITE_TEXT"round"RESET_STYLE" : Rayon de courbure pour des bords arrondis (entier non signé)\n\n");
}

void Recup_square_data(Rect* square) {
    if (!Does_square_exist(square)) return;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│    INITIALISATION CARRE      │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Souhaitez-vous afficher la documentation pour créer un carré ?\n");
    printf("Appuyez sur une touche avant la fin du chrono pour passer :  ");

    Chrono(5);

    if (kbhit()) getchar();
    else Infos_square();

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│      CRÉATION DU CARRE       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    square->x = Int_recup_verify("Entrez la position X du centre : ");
    square->y = Int_recup_verify("Entrez la position Y du centre : ");
    square->height = Unsigned_int_recup_verify("Entrez la longueur des côtés de votre carré (px) : ");
    square->width = square->height;

    printf("\nSouhaitez-vous ajouter des bords arrondis ?\n");
    printf("Appuyez sur une touche avant la fin du chrono pour passer :  ");
    Chrono_without_clear(5);
    Delete_two_lines();

    if (kbhit()) {
        getchar();
        square->round = 0;
    } else {
        square->round = Unsigned_int_recup_verify("Entrez le rayon de l'arrondi de votre carré : ");
    }

    system("clear");
}

Rect* Create_square(int x, int y, unsigned int height, unsigned int round) {
    Rect* square = malloc(sizeof(Rect));
    if (!square) return NULL;

    square->x = x;
    square->y = y;
    square->height = height;
    square->width = height;
    square->round = round;

    return square;
}

int Does_square_exist(Rect* square) {
    if (!square) {
        Print_in_red("\nShape Not Found !\n");
        return 0;
    }
    return 1;
}

void Destroy_square(Rect* square) {
    if (!Does_square_exist(square)) return;
    free(square);
}

void Display_square(Rect* square) {
    if (!Does_square_exist(square)) return;

    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        DONNÉES CARRE         │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("•  Position X : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", square->x);
    printf("•  Position Y : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", square->y);
    printf("•  Longueur d'un côté (px) : "BOLD_WHITE_TEXT"%u"RESET_STYLE"\n", square->height);
    printf("•  Rayon d'arrondi (px) : "BOLD_WHITE_TEXT"%u"RESET_STYLE"\n\n", square->round);
}

int Modify_square_menu() {
    int choice = 0;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     MODIFIER LE CARRE        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier la position X\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier la position Y\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Modifier la longueur d'un côté\n");
    printf(BRIGHT_CYAN"  4)"RESET_STYLE" Modifier le rayon d'arrondi\n");
    printf(BRIGHT_CYAN"  5)"RESET_STYLE" Annuler\n\n");

    choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez la valeur à modifier : "RESET_STYLE, 1, 5);
    Delete_two_lines();
    return choice;
}

void Modify_square(Rect* square) {
    if (!Does_square_exist(square)) return;

    int value = 0, breaker = 0;

    do {
        system("clear");
        Display_square(square);
        value = Modify_square_menu();

        switch (value) {
            case 1:
                square->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                break;
            case 2:
                square->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                break;
            case 3:
                square->height = Unsigned_int_recup_verify(BRIGHT_GREEN"Nouvelle longueur d'un côté (px) : "RESET_STYLE);
                square->width = square->height;
                break;
            case 4:
                square->round = Unsigned_int_recup_verify(BRIGHT_GREEN"Nouveau rayon d'arrondi (px) : "RESET_STYLE);
                break;
            case 5:
                return;
            default:
                Print_in_red("Entrée invalide !");
                break;
        }

        system("clear");
        Display_square(square);

        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│    CONTINUER LES MODIFS ?    │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);

        breaker = Chrono_assassin(5);
        system("clear");

    } while (!breaker);
}

void Export_square(Rect* square, Style* style) {
    if (!Does_square_exist(square)) return;
    if (!Does_style_exist(style)) return;

    int breaker = 0;
    char name[40];
    char file_name[70];
    char command[100];

    system("clear");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     EXPORTATION EN SVG       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Entrez le nom du fichier à exporter : ");
    scanf("%39s", name);
    snprintf(file_name, sizeof(file_name), "../Generated_Files/%s.svg", name);

    Svg* svg = Create_new_svg();
    if (!svg) { Print_in_red("SVG Not Found.\n"); return; }

    system("clear");
    Display_svg(svg);
    Drain_buffer();

    printf(BRIGHT_CYAN"\n╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     FAIRE DES MODIFICATIONS ?│\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
    printf("Souhaitez-vous utiliser les paramètres d'SVG par défaut ?\n");
    printf(BRIGHT_GREEN"Attendez la fin du chrono pour modifier ou appuyez sur une touche avant pour skip :  "RESET_STYLE);

    breaker = Chrono_assassin(5);
    system("clear");

    if (breaker) Modify_svg(svg);

    FILE* write_file = fopen(file_name, "w");
    if (!write_file) {
        Print_in_red("Impossible de créer le fichier.\n");
        Destroy_svg(svg);
        return;
    }

    fprintf(write_file,
        "<svg xmlns=\"%s\" width=\"%u%%\" height=\"%u%%\" viewBox=\"%d %d %u %u\">\n",
        svg->xlmns, svg->width, svg->height,
        svg->view_box->minx, svg->view_box->miny,
        svg->view_box->width, svg->view_box->height );

    fprintf(write_file,
        "  <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" rx=\"%d\" fill=\"rgba(%d,%d,%d,%.2f)\" stroke=\"rgba(%d,%d,%d,%.2f)\" stroke-width=\"%d\"",
        square->x, square->y, square->width, square->height, square->round,
        style->Rf, style->Gf, style->Bf, style->Af,
        style->Rs, style->Gs, style->Bs, style->As,
        style->stroke_width );

    int transform_params = ( style->translate_x || style->translate_y || style->rotation || (style->scale_x != 1) || (style->scale_y != 1) );
    if (transform_params) {
        fprintf(write_file, " transform=\"");
        if (style->translate_x || style->translate_y)
            fprintf(write_file, "translate(%d,%d) ", style->translate_x, style->translate_y);
        if (style->rotation)
            fprintf(write_file, "rotate(%d,%d,%d) ", style->rotation, style->rotation_cx, style->rotation_cy);
        if (style->scale_x != 1 || style->scale_y != 1)
            fprintf(write_file, "scale(%d,%d) ", style->scale_x, style->scale_y);
        fprintf(write_file, "\"");
    }

    fprintf(write_file, " />\n</svg>\n");
    fclose(write_file);

    Progress_bar_animation(2);
    sleep(1);
    system("clear");

    printf(BRIGHT_CYAN"\n╭────────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│      OUVRIR LE FICHIER ?       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰────────────────────────────────╯\n\n"RESET_STYLE);
    printf("Souhaitez-vous ouvrir le fichier pour visualiser votre carré ? \n");
    printf(BRIGHT_GREEN"Attendez la fin du chrono pour l'ouvrir ou appuyez sur une touche avant pour skip :  "RESET_STYLE);

    breaker = Chrono_assassin(5);
    if (breaker) {
        snprintf(command, sizeof(command), "explorer.exe \"..\\Generated_Files\\%s.svg\"", name);
        system(command);
    }

    Auto_write("\n\n"BRIGHT_YELLOW"Retour au menu précédent...\n\n"RESET_STYLE, 25000);
    system("clear");
    Destroy_svg(svg);
}
