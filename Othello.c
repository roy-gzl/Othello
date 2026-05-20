#include<stdio.h>
#define PLAYER1 1
#define PLAYER2 -1
#define N 10

int board[N][N],check[N][N],current_player_id=1,i,j,k,p,judge_num,result=0,sum=0;

void print_board(int board[N][N]){
 int y,x;
 printf("   1 2 3 4 5 6 7 8\n");
 for( y = 1; y <= N-2; y++ ){
   printf(" %d",y);
   for( x = 1; x <= N-2; x++ ){
    if(board[y][x]==0 && check[y][x]>0)printf(" +");
    else if(board[y][x]==0)printf(" ."); //■ - をスペースに変えること
    else if(board[y][x]==1)printf(" ○");
    else if(board[y][x]==-1)printf(" ●");
   }
   printf("\n");
 }
 printf("\n");
 //デバッグ用．盤面の2値表示をする
/*  
 for( y = 1; y <= N-2; y++ ){
   for( x = 1; x <= N-2; x++ ){
    printf("%2d",check[y][x]);
   }
   printf("\n");
 }
   */
 printf("\n");
}

int judge(int x,int y,int board[N][N]){
  k=2;
  int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;

  k=2;
  if(board[y-1][x-1]==-current_player_id){
    while(board[y-k][x-k]==-current_player_id){
      k++;
    }
    if(board[y-k][x-k]==0){
      a=0;                       //置けない
    }else if(board[y-k][x-k]==current_player_id){
      a=1;
    }
  }else if(board[y-1][x-1]!=-current_player_id){
    a=0;
  }

  k=2;
  if(board[y-1][x]==-current_player_id){
    while(board[y-k][x]==-current_player_id){
      k++;
    }
    if(board[y-k][x]==0){
      b=0;                       //置けない
    }else if(board[y-k][x]==current_player_id){
      b=1;
    }
  }else if(board[y-1][x]!=-current_player_id){
    b=0;
  }

  k=2;
  if(board[y-1][x+1]==-current_player_id){
    while(board[y-k][x+k]==-current_player_id){
      k++;
    }
    if(board[y-k][x+k]==0){
      c=0;                       //置けない
    }else if(board[y-k][x+k]==current_player_id){
      c=1;
    }
  }else if(board[y-1][x+1]!=-current_player_id){
    c=0;
  }

  k=2;
  if(board[y][x+1]==-current_player_id){
    while(board[y][x+k]==-current_player_id){
      k++;
    }
    if(board[y][x+k]==0){
      d=0;                       //置けない
    }else if(board[y][x+k]==current_player_id){
      d=1;
    }
  }else if(board[y][x+1]!=-current_player_id){
    d=0;
  }

  k=2;
  if(board[y+1][x+1]==-current_player_id){
    while(board[y+k][x+k]==-current_player_id){
      k++;
    }
    if(board[y+k][x+k]==0){
      e=0;                       //置けない
    }else if(board[y+k][x+k]==current_player_id){
      e=1;
    }
  }else if(board[y+1][x+1]!=-current_player_id){
    e=0;
  }

  k=2;
  if(board[y+1][x]==-current_player_id){
    while(board[y+k][x]==-current_player_id){
      k++;
    }
    if(board[y+k][x]==0){
      f=0;                       //置けない
    }else if(board[y+k][x]==current_player_id){
      f=1;
    }
  }else if(board[y+1][x]!=-current_player_id){
    f=0;
  }

  k=2;
  if(board[y+1][x-1]==-current_player_id){
    while(board[y+k][x-k]==-current_player_id){
      k++;
    }
    if(board[y+k][x-k]==0){
      g=0;                       //置けない
    }else if(board[y+k][x-k]==current_player_id){
      g=1;
    }
  }else if(board[y+1][x-1]!=-current_player_id){
    g=0;
  }

  k=2;
  if(board[y][x-1]==-current_player_id){
    while(board[y][x-k]==-current_player_id){
      k++;
    }
    if(board[y][x-k]==0){
      h=0;                       //置けない
    }else if(board[y][x-k]==current_player_id){
      h=1;
    }
  }else if(board[y][x-1]!=-current_player_id){
    h=0;
  }

  return a+b+c+d+e+f+g+h;
}

