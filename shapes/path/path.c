#include "./path.h"

void Infos_path() {
    system("clear");

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│          INFOS PATH          │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
    printf("\nLe saviez-vous ?\n");
    printf("L'élément SVG 'path' est l'un des éléments les plus puissants et flexibles du langage SVG.\n");
    printf("Il permet de décrire des formes très complexes à l'aide d'une suite de commandes et de coordonnées,\n");
    printf("rassemblées dans un seul attribut : 'd'. Chaque commande contrôle un déplacement ou un tracé précis.\n\n");

    printf("Voici les principales commandes du PATH et leur signification :\n\n");

    printf("M (moveto)     : Déplace le curseur vers un point sans tracer de ligne.\n");
    printf("L (lineto)     : Trace une ligne droite jusqu'au point spécifié.\n");
    printf("H (horizontal) : Trace une ligne horizontale jusqu'à la position X indiquée.\n");
    printf("V (vertical)   : Trace une ligne verticale jusqu'à la position Y indiquée.\n");
    printf("C (cubic)      : Crée une courbe de Bézier cubique à l'aide de deux points de contrôle.\n");
    printf("S (smooth)     : Variante simplifiée de C, le premier point de contrôle est déduit automatiquement.\n");
    printf("Q (quadratic)  : Crée une courbe de Bézier quadratique avec un seul point de contrôle.\n");
    printf("T (smooth quad): Variante simplifiée de Q, le point de contrôle est déduit automatiquement.\n");
    printf("Z (closepath)  : Ferme le tracé en reliant le dernier point au premier.\n\n");

    printf("Chaque commande utilise des paramètres numériques, pouvant être entiers ou flottants :\n");
    printf("  - X, Y   : Coordonnées d'un point.\n");
    printf("  - X1,Y1  : Premier point de contrôle (pour les courbes C ou Q).\n");
    printf("  - X2,Y2  : Second point de contrôle (pour les courbes C ou S).\n\n");

    printf("Astuce : Les commandes en MAJUSCULE utilisent des coordonnées ABSOLUES,\n");
    printf("tandis que les minuscules (m, l, c, etc.) représentent des coordonnées RELATIVES\n");
    printf("par rapport à la position courante.\n\n");

    printf("Exemple :\n");
    printf("  <path d=\"M10 10 L100 10 L100 100 L10 100 Z\" />\n");
    printf("Ce code crée un carré fermé à partir de quatre lignes droites.\n\n\n");
}

void Infos_M() {
    system("clear");
    printf(BRIGHT_CYAN"\nCommande M (moveto)\n"RESET_STYLE);
    printf("-------------------\n");
    printf("Déplace le curseur vers un point donné sans tracer de ligne.\n");
    printf("C’est généralement la première commande d’un chemin SVG.\n\n");

    printf("Paramètres attendus :\n");
    printf("  X : Coordonnée horizontale du point de départ.\n");
    printf("  Y : Coordonnée verticale du point de départ.\n\n");

    printf("Exemple :\n");
    printf("  M 50 50\n");
    printf("→ Place le point de départ à la position (50, 50).\n\n");

    printf("Note : 'm' (minuscule) effectue le déplacement de manière relative à la position courante.\n\n");
}

void Infos_L() {
    system("clear");
    printf(BRIGHT_CYAN"\nCommande L (lineto)\n"RESET_STYLE);
    printf("-------------------\n");
    printf("Trace une ligne droite entre le point courant et un nouveau point.\n\n");

    printf("Paramètres attendus :\n");
    printf("  X : Coordonnée horizontale du point d’arrivée.\n");
    printf("  Y : Coordonnée verticale du point d’arrivée.\n\n");

    printf("Exemple :\n");
    printf("  L 200 100\n");
    printf("→ Trace une ligne droite jusqu’au point (200, 100).\n\n");

    printf("Note : 'l' (minuscule) trace une ligne RELATIVE au point actuel.\n\n");
}

void Infos_H() {
    system("clear");
    printf(BRIGHT_CYAN"\nCommande H (horizontal lineto)\n"RESET_STYLE);
    printf("------------------------------\n");
    printf("Trace une ligne horizontale à partir du point courant.\n\n");

    printf("Paramètre attendu :\n");
    printf("  X : Nouvelle position horizontale (l’axe Y ne change pas).\n\n");

    printf("Exemple :\n");
    printf("  H 250\n");
    printf("→ Déplace horizontalement jusqu’à X = 250.\n\n");

    printf("Note : 'h' (minuscule) déplace RELATIVEMENT sur l’axe horizontal.\n\n");
}

void Infos_V() {
    system("clear");
    printf(BRIGHT_CYAN"\nCommande V (vertical lineto)\n"RESET_STYLE);
    printf("----------------------------\n");
    printf("Trace une ligne verticale à partir du point courant.\n\n");

    printf("Paramètre attendu :\n");
    printf("  Y : Nouvelle position verticale (l’axe X ne change pas).\n\n");

    printf("Exemple :\n");
    printf("  V 300\n");
    printf("→ Déplace verticalement jusqu’à Y = 300.\n\n");

    printf("Note : 'v' (minuscule) déplace RELATIVEMENT sur l’axe vertical.\n\n");
}

void Infos_C() {
    system("clear");
    printf(BRIGHT_CYAN"\nCommande C (cubic Bézier curve)\n"RESET_STYLE);
    printf("--------------------------------\n");
    printf("Crée une courbe de Bézier cubique entre le point courant et un point d’arrivée.\n");
    printf("Deux points de contrôle définissent la tangente de départ et d’arrivée.\n\n");

    printf("Paramètres attendus :\n");
    printf("  X1, Y1 : Coordonnées du premier point de contrôle.\n");
    printf("  X2, Y2 : Coordonnées du second point de contrôle.\n");
    printf("  X, Y   : Coordonnées du point d’arrivée.\n\n");

    printf("Exemple :\n");
    printf("  C 50 200, 150 100, 200 200\n");
    printf("→ Trace une courbe lisse depuis le point courant jusqu’à (200, 200).\n\n");

    printf("Note : 'c' (minuscule) utilise des coordonnées RELATIVES.\n\n");
}

void Infos_S() {
    system("clear");
    printf(BRIGHT_CYAN"\nCommande S (smooth cubic Bézier)\n"RESET_STYLE);
    printf("--------------------------------\n");
    printf("Crée une courbe de Bézier cubique sans spécifier le premier point de contrôle.\n");
    printf("Ce point est déduit automatiquement du segment précédent.\n\n");

    printf("Paramètres attendus :\n");
    printf("  X2, Y2 : Coordonnées du second point de contrôle.\n");
    printf("  X, Y   : Coordonnées du point d’arrivée.\n\n");

    printf("Exemple :\n");
    printf("  S 250 150, 300 200\n");
    printf("→ Prolonge naturellement une courbe précédente jusqu’à (300, 200).\n\n");

    printf("Note : 's' (minuscule) utilise des coordonnées RELATIVES.\n\n");
}

