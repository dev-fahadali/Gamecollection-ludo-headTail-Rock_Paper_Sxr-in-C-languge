#include<stdio.h>
#include<unistd.h>
#include<time.h>

//menu prototype
void menu();
//case 1:
int ludo();
//case 2
int rock;
void decider();
int star1=0;star2=0;
int Computer_Number();
void winners_of_round(int playerMove, int Freya_Move);
//case3
int head();
int decision(char alphabet);
int bat();

int bat_score=0;
int bowl_score=0;
int count=0;
int count1=0;
void total(int player,int freya);

int main() {

menu();




return 0;
}




void menu()
{
int choice;
star1=0;
star2=0;
printf("Press 1 for ludo\nPress 2 for Rock/paper/scissor\npress 3 for Head/Tail\n");
printf("\n\n\nPress any key to exit\n\n\n");

scanf("%d",&choice);

char toss;
   switch(choice)
   
{
case 1: 
{
     ludo();
     break;
} 
 case 2: 
{ 
              Rock();
              break;
}
 
 case 3:
{ 
          
         head(toss);
         break;
}
 
          
default:
   return 0;
}
}










//Function for head/tail
int head() 
{
char toss;

printf(".....................Welcome to Head/Tail Game!.....................\n");
    printf("Rules:\n1:The limit for score is 6 breaking this rule will lead to exit of the program\n2:Do as you're instructed pressing any other keys will lead to the exit of the game and program\nYou can play this game only once\n*Follow the Rules!\n*Have Fun");


printf("\nPress H for Head\nPress T for tail\n");
          scanf(" %c",&toss);
          if(toss =='H' || toss=='h'|| toss=='t'|| toss=='T') 
          {
          if( toss =='H' || toss=='h')
          {
          printf("You chose Head and Freya Chose Tail");
         
          }
          else if(toss=='t'|| toss=='T') 
               {
               printf("You chose Tail and Freya Chose Head");
               
               }
               
         }
         else if(toss !='H' || toss!='h'|| toss!='t'|| toss!='T'){
         printf("\nYou Entered the wrong key hence breaking the rule \n");
         sleep(2);
         return 0;}







int player=0,freya=0;
char P,F;
while(player==freya) {
player=0,freya=0;


printf("\ntossing the coin\n");



srand(time(NULL));
freya=rand()%5+1;
sleep(2);
srand(time(NULL));
player=rand()%5+1;

if (player>freya){
      printf("\tCongratulations! You won the Toss\n");
      decision ('P');
    }
    else if(freya>player){
         printf("\tFreya won the Toss\n");
         decision ('F');
         }
         else 
      printf("\tDraw");

}
}







int decision(char alphabet)
{    
     char P,F;
     int choice=0;
     if(alphabet=='P'){
     printf("\nWhat would You like to do Bat or Bowl?\nPress 1 for Bat\nPress 2 for Bowl\n");
     scanf("%d",&choice);
     if(choice < 1 || choice>2){
     printf("You broke the rule");
     return 0;}
     if(choice==1)
             bat(); 
      if(choice==2)
              bowl();   
     }
     
     
     if(alphabet=='F') {
     srand(time(NULL));
     choice=rand()%2+1;
     
     if(choice==1){
      printf("\nFreya Chose to Bat\n");
      bowl();
     }
     else if(choice==2){
     printf("\nFreya Chose to Bowl\n\n");
     
     bat();
     }
     }
     
}




