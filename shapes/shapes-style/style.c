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

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Couleur de fond\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Couleur de contour\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Épaisseur du contour\n");
    printf(BRIGHT_CYAN"  4)"RESET_STYLE" Rotation\n");
    printf(BRIGHT_CYAN"  5)"RESET_STYLE" Mise à l’échelle\n");
    printf(BRIGHT_CYAN"  6)"RESET_STYLE" Déplacement\n");
    printf(BRIGHT_CYAN"  7)"RESET_STYLE" Quitter\n\n");

    return Int_recup_verify_with_padding("Choisissez un paramètre à modifier : ",1,7);
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
                style->stroke_width = Int_recup_verify(BRIGHT_GREEN"Entrez l'épaisseur du contour : "RESET_STYLE);
                break;
            case ROTATE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│         ROTATION SVG         │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                style->rotation = Int_recup_verify("Entrez l’angle de rotation : "RESET_STYLE);
                style->rotation_cx = Int_recup_verify("Coordonnée X du centre de rotation : "RESET_STYLE);
                style->rotation_cy = Int_recup_verify("Coordonnée Y du centre de rotation : "RESET_STYLE);
                break;
            case SCALE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│      MISE À L’ÉCHELLE SVG    │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                style->scale_x = Int_recup_verify("Valeur d’échelle sur X : "RESET_STYLE);
                style->scale_y = Int_recup_verify("Valeur d’échelle sur Y : "RESET_STYLE);
                break;
            case TRANSLATE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│        DÉPLACEMENT SVG       │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                style->translate_x = Int_recup_verify("Déplacement sur X : "RESET_STYLE);
                style->translate_y = Int_recup_verify("Déplacement sur Y : "RESET_STYLE);
                break;
            case EXIT:
               return;
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

    printf("  Couleur de fond : "BOLD_WHITE_TEXT"RGBA (%d, %d, %d, %g)"RESET_STYLE"\n", style->Rf, style->Gf, style->Bf, style->Af);
    printf("  Couleur de contour : "BOLD_WHITE_TEXT"RGBA (%d, %d, %d, %g)"RESET_STYLE"\n", style->Rs, style->Gs, style->Bs, style->As);
    printf("  Épaisseur du contour : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n\n", style->stroke_width);

    printf("  Angle de rotation : "BOLD_WHITE_TEXT"%d ° "RESET_STYLE"\n", style->rotation);
    printf("  Centre de rotation X : "BOLD_WHITE_TEXT"%d "RESET_STYLE"\n", style->rotation_cx);
    printf("  Centre de rotation Y : "BOLD_WHITE_TEXT"%d "RESET_STYLE"\n\n", style->rotation_cy);

    printf("  Échelle sur X : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", style->scale_x);
    printf("  Échelle sur Y : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n\n", style->scale_y);

    printf("  Déplacement sur X : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", style->translate_x);
    printf("  Déplacement sur Y : "BOLD_WHITE_TEXT"%d"RESET_STYLE"\n", style->translate_y);
}