void Infos_Q() {
    system("clear");
    printf(BRIGHT_CYAN"\nCommande Q (quadratic Bézier curve)\n"RESET_STYLE);
    printf("-----------------------------------\n");
    printf("Crée une courbe de Bézier quadratique entre le point courant et un point d’arrivée.\n");
    printf("Un seul point de contrôle définit la courbure.\n\n");

    printf("Paramètres attendus :\n");
    printf("  X1, Y1 : Coordonnées du point de contrôle.\n");
    printf("  X, Y   : Coordonnées du point d’arrivée.\n\n");

    printf("Exemple :\n");
    printf("  Q 150 50, 200 200\n");
    printf("→ Trace une courbe douce vers (200, 200).\n\n");

    printf("Note : 'q' (minuscule) utilise des coordonnées RELATIVES.\n\n");
}

void Infos_T() {
    system("clear");
    printf(BRIGHT_CYAN"\nCommande T (smooth quadratic Bézier)\n"RESET_STYLE);
    printf("------------------------------------\n");
    printf("Crée une courbe quadratique continue sans redéfinir le point de contrôle.\n");
    printf("Le point de contrôle est calculé automatiquement selon la courbe précédente.\n\n");

    printf("Paramètres attendus :\n");
    printf("  X, Y : Coordonnées du point d’arrivée.\n\n");

    printf("Exemple :\n");
    printf("  T 300 250\n");
    printf("→ Prolonge la courbe précédente jusqu’à (300, 250) en douceur.\n\n");

    printf("Note : 't' (minuscule) utilise des coordonnées RELATIVES.\n\n");
}

void Infos_Z() {
    system("clear");
    printf(BRIGHT_CYAN"\nCommande Z (closepath)\n"RESET_STYLE);
    printf("----------------------\n");
    printf("Ferme le chemin en reliant le dernier point au point de départ.\n");
    printf("Aucune coordonnée n’est nécessaire.\n\n");

    printf("Exemple :\n");
    printf("  Z\n");
    printf("→ Ferme la forme courante (utile pour des polygones, contours, etc.).\n\n");

    printf("Note : 'z' (minuscule) a exactement le même effet.\n\n");
}

//Pistes d'amélioration : Pour les mallocs successifs dans Create_new_cubic...
// Je peux faire un free(du pointeur malloc principal) si les suivants ont échoués Exemple correct : Ligne 344 ou dans Create_new_path_element


HeadPath* Create_new_path() {
    HeadPath* head = malloc(sizeof(HeadPath));
    if(!head) return NULL;

    head->start = NULL;
    return head;
}


Point* Create_new_couple(int x, int y){
    Point* point = malloc(sizeof(Point));
    if(!point) return NULL;

    point->x = x;
    point->y = y;

    return point;
}

MoveTo* Create_new_move_to(Point* point) {
    MoveTo* move_to = malloc(sizeof(MoveTo));
    if(!move_to) return NULL;


    move_to->p = point;

    return move_to;
}

LineTo* Create_new_line_to(Point* point) {
    LineTo* line_to = malloc(sizeof(LineTo));
    if(!line_to) return NULL;

    line_to->p = point;

    return line_to;
}

HLineTo* Create_new_h_line_to(int x) {
    HLineTo* h_line_to = malloc(sizeof(HLineTo));
    if(!h_line_to) return NULL;

    h_line_to->x = x;

    return h_line_to;
}

VLineTo* Create_new_v_line_to(int x) {
    VLineTo* v_line_to = malloc(sizeof(VLineTo));
    if(!v_line_to) return NULL;

    v_line_to->x = x;

    return v_line_to;
}

CubicCurve* Create_new_cubic_curve(Point* point1, Point* point2, Point* point3){
    CubicCurve* cubic_curve = malloc(sizeof(CubicCurve));
    if(!cubic_curve) return NULL;

    cubic_curve->point1 = point1;
    cubic_curve->point2 = point2;
    cubic_curve->point3 = point3;

    return cubic_curve;
}

SmoothCubicCurve* Create_new_smooth_cubic_curve(Point* point1, Point* point2){
    SmoothCubicCurve* smooth_cubic_curve = malloc(sizeof(SmoothCubicCurve));
    if(!smooth_cubic_curve) return NULL;

    smooth_cubic_curve->point1 = point1;
    smooth_cubic_curve->point2 = point2;

    return smooth_cubic_curve;
}

QuadraCurve* Create_new_quadra_curve(Point* point1, Point* point2){
    QuadraCurve* quadra_curve = malloc(sizeof(QuadraCurve));
    if(!quadra_curve) return NULL;

    quadra_curve->point1 = point1;
    quadra_curve->point2 = point2;

    return quadra_curve;
}

SmoothQuadraCurve* Create_new_smooth_quadra_curve(Point* p){
    SmoothQuadraCurve* smooth_quadra_curve = malloc(sizeof(SmoothQuadraCurve));
    if(!smooth_quadra_curve) return NULL;

    smooth_quadra_curve->p = p;

    return smooth_quadra_curve;
}

Close* Create_new_close(){
    Close* close = malloc(sizeof(Close));
    if(!close) return NULL;

    return close;
}



Node* Create_new_path_element(int commands){

    Node* node = malloc(sizeof(Node));
    if(!node) return NULL;

    node->path_element = malloc(sizeof(Path_element));
    if(!(node->path_element)) { free(node); return NULL; }

    switch(commands){

        case MOVE_TO:
            node->type = 'M';
            node->path_element->commands = commands;
            node->path_element->current_command.move_to = Create_new_move_to(Create_new_couple(0,0));
            node->previous = NULL;
            node->next = NULL;
        break;

        case LINE_TO:
            node->type = 'L';
            node->path_element->commands = commands;
            node->path_element->current_command.line_to = Create_new_line_to(Create_new_couple(0,0));
            node->previous = NULL;
            node->next = NULL;
        break;

        case H_LINE_TO:
            node->type = 'H';
            node->path_element->commands = commands;
            node->path_element->current_command.h_line_to = Create_new_h_line_to(0);
            node->previous = NULL;
            node->next = NULL;
        break;

        case V_LINE_TO:
            node->type = 'V';
            node->path_element->commands = commands;
            node->path_element->current_command.v_line_to = Create_new_v_line_to(0);
            node->previous = NULL;
            node->next = NULL;
        break;

        case CUBIC_CURVE:
            node->type = 'C';
            node->path_element->commands = commands;
            node->path_element->current_command.cubic_curve = Create_new_cubic_curve(Create_new_couple(0,0), Create_new_couple(0,0), Create_new_couple(0,0));
            node->previous = NULL;
            node->next = NULL;
        break;

        case SMOOTH_CUBIC_CURVE:
            node->type = 'S';
            node->path_element->commands = commands;
            node->path_element->current_command.smooth_cubic_curve = Create_new_smooth_cubic_curve(Create_new_couple(0,0), Create_new_couple(0,0));
            node->previous = NULL;
            node->next = NULL;
        break;

        case QUADRA_CURVE:
            node->type = 'Q';
            node->path_element->commands = commands;
            node->path_element->current_command.quadra_curve = Create_new_quadra_curve(Create_new_couple(0,0), Create_new_couple(0,0));
            node->previous = NULL;
            node->next = NULL;
        break;

        case SMOOTH_QUADRA_CURVE:
            node->type = 'T';
            node->path_element->commands = commands;
            node->path_element->current_command.smooth_quadra_curve = Create_new_smooth_quadra_curve(Create_new_couple(0,0));
            node->previous = NULL;
            node->next = NULL;
        break;

        case CLOSE:
            node->type = 'Z';
            node->path_element->commands = commands;
            node->path_element->current_command.close = Create_new_close();
            node->previous = NULL;
            node->next = NULL;
        break;

        default:
            Print_in_red("\nCommand not found\n");
            return NULL;
        break;   

    }
    return node;
    
}

