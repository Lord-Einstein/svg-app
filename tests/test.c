#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../other/kbhit.c"


void Infos_cercle() {
    system("clear");
    printf("\nLe saviez-vous ?\n");
    printf("Le 'circle' en SVG est un élément de la catégorie des Formes simples, utilisé pour créer des cercles, en se basant sur un centre et un rayon.\nPour le créer, il faut passer trois paramètres de base esentiels :\n\nLa position sur X du centre = cx;\nLa position sur Y du centre = cy;\nLa taille du rayon(px) = rx\n\n");
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

void Recup_circle_data() {


    printf("Souhaitez vous lire la documentation pour concevoir un cercle ?\n");
    printf("Tapez une touche avant la fin du chrono pour skip :  ");

   Chrono(100);

    if (kbhit()) getchar(); //je vide le buffer, juste au cas où.
    else Infos_cercle();

}

int main(void) {

    Recup_circle_data();

    return EXIT_SUCCESS;
}
