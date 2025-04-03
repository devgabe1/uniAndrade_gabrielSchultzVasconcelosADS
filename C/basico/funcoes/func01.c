#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// int main(int argc, char *argv[])
// {
//     for(int i=0; i < argc; i++){
//         printf("Arg[%i] %s\n", i, argv[i]);
//     }
//     return 0;
// }



float intToFloat(int n){
    float new = (float)n;
    return new;
}
void halfConvert(int n){
    float num = intToFloat(n);
    float half = num * 0.5;
    printf("Metade: %.2f\n", half);
}

void menu(){
    printf("\n\n\n\n================= NÚMERO FORMATADO ================\n");
    int i = 100;
    printf("Número: %i\n", i);
    halfConvert(100);
    printf("===================================================\n\n\n\n");
}

#define MAX_STR 50

typedef struct
{
    char name[50];
    float power;
    int lives;
    bool alive;

} Player;

void imprimePlayer(Player *p){

    for (int i=0; i>=2; i++){
        printf("\n========= GAME OVER ========\n\n");
        printf("Name: %s", p->name);
        printf("\nPower: %f", p->power);
        printf("\nLives: %i", p->lives);
        printf("\nAlive: %d", p->alive);
        printf("\n============================\n\n");
    }


}
int main(){
    Player players[] = {
        {.name = "Gabe", .power = 9999999999999.9999, .lives = 9249,  .alive = true  },
        {.name = "GuiGui", .power = 0.9999, .lives = 2, .alive = true}
    };
    imprimePlayer(&players);
    return 0;
}