int Does_path_exist(HeadPath* head){
    if(!head) return 0;
    return 1;
}

int Does_path_element_exist(Node* node){
    if(!node) return 0;
    return 1;
}

//Faire les vérifs d'exist ap. surtout en mode does_move_to_exist... De la merde je vous dis..

void Destroy_path_element(Node* node){
    if(!Does_path_element_exist(node)){
        Print_in_red("\nPath Element not found !\n");
        return;
    } 
    switch (node->path_element->commands)
    {
    case MOVE_TO:
        free(node->path_element->current_command.move_to->p);
        free(node->path_element->current_command.move_to);
        free(node->path_element);
        free(node);
    break;
    case LINE_TO:
        free(node->path_element->current_command.line_to->p);
        free(node->path_element->current_command.line_to);
        free(node->path_element);
        free(node);
    break;
    case H_LINE_TO:
        free(node->path_element->current_command.h_line_to);
        free(node->path_element);
        free(node);
    break;
    case V_LINE_TO:
        free(node->path_element->current_command.v_line_to);
        free(node->path_element);
        free(node);
    break;
    case CUBIC_CURVE:
        free(node->path_element->current_command.cubic_curve->point1);
        free(node->path_element->current_command.cubic_curve->point2);
        free(node->path_element->current_command.cubic_curve->point3);
        free(node->path_element->current_command.cubic_curve);
        free(node->path_element);
        free(node);
    break;
    case SMOOTH_CUBIC_CURVE:
        free(node->path_element->current_command.smooth_cubic_curve->point1);
        free(node->path_element->current_command.smooth_cubic_curve->point2);
        free(node->path_element->current_command.smooth_cubic_curve);
        free(node->path_element);
        free(node);
    break;
    case QUADRA_CURVE:
        free(node->path_element->current_command.quadra_curve->point1);
        free(node->path_element->current_command.quadra_curve->point2);
        free(node->path_element->current_command.quadra_curve);
        free(node->path_element);
        free(node);
    break;
    case SMOOTH_QUADRA_CURVE:
        free(node->path_element->current_command.smooth_quadra_curve->p);
        free(node->path_element->current_command.smooth_quadra_curve);
        free(node->path_element);
        free(node);
    break;
    case CLOSE:
        free(node->path_element->current_command.close);
        free(node->path_element);
        free(node);
    break;

    default: return; break;
    }
}

void Destroy_path(HeadPath* head){
    if(!Does_path_exist(head)){
        Print_in_red("\nShape not found !\n");
        return;
    }

    Node* node = head->start;
    Node* temp;

    if(node != NULL){
        while (node->next != NULL)
        {
            temp = node;
            node = node->next;
            Destroy_path_element(temp);
        }
        Destroy_path_element(node);
    }
    free(head);
}

void Display_path_element(Node* node) {
    if(!Does_path_element_exist(node)) {
        Print_in_red("\nSub Shape not found !\n");
        return;
    }

    switch (node->path_element->commands) {
        case MOVE_TO:
            printf(BRIGHT_CYAN"M"RESET_STYLE" %d,%d", 
                node->path_element->current_command.move_to->p->x, 
                node->path_element->current_command.move_to->p->y);
        break;
        case LINE_TO:
            printf(BRIGHT_CYAN"L"RESET_STYLE" %d,%d", 
                node->path_element->current_command.line_to->p->x, 
                node->path_element->current_command.line_to->p->y);
        break;
        case H_LINE_TO:
            printf(BRIGHT_CYAN"H"RESET_STYLE" %d", 
                node->path_element->current_command.h_line_to->x);
        break;
        case V_LINE_TO:
            printf(BRIGHT_CYAN"V"RESET_STYLE" %d", 
                node->path_element->current_command.v_line_to->x);
        break;
        case CUBIC_CURVE:
            printf(BRIGHT_CYAN"C"RESET_STYLE" %d,%d %d,%d %d,%d",
                node->path_element->current_command.cubic_curve->point1->x,
                node->path_element->current_command.cubic_curve->point1->y,
                node->path_element->current_command.cubic_curve->point2->x,
                node->path_element->current_command.cubic_curve->point2->y,
                node->path_element->current_command.cubic_curve->point3->x,
                node->path_element->current_command.cubic_curve->point3->y);
        break;
        case SMOOTH_CUBIC_CURVE:
            printf(BRIGHT_CYAN"S"RESET_STYLE" %d,%d %d,%d",
                node->path_element->current_command.smooth_cubic_curve->point1->x,
                node->path_element->current_command.smooth_cubic_curve->point1->y,
                node->path_element->current_command.smooth_cubic_curve->point2->x,
                node->path_element->current_command.smooth_cubic_curve->point2->y);
        break;
        case QUADRA_CURVE:
            printf(BRIGHT_CYAN"Q"RESET_STYLE" %d,%d %d,%d",
                node->path_element->current_command.quadra_curve->point1->x,
                node->path_element->current_command.quadra_curve->point1->y,
                node->path_element->current_command.quadra_curve->point2->x,
                node->path_element->current_command.quadra_curve->point2->y);
        break;
        case SMOOTH_QUADRA_CURVE:
            printf(BRIGHT_CYAN"T"RESET_STYLE" %d,%d",
                node->path_element->current_command.smooth_quadra_curve->p->x,
                node->path_element->current_command.smooth_quadra_curve->p->y);
        break;
        case CLOSE:
            printf(BRIGHT_CYAN"Z"RESET_STYLE);
        break;
        default:
            printf("\nCommand not found\n");
            return;
        break;
    }
}

void Display_path(HeadPath* head) {
    if(!Does_path_exist(head)) {
        Print_in_red("\nShape not found\n");
        return;
    }

    Node* node = head->start;
    int element_counter = 0;

    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│        DONNÉES PATH          │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
    printf(BOLD_WHITE_TEXT"d >>> "RESET_STYLE);

    while(node != NULL) {
        element_counter++;
        if (element_counter > 1) printf(" ");
        Display_path_element(node);
        node = node->next;
    }

    printf("\n\n");
}

