#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>

void print_board(int [][5],int [][5],int,char);
void prepare_board(int [][5],int []);
void print_desk(int []);
int your_card(int []);
int control(int [][5],int,int);
void update(int [6],int [][5],int [][5],int *,int);
int high_score(int,char);

int main(){
	
	int board[5][5];
	int player_board[5][5]={0};
	int cards[25]={1,1,1,1,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,6};
	int desk[6]={5,2,2,1,1,1};
	int score=0,highscore;
	char control='r';
	int hand=1;
	int i,j;
	
	srand(time(NULL));
	
	highscore=high_score(score,control);
	prepare_board(board,cards);
	while(hand!=-1){
		print_board(board,player_board,score,control);
		print_desk(desk);
		update(desk,board,player_board,&score,hand);
		hand=your_card(desk);
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			player_board[i][j]=1;
		}
	}
	control = 'w';
	print_board(board,player_board,score,control);
	
	if(score>=10 && score<=399){
		printf("You earned Bronze Chest!");
	}
	else if(score>=400 && score<=549){
		printf("You earned Silver Chest!");
	}
	else if(score>=550){
		printf("You earned Gold Chest");
	}
	
	getch();
	
	
	return 0;
}


void update(int desk[6],int board[5][5],int player_board[5][5],int *score,int hand){
	
	int x,y;
	int i,j;
	int flag;
	static int horizontal[5],vertical[5],diagonal[2];

	do{
		printf("\nEnter the number of rows and columns of the number you want to select (Exp:2 4):");
		scanf("%d %d",&x,&y);
	}while(player_board[x-1][y-1]==1 || x>5 || y>5);
	
	if(hand!=5){
		
		if(board[x-1][y-1]<hand){
			if(hand!=6){
				if(control(board,x-1,y-1)==1){
					printf("5 ALERT!\n");
				}
				if(board[x-1][y-1]==75){
					printf("Card: K\n");
				}
				else{
					printf("Card: %d\n",board[x-1][y-1]);
				}
				player_board[x-1][y-1]=1;
				*score=*score+board[x-1][y-1]*10;
			}
			else{
				player_board[x-1][y-1]=1;
				*score=*score+board[x-1][y-1]*10;
				desk[hand-1]--;
				if(board[x-1][y-1]==75){
					printf("Card: K\n");
				}
				else{
					printf("Card: %d\n",board[x-1][y-1]);
				}
			}
			
		}
		else if(board[x-1][y-1]==hand){
			if(control(board,x-1,y-1)==1){
				printf("5 ALERT!\n");
			}
			if(board[x-1][y-1]==75){
				printf("Card: K\n");
			}
			else{
				printf("Card: %d\n",board[x-1][y-1]);
			}
			player_board[x-1][y-1]=1;
			*score=*score+board[x-1][y-1]*10;
			desk[hand-1]--;
		}
		else{
			if(control(board,x-1,y-1)==1){
				printf("5 ALERT!\n");
			}
			desk[hand-1]--;
			if(board[x-1][y-1]==75){
				printf("Card: K\n");
			}
			else{
				printf("Card: %d\n",board[x-1][y-1]);
			}
			
			if(hand==6 && board[x-1][y-1]==75){
				*score+=100;
			}
		}
	}
	else{
		if(control(board,x-1,y-1)==1){
			printf("5 ALERT!\n");
			desk[hand-1]--;
			if(board[x-1][y-1]==75){
				printf("Card: K\n");
			}
			else{
				printf("Card: %d\n",board[x-1][y-1]);
			}
		}
		else{
			if(board[x-1][y-1]<hand){
			if(hand!=6){
				if(control(board,x-1,y-1)==1){
					printf("5 ALERT!\n");
				}
				printf("Card: %d\n",board[x-1][y-1]);
				player_board[x-1][y-1]=1;
				*score=*score+board[x-1][y-1]*10;
			}
			else{
				player_board[x-1][y-1]=1;
				*score=*score+board[x-1][y-1]*10;
				desk[hand-1]--;
			}
			
		}
		else if(board[x-1][y-1]==hand){
			if(control(board,x-1,y-1)==1){
				printf("5 ALERT!\n");
			}
			if(board[x-1][y-1]==75){
				printf("Card: K\n");
			}
			else{
				printf("Card: %d\n",board[x-1][y-1]);
			}
			player_board[x-1][y-1]=1;
			*score=*score+board[x-1][y-1]*10;
			desk[hand-1]--;
		}
		else{
			if(control(board,x-1,y-1)==1){
				printf("5 ALERT!\n");
			}
			desk[hand-1]--;
			if(board[x-1][y-1]==75){
				printf("Card: K\n");
			}
			else{
				printf("Card: %d\n",board[x-1][y-1]);
			}
			
			if(hand==6 && board[x-1][y-1]==75){
				*score+=100;
			}
		}
		}
	}
	
	for(i=0;i<5;i++){
		flag=1;
		for(j=0;j<5;j++){
			if(player_board[i][j]==0){
				flag=0;
			}
			
		}
		if(flag==1 && horizontal[i]==0){
			*score+=10;
			horizontal[i]=1;
			printf("Horizontal Bonus +10\n");
			
		}
	}
	
	
	for(i=0;i<5;i++){
		flag=1;
		for(j=0;j<5;j++){
			if(player_board[j][i]==0){
				flag=0;
			}
			
		}
		if(flag==1 && vertical[i]==0){
			*score+=10;
			vertical[i]=1;
			printf("Vertical Bonus +10\n");
			
		}
	}
	
	
	for(i=0;i<2;i++){
		flag=1;
		for(j=0;j<5;j++){
			if(player_board[j][j]==0){
				flag=0;
			}
			
		}
		if(flag==1 && diagonal[i]==0){
			*score+=10;
			diagonal[i]=1;
			printf("Diagonal Bonus +10\n");
			
		}
	}
	
	sleep(2);
}

