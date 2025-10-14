#include "./style.h"

void Infos_style(void)
{
    Delete_two_lines();
    printf("Informations sur les paramètres de style et transformation SVG\n");
    printf("=================================================================\n\n");

    printf("PARAMÈTRES DE STYLE :\n");
    printf("  - stroke : couleur du trait (ex: 'red', 'none')\n");
    printf("  - stroke_width : épaisseur du trait (entier ou flottant)\n");
    printf("  - fill : couleur de remplissage (ex: 'blue', 'lightgray')\n\n");

    printf("PARAMÈTRES DE POSITION ET DE TRANSFORMATION :\n");
    printf("  - translate_x : déplacement horizontal (entier)\n");
    printf("  - translate_y : déplacement vertical (entier)\n");
    printf("  - rotation : angle de rotation en degrés (entier)\n");
    printf("  - rotation_cx : coordonnée X du centre de rotation (entier)\n");
    printf("  - rotation_cy : coordonnée Y du centre de rotation (entier)\n");
    printf("  - scale_x : mise à l’échelle horizontale (1 = normal, -1 = miroir horizontal)\n");
    printf("  - scale_y : mise à l’échelle verticale (1 = normal, -1 = miroir vertical)\n\n");

    printf("ASTUCE SVG :\n");
    printf("Si vous ne souhaitez pas éditer un paramètre, contentez vous d'y assigner la valeur 0, les paramètres par défaut seront utilisés dans ce cas.\n\n");

}



Style* Create_style() {
    Style* style = malloc(sizeof(Style));
    if(!style) return NULL;

    style->fill = "none";

    style->stroke = "none";

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
    printf("\r\n"BOLD_WHITE_TEXT""UNDERLINE_WHITE_TEXT" MENU DE STYLES "RESET_STYLE BOLD_WHITE_TEXT"\n\n"RESET_STYLE);
    printf("1) Préciser une couleur de fond \n2) Préciser une couleur de contour\n3) Définir l'épaisseur du contour \n4) Appliquer une rotation\n5) Appliquer une mise à échelle\n6) Définir un déplacement \n\n"); 

    return Int_recup_verify("Choisissez le paramètre de style à ajouter : ");
}

char* Color_menu() {
    int choice = 0;
    char* color;

    system("clear");
    printf("\r"BOLD_WHITE_TEXT""UNDERLINE_WHITE_TEXT" PANNEL DE COULEURS "RESET_STYLE BOLD_WHITE_TEXT RESET_STYLE"\n\n");
 
    Print_in_black("1) "BLACK"NOIR"RESET_STYLE"\n");
    Print_in_red(RED"2) ROUGE"RESET_STYLE"\n");
    Print_in_green(GREEN"3) VERT"RESET_STYLE"\n");
    Print_in_yellow(YELLOW"4) JAUNE"RESET_STYLE"\n");
    Print_in_blue(BLUE"5) BLEU"RESET_STYLE"\n");
    Print_in_magenta(MAGENTA"6) MAGENTA"RESET_STYLE"\n");
    Print_in_cyan(CYAN"7) CYAN"RESET_STYLE"\n");
    Print_in_white(WHITE"8) BLANC"RESET_STYLE"\n");

    Print_in_bright_black(BRIGHT_BLACK"9) NOIR CLAIR"RESET_STYLE"\n");
    Print_in_bright_red(BRIGHT_RED"10) ROUGE VIF"RESET_STYLE"\n");
    Print_in_bright_green(BRIGHT_GREEN"11) VERT VIF"RESET_STYLE"\n");
    Print_in_bright_yellow(BRIGHT_YELLOW"12) JAUNE VIF"RESET_STYLE"\n");
    Print_in_bright_blue(BRIGHT_BLUE"13) BLEU VIF"RESET_STYLE"\n");
    Print_in_bright_magenta(BRIGHT_MAGENTA"14) MAGENTA VIF"RESET_STYLE"\n");
    Print_in_bright_cyan(BRIGHT_CYAN"15) CYAN VIF"RESET_STYLE"\n");
    Print_in_bright_white(BRIGHT_WHITE"16) BLANC VIF"RESET_STYLE"\n\n");

    choice = Int_recup_verify("Choisissez le numéro correspondant à la couleur souhaitée : " );

    switch (choice) {
        case 1:
            color = "black";
            break;
        case 2:
            color = "red";
            break;
        case 3:
            color = "green";
            break;
        case 4:
            color = "yellow";
            break;
        case 5:
            color = "blue";
            break;
        case 6:
            color = "magenta";
            break;
        case 7:
            color = "cyan";
            break;
        case 8:
            color = "white";
            break;

        // --- Couleurs vives ---
        case 9:
            color = "gray";              // bright black
            break;
        case 10:
            color = "brightred";         // bright red
            break;
        case 11:
            color = "lime";              // bright green
            break;
        case 12:
            color = "gold";              // bright yellow
            break;
        case 13:
            color = "deepskyblue";       // bright blue
            break;
        case 14:
            color = "fuchsia";           // bright magenta
            break;
        case 15:
            color = "aqua";              // bright cyan
            break;
        case 16:
            color = "whitesmoke";        // bright white
            break;

        default:
            color = "black"; // couleur par défaut
        break;
    }

    return color;
}

