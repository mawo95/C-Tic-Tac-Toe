#include <cstdio>

//0 = empty, 1 = player (X), 2 = pc (O)

int arr[3][3] = {};

void printBoard(){
  for(int i = 0; i < 3; ++i){
    printf("\n");
    for(int j = 0; j < 3; ++j){
      char place;
      if(arr[i][j] == 0){
        place = ' ';
      }else if(arr[i][j] == 1){
        place = 'X';
      }else{
        place = 'O';
      }
      if(j == 2){printf("%c",place);}else{
      printf("%c | ",place);
      }
      
    }
  }
}

bool doPlayer(){
  int zeile;
  int spalte;
  printf("\nZeile eingeben: ");
  scanf("%i",&zeile);
  printf("\nSpalte eingeben: ");
  scanf("%i",&spalte);
  if(zeile < 3 && zeile > -1 && spalte < 3 & spalte > -1){

  if(arr[zeile][spalte] == 0){
    arr[zeile][spalte] = 1;

    if (arr[zeile][0] == 1 && arr[zeile][1] == 1 && arr[zeile][2] == 1){
        return true;

    }else if (arr[0][spalte] == 1 && arr[1][spalte] == 1 && arr[2][spalte] == 1){
       return true;

   
    }else if (arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 1){
        return true;

    }else if (arr[0][2] == 1 && arr[1][1] == 1 && arr[2][0] == 1){
        return true;
    }else{
      return false;
    }

    




  }else{
    printf("\nbesetzt");
    return doPlayer();
  }

}else{
  printf("\nne");
  return doPlayer();
}
}

bool doPc(){
  
    int i, j;

    for (i = 0; i < 3; i++) {
        if (arr[i][0] == 2 && arr[i][1] == 2 && arr[i][2] == 0) { arr[i][2] = 2; return true; }
        if (arr[i][0] == 2 && arr[i][2] == 2 && arr[i][1] == 0) { arr[i][1] = 2; return true; }
        if (arr[i][1] == 2 && arr[i][2] == 2 && arr[i][0] == 0) { arr[i][0] = 2; return true; }

        if (arr[0][i] == 2 && arr[1][i] == 2 && arr[2][i] == 0) { arr[2][i] = 2; return true; }
        if (arr[0][i] == 2 && arr[2][i] == 2 && arr[1][i] == 0) { arr[1][i] = 2; return true; }
        if (arr[1][i] == 2 && arr[2][i] == 2 && arr[0][i] == 0) { arr[0][i] = 2; return true; }
    }

    if (arr[0][0] == 2 && arr[1][1] == 2 && arr[2][2] == 0) { arr[2][2] = 2; return true; }
    if (arr[0][0] == 2 && arr[2][2] == 2 && arr[1][1] == 0) { arr[1][1] = 2; return true; }
    if (arr[1][1] == 2 && arr[2][2] == 2 && arr[0][0] == 0) { arr[0][0] = 2; return true; }

    if (arr[0][2] == 2 && arr[1][1] == 2 && arr[2][0] == 0) { arr[2][0] = 2; return true;}
    if (arr[0][2] == 2 && arr[2][0] == 2 && arr[1][1] == 0) { arr[1][1] = 2; return true; }
    if (arr[1][1] == 2 && arr[2][0] == 2 && arr[0][2] == 0) { arr[0][2] = 2; return true; }

    for (i = 0; i < 3; i++) {
        if (arr[i][0] == 1 && arr[i][1] == 1 && arr[i][2] == 0) { arr[i][2] = 2; return false; }
        if (arr[i][0] == 1 && arr[i][2] == 1 && arr[i][1] == 0) { arr[i][1] = 2; return false; }
        if (arr[i][1] == 1 && arr[i][2] == 1 && arr[i][0] == 0) { arr[i][0] = 2; return false; }

        if (arr[0][i] == 1 && arr[1][i] == 1 && arr[2][i] == 0) { arr[2][i] = 2; return false; }
        if (arr[0][i] == 1 && arr[2][i] == 1 && arr[1][i] == 0) { arr[1][i] = 2; return false; }
        if (arr[1][i] == 1 && arr[2][i] == 1 && arr[0][i] == 0) { arr[0][i] = 2; return false; }
    }

    if (arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 0) { arr[2][2] = 2; return false; }
    if (arr[0][0] == 1 && arr[2][2] == 1 && arr[1][1] == 0) { arr[1][1] = 2; return false; }
    if (arr[1][1] == 1 && arr[2][2] == 1 && arr[0][0] == 0) { arr[0][0] = 2; return false; }

    if (arr[0][2] == 1 && arr[1][1] == 1 && arr[2][0] == 0) { arr[2][0] = 2; return false; }
    if (arr[0][2] == 1 && arr[2][0] == 1 && arr[1][1] == 0) { arr[1][1] = 2; return false; }
    if (arr[1][1] == 1 && arr[2][0] == 1 && arr[0][2] == 0) { arr[0][2] = 2; return false; }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 2;
                return false;
            }
        }
    }
}





void startGame(){
  while(true){
    if(arr[0][0] == 0 || arr[0][1] == 0 || arr[0][2] == 0 || arr[1][0] == 0 || arr[1][1] == 0 || arr[1][2] == 0 || arr[2][0] == 0 || arr[2][1] == 0 || arr[2][2] == 0){



  printBoard();
  bool won = doPlayer();
  if(won == true){
    printf("\nPlayer won!");
    break;
  }
  printBoard();
  if(arr[0][0] == 0 || arr[0][1] == 0 || arr[0][2] == 0 || arr[1][0] == 0 || arr[1][1] == 0 || arr[1][2] == 0 || arr[2][0] == 0 || arr[2][1] == 0 || arr[2][2] == 0){

  printf("\nPC:");
  bool won2 = doPc();
  if(won2 == true){
    printf("\nComputer won!");
    break;
  }
}else{
  printf("\nUnentschieden");
  break;
}

}else{
  printf("\nUnentschieden!");
  break;
}

}
printBoard();

}

int main(){
  startGame();
  return 0;
}