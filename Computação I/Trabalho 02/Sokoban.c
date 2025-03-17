#include<stdio.h>
#include<string.h>

int X, Y,cont;

void main(){
    char direcao;
    int campo[10][10] = {
                        {1,1,1,1,1,1,1,1,1,1},
                        {1,2,1,0,0,1,5,4,0,1},
                        {1,0,1,0,0,1,5,4,0,1},
                        {1,4,1,0,4,1,5,4,0,1},
                        {1,0,0,0,0,1,1,1,0,1},
                        {1,0,1,0,0,0,0,1,0,1},
                        {1,5,1,0,0,0,0,0,0,1},
                        {1,1,1,0,0,0,0,0,0,1},
                        {1,1,1,0,0,0,0,0,5,1},
                        {1,1,1,1,1,1,1,1,1,1}
                        };
    printf("BEM VIND@ A SOKOBAN! \n");
    printf("\nPara movimentar o personagem(x) utilize  W/A/S/D\n\n");
    printf("Para comecar, digite ENTER:\n");
    printf("Para encerrar, a qualquer momento digite 0\n");
    printf("Para recomecar, a qualquer momento digite 1\n\n");
    getch();
    system("@cls||clear");

    do{
        imprimirMatriz(campo);
        direcao = getch();

        switch(direcao){
            case 'w':
            case 'W':
                movimentarW(campo);
                break;
            case 'a':
            case 'A':
                movimentarA(campo);
                break;
            case 's':
            case 'S':
                movimentarS(campo);
                break;
            case 'd':
            case 'D':
                movimentarD(campo);
                break;
            case '0':
                printf("\nOBRIGADA POR JOGAR SOKOBAN! \n");
                exit(0);
            case '1':
                system("@cls||clear");
                cont = 0;
                main();
                exit(0);
            default:
                printf("\n***CARACTER INVALIDO***");
                printf("\nDigite ENTER e tente novamente:\n");
                getch();
                break;
            }
            system("@cls||clear");
            if(cont == 5){
                printf("\nPARABENS! VOCE VENCEU! \n");
                printf("\nDigite 0 para encerrar");
                printf("\nDigite 1 para jogar novamente\n\n");
            }

        }while(1);


}

void imprimirMatriz(int campo[10][10]){

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(campo[i][j]==2){
                X = i;
                Y = j;
            }
            if(campo[i][j]==0){
                printf("  ");
            }else if(campo[i][j]==2){
                printf("x ");
            }else if(campo[i][j]==1){
                printf("# ");
            }
            else if(campo[i][j]==4){
                printf("a ");
            }
            else if(campo[i][j]==5){
                printf("O ");
            }
            else if(campo[i][j]==9){
                printf("@ ");
            }

        }
        printf("\n");
    }
}

void movimentarA(int campo[10][10]){
    if(campo[X][Y-1] == 0){
        campo[X][Y-1] = 2;
        campo[X][Y] = 0;
    }
    if(campo[X][Y-1]==4){
        if(campo[X][Y-2]==0){
            campo[X][Y-2] = campo[X][Y+1];
            campo[X][Y-1] = campo[X][Y];
            campo[X][Y] = 0;
        }
    if(campo[X][Y-2]==5){
            campo[X][Y-2]=9;
            campo[X][Y-1] = campo[X][Y];
            campo[X][Y] = 0;
            cont++;
        }

    }
}

void movimentarD(int campo[10][10]){
    if(campo[X][Y+1] == 0){
        campo[X][Y+1] = 2;
        campo[X][Y] = 0;
    }
    if(campo[X][Y+1]==4){
        if(campo[X][Y+2]==0){
            campo[X][Y+2] = campo[X][Y+1];
            campo[X][Y+1] = campo[X][Y];
            campo[X][Y] = 0;
        }
    if(campo[X][Y+2]==5){
            campo[X][Y+2]=9;
            campo[X][Y+1] = campo[X][Y];
            campo[X][Y] = 0;
            cont++;
        }

    }
}

void movimentarW(int campo[10][10]){
    if(campo[X-1][Y] == 0){
        campo[X-1][Y] = 2;
        campo[X][Y] = 0;
    }
    if(campo[X-1][Y]==4){
        if(campo[X-2][Y]==0){
            campo[X-2][Y] = campo[X-1][Y];
            campo[X-1][Y] = campo[X][Y];
            campo[X][Y] = 0;
        }
    if(campo[X-2][Y]==5){
            campo[X-2][Y]=9;
            campo[X-1][Y] = campo[X][Y];
            campo[X][Y] = 0;
            cont++;
        }
    }
}

void movimentarS(int campo[10][10]){
    if(campo[X+1][Y] == 0){
        campo[X+1][Y] = 2;
        campo[X][Y] = 0;
    }
    if(campo[X+1][Y]==4){
        if(campo[X+2][Y]==0){
            campo[X+2][Y] = campo[X+1][Y];
            campo[X+1][Y] = campo[X][Y];
            campo[X][Y] = 0;
        }
    if(campo[X+2][Y]==5){
            campo[X+2][Y]=9;
            campo[X+1][Y] = campo[X][Y];
            campo[X][Y] = 0;
            cont++;
        }

    }

}