void Recup_style_data(Style* style){
    if(!Does_style_exist(style)) return; 

    system("clear");
    printf("Souhaitez vous lire la documentation sur le 'Style' des formes SVG ? \n");
    printf("Tapez une touche avant la fin du chrono pour skip :  ");
    Chrono(5);

    if (kbhit()) getchar();
    else Infos_style();

    BlocStyle choice;
    int breaker = 0;

    do
    {
        system("clear");
        Display_style(style);
        choice = Style_menu() - 1;

        switch (choice)
        {
        case FILL:
            style->fill = Color_menu();
        break;
        case STROKE:
            style->stroke = Color_menu();
        break;

        case S_WIDTH:
            system("clear");
            printf(CYAN"EDITION DE STYLE\n\n"RESET_STYLE);
            style->stroke_width = Int_recup_verify("Entrez la valeur souhaitée pour l'épaisseur des contours : ");
        break;
        case ROTATE:
            system("clear");
            printf(CYAN"EDITION DE STYLE\n\n"RESET_STYLE);
            style->rotation = Int_recup_verify("Entrez l'angle de rotation : ");
            style->rotation_cx = Int_recup_verify("Entrez la référence de rotation sur X : ");
            style->rotation_cy = Int_recup_verify("Entrez la référence de rotation sur Y : ");
        break;
        case SCALE:
            system("clear");
            printf(CYAN"EDITION DE STYLE\n\n"RESET_STYLE);
            style->scale_x = Int_recup_verify("Entrez les paramètres d'échelle sur X : ");
            style->scale_y = Int_recup_verify("Entrez les paramètres d'échelle sur Y : ");
        break;
        case TRANSLATE:
            system("clear");
            printf(CYAN"EDITION DE STYLE\n\n"RESET_STYLE);
            style->translate_x = Int_recup_verify("Entrez les paramètres de déplacement sur X : ");
            style->translate_y = Int_recup_verify("Entrez les paramètres de déplacement sur Y : ");
        break;
        
        default:
            Print_in_red("Entrée Invalide!");
        break;
        
        }

        system("clear");
        printf("\n\nSouhaitez vous continuer de styliser votre forme ?");
        printf("\nTapez une touche avant la fin du chrono pour continuer :  ");
        breaker = Chrono_assassin(5);

    } while (!breaker);

    system("clear");
    
}

void Display_style(Style* style ) {
    if(!Does_style_exist(style)) return;

    printf("\n");
    printf("\r"BOLD_WHITE_TEXT""UNDERLINE_WHITE_TEXT" STYLE "RESET_STYLE BOLD_WHITE_TEXT"\n\n"RESET_STYLE);
    printf("Couleur de fond : %s\n\n", style->fill);

    printf("Couleur de contour : %s\n", style->stroke);
    printf("Epaisseur de contour : %d\n\n", style->stroke_width);

    printf("Angle de rotation : %d°\n", style->rotation);
    printf("Réference de rotation sur X : %d\n", style->rotation_cx);
    printf("Réference de rotation sur Y : %d\n\n", style->rotation_cy);

    printf("Valeur d'échelle sur X : %d\n", style->scale_x);
    printf("Valeur d'échelle sur Y : %d\n\n", style->scale_y);

    printf("Déplacement sur X : %d\n", style->translate_x);
    printf("Déplacement sur Y : %d\n\n", style->translate_y);

}

// int main() {

//     Style* style = Create_style();
//     Recup_style_data(style);
//     Display_style(style);
//     Destroy_style(style);

//     return EXIT_SUCCESS;
// }