int bat() 
{
int score_of_player=0,score_of_freya=0,score_player=0;
if(count==1)
{
total(bat_score,bowl_score);
}
else if(count==0)
{ 
count++;
printf("\n\nYou're Batting\n");
do
   {     
         
         printf("\n\n\nEnter the Score:  ");
         scanf("%d",&score_of_player);
         if(score_of_player>6 || score_of_player<1 ){
         printf("\nYou  broke the Rule\n");
         return 0;}
         srand(time(NULL));
         score_of_freya= rand()%6+1;   // generating random score for freya
         if(score_of_freya!=score_of_player)
            score_player+= score_of_player; // storing score of batsman 
         
         
         printf("\n\n\tYou're score\tFreya score\n\t%d\t\t%d\n",score_player,score_of_freya);
         if(count1==1){
            if(bowl_score<score_player){
            total(bat_score,score_player);
            return 0;
            
            }
          
         }
         
         
         if(score_of_player==score_of_freya)
         {      
                bat_score=score_player;
                printf("\n\nYou're Out!\n");
                bowl();
                
         }
                                
    }
          while(score_of_player > score_of_freya || score_of_player < score_of_freya);   
   
              
} } 



int bowl()
{
int score_of_player=0,score_of_freya=0,score_player=0,score=0;
       if(count1==1)
       {
           total(bat_score,bowl_score); 
       }
       else if(count1==0)
       { 
         count1++;
         printf("You're Bowling\n");
do
   {     
         
         printf("\n\n\nEnter score:  ");
         scanf("%d",&score_of_player);
         if(score_of_player>6 || score_of_player <1 ){
         printf("\nYou broke the rule\n");
         return 0;}
         srand(time(NULL));
         score_of_freya= rand()%6+1;   // generating random score for freya
         if(score_of_freya!=score_of_player)
                      score_player+= score_of_freya; // storing score of batsman
         
         printf("\nScore of Freya:  %d",score_of_freya);
         printf("\n\n\n\tFreya score\tYou're bowl score\n\t%d\t\t%d\n\n\n",score_player,score_of_player);
         
         if(count==1){
            if(bat_score<score_player){
            total(bat_score,score_player);
            return 0;
            }
            }
         
         if(score_of_player==score_of_freya)
         {      
                bowl_score=score_player;
                printf("\n\nFreya is Out!");
                bat();
                
         }
   } 
          while(score_of_player > score_of_freya || score_of_player < score_of_freya);   
   
            }    
}

void total(int player,int freya)

{  
   count1=0,count1=0;
   printf("\nResult is being Calculated\n");
   sleep(4);
   if(player > freya )
       printf("\n\t\tYou won the match\n");
  else if(freya>player)
       printf("\n\t\tFreya won the match\n");
   else if(freya==player)
        printf("\nMatch is drawn");
        
}






//Functions for Rock/paper



void winners_of_round(int playerMove, int Freya_Move) {
    if (playerMove == Freya_Move) {
        printf("      Result : Match is tie because Freya has the same move as you !\n\n");
    } else if ((playerMove == 1 && Freya_Move == 3) || (playerMove == 2 && Freya_Move == 1) || (playerMove == 3 && Freya_Move == 2)) {
        printf("      Result : You Win Round\n\n");
        star1++ ;
    } else {
        printf("      Result : Freya Wins Round\n\n");
        star2++ ;
    }
}


