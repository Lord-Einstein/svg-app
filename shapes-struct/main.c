#include "./main.h"
#include "../other/kbhit.c"

//Noms de structures, d'enums, d'unions :: PascalCase
//Noms de varaibles :: snake_case
//Noms de fontions ou de procédures :: Big_snake_case

typedef struct {
    int minx; //-50 default
    int miny; //-50% default
    unsigned int width; //200 default
    unsigned int height; // 200 default

} ViewBox;

typedef struct{

    unsigned int width; //100% default
    unsigned int height; //100% default
    const char* xlmns;
    ViewBox* view_box;

} Svg;

typedef struct {
    int cx;
    int cy;
    unsigned int rx;
} Circle;

typedef struct {
    Circle* circle;
    unsigned int ry;
} Ellipse;

void Infos_cercle() {
    system("clear");
    printf("\nLe saviez-vous ?\n");
    printf("Le 'circle' en SVG est un élément de la catégorie des Formes simples, utilisé pour créer des cercles, en se basant sur un centre et un rayon.\nPour le créer, il faut passer trois paramètres de base esentiels :\n\nLa position sur X du centre = cx (entier);\nLa position sur Y du centre = cy (entier);\nLa taille du rayon(entier non signé) = rx\n\n");
}

void Delete_a_consol_line(){
    printf("\r                                                                                            \r");
}

void Chrono(int chrono) {
    if(chrono > 9) chrono = 9;
    while(chrono > 0 && !kbhit()){

        printf("\b%d", chrono); //À noter que %2d oblige un aff sur deux car avec un space devant sinon %02d le fait rn remplaçant space par 0
        chrono--;
        sleep(1);

    }
    system("clear");
    printf("\n");
}

void Drain_buffer() {
    int c; //C'est mieux qu'un char, d'toutes façons getchar renvoie un int !!
    while((c = getchar()) != '\n' && c != EOF);
}

int Int_recup_verify(const char* prompt){ //Juste pour être sûr que mon prompt ne sera pas modifié
    int scanf_return = 0;
    int a_int = 0;

    do{

        printf("%s", prompt);
        scanf_return = scanf("%d", &a_int);

        if(scanf_return != 1){
            Drain_buffer();
            printf("Entrée invalide !\n\n");
        }

    }while(scanf_return != 1);
    Drain_buffer();

    return a_int;   

}

unsigned int Unsigned_int_recup_verify(const char* prompt){ //Juste pour être sûr que mon prompt ne sera pas modifié
    int scanf_return = 0, a_int = 0;
    unsigned int a_unsigned_int = 0;

    do{

        printf("%s", prompt);
        scanf_return = scanf("%d", &a_int);

        if((scanf_return != 1)  || (a_int < 0)){
            Drain_buffer();
            printf("Entrée invalide !\n\n");
        }

    }while((scanf_return != 1) || (a_int < 0));
    a_unsigned_int = (unsigned int)a_int;
    Drain_buffer();

    return a_unsigned_int;   

}


void Recup_circle_data(Circle* circle) {

    printf("Souhaitez vous lire la documentation pour concevoir un cercle ?\n");
    printf("Tapez une touche avant la fin du chrono pour skip :  ");

    Chrono(5);

    
    if (kbhit()) getchar();//je vide le buffer, juste au cas où.
    else Infos_cercle();

    circle->cx = Int_recup_verify("Entrez la position X du centre : ");
    circle->cy = Int_recup_verify("Entrez la position Y du centre : ");
    circle->rx = Unsigned_int_recup_verify("Entrez le rayon de votre cercle(px) : ");

}


Circle* Create_circle(int cx, int cy, unsigned int rx) {
    Circle* circle = malloc(sizeof(Circle));

    if (!circle) return NULL;

    circle->cx = cx;
    circle->cy = cy;
    circle->rx = rx;

    return circle;
}

void Destroy_circle(Circle* circle) {
    if(!circle) return; // Je vérifie toujours que le pointeur existe pour éviter le Segfault de mes deux !!!
    free(circle);
}



// int Data_type_verifier(){
    
// }

Ellipse* Create_ellipse(int cx, int cy, unsigned int rx, unsigned int ry) {
    Ellipse* ellipse = malloc(sizeof(Ellipse));

    if(!ellipse) return NULL;

    ellipse->circle = Create_circle(cx, cy, rx);
    if(!ellipse->circle) return NULL;
    ellipse->ry = ry;

    return ellipse;
}

void Destroy_ellipse(Ellipse* ellipse) {
    if(!ellipse) return; 
    Destroy_circle(ellipse->circle); //Bah ouais faut libérer le pointeur sur le cercle d'abord. Pas de memory leak aujourd'hui !
    free(ellipse);
}

void Display_circle(Circle* circle) {
    system("clear");
    printf("\n======== CERCLE ========\n");
    printf("\nPosition sur l'axe X : %d", circle->cx);
    printf("\nPosition sur l'axe Y : %d", circle->cy);
    printf("\nRayon(px) : %u\n\n", circle->rx);
}

void Display_ellipse(Ellipse* ellipse) {
    system("clear");
    printf("\n======== ELLIPSE ========\n");
    printf("\nPosition sur l'axe X : %d", ellipse->circle->cx);
    printf("\nPosition sur l'axe Y : %d", ellipse->circle->cy);
    printf("\nRayon sur l'axe X (px) : %u", ellipse->circle->rx);
    printf("\nRayon sur l'axe Y(px) : %u", ellipse->ry);
}

// void Edit_circle(Circle *circle) {

// }



int main(void) {

    Circle* circle = Create_circle(0,0,0);
    Recup_circle_data(circle);
    Display_circle(circle);
    Destroy_circle(circle);

    return EXIT_SUCCESS;
}