void Display_path_list(HeadPath* head) {
    if(!Does_path_exist(head)) {
        Print_in_red("\nShape not found\n");
        return;
    }

    Node* node = head->start;
    int element_counter = 0;

    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│       LISTE DES ÉLÉMENTS     │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    while(node != NULL) {
        element_counter++;
        printf("Élément %d : ", element_counter);
        Display_path_element(node);
        printf("\n");
        node = node->next;
    }

    printf("\n");
}

void Add_path_element(HeadPath* head, Node* new_node) {
    if(!Does_path_exist(head)) return;
    if(!Does_path_element_exist(new_node)) return;

    Node* node = head->start;

    if(node == NULL) {
        head->start = new_node;
        return;
    }

    while(node->next != NULL) {
        node = node->next;
    }

    node->next = new_node;
    new_node->previous = node;
}

int Menu_commands() {
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│    MENU DE COMMANDES         │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Déplacer le curseur\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Tracer une ligne\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Tracer une ligne horizontale\n");
    printf(BRIGHT_CYAN"  4)"RESET_STYLE" Tracer une ligne verticale\n");
    printf(BRIGHT_CYAN"  5)"RESET_STYLE" Tracer une courbe cubique\n");
    printf(BRIGHT_CYAN"  6)"RESET_STYLE" Tracer une courbe cubique lisse\n");
    printf(BRIGHT_CYAN"  7)"RESET_STYLE" Tracer une courbe quadratique\n");
    printf(BRIGHT_CYAN"  8)"RESET_STYLE" Tracer une courbe quadratique lisse\n");
    printf(BRIGHT_CYAN"  9)"RESET_STYLE" Fermer le chemin\n");
    printf(BRIGHT_CYAN"  10)"RESET_STYLE" Annuler\n\n");

    return Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez une commande : "RESET_STYLE, 1, 10);
}

void Recup_path_data(HeadPath* head) {
    if(!Does_path_exist(head)) return;

    system("clear");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│  INITIALISATION PATH         │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Souhaitez vous lire la documentation pour concevoir un 'Path' ?\n");
    printf("Tapez une touche avant la fin du chrono pour skip :  ");
    Chrono(5);

    if (kbhit()) getchar();
    else Infos_path();

    int choice = 0, breaker = 0;
    Node* node = NULL;

    do {
        system("clear");
        Display_path_list(head);

        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│   AJOUTER UN ÉLÉMENT         │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

        choice = Menu_commands();
        choice--;

        switch (choice) {
            case MOVE_TO:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│  COMMANDE MOVE TO (M)        │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                
                printf("Souhaitez vous lire la documentation ?\n");
                printf("Tapez une touche avant la fin du chrono pour skip :  ");
                Chrono(5);

                if (kbhit()) getchar();
                else Infos_M();

                node = Create_new_path_element(choice);
                if (!node) break;
                
                node->path_element->current_command.move_to->p->x = Int_recup_verify(BRIGHT_GREEN"Position X : "RESET_STYLE);
                node->path_element->current_command.move_to->p->y = Int_recup_verify(BRIGHT_GREEN"Position Y : "RESET_STYLE);

                Add_path_element(head, node);
            break;

            case LINE_TO:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│  COMMANDE LINE TO (L)        │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                
                printf("Souhaitez vous lire la documentation ?\n");
                printf("Tapez une touche avant la fin du chrono pour skip :  ");
                Chrono(5);

                if (kbhit()) getchar();
                else Infos_L();

                node = Create_new_path_element(choice);
                if (!node) break;
                
                node->path_element->current_command.line_to->p->x = Int_recup_verify(BRIGHT_GREEN"Position X : "RESET_STYLE);
                node->path_element->current_command.line_to->p->y = Int_recup_verify(BRIGHT_GREEN"Position Y : "RESET_STYLE);

                Add_path_element(head, node);
            break;

            case H_LINE_TO:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│ COMMANDE HORIZONTAL LINE (H) │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                
                printf("Souhaitez vous lire la documentation ?\n");
                printf("Tapez une touche avant la fin du chrono pour skip :  ");
                Chrono(5);

                if (kbhit()) getchar();
                else Infos_H();

                node = Create_new_path_element(choice);
                if (!node) break;
                
                node->path_element->current_command.h_line_to->x = Int_recup_verify(BRIGHT_GREEN"Position X : "RESET_STYLE);

                Add_path_element(head, node);
            break;

            case V_LINE_TO:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│  COMMANDE VERTICAL LINE (V)  │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                
                printf("Souhaitez vous lire la documentation ?\n");
                printf("Tapez une touche avant la fin du chrono pour skip :  ");
                Chrono(5);

                if (kbhit()) getchar();
                else Infos_V();

                node = Create_new_path_element(choice);
                if (!node) break;
                
                node->path_element->current_command.v_line_to->x = Int_recup_verify(BRIGHT_GREEN"Position Y : "RESET_STYLE);

                Add_path_element(head, node);
            break;

            case CUBIC_CURVE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│  COMMANDE CUBIC CURVE (C)    │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                
                printf("Souhaitez vous lire la documentation ?\n");
                printf("Tapez une touche avant la fin du chrono pour skip :  ");
                Chrono(5);

                if (kbhit()) getchar();
                else Infos_C();

                node = Create_new_path_element(choice);
                if (!node) break;
                
                printf(BRIGHT_GREEN"Point de contrôle 1"RESET_STYLE"\n");
                node->path_element->current_command.cubic_curve->point1->x = Int_recup_verify("  X : "RESET_STYLE);
                node->path_element->current_command.cubic_curve->point1->y = Int_recup_verify("  Y : "RESET_STYLE);
                
                printf(BRIGHT_GREEN"Point de contrôle 2"RESET_STYLE"\n");
                node->path_element->current_command.cubic_curve->point2->x = Int_recup_verify("  X : "RESET_STYLE);
                node->path_element->current_command.cubic_curve->point2->y = Int_recup_verify("  Y : "RESET_STYLE);
                
                printf(BRIGHT_GREEN"Point d'arrivée"RESET_STYLE"\n");
                node->path_element->current_command.cubic_curve->point3->x = Int_recup_verify("  X : "RESET_STYLE);
                node->path_element->current_command.cubic_curve->point3->y = Int_recup_verify("  Y : "RESET_STYLE);
                
                Add_path_element(head, node);
            break;

            case SMOOTH_CUBIC_CURVE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│ COMMANDE SMOOTH CUBIC (S)    │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                
                printf("Souhaitez vous lire la documentation ?\n");
                printf("Tapez une touche avant la fin du chrono pour skip :  ");
                Chrono(5);

                if (kbhit()) getchar();
                else Infos_S();

                node = Create_new_path_element(choice);
                if (!node) break;
                
                printf(BRIGHT_GREEN"Point de contrôle"RESET_STYLE"\n");
                node->path_element->current_command.smooth_cubic_curve->point1->x = Int_recup_verify("  X : "RESET_STYLE);
                node->path_element->current_command.smooth_cubic_curve->point1->y = Int_recup_verify("  Y : "RESET_STYLE);
                
                printf(BRIGHT_GREEN"Point d'arrivée"RESET_STYLE"\n");
                node->path_element->current_command.smooth_cubic_curve->point2->x = Int_recup_verify("  X : "RESET_STYLE);
                node->path_element->current_command.smooth_cubic_curve->point2->y = Int_recup_verify("  Y : "RESET_STYLE);
                
                Add_path_element(head, node);
            break;

            case QUADRA_CURVE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│ COMMANDE QUADRATIC CURVE (Q) │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                
                printf("Souhaitez vous lire la documentation ?\n");
                printf("Tapez une touche avant la fin du chrono pour skip :  ");
                Chrono(5);

                if (kbhit()) getchar();
                else Infos_Q();

                node = Create_new_path_element(choice);
                if (!node) break;
                
                printf(BRIGHT_GREEN"Point de contrôle"RESET_STYLE"\n");
                node->path_element->current_command.quadra_curve->point1->x = Int_recup_verify("  X : "RESET_STYLE);
                node->path_element->current_command.quadra_curve->point1->y = Int_recup_verify("  Y : "RESET_STYLE);
                
                printf(BRIGHT_GREEN"Point d'arrivée"RESET_STYLE"\n");
                node->path_element->current_command.quadra_curve->point2->x = Int_recup_verify("  X : "RESET_STYLE);
                node->path_element->current_command.quadra_curve->point2->y = Int_recup_verify("  Y : "RESET_STYLE);
                
                Add_path_element(head, node);
            break;

            case SMOOTH_QUADRA_CURVE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│ COMMANDE SMOOTH QUADRATIC (T)│\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                
                printf("Souhaitez vous lire la documentation ?\n");
                printf("Tapez une touche avant la fin du chrono pour skip :  ");
                Chrono(5);

                if (kbhit()) getchar();
                else Infos_T();

                node = Create_new_path_element(choice);
                if (!node) break;
                
                printf(BRIGHT_GREEN"Point d'arrivée"RESET_STYLE"\n");
                node->path_element->current_command.smooth_quadra_curve->p->x = Int_recup_verify("  X : "RESET_STYLE);
                node->path_element->current_command.smooth_quadra_curve->p->y = Int_recup_verify("  Y : "RESET_STYLE);
                
                Add_path_element(head, node);
            break;

            case CLOSE:
                system("clear");
                printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                printf(BRIGHT_CYAN"│    COMMANDE CLOSE (Z)        │\n"RESET_STYLE);
                printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);
                
                printf("Souhaitez vous lire la documentation ?\n");
                printf("Tapez une touche avant la fin du chrono pour skip :  ");
                Chrono(5);

                if (kbhit()) getchar();
                else Infos_Z();

                node = Create_new_path_element(choice);
                if (!node) break;
                
                Add_path_element(head, node);
            break;

            case 9:
            return;
            
            default:
                Print_in_red("Commande invalide !");
                sleep(2);
            break;
        }

        system("clear");
        Display_path(head);

        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│  AJOUTER UN AUTRE ÉLÉMENT ?  │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);
        breaker = Chrono_assassin(5);
        system("clear");

    } while(!breaker);
}



