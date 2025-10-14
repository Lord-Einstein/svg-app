#include "./style.h"

void Infos_style(void)
{
    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│     INFORMATIONS STYLES SVG  │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_WHITE"PARAMÈTRES DE STYLE :\n"RESET_STYLE);
    printf("  • stroke : couleur du trait (ex : 'red', 'none')\n");
    printf("  • stroke_width : épaisseur du trait (entier ou flottant)\n");
    printf("  • fill : couleur de remplissage (ex : 'blue', 'lightgray')\n\n");

    printf(BRIGHT_WHITE"PARAMÈTRES DE TRANSFORMATION :\n"RESET_STYLE);
    printf("  • translate_x / translate_y : déplacement horizontal / vertical\n");
    printf("  • rotation : angle en degrés\n");
    printf("  • rotation_cx / rotation_cy : centre de rotation\n");
    printf("  • scale_x / scale_y : mise à l’échelle horizontale et verticale\n\n");

    printf(BRIGHT_WHITE"ASTUCE :\n"RESET_STYLE);
    printf("  Si vous ne souhaitez pas modifier un paramètre, entrez simplement 0.\n");
    printf("  Les valeurs par défaut seront utilisées dans ce cas.\n\n");
}

Style* Create_style() {
    Style* style = malloc(sizeof(Style));
    if(!style) return NULL;

    style->Rs = 0;
    style->Gs = 0;
    style->Bs = 0;
    style->As = 0.0;

    style->Rf = 0;
    style->Gf = 0;
    style->Bf = 0;
    style->Af = 0.0;

    style->stroke_width = 0;

    style->rotation = 0;
    style->rotation_cx = 0;
    style->rotation_cy = 0;

    style->scale_x = 1;
    style->scale_y = 1;

    style->translate_x = 0;
    style->translate_y = 0;

    return style;
}

int Does_style_exist(Style* style){
    if(!style) return 0;
    return 1;
}

void Destroy_style(Style* style){
    if(!Does_style_exist(style)) return;
    free(style);
}

int Style_menu() {
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        MENU DE STYLES        │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("  1) Couleur de fond\n");
    printf("  2) Couleur de contour\n");
    printf("  3) Épaisseur du contour\n");
    printf("  4) Rotation\n");
    printf("  5) Mise à l’échelle\n");
    printf("  6) Déplacement\n\n");

    return Int_recup_verify_with_padding("Choisissez un paramètre à modifier : ",1,6);
}

char* Color_menu() {
    int choice = 0;
    char* color;

    system("clear");
    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        PANNEL DE COULEURS    │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    Print_in_black(" 1) "BLACK"NOIR"RESET_STYLE"\n");
    Print_in_red(" 2) "RED"ROUGE"RESET_STYLE"\n");
    Print_in_green(" 3) "GREEN"VERT"RESET_STYLE"\n");
    Print_in_yellow(" 4) "YELLOW"JAUNE"RESET_STYLE"\n");
    Print_in_blue(" 5) "BLUE"BLEU"RESET_STYLE"\n");
    Print_in_magenta(" 6) "MAGENTA"MAGENTA"RESET_STYLE"\n");
    Print_in_cyan(" 7) "CYAN"CYAN"RESET_STYLE"\n");
    Print_in_white(" 8) "WHITE"BLANC"RESET_STYLE"\n");

    Print_in_bright_black(" 9) "BRIGHT_BLACK"NOIR CLAIR"RESET_STYLE"\n");
    Print_in_bright_red("10) "BRIGHT_RED"ROUGE VIF"RESET_STYLE"\n");
    Print_in_bright_green("11) "BRIGHT_GREEN"VERT VIF"RESET_STYLE"\n");
    Print_in_bright_yellow("12) "BRIGHT_YELLOW"JAUNE VIF"RESET_STYLE"\n");
    Print_in_bright_blue("13) "BRIGHT_BLUE"BLEU VIF"RESET_STYLE"\n");
    Print_in_bright_magenta("14) "BRIGHT_MAGENTA"MAGENTA VIF"RESET_STYLE"\n");
    Print_in_bright_cyan("15) "BRIGHT_CYAN"CYAN VIF"RESET_STYLE"\n");
    Print_in_bright_white("16) "BRIGHT_WHITE"BLANC VIF"RESET_STYLE"\n\n");

    choice = Int_recup_verify("Choisissez la couleur souhaitée : ");

    switch (choice) {
        case 1: color = "black"; break;
        case 2: color = "red"; break;
        case 3: color = "green"; break;
        case 4: color = "yellow"; break;
        case 5: color = "blue"; break;
        case 6: color = "magenta"; break;
        case 7: color = "cyan"; break;
        case 8: color = "white"; break;
        case 9: color = "gray"; break;
        case 10: color = "brightred"; break;
        case 11: color = "lime"; break;
        case 12: color = "gold"; break;
        case 13: color = "deepskyblue"; break;
        case 14: color = "fuchsia"; break;
        case 15: color = "aqua"; break;
        case 16: color = "whitesmoke"; break;
        default: color = "black"; break;
    }

    return color;
}

