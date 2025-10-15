#include "./main.h"

void Infos_ellipse() {
    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        INFOS ELLIPSE         │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Le saviez-vous ?\n");
    printf("L’élément "BOLD_WHITE_TEXT"<ellipse>"RESET_STYLE" en SVG appartient à la famille des formes simples.\n");
    printf("Il sert à tracer une ellipse à partir d’un "BOLD_WHITE_TEXT"centre (cx, cy)"RESET_STYLE" et de deux "BOLD_WHITE_TEXT"rayons (rx, ry)"RESET_STYLE".\n\n");

    printf(BRIGHT_CYAN"Paramètres nécessaires :\n"RESET_STYLE);
    printf("  • "BOLD_WHITE_TEXT"cx"RESET_STYLE" : Position X du centre (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"cy"RESET_STYLE" : Position Y du centre (entier)\n");
    printf("  • "BOLD_WHITE_TEXT"rx"RESET_STYLE" : Taille du rayon sur X (entier non signé)\n");
    printf("  • "BOLD_WHITE_TEXT"ry"RESET_STYLE" : Taille du rayon sur Y (entier non signé)\n\n");
}

void Recup_ellipse_data(Ellipse* ellipse) {
    if (!Does_ellipse_exist(ellipse)) return;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│    INITIALISATION ELLIPSE    │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Souhaitez-vous afficher la documentation pour créer une ellipse ?\n");
    printf("Appuyez sur une touche avant la fin du chrono pour passer :  ");

    Chrono(5);

    if (kbhit()) getchar();
    else Infos_ellipse();

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     CRÉATION D'ELLIPSE       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    ellipse->circle->cx = Int_recup_verify("Entrez la position X du centre : ");
    ellipse->circle->cy = Int_recup_verify("Entrez la position Y du centre : ");
    ellipse->circle->rx = Unsigned_int_recup_verify("Entrez le rayon sur X de votre ellipse (px) : ");
    ellipse->ry = Unsigned_int_recup_verify("Entrez le rayon sur Y de votre ellipse (px) : ");

    system("clear");
}

Ellipse* Create_ellipse(int cx, int cy, unsigned int rx, unsigned int ry) {
    Ellipse* ellipse = malloc(sizeof(Ellipse));
    if (!ellipse) return NULL;

    ellipse->circle = Create_circle(cx, cy, rx);
    if (!ellipse->circle) {
        free(ellipse);
        return NULL;
    }

    ellipse->ry = ry;
    return ellipse;
}

int Does_ellipse_exist(Ellipse* ellipse) {
    if (!ellipse) {
        Print_in_red("\nShape Not Found !\n");
        return 0;
    }
    if (!ellipse->circle) {
        Print_in_red("\nSub Shape Not Found !\n");
        return 0;
    }
    return 1;
}

void Destroy_ellipse(Ellipse* ellipse) {
    if (!Does_ellipse_exist(ellipse)) return;
    Destroy_circle(ellipse->circle);
    free(ellipse);
}

void Display_ellipse(Ellipse* ellipse) {
    if (!Does_ellipse_exist(ellipse)) return;

    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        DONNÉES ELLIPSE       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("•  Position X du centre : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", ellipse->circle->cx);
    printf("•  Position Y du centre : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", ellipse->circle->cy);
    printf("•  Rayon sur X (px) : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", ellipse->circle->rx);
    printf("•  Rayon sur Y (px) : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n\n", ellipse->ry);
}

int Modify_ellipse_menu() {
    int choice = 0;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│      MODIFIER L'ELLIPSE      │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier la position sur X\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier la position sur Y\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Modifier le rayon sur X\n");
    printf(BRIGHT_CYAN"  4)"RESET_STYLE" Modifier le rayon sur Y\n");
    printf(BRIGHT_CYAN"  5)"RESET_STYLE" Annuler\n\n");

    choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez la valeur à modifier : "RESET_STYLE, 1, 5);
    Delete_two_lines();
    return choice;
}

void Modify_ellipse(Ellipse* ellipse) {
    if (!Does_ellipse_exist(ellipse)) return;

    int value = 0, breaker = 0;

    do {
        system("clear");
        Display_ellipse(ellipse);
        value = Modify_ellipse_menu();

        switch (value) {
            case 1:
                ellipse->circle->cx = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X du centre : "RESET_STYLE);
                break;
            case 2:
                ellipse->circle->cy = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y du centre : "RESET_STYLE);
                break;
            case 3:
                ellipse->circle->rx = Unsigned_int_recup_verify(BRIGHT_GREEN"Nouveau rayon sur X (px) : "RESET_STYLE);
                break;
            case 4:
                ellipse->ry = Unsigned_int_recup_verify(BRIGHT_GREEN"Nouveau rayon sur Y (px) : "RESET_STYLE);
                break;
            case 5:
                return;
            default:
                Print_in_red("Entrée invalide !");
                break;
        }

        system("clear");
        Display_ellipse(ellipse);

        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│    CONTINUER LES MODIFS ?    │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);

        breaker = Chrono_assassin(5);
        system("clear");

    } while (!breaker);
}

void Export_ellipse(Ellipse* ellipse, Style* style) {
    if (!Does_ellipse_exist(ellipse)) return;
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
        svg->xlmns, svg->width, svg->height, svg->view_box->minx, svg->view_box->miny, svg->view_box->width, svg->view_box->height );

    fprintf(write_file,
        "  <ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"rgba(%d,%d,%d,%.2f)\" stroke=\"rgba(%d,%d,%d,%.2f)\" stroke-width=\"%d\"",
        ellipse->circle->cx, ellipse->circle->cy, ellipse->circle->rx, ellipse->ry,
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

    Progress_bar_animation(8);
    sleep(3);
    system("clear");

    printf(BRIGHT_CYAN"\n╭────────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│      OUVRIR LE FICHIER ?       │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰────────────────────────────────╯\n\n"RESET_STYLE);
    printf("Souhaitez-vous ouvrir le fichier pour visualiser votre ellipse ? \n");
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