void Display_path_element_detailed(Node* node) {
    if(!Does_path_element_exist(node)) return;

    printf("\n");
    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│    ÉLÉMENT DE PATH           │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    switch (node->path_element->commands) {
        case MOVE_TO:
            printf("Type : "BOLD_WHITE_TEXT"MOVE TO (M)"RESET_STYLE"\n");
            printf("Point : [ X = %d, Y = %d ]\n\n", 
                node->path_element->current_command.move_to->p->x,
                node->path_element->current_command.move_to->p->y);
        break;
        case LINE_TO:
            printf("Type : "BOLD_WHITE_TEXT"LINE TO (L)"RESET_STYLE"\n");
            printf("Point : [ X = %d, Y = %d ]\n\n",
                node->path_element->current_command.line_to->p->x,
                node->path_element->current_command.line_to->p->y);
        break;
        case H_LINE_TO:
            printf("Type : "BOLD_WHITE_TEXT"HORIZONTAL LINE TO (H)"RESET_STYLE"\n");
            printf("Position X : %d\n\n",
                node->path_element->current_command.h_line_to->x);
        break;
        case V_LINE_TO:
            printf("Type : "BOLD_WHITE_TEXT"VERTICAL LINE TO (V)"RESET_STYLE"\n");
            printf("Position Y : %d\n\n",
                node->path_element->current_command.v_line_to->x);
        break;
        case CUBIC_CURVE:
            printf("Type : "BOLD_WHITE_TEXT"CUBIC CURVE (C)"RESET_STYLE"\n");
            printf("Point de contrôle 1 : [ X = %d, Y = %d ]\n",
                node->path_element->current_command.cubic_curve->point1->x,
                node->path_element->current_command.cubic_curve->point1->y);
            printf("Point de contrôle 2 : [ X = %d, Y = %d ]\n",
                node->path_element->current_command.cubic_curve->point2->x,
                node->path_element->current_command.cubic_curve->point2->y);
            printf("Point d'arrivée : [ X = %d, Y = %d ]\n\n",
                node->path_element->current_command.cubic_curve->point3->x,
                node->path_element->current_command.cubic_curve->point3->y);
        break;
        case SMOOTH_CUBIC_CURVE:
            printf("Type : "BOLD_WHITE_TEXT"SMOOTH CUBIC CURVE (S)"RESET_STYLE"\n");
            printf("Point de contrôle 2 : [ X = %d, Y = %d ]\n",
                node->path_element->current_command.smooth_cubic_curve->point1->x,
                node->path_element->current_command.smooth_cubic_curve->point1->y);
            printf("Point d'arrivée : [ X = %d, Y = %d ]\n\n",
                node->path_element->current_command.smooth_cubic_curve->point2->x,
                node->path_element->current_command.smooth_cubic_curve->point2->y);
        break;
        case QUADRA_CURVE:
            printf("Type : "BOLD_WHITE_TEXT"QUADRATIC CURVE (Q)"RESET_STYLE"\n");
            printf("Point de contrôle : [ X = %d, Y = %d ]\n",
                node->path_element->current_command.quadra_curve->point1->x,
                node->path_element->current_command.quadra_curve->point1->y);
            printf("Point d'arrivée : [ X = %d, Y = %d ]\n\n",
                node->path_element->current_command.quadra_curve->point2->x,
                node->path_element->current_command.quadra_curve->point2->y);
        break;
        case SMOOTH_QUADRA_CURVE:
            printf("Type : "BOLD_WHITE_TEXT"SMOOTH QUADRATIC CURVE (T)"RESET_STYLE"\n");
            printf("Point d'arrivée : [ X = %d, Y = %d ]\n\n",
                node->path_element->current_command.smooth_quadra_curve->p->x,
                node->path_element->current_command.smooth_quadra_curve->p->y);
        break;
        case CLOSE:
            printf("Type : "BOLD_WHITE_TEXT"CLOSE (Z)"RESET_STYLE"\n");
            printf("Fermeture du chemin.\n\n");
        break;
    }
}