int Rock(){
int playerMove;
    int Freya_Move;
    int playerScore = 0;
    int Freya_score = 0;
    char play_Again;
    srand(srand(time(NULL)));
     printf(".....................Welcome to Rock-Paper-Scissors Game!.....................\n");
    printf("Rules:\n");
    printf("1. There are 5 rounds in this game.\n");
    printf("2. If you make an invalid choice three times in a row, the game will exit.\n");
    printf("............................................................................\n\n");
    sleep(2);
    srand(time(NULL));

    int repeatedInvalidMoves = 0;

    do {
        for (int round = 1; round <= 5; ++round) {
            printf("......Round %d......\n\n", round);
            printf("Enter Your Move From 1-3 As\n\n1.Rock\n\n2.Paper\n\n3.Scissors\n\n");
            printf("Enter :");
            
            scanf("%d", &playerMove);


                if(playerMove < 1|| playerMove > 3)
                {
                repeatedInvalidMoves++;
                if(repeatedInvalidMoves<=2){
                 printf("Invalid Input.Please enter a number between 1 and 3.\n");
                  }
                 if(repeatedInvalidMoves>=3){
                 printf("\n*You Broke the rule*\n\n\n");
                 menu();
                 return 0;} 
                

                round--; 
                continue;
             }

            repeatedInvalidMoves = 0; 
            Freya_Move = rand() % 3 + 1;;
            
            
            
            Freya_Move = rand() % 3 + 1;;
           
            
            
            printf("You Choose: %d\n", playerMove);
            printf("Freya Chooses: %d\n", Freya_Move);
            

            
            printf("Calculating result...\n\n");
            sleep(3);
            winners_of_round(playerMove, Freya_Move);
            
           }

        printf("\n  Final  Result\n");
        sleep(2);
        decider();
        

        printf("\nDo You Want To Play Again?\n");
        printf("\n.....Press 'Y' for Yes, 'X' for Main Menu:..... \n*CAUTION*PRESSING ANY OTHER KEY WILL LEAD TO EXIT FROM THE PROGRAM\n");
        scanf(" %c", &play_Again);

     }while (play_Again == 'y' || play_Again == 'Y');

    if(play_Again == 'X' || play_Again == 'x')
    {
        menu();
    }
    else 
    return 0;
      

    
}
void decider()  {

if (star1>star2)
   printf("\nCongratulation you won \n");
   
if(star2>star1)
   printf("\nFreya has won ");
if(star2==star1)
   printf("\nDraw\n");

}







//function for ludu
int ludo(){
char play_again;
do{

printf(".....................Welcome to Dice Game!.....................\n");
   

	char player1[100],player2[100];
	
	printf("\nPlayer 1, please enter you're name: ");
	scanf("%s",player1);
	
	printf("\nPlease 2, please enter you're name: ");
	scanf("%s",player2);
	
	char total1[4];
	char total2[4];
	srand(time(NULL));

	printf("Rolling the dice for %s",player1);
	
	
	
	for (int i=0,j=1;i<=2;i++,j++) { 
		total1[i] = rand() %6 + 1; // generating random numbers and storing it in an array 
		sleep(1);
		printf("\nDice %d : %d",j,total1[i]);
	}
	printf("\n\n\nRolling dice for %s",player2);
	
	
	for (int i=0,j=1;i<=2;i++,j++) {
		total2[i] = rand() %6 + 1;  // generating random numbers and storing it in an array 
		sleep(1);
		printf("\nDice %d : %d",j,total2[i]);
	}
	
	printf("\nCalculating the total scores...");
	
	
	int score1=0;
	for (int for1=0; for1<=2 ;for1++) {
		
		score1+=total1[for1];
	}
	int score2=0;
	for (int for2=0; for2<=2 ;for2++) {
		
		score2+=total2[for2];
	}
	sleep(2);
    printf("\nTotal score for %s :%d",player1,score1);
    printf("\nTotal score for %s :%d",player2,score2);
    
    if (score1>score2) {
    	printf("\nAnd the winner is... %s! Congratulation! ",player1);
}
	else if(score1<score2) {
	
		printf("\nAnd the winner is... %s! Congratulation!",player2);
}
	else if(score1==score2) {
		
		
		for(int check=0;check<=2;check++) {
			if(player1[check]>player2[check]) {
			printf("\nAnd the winner is... %s! Congratulation! ",player1);
			break;
	     	}
			else if(player1[check]<player2[check]) {
			printf("\nAnd the winner is... %s! Congratulation! ",player2);
			break;
			}
			else  {
					printf("Tie");
			}
		
		}
	}
	printf("\nDo You Want To Play Again?\n");
        printf("\n.....Press 'Y' for Yes, 'X' for Main Menu:..... \n*CAUTION*PRESSING ANY OTHER KEY WILL LEAD TO EXIT FROM THE PROGRAM\n");
        
        scanf(" %c",&play_again);
        
	} while (play_again =='y'|| play_again =='Y');
	if(play_again=='x' || play_again=='X')
	   menu();
	   else 
	     return 0;
}