void Recup_style_data(Style* style){
    if(!Does_style_exist(style)) return; 

    system("clear");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│       INITIALISATION STYLE   │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Souhaitez-vous lire la documentation sur le style SVG ?\n");
    printf("Appuyez sur une touche avant la fin du chrono pour passer :  ");
    Chrono(5);

    if (kbhit()) getchar();
    else Infos_style();

    BlocStyle choice;
    int breaker = 0;

    do {
        // system("clear");
        Display_style(style);
        choice = Style_menu();

        switch (choice) {
            case FILL:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│       COULEUR DE FOND        │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                style->Rf= Int_recup_verify_with_padding(BRIGHT_RED"R : "RESET_STYLE, 0, 255);
                style->Gf = Int_recup_verify_with_padding(BRIGHT_GREEN"G : "RESET_STYLE, 0, 255);
                style->Bf = Int_recup_verify_with_padding(BRIGHT_BLUE"B : "RESET_STYLE, 0, 255);
                style->Af = Float_recup_verify_with_padding(BOLD_WHITE_TEXT"A : "RESET_STYLE, 0.0, 1.0);
                break;
            case STROKE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│    COULEUR DE BORDURE        │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                style->Rs= Int_recup_verify_with_padding(BRIGHT_RED"R : "RESET_STYLE, 0, 255);
                style->Gs = Int_recup_verify_with_padding(BRIGHT_GREEN"G : "RESET_STYLE, 0, 255);
                style->Bs = Int_recup_verify_with_padding(BRIGHT_BLUE"B : "RESET_STYLE, 0, 255);
                style->As = Float_recup_verify_with_padding(BOLD_WHITE_TEXT"A : "RESET_STYLE, 0.0, 1.0);
                break;
            case S_WIDTH:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│   MODIFICATION DU CONTOUR    │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                style->stroke_width = Int_recup_verify("Entrez l'épaisseur du contour : ");
                break;
            case ROTATE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│         ROTATION SVG         │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                style->rotation = Int_recup_verify("Entrez l’angle de rotation : ");
                style->rotation_cx = Int_recup_verify("Coordonnée X du centre de rotation : ");
                style->rotation_cy = Int_recup_verify("Coordonnée Y du centre de rotation : ");
                break;
            case SCALE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│      MISE À L’ÉCHELLE SVG    │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                style->scale_x = Int_recup_verify("Valeur d’échelle sur X : ");
                style->scale_y = Int_recup_verify("Valeur d’échelle sur Y : ");
                break;
            case TRANSLATE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│        DÉPLACEMENT SVG       │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                style->translate_x = Int_recup_verify("Déplacement sur X : ");
                style->translate_y = Int_recup_verify("Déplacement sur Y : ");
                break;
            default:
                Print_in_bright_red("Invalide !");
            break;
        }

        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│  CONTINUER LA STYLISATION ?  │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf("Appuyez sur une touche avant la fin du chrono pour continuer :  ");
        breaker = Chrono_assassin(5);
        system("clear");

    } while (!breaker);

    system("clear");
}

void Display_style(Style* style) {
    if(!Does_style_exist(style)) return;

    // printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│         STYLE ACTUEL         │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("  Couleur de fond : RGBA (%d, %d, %d, %.2f) \n", style->Rf, style->Gf, style->Bf, style->Af);
    printf("  Couleur de contour : RGBA (%d, %d, %d, %.2f) \n", style->Rs, style->Gs, style->Bs, style->As);
    printf("  Épaisseur du contour : %d\n\n", style->stroke_width);

    printf("  Angle de rotation : %d°\n", style->rotation);
    printf("  Centre de rotation X : %d\n", style->rotation_cx);
    printf("  Centre de rotation Y : %d\n\n", style->rotation_cy);

    printf("  Échelle sur X : %d\n", style->scale_x);
    printf("  Échelle sur Y : %d\n\n", style->scale_y);

    printf("  Déplacement sur X : %d\n", style->translate_x);
    printf("  Déplacement sur Y : %d\n", style->translate_y);
}