int Modify_path_element_menu() {
    int choice = 0;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│   MODIFIER L'ÉLÉMENT         │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    switch (choice) {
        case MOVE_TO:
        case LINE_TO:
            printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier X\n");
            printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier Y\n");
            printf(BRIGHT_CYAN"  3)"RESET_STYLE" Quitter\n\n");
        break;
        case H_LINE_TO:
            printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier X\n");
            printf(BRIGHT_CYAN"  2)"RESET_STYLE" Quitter\n\n");
        break;
        case V_LINE_TO:
            printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier Y\n");
            printf(BRIGHT_CYAN"  2)"RESET_STYLE" Quitter\n\n");
        break;
        case CUBIC_CURVE:
            printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier point de contrôle 1\n");
            printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier point de contrôle 2\n");
            printf(BRIGHT_CYAN"  3)"RESET_STYLE" Modifier point d'arrivée\n");
            printf(BRIGHT_CYAN"  4)"RESET_STYLE" Quitter\n\n");
        break;
        case SMOOTH_CUBIC_CURVE:
        case QUADRA_CURVE:
            printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier point de contrôle\n");
            printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier point d'arrivée\n");
            printf(BRIGHT_CYAN"  3)"RESET_STYLE" Quitter\n\n");
        break;
        case SMOOTH_QUADRA_CURVE:
            printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier point d'arrivée\n");
            printf(BRIGHT_CYAN"  2)"RESET_STYLE" Quitter\n\n");
        break;
        case CLOSE:
            printf(BRIGHT_CYAN"  1)"RESET_STYLE" Quitter\n\n");
        break;
    }

    return Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez une option : "RESET_STYLE, 1, 4);
}

void Modify_path_element(Node* node) {
    if(!Does_path_element_exist(node)) return;
    int choice = 0, breaker = 0;

    do {
        system("clear");
        Display_path_element_detailed(node);

        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│   MODIFIER L'ÉLÉMENT         │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

        switch (node->path_element->commands) {
            case MOVE_TO:
            case LINE_TO: {
                Point** p = (node->path_element->commands == MOVE_TO) ?
                    &(node->path_element->current_command.move_to->p) :
                    &(node->path_element->current_command.line_to->p);
                
                printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier X\n");
                printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier Y\n");
                printf(BRIGHT_CYAN"  3)"RESET_STYLE" Quitter\n\n");

                choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 3);
                Delete_two_lines();

                if (choice == 1) (*p)->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                else if (choice == 2) (*p)->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                else return;
                break;
            }
            case H_LINE_TO:
                printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier X\n");
                printf(BRIGHT_CYAN"  2)"RESET_STYLE" Quitter\n\n");

                choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 2);
                Delete_two_lines();

                if (choice == 1) node->path_element->current_command.h_line_to->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                else return;
                break;

            case V_LINE_TO:
                printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier Y\n");
                printf(BRIGHT_CYAN"  2)"RESET_STYLE" Quitter\n\n");

                choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 2);
                Delete_two_lines();

                if (choice == 1) node->path_element->current_command.v_line_to->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                else return;
                break;

            case CUBIC_CURVE:
                printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier point de contrôle 1\n");
                printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier point de contrôle 2\n");
                printf(BRIGHT_CYAN"  3)"RESET_STYLE" Modifier point d'arrivée\n");
                printf(BRIGHT_CYAN"  4)"RESET_STYLE" Quitter\n\n");

                choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 4);
                Delete_two_lines();

                if (choice == 1) {
                    node->path_element->current_command.cubic_curve->point1->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                    node->path_element->current_command.cubic_curve->point1->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                } else if (choice == 2) {
                    node->path_element->current_command.cubic_curve->point2->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                    node->path_element->current_command.cubic_curve->point2->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                } else if (choice == 3) {
                    node->path_element->current_command.cubic_curve->point3->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                    node->path_element->current_command.cubic_curve->point3->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                } else return;
                break;

            case SMOOTH_CUBIC_CURVE:
                printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier point de contrôle\n");
                printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier point d'arrivée\n");
                printf(BRIGHT_CYAN"  3)"RESET_STYLE" Quitter\n\n");

                choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 3);
                Delete_two_lines();

                if (choice == 1) {
                    node->path_element->current_command.smooth_cubic_curve->point1->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                    node->path_element->current_command.smooth_cubic_curve->point1->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                } else if (choice == 2) {
                    node->path_element->current_command.smooth_cubic_curve->point2->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                    node->path_element->current_command.smooth_cubic_curve->point2->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                } else return;
                break;

            case QUADRA_CURVE:
                printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier point de contrôle\n");
                printf(BRIGHT_CYAN"  2)"RESET_STYLE" Modifier point d'arrivée\n");
                printf(BRIGHT_CYAN"  3)"RESET_STYLE" Quitter\n\n");

                choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 3);
                Delete_two_lines();

                if (choice == 1) {
                    node->path_element->current_command.quadra_curve->point1->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                    node->path_element->current_command.quadra_curve->point1->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                } else if (choice == 2) {
                    node->path_element->current_command.quadra_curve->point2->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                    node->path_element->current_command.quadra_curve->point2->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                } else return;
                break;

            case SMOOTH_QUADRA_CURVE:
                printf(BRIGHT_CYAN"  1)"RESET_STYLE" Modifier point d'arrivée\n");
                printf(BRIGHT_CYAN"  2)"RESET_STYLE" Quitter\n\n");

                choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 2);
                Delete_two_lines();

                if (choice == 1) {
                    node->path_element->current_command.smooth_quadra_curve->p->x = Int_recup_verify(BRIGHT_GREEN"Nouvelle position X : "RESET_STYLE);
                    node->path_element->current_command.smooth_quadra_curve->p->y = Int_recup_verify(BRIGHT_GREEN"Nouvelle position Y : "RESET_STYLE);
                } else return;
                break;

            case CLOSE:
                printf(BRIGHT_CYAN"  1)"RESET_STYLE" Quitter\n\n");
                choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Votre choix : "RESET_STYLE, 1, 1);
                return;
                break;
        }

        system("clear");
        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│ CONTINUER LES MODIFICATIONS ?│\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);
        breaker = Chrono_assassin(5);
        system("clear");

    } while(!breaker);
}

