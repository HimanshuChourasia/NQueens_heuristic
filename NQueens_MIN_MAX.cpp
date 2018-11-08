#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<random_generator.hpp>
using namespace std ;
class ChessBoard {
private:
vector<int> chess_rows ;
int iterations = 0;
int no_of_conflicts ;
// Intialize a chessboard of N  * N
public:
ChessBoard(){
}
// Randomizing the chessboard .
void randomizedChessBoard(int n)
{
    for(int i=0;i<n ;i++)
    {
        chess_rows.push_back(i);
    }
    fill();
}
// Placing each queen in a row and then randomizing the row and column values.
void fill()
{
    int total_conflicts = 0;
    for(int i=0;i<chess_rows.size() ; i++)
        {
            chess_rows[i] = i ;
        }
    for(int i =0 ;i < chess_rows.size();i++)
    {
        int random_cols = rand()%chess_rows.size() ;
        int random_rows = rand()%chess_rows.size() ;
        if (i != random_rows && chess_rows[i]!= chess_rows[random_rows])
            chess_rows[random_rows] = random_cols ;
        /* int temp = chess_rows[i];
        chess_rows[i] = chess_rows[random_cols];
        chess_rows[random_cols] = temp ;
 */
    }
    // Calculating the conflicts of the intial position of the queens.   
    for(int i =0 ; i< chess_rows.size();i++)
    {
        int eachQueenConflict = conflicts(chess_rows[i],i);
        total_conflicts = total_conflicts + eachQueenConflict;
    }
    no_of_conflicts = total_conflicts ;
}
// Conflicts function calculates the conflicts .
int conflicts(int row,int cols)
{
    no_of_conflicts = 0;
    for(int i = 0 ;i < chess_rows.size();i++)
    {
        if(i == cols)
            continue;
        else if(chess_rows[i] == row) // Same row or column 
            no_of_conflicts++;
        else if(abs(chess_rows[i]-row) == abs(i-cols)) // Diagonal attack.
            no_of_conflicts++ ;
            

    }
    return no_of_conflicts ;
}

void solve()
{
    iterations = 0 ;
    vector<int> candidates ;
    while(true)
    {
        // finding a queen with most conflicts
        int max_conflicts = 0;
        candidates.clear(); // vector to store a queen with most conflicts.
        for(int i=0 ;i<chess_rows.size();i++)
            {
                int conflict = conflicts(chess_rows[i],i);
                if (conflict == max_conflicts)
                    candidates.push_back(i);
                else if(conflict > max_conflicts)
                {
                    max_conflicts = conflict;
                    candidates.clear();
                    candidates.push_back(i);
                }

            }
            if(max_conflicts == 0)
            {
                return;
            }

            
            int mostConflictedQueen = *select_randomly(candidates.begin(),candidates.end()); // randomly selects a queen .
            // place the most conflicted queen to least conflict position.
            int min_Conflicts = chess_rows.size();
            candidates.clear();
            for (int i = 0; i< chess_rows.size();i++)
            {
               int conflict = conflicts(chess_rows[i],i);
               if (conflict == min_Conflicts)
                    candidates.push_back(i);
               else if(conflict < min_Conflicts){
                     min_Conflicts = conflict ;
                     candidates.clear();
                     candidates.push_back(i);
               }
            }
            if(!candidates.empty()) {
                chess_rows[mostConflictedQueen] = *select_randomly(candidates.begin(),candidates.end());

            }
            iterations++;
            if(iterations == 2*chess_rows.size()){
                fill();
                iterations = 0;
            }

    }
}
void Print() {
	for(int i=0; i<chess_rows.size(); i++) {
		for(int j=0; j<chess_rows.size(); j++) {
            chess_rows[j]==i ? cout<<"Q" : cout<<"." ;
            }
         cout<<endl ;   
    }
    cout << "Conflicts:  " << no_of_conflicts<<endl ; 
    cout<<"No of Iterations:"<< iterations << endl ;
    

}



};
int main()
{
    srand(time(NULL));
    int queens ;
    cout<<"Enter number of queens"<< endl ;
    cin >> queens ; 
    /* code */
    cout << "Building a random  " << queens <<" X "<<queens<<"  chessboard with  "<< queens<<"  queens" << "  placed at random places" << endl;
    ChessBoard cb ;
    cb.randomizedChessBoard(queens); 
    cb.Print();
    cout <<endl<< "Solving......." << endl ;
    cb.solve();
    cout <<"Printing possible solution"<<endl ;
    cb.Print();
    return 0 ;

}