void reverse(int x,int y,int board[N][N]){
  k=2;
  if(board[y-1][x-1]==-current_player_id){
    while(board[y-k][x-k]==-current_player_id){
      k++;
    }
    if(board[y-k][x-k]==current_player_id){
      for(i=1;i<k;i++){
        board[y-i][x-i]=current_player_id;
      }
    }
  }

  k=2;
  if(board[y-1][x]==-current_player_id){
    while(board[y-k][x]==-current_player_id){
      k++;
    }
    if(board[y-k][x]==current_player_id){
      for(i=1;i<k;i++){
        board[y-i][x]=current_player_id;
      }
    }
  }

  k=2;
  if(board[y-1][x+1]==-current_player_id){
    while(board[y-k][x+k]==-current_player_id){
      k++;
    }
    if(board[y-k][x+k]==current_player_id){
      for(i=1;i<k;i++){
        board[y-i][x+i]=current_player_id;
      }
    }
  }

  k=2;
  if(board[y][x+1]==-current_player_id){
    while(board[y][x+k]==-current_player_id){
      k++;
    }
    if(board[y][x+k]==current_player_id){
      for(i=1;i<k;i++){
        board[y][x+i]=current_player_id;
      }
    }
  }

  k=2;
  if(board[y+1][x+1]==-current_player_id){
    while(board[y+k][x+k]==-current_player_id){
      k++;
    }
    if(board[y+k][x+k]==current_player_id){
      for(i=1;i<k;i++){
        board[y+i][x+i]=current_player_id;
      }
    }
  }

  k=2;
  if(board[y+1][x]==-current_player_id){
    while(board[y+k][x]==-current_player_id){
      k++;
    }
    if(board[y+k][x]==current_player_id){
      for(i=1;i<k;i++){
        board[y+i][x]=current_player_id;
      }
    }
  }

  k=2;
  if(board[y+1][x-1]==-current_player_id){
    while(board[y+k][x-k]==-current_player_id){
      k++;
    }
    if(board[y+k][x-k]==current_player_id){
      for(i=1;i<k;i++){
        board[y+i][x-i]=current_player_id;
      }
    }
  }

  k=2;
  if(board[y][x-1]==-current_player_id){
    while(board[y][x-k]==-current_player_id){
      k++;
    }
    if(board[y][x-k]==current_player_id){
      for(i=1;i<k;i++){
        board[y][x-i]=current_player_id;
      }
    }
  }
}

void update_board(int x, int y, int current_player_id){
  do{
    printf("input x:");
    scanf("%d",&x);
    printf("input y:");
    scanf("%d",&y);
    if((x<1 || x>N-2) || (y<1 || y>N-2) || board[y][x]!=0 || check[y][x]==0){
      printf("Unavailable %d %d\n",x,y);
    }
  }while((x<1 || x>N-2) || (y<1 || y>N-2) || board[y][x]!=0 || check[y][x]==0);
    board[y][x]=current_player_id;
    reverse(x,y,board);
}

int turn_num(int current_player_id){
  if(current_player_id==-1){
    return 2;
  }else if (current_player_id==1){
    return 1;
  }
  return 0;
}

void make_check(int check[N][N]){
  for(j=1;j<N-1;j++){
    for(i=1;i<N-1;i++){
      if(board[j][i]==0){
        check[j][i]=judge(i,j,board);
      }else if(board[j][i]!=0){
        check[j][i]=0;
      }
    }
  }
}

int count_check(int check[N][N]){
  sum=0;
  for(j=1;j<N-1;j++){
    for(i=1;i<N-1;i++){
      sum+=check[j][i];
    }
  }
  return sum;
}

int full_board(int board[N][N]){
  for(j=1;j<N-1;j++){
    for(i=1;i<N-1;i++){
      if(board[j][i]==0){
        return 0;
      }
    }
  }
  return 1;
}

void clear_check(int check[N][N]){
  for(j=1;j<N-1;j++){
    for(i=1;i<N-1;i++){
      check[j][i]=0;
    }
  }
}

void print_result(int board[N][N]){
  int white=0,black=0;
  for(j=1;j<N-1;j++){
    for(i=1;i<N-1;i++){
      if(board[j][i]==PLAYER1){
        white++;
      }else if(board[j][i]==PLAYER2){
        black++;
      }
    }
  }

  printf("______________\n");
  clear_check(check);
  print_board(board);
  printf("RESULT\n");
  printf("○ PLAYER1:%d\n",white);
  printf("● PLAYER2:%d\n",black);
  if(white>black){
    printf("WINNER ○ PLAYER1\n");
  }else if(black>white){
    printf("WINNER ● PLAYER2\n");
  }else{
    printf("DRAW\n");
  }
}

int main(void){
  int y,x;
  for(y=0;y<N;y++){
    for(x=0;x<N;x++){
      board[y][x]=0;
    }
  }
  board[4][4]=1;board[4][5]=-1;board[5][4]=-1;board[5][5]=1;

  while(result==0){
    make_check(check);
    if(full_board(board)==1){
      result=1;
      break;
    }
    if(count_check(check)==0){
      printf("%s PLAYER%d PASS\n", current_player_id == PLAYER1 ? "○" : "●", turn_num(current_player_id));
      current_player_id*=-1;
      make_check(check);
      if(count_check(check)==0){
        result=1;
      }
      continue;
    }
    printf("______________\n");
    printf("%s PLAYER%d\n", current_player_id == PLAYER1 ? "○" : "●", turn_num(current_player_id));
    print_board(board); //配列を表示
    update_board(x,y,current_player_id); //配列をアップデート
    if(full_board(board)==1){
      result=1;
    }else{
      current_player_id*=-1;
    }
  }
  print_result(board);
  return 0;
}