void Delete_path_element_by_index(HeadPath* head, int index) {
    if (!Does_path_exist(head)) {
        Print_in_red("Shape not found.\n");
        return;
    }

    if (index <= 0) {
        Auto_write(BRIGHT_RED"\nIndex invalide ..."RESET_STYLE, 30000);
        sleep(2);
        system("clear");
        return;
    }

    Node* node = head->start;
    int current_index = 1;

    while (node != NULL && current_index < index) {
        node = node->next;
        current_index++;
    }

    if (!Does_path_element_exist(node)) {
        Auto_write(BRIGHT_RED"\nÉlément inexistant ..."RESET_STYLE, 30000);
        sleep(2);
        system("clear");
        return;
    }

    printf(BRIGHT_CYAN"\n╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"  SUPPRESSION DE L'ÉLÉMENT N°%d \n"RESET_STYLE, index);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf("Élément à supprimer : ");
    Display_path_element(node);
    printf("\n\nConfirmez-vous la suppression ?\n");
    printf(BRIGHT_GREEN"Attendez la fin du chrono pour confirmer ou appuyez sur une touche avant pour annuler :  "RESET_STYLE);

    int breaker = Chrono_assassin(5);

    if (!breaker) {
        Auto_write(BRIGHT_RED"\nSuppression annulée...\n"RESET_STYLE, 30000);
        sleep(2);
        system("clear");
        return;
    }

    if (node->previous == NULL && node->next == NULL) {
        head->start = NULL;
    } else if (node->previous == NULL) {
        head->start = node->next;
        node->next->previous = NULL;
    } else if (node->next == NULL) {
        node->previous->next = NULL;
    } else {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }

    Destroy_path_element(node);

    Auto_write(BRIGHT_RED"\n\nÉlément supprimé."RESET_STYLE, 30000);
    Auto_write(BRIGHT_YELLOW"\n\nRetour ...\n"RESET_STYLE, 30000);
    sleep(1);
}

int Modify_path_menu() {
    int choice = 0;

    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
    printf(BRIGHT_CYAN"│    MODIFIER LE PATH          │\n"RESET_STYLE);
    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n\n"RESET_STYLE);

    printf(BRIGHT_CYAN"  1)"RESET_STYLE" Agir sur un élément existant\n");
    printf(BRIGHT_CYAN"  2)"RESET_STYLE" Ajouter un élément\n");
    printf(BRIGHT_CYAN"  3)"RESET_STYLE" Supprimer un élément\n");
    printf(BRIGHT_CYAN"  4)"RESET_STYLE" Quitter\n\n");

    choice = Int_recup_verify_with_padding(BRIGHT_GREEN"Choisissez une option : "RESET_STYLE, 1, 4);
    Delete_two_lines();
    return choice;
}

void Modify_path(HeadPath* head) {
    if(!Does_path_exist(head)) return;

    int choice = 0, breaker = 0;

    do {
        system("clear");
        Display_path(head);
        choice = Modify_path_menu();

        switch(choice) {
            case 1: {
                system("clear");
                Display_path(head);
                int index = Int_recup_verify(BRIGHT_GREEN"Sur quel élément souhaitez-vous agir ? : "RESET_STYLE);
                Node* current = head->start;
                int counter = 1;
                while(current && counter < index) {
                    current = current->next;
                    counter++;
                }
                if(!current) {
                    Print_in_red("Élément inexistant.\n");
                    sleep(2);
                } else Modify_path_element(current);
                break;
            }
            case 2: {
                int cont = 0;
                do {
                    system("clear");
                    int cmd = Menu_commands() - 1;
                    Node* new_node = Create_new_path_element(cmd);
                    
                    if(!new_node) {
                        Print_in_red("Erreur lors de la création.\n");
                        sleep(2);
                        break;
                    }

                    printf("Souhaitez vous lire la documentation ?\n");
                    printf("Tapez une touche avant la fin du chrono pour skip :  ");
                    Chrono(5);

                    if (kbhit()) getchar();
                    else {
                        switch(cmd) {
                            case MOVE_TO: Infos_M(); break;
                            case LINE_TO: Infos_L(); break;
                            case H_LINE_TO: Infos_H(); break;
                            case V_LINE_TO: Infos_V(); break;
                            case CUBIC_CURVE: Infos_C(); break;
                            case SMOOTH_CUBIC_CURVE: Infos_S(); break;
                            case QUADRA_CURVE: Infos_Q(); break;
                            case SMOOTH_QUADRA_CURVE: Infos_T(); break;
                            case CLOSE: Infos_Z(); break;
                        }
                    }

                    system("clear");
                    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                    printf(BRIGHT_CYAN"│      AJOUTER UN ÉLÉMENT ?    │\n"RESET_STYLE);
                    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);

                    switch(cmd) {
                        case MOVE_TO:
                            new_node->path_element->current_command.move_to->p->x = Int_recup_verify(BRIGHT_GREEN"Entrez la valeur du point X : "RESET_STYLE);
                            new_node->path_element->current_command.move_to->p->y = Int_recup_verify(BRIGHT_GREEN"Entrez la valeur du point Y : "RESET_STYLE);
                            break;
                        case LINE_TO:
                            new_node->path_element->current_command.line_to->p->x = Int_recup_verify(BRIGHT_GREEN"Entrez la valeur du point X : "RESET_STYLE);
                            new_node->path_element->current_command.line_to->p->y = Int_recup_verify(BRIGHT_GREEN"Entrez la valeur du point Y : "RESET_STYLE);
                            break;
                        case H_LINE_TO:
                            new_node->path_element->current_command.h_line_to->x = Int_recup_verify(BRIGHT_GREEN"Entrez la valeur du point sur X : "RESET_STYLE);
                            break;
                        case V_LINE_TO:
                            new_node->path_element->current_command.v_line_to->x = Int_recup_verify(BRIGHT_GREEN"Entrez la valeur du point sur Y : "RESET_STYLE);
                            break;
                        case CUBIC_CURVE:
                            new_node->path_element->current_command.cubic_curve->point1->x = Int_recup_verify(BRIGHT_GREEN"Point de contrôle 1 - X : "RESET_STYLE);
                            new_node->path_element->current_command.cubic_curve->point1->y = Int_recup_verify(BRIGHT_GREEN"Point de contrôle 1 - Y : "RESET_STYLE);
                            new_node->path_element->current_command.cubic_curve->point2->x = Int_recup_verify(BRIGHT_GREEN"Point de contrôle 2 - X : "RESET_STYLE);
                            new_node->path_element->current_command.cubic_curve->point2->y = Int_recup_verify(BRIGHT_GREEN"Point de contrôle 2 - Y : "RESET_STYLE);
                            new_node->path_element->current_command.cubic_curve->point3->x = Int_recup_verify(BRIGHT_GREEN"Point d'arrivée - X : "RESET_STYLE);
                            new_node->path_element->current_command.cubic_curve->point3->y = Int_recup_verify(BRIGHT_GREEN"Point d'arrivée - Y : "RESET_STYLE);
                            break;
                        case SMOOTH_CUBIC_CURVE:
                            new_node->path_element->current_command.smooth_cubic_curve->point1->x = Int_recup_verify(BRIGHT_GREEN"Point de contrôle - X : "RESET_STYLE);
                            new_node->path_element->current_command.smooth_cubic_curve->point1->y = Int_recup_verify(BRIGHT_GREEN"Point de contrôle - Y : "RESET_STYLE);
                            new_node->path_element->current_command.smooth_cubic_curve->point2->x = Int_recup_verify(BRIGHT_GREEN"Point d'arrivée - X : "RESET_STYLE);
                            new_node->path_element->current_command.smooth_cubic_curve->point2->y = Int_recup_verify(BRIGHT_GREEN"Point d'arrivée - Y : "RESET_STYLE);
                            break;
                        case QUADRA_CURVE:
                            new_node->path_element->current_command.quadra_curve->point1->x = Int_recup_verify(BRIGHT_GREEN"Point de contrôle - X : "RESET_STYLE);
                            new_node->path_element->current_command.quadra_curve->point1->y = Int_recup_verify(BRIGHT_GREEN"Point de contrôle - Y : "RESET_STYLE);
                            new_node->path_element->current_command.quadra_curve->point2->x = Int_recup_verify(BRIGHT_GREEN"Point d'arrivée - X : "RESET_STYLE);
                            new_node->path_element->current_command.quadra_curve->point2->y = Int_recup_verify(BRIGHT_GREEN"Point d'arrivée - Y : "RESET_STYLE);
                            break;
                        case SMOOTH_QUADRA_CURVE:
                            new_node->path_element->current_command.smooth_quadra_curve->p->x = Int_recup_verify(BRIGHT_GREEN"Point d'arrivée - X : "RESET_STYLE);
                            new_node->path_element->current_command.smooth_quadra_curve->p->y = Int_recup_verify(BRIGHT_GREEN"Point d'arrivée - Y : "RESET_STYLE);
                            break;
                        case CLOSE:
                            break;
                    }

                    Add_path_element(head, new_node);
                    system("clear");
                    Display_path(head);
                    printf("\n");
                    printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
                    printf(BRIGHT_CYAN"│  AJOUTER UN AUTRE ÉLÉMENT ?  │\n"RESET_STYLE);
                    printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
                    printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);
                    cont = Chrono_assassin(5);
                    system("clear");
                } while(!cont);
                break;
            }
            case 3:
                system("clear");
                Display_path(head);
                int index = Int_recup_verify(BRIGHT_GREEN"Quel élément souhaitez-vous supprimer ? : "RESET_STYLE);
                Node* current = head->start;
                int counter = 1;
                while(current && counter < index) {
                    current = current->next;
                    counter++;
                }
                if(!current) {
                    Print_in_red("Élément inexistant.\n");
                    sleep(2);
                } else Delete_path_element_by_index(head, index);
                break;

            case 4:
                return;

            default:
                Print_in_red("INVALID ! ");
            break;
        }

        system("clear");
        printf("\n");
        printf(BRIGHT_CYAN"╭──────────────────────────────╮\n"RESET_STYLE);
        printf(BRIGHT_CYAN"│  CONTINUER LES MODIFS ?      │\n"RESET_STYLE);
        printf(BRIGHT_CYAN"╰──────────────────────────────╯\n"RESET_STYLE);
        printf(BRIGHT_GREEN"Appuyez sur une touche avant la fin du chrono pour continuer :  "RESET_STYLE);
        breaker = Chrono_assassin(5);
        system("clear");

    } while(!breaker);
}

