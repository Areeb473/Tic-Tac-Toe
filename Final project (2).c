#include <stdio.h>
#include <stdlib.h>


//Here i am creating all the necessary variables and i am making them universal because i need to use them in multiple functions......

char Game[4][4];    // this is the board that represents or game..

char Player = 'X';   // this is the charecter that represents players UI.
char Player2 = 'O'; // this is the charecter that represents Computers UI.



// Calling out all functions that will make the basic functionality of the game

void reset();
void display();

int checkemptyboxes();                 // Checkng how many empty boxes are left ( IF ANY );;;
void PlayerTurn();                     // To give turn to The Player
void Player2Turn();                   // To give turn to The Player 2

char FindWinner();                        // To check who is the winner
void DisplayWinner(char);                 // To display the winner



int main()
{
	
	
	
	
		
   char winner = ' ';   //  Declaring two charecters which are the winner and the Users response  to play again,,,   initially the winner is null   
   
   do                       // using do-while loop
   {
      winner = ' ';
      
      reset();                 //calling out the reset function

      while(winner == ' ' && checkemptyboxes() != 0)   // the program will run when empty spaces are more than zero and winner is not yer declared
      {
         display();          // this will print the board in the console

         PlayerTurn();      // calling the function to give player's turn
         winner = FindWinner();      //if findWinner function reurns the winner succesfully then this will set the winner to whatever the thing that the funcction returns
         
         if(winner != ' ' || checkemptyboxes() == 0)   // if winner is null or either boxes are all full then the game will stop
         {
            break;
         }

         Player2Turn();       // this function will give Player 2 its turn// checking if winner function is returning anything after Second Player's turn

         
         winner = FindWinner();  // checking the winner's condition again
\
         if(winner != ' ' || checkemptyboxes() == 0)     // if winner is null or either boxes are all full then the game will stop
         {
            break;
         }
      }

      display();                               //calling function to display game board
      DisplayWinner(winner);                   //calling function to display game winner


     
   } while (winner == ' ');

   printf("Thanks for your attention!");

   return 0;
}
        
//	return 0;



void display()    // this function will print the game board

{
	
	
   printf("| %c | %c | %c | %c |", Game[0][0], Game[0][1], Game[0][2], Game[0][3]);
   printf("\n|---|---|---|---|\n");
   printf("| %c | %c | %c | %c |", Game[1][0], Game[1][1], Game[1][2], Game[1][3]);
   printf("\n|---|---|---|---|\n");
   printf("| %c | %c | %c | %c |", Game[2][0], Game[2][1], Game[2][2], Game[2][3]);
   printf("\n|---|---|---|---|\n");
   printf("| %c | %c | %c | %c |", Game[3][0], Game[3][1], Game[3][2], Game[3][3]);
   printf("\n");
}

void reset() 
{
	int i, j;    // loop supporters
	
	for(i = 0; i < 4; i++)             // using nested for-loop to create board           
   {
      for(j = 0; j < 4; j++)
      {
         Game[i][j] = ' ';
      }
   }
}


void PlayerTurn()
{
	int x;      // this represents the row index
    int y;      // this represents the coulumn index

   do
   {
      printf("Player 1, Enter row (1-4)");    // taking inut of row index
      scanf("%d", &x);
      x--;                         
      
      /*   X-- is due to the fact that the first index is 0 in programming while for user's betterment we show it to 1
 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\          So x-- will reduce the value by 1 of whatever the input user gives
           this will alter the gap of program and tha user input
     */    
      
      printf("Player 1, Enter column (1-4)");  // taking inut of Coulumn index
      scanf("%d", &y);
      y--;
      
      /*   Y-- is due to the fact that the first index is 0 in programming while for user's betterment we show it to 1
           So y-- will reduce the value by 1 of whatever the input user gives
           this will alter the gap of program and tha user input
     */    
     
     printf("------------------------------------------------------------------\n");

      if(Game[x][y] != ' ')
      {
         printf("Box Taken!!! \n");
      }
      else
      {
         Game[x][y] = Player;
         break;
      }
   } while (Game[x][y] != ' ');
}

void Player2Turn()     //This function gives turn to Player 2
{
	int x;      // this represents the row index
    int y;      // this represents the coulumn index

   do
   {
      printf("Player 2 Enter row (1-4)");    // taking inut of row index
      scanf("%d", &x);
      x--;                         
      
      /*   X-- is due to the fact that the first index is 0 in programming while for user's betterment we show it to 1
           So x-- will reduce the value by 1 of whatever the input user gives
           this will alter the gap of program and tha user input
     */    
      
      printf("Player 2 Enter column (1-4)");  // taking inut of Coulumn index
      scanf("%d", &y);
      y--;
      
      /*   Y-- is due to the fact that the first index is 0 in programming while for user's betterment we show it to 1
           So y-- will reduce the value by 1 of whatever the input user gives
           this will alter the gap of program and tha user input
     */    
     
          
     printf("------------------------------------------------------------------\n");

      if(Game[x][y] != ' ')
      {
         printf("Box Taken!!!\n");
      }
      else
      {
         Game[x][y] = Player2;
         break;
      }
   } while (Game[x][y] != ' ');
}


int checkemptyboxes()            // function to check empty spaces plus this function will return a type integer which are the number of empty spaces
{
	int emptyboxes = 16;      // 4 by 4 game will have total 16 elements
	
	int i, j;            // loop suppoters

   for(i = 0; i < 4; i++)       // Outer loop is for rows
   {                                                            // nested loop to count the rows and coulumns that have been filled
      for(j = 0; j < 4; j++)    // inner loop is for coulumns
      {
         if(Game[i][j] != ' ')
         {
            emptyboxes--;
         }
      }
   }
   return emptyboxes;       // returns amount of empty boxes
}

char FindWinner()     // this function wil return the winner
{
	/* Here are the possible combinations || possible choices  
	   
	    1-2-3-4
	    5-6-7-8
	    9-10-11-12
	    13-14-15-16
	    1-6-11-16
	    4-7-10-13
	    
	*/
	
	int i, j;
	
   for(i = 0; i < 4; i++)                // checking rows
   {
      if(Game[i][0] == Game[i][1] && Game[i][0] == Game[i][2] && Game[i][0] == Game[i][3])
      {
         return Game[i][0];
      }
   }
   
   
   for(i = 0; i < 3; i++)              // checking coulumns
   {
      if(Game[0][i] == Game[1][i] && Game[0][i] == Game[2][i] && Game[0][i] == Game[3][i])
      {
         return Game[0][i];
      }
   }
                                          //checking diagonals
   if(Game[0][0] == Game[1][1] && Game[0][0] == Game[2][2], Game[0][0] == Game[3][3])
   {
      return Game[0][0];
   }
   
   if(Game[0][3] == Game[1][2] && Game[0][3] == Game[2][1], Game[0][3] == Game[3][0])
   {
      return Game[0][3];
   }

   return ' ';
}

void DisplayWinner(char winner)       // prints out the winner
{
	if (winner == Player)
   {
      printf("\n Player 1 IS THE WINNER! \n");
   }
   else 
   {
   	printf("\n Player 2 IS THE Winner! \n");
   }
}
   
      
   