int high_score(int score,char control){

	static int highscore=0;
	FILE *file=fopen("HighScore.txt","r+");;
	
	if(file!=NULL){
		if(control=='r'){
		fscanf(file, "%d", &highscore);	
		}
	
		else if(control=='w'){
			if(score>highscore){
				fprintf(file,"%d",score);
			}
		}
	
		fclose(file);
		return highscore;
	}
	
	else{
		return -1;
	}
	
	
	
	
}

int control(int board[5][5],int i,int j){
	
	int x[8]={+1, 0, -1, 0,+1,+1,-1,-1};
	int y[8]={0, +1, 0, -1,+1,-1,-1,+1};
	int direction;
	int flag;
	
	flag=1;
	direction=0;
	
	while(direction<8 && flag==1){
		if(i+x[direction]<5 && j+y[direction]<5 && i+x[direction]>=0 && j+y[direction]>=0){
			if(board[i+x[direction]][j+y[direction]]==5){
				flag=0;
			}
		}
		direction++;
	}
	if(flag==0){
		return 1;
	}
	else{
		return 0;
	}
	
}


int your_card(int desk[6]){
	
	int i;
	i=0;
	
	while(desk[i]==0 && i<6){
		i++;
	}
	if(i<6){
		return i+1;
	}
	else{
		return -1;
	}
	
}


void print_desk(int desk[6]){
	
	int i;
	
	printf("Your card: ");
	for(i=0;i<6;i++){
		if(desk[i]!=0){
			if(i==5){
				printf("K -> x%d\n",desk[i]);
			}
			else{
				printf("%d -> x%d\n",i+1,desk[i]);
			}
			
		}
	}
}

void prepare_board(int board[5][5],int cards[5]){
	
	int i,j;
	int random;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			do{
				random=rand()%25;
			}while(cards[random]==0);
			
			if(cards[random]!=6){
				board[i][j]=cards[random];
				cards[random]=0;
			}
			else{
				board[i][j]='K';
				cards[random]=0;
			}
		}
	}
	
}


void print_board(int board[5][5],int player_board[5][5],int score,char control){
	
	int i,j;
	int highscore;
	system("cls");
	
	printf("         1     2     3     4     5\n\n\n");
	
	for(i=0;i<5;i++){
		printf("%d     |",i+1);
		for(j=0;j<5;j++){
			if(player_board[i][j]==0){
				printf("%3c  |",242);	
			}
			else{
				if(board[i][j]==75){
					printf("%3c  |",board[i][j]);
				}
				else{
					printf("%3d  |",board[i][j]);
				}
				
			}
					
		}
		printf("\n\n");
	}
	printf("\nScore: %d\n",score);
	highscore=high_score(score,control);
	if(highscore!=-1){
		printf("HighScore: %d\n\n",highscore);
	}
	else{
		printf("HighScore: You should download the file named HighScore.txt!\n\n");
	}
	
}