Node* Get_path_element_by_index(HeadPath* head, int index) {
    if (!Does_path_exist(head)) return NULL;
    if (index <= 0) return NULL;

    Node* node = head->start;
    int counter = 1;

    while (node != NULL && counter < index) {
        node = node->next;
        counter++;
    }

    return node;
}

void Export_path(HeadPath* head, Style* style) {
    if (!Does_path_exist(head)) return;
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
    if (!svg) {
        Print_in_red("SVG Not Found.\n");
        return;
    }

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

    fprintf(write_file, "  <path d=\"");

    Node* node = head->start;
    int first = 1;

    while(node != NULL) {
        if (!first) fprintf(write_file, " ");
        first = 0;

        switch (node->path_element->commands) {
            case MOVE_TO:
                fprintf(write_file, "M%d %d",
                    node->path_element->current_command.move_to->p->x,
                    node->path_element->current_command.move_to->p->y);
            break;
            case LINE_TO:
                fprintf(write_file, "L%d %d",
                    node->path_element->current_command.line_to->p->x,
                    node->path_element->current_command.line_to->p->y);
            break;
            case H_LINE_TO:
                fprintf(write_file, "H%d",
                    node->path_element->current_command.h_line_to->x);
            break;
            case V_LINE_TO:
                fprintf(write_file, "V%d",
                    node->path_element->current_command.v_line_to->x);
            break;
            case CUBIC_CURVE:
                fprintf(write_file, "C%d %d %d %d %d %d",
                    node->path_element->current_command.cubic_curve->point1->x,
                    node->path_element->current_command.cubic_curve->point1->y,
                    node->path_element->current_command.cubic_curve->point2->x,
                    node->path_element->current_command.cubic_curve->point2->y,
                    node->path_element->current_command.cubic_curve->point3->x,
                    node->path_element->current_command.cubic_curve->point3->y);
            break;
            case SMOOTH_CUBIC_CURVE:
                fprintf(write_file, "S%d %d %d %d",
                    node->path_element->current_command.smooth_cubic_curve->point1->x,
                    node->path_element->current_command.smooth_cubic_curve->point1->y,
                    node->path_element->current_command.smooth_cubic_curve->point2->x,
                    node->path_element->current_command.smooth_cubic_curve->point2->y);
            break;
            case QUADRA_CURVE:
                fprintf(write_file, "Q%d %d %d %d",
                    node->path_element->current_command.quadra_curve->point1->x,
                    node->path_element->current_command.quadra_curve->point1->y,
                    node->path_element->current_command.quadra_curve->point2->x,
                    node->path_element->current_command.quadra_curve->point2->y);
            break;
            case SMOOTH_QUADRA_CURVE:
                fprintf(write_file, "T%d %d",
                    node->path_element->current_command.smooth_quadra_curve->p->x,
                    node->path_element->current_command.smooth_quadra_curve->p->y);
            break;
            case CLOSE:
                fprintf(write_file, "Z");
            break;
        }

        node = node->next;
    }

    fprintf(write_file,
        "\" fill=\"rgba(%d,%d,%d,%.2f)\" stroke=\"rgba(%d,%d,%d,%.2f)\" stroke-width=\"%d\"",
        style->Rf, style->Gf, style->Bf, style->Af, style->Rs, style->Gs, style->Bs, style->As,
        style->stroke_width);

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
    printf("Souhaitez-vous ouvrir le fichier pour visualiser votre path ? \n");
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


// int main() {

//     HeadPath* head = Create_new_path();
//     Recup_path_data(head);
//     Display_path(head);
//     Destroy_path(head);

//     return EXIT_SUCCESS;
// }