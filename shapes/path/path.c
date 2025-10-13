#include "./path.h"

void Infos_path() {
    system("clear");
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
    printf("\nCommande M (moveto)\n");
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
    printf("\nCommande L (lineto)\n");
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
    printf("\nCommande H (horizontal lineto)\n");
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
    printf("\nCommande V (vertical lineto)\n");
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
    printf("\nCommande C (cubic Bézier curve)\n");
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
    printf("\nCommande S (smooth cubic Bézier)\n");
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
    printf("\nCommande Q (quadratic Bézier curve)\n");
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
    printf("\nCommande T (smooth quadratic Bézier)\n");
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
    printf("\nCommande Z (closepath)\n");
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

void Display_path_element(Node* node){
    if(!Does_path_element_exist(node)){
        Print_in_red("\nSub Shape not found !\n");
        return;
    }

    switch (node->path_element->commands)
    {
    case MOVE_TO:
        printf("  %c %d %d  ", node->type, node->path_element->current_command.move_to->p->x, node->path_element->current_command.move_to->p->y);
    break;
    case LINE_TO:
        printf("   %c %d %d   ", node->type, node->path_element->current_command.line_to->p->x, node->path_element->current_command.line_to->p->y);
    break;
    case H_LINE_TO:
        printf("   %c %d   ", node->type, node->path_element->current_command.h_line_to->x);
    break;
    case V_LINE_TO:
        printf("   %c %d   ", node->type, node->path_element->current_command.v_line_to->x);
    break;
    case CUBIC_CURVE:
        printf("   %c %d %d  %d %d  %d %d   ", node->type, node->path_element->current_command.cubic_curve->point1->x, node->path_element->current_command.cubic_curve->point1->y, node->path_element->current_command.cubic_curve->point2->x, node->path_element->current_command.cubic_curve->point2->y, node->path_element->current_command.cubic_curve->point3->x, node->path_element->current_command.cubic_curve->point3->y);
    break;
    case SMOOTH_CUBIC_CURVE:
        printf("   %c %d %d  %d %d   ", node->type, node->path_element->current_command.smooth_cubic_curve->point1->x, node->path_element->current_command.smooth_cubic_curve->point1->y, node->path_element->current_command.smooth_cubic_curve->point2->x, node->path_element->current_command.smooth_cubic_curve->point2->y);
    break;
    case QUADRA_CURVE:
        printf("   %c %d %d  %d %d   ", node->type, node->path_element->current_command.quadra_curve->point1->x, node->path_element->current_command.quadra_curve->point1->y, node->path_element->current_command.quadra_curve->point2->x, node->path_element->current_command.quadra_curve->point2->y);
    break;
    case SMOOTH_QUADRA_CURVE:
        printf("   %c %d %d   ", node->type, node->path_element->current_command.smooth_quadra_curve->p->x, node->path_element->current_command.smooth_quadra_curve->p->y);
    break;
    case CLOSE:
        printf("   %c   ", node->type);
    break;
    default:
        printf("\nCommand not found\n");
        return;
    break;
    }


}


void Display_path(HeadPath* head){
    if(!Does_path_exist(head)){
        Print_in_red("\nShape not found\n");
        return;
    }

    Node* node = head->start;
    printf("\n");
    // system("clear");
    printf(BOLD_WHITE_TEXT"\n======== "UNDERLINE_WHITE_TEXT" PATH "RESET_STYLE BOLD_WHITE_TEXT" ========\n\n"RESET_STYLE);
    printf("D >>> ");

    while(node != NULL){
        Display_path_element(node);
        node = node->next;
    }

    printf("\n");
}

void Add_path_element(HeadPath* head, Node* new_node){

    if(!Does_path_exist(head)) return;
    if(!Does_path_element_exist(new_node)) return;

    Node* node = head->start;

    if(node == NULL) {
        head->start = new_node;
        return;
    }

    while(node->next != NULL){
        node = node->next;
    }

    node->next = new_node;
    new_node->previous = node;

}

int Menu_commands() {

    printf("\r"BOLD_WHITE_TEXT""UNDERLINE_WHITE_TEXT" MENU DE COMMANDES "RESET_STYLE BOLD_WHITE_TEXT"\n\n"RESET_STYLE);
    printf("1) Déplacer le curseur \n2) Tracer une ligne depuis le point courant\n3) Tracer une ligne horizontale\n4) Tracer une ligne verticale\n5) Tracer une courbe de Bézier\n6) Tracer la variante de la courbe de Bézier\n7) Tracer la Quadratique de Bézier\n8) Tracer la variante de la Quadratique de Bézier\n9) Refermez une forme\n\n");

    return Int_recup_verify("Choisissez la commande à ajouter à votre 'Path' : ");
}

void Recup_path_data(HeadPath* head) {
    
    if(!Does_path_exist(head)) return;

    int choice = 0, breaker = 0;

    printf("Souhaitez vous lire la documentation pour concevoir un 'Path' ? \n");
    printf("Tapez une touche avant la fin du chrono pour skip :  ");
    Chrono(5);

    if (kbhit()) getchar();
    else {Infos_path();}

    Node* node = NULL;

    do{

        choice = Menu_commands();

        switch (--choice) {
        case MOVE_TO:
            printf("\n\nSouhaitez vous lire la documentation sur la commande MOVE TO ? \n");
            printf("Tapez une touche avant la fin du chrono pour skip :  ");
            Chrono(5);

            if (kbhit()) getchar();
            else Infos_M();

            node = Create_new_path_element(choice);
            
            node->path_element->current_command.move_to->p->x = Int_recup_verify("Entrez la valeur du point X : ");
            node->path_element->current_command.move_to->p->y = Int_recup_verify("Entrez la valeur du point Y : ");

            Add_path_element(head, node);

        break;
        case LINE_TO:
            printf("Souhaitez vous lire la documentation sur la commande LINE TO ? \n");
            printf("Tapez une touche avant la fin du chrono pour skip :  ");
            Chrono(5);

            if (kbhit()) getchar();
            else Infos_L();

            node = Create_new_path_element(choice);
            
            node->path_element->current_command.line_to->p->x = Int_recup_verify("Entrez la valeur du point X : ");
            node->path_element->current_command.line_to->p->y = Int_recup_verify("Entrez la valeur du point Y : ");

            Add_path_element(head, node);

        break;
        case H_LINE_TO:
            printf("Souhaitez vous lire la documentation sur la commande HORIZONTAL LINE TO ? \n");
            printf("Tapez une touche avant la fin du chrono pour skip :  ");
            Chrono(5);

            if (kbhit()) getchar();
            else Infos_H();

            node = Create_new_path_element(choice);
            
            node->path_element->current_command.h_line_to->x = Int_recup_verify("Entrez la valeur du point sur X : ");

            Add_path_element(head, node);

        break;
        case V_LINE_TO:
            printf("Souhaitez vous lire la documentation sur la commande VERTICAL LINE TO ? \n");
            printf("Tapez une touche avant la fin du chrono pour skip :  ");
            Chrono(5);

            if (kbhit()) getchar();
            else Infos_V();

            node = Create_new_path_element(choice);
            
            node->path_element->current_command.v_line_to->x = Int_recup_verify("Entrez la valeur du point sur Y : ");
            
            Add_path_element(head, node);

        break;
        case CUBIC_CURVE:
            printf("Souhaitez vous lire la documentation sur la commande CUBIC CURVE ? \n");
            printf("Tapez une touche avant la fin du chrono pour skip :  ");
            Chrono(5);

            if (kbhit()) getchar();
            else Infos_C();

            node = Create_new_path_element(choice);
            
            node->path_element->current_command.cubic_curve->point1->x = Int_recup_verify("Entrez la valeur du premier point de contrôle sur X : ");
            node->path_element->current_command.cubic_curve->point1->y = Int_recup_verify("Entrez la valeur du premier point de contrôle sur Y : ");
            node->path_element->current_command.cubic_curve->point2->x = Int_recup_verify("Entrez la valeur du second point de contrôle sur X : ");
            node->path_element->current_command.cubic_curve->point2->y = Int_recup_verify("Entrez la valeur du second point de contrôle sur Y : ");
            node->path_element->current_command.cubic_curve->point3->x = Int_recup_verify("Entrez la valeur du point d'arrivée sur X : ");
            node->path_element->current_command.cubic_curve->point3->y = Int_recup_verify("Entrez la valeur du point d'arrivée sur Y : ");
            
            Add_path_element(head, node);

        break;
        case SMOOTH_CUBIC_CURVE:
            printf("Souhaitez vous lire la documentation sur la commande SMOOTH CUBIC CURVE ? \n");
            printf("Tapez une touche avant la fin du chrono pour skip :  ");
            Chrono(5);

            if (kbhit()) getchar();
            else Infos_S();

            node = Create_new_path_element(choice);
            
            node->path_element->current_command.smooth_cubic_curve->point1->x = Int_recup_verify("Entrez la valeur du second point de contrôle sur X : ");
            node->path_element->current_command.smooth_cubic_curve->point1->y = Int_recup_verify("Entrez la valeur du second point de contrôle sur Y : ");
            node->path_element->current_command.smooth_cubic_curve->point2->x = Int_recup_verify("Entrez la valeur du point d'arrivée sur X : ");
            node->path_element->current_command.smooth_cubic_curve->point2->y = Int_recup_verify("Entrez la valeur du point d'arrivée sur Y : ");
            
            Add_path_element(head, node);

        break;
        case QUADRA_CURVE:
            printf("Souhaitez vous lire la documentation sur la commande QUADRATIC CURVE ? \n");
            printf("Tapez une touche avant la fin du chrono pour skip :  ");
            Chrono(5);

            if (kbhit()) getchar();
            else Infos_Q();

            node = Create_new_path_element(choice);
            
            node->path_element->current_command.quadra_curve->point1->x = Int_recup_verify("Entrez la valeur du point de contrôle sur X : ");
            node->path_element->current_command.quadra_curve->point1->y = Int_recup_verify("Entrez la valeur du point de contrôle sur Y : ");
            node->path_element->current_command.quadra_curve->point2->x = Int_recup_verify("Entrez la valeur du point d'arrivée sur X : ");
            node->path_element->current_command.quadra_curve->point2->y = Int_recup_verify("Entrez la valeur du point d'arrivée sur Y : ");
            
            Add_path_element(head, node);

        break;
        case SMOOTH_QUADRA_CURVE:
            printf("Souhaitez vous lire la documentation sur la commande SMOOTH QUADRATIC CURVE ? \n");
            printf("Tapez une touche avant la fin du chrono pour skip :  ");
            Chrono(5);

            if (kbhit()) getchar();
            else Infos_T();

            node = Create_new_path_element(choice);
            
            node->path_element->current_command.smooth_quadra_curve->p->x = Int_recup_verify("Entrez la valeur du point d'arrivée sur X : ");
            node->path_element->current_command.smooth_quadra_curve->p->y = Int_recup_verify("Entrez la valeur du point d'arrivée sur Y : ");
            
            Add_path_element(head, node);

        break;
        case CLOSE:
            printf("Souhaitez vous lire la documentation sur la commande CLOSE ? \n");
            printf("Tapez une touche avant la fin du chrono pour skip :  ");
            Chrono(5);

            if (kbhit()) getchar();
            else Infos_Z();

            node = Create_new_path_element(choice);
            
            Add_path_element(head, node);

        break;
        
        default:
            Print_in_red("Command not found !");
        break;
        }

        // system("clear");
        printf("\n\nSouhaitez vous insérer une autre commande à votre path ?");
        printf("\nTapez une touche avant la fin du chrono pour skip :  ");
        breaker = Chrono_assassin(5);
        system("clear");

    }while(breaker);

}


// int main() {

//     HeadPath* head = Create_new_path();
//     Recup_path_data(head);
//     Display_path(head);
//     Destroy_path(head);

//     return EXIT_SUCCESS;
// }