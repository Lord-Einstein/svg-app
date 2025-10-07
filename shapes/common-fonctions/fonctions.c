#include "./fonctions.h"


// PROCEDURES -------------------

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



// FONCTIONS ---------------------

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

unsigned int Unsigned_int_recup_verify(const char* prompt) { //Juste pour être sûr que mon prompt ne sera pas modifié
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
