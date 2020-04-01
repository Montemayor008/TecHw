#include <fstream>
#include <iostream>
using namespace std;

void ReadTextFile(){
// ====================================FILE READING=======================================================
    ifstream inFile;                   //Opens file
    inFile.open("C:\\Users\\monte\\Desktop\\CAMPUS\\SEMESTRE 2\\5 SEMANAS ONLINE\\BIOLOGIA\\TTN.txt");
    //****************************************************************************************************
    //***************************** IMPORTANT ************************************************************
    //****************************************************************************************************
    //******* TO RUN THIS CODE YOU MUST UPDATE THE .TXT FILE LOCATION ON THE LINE 8 **********************
    //****************************************************************************************************
    //**** GO TO FILE LOCATION AND COPY PASTE THE PATH FILE KEEPING THE \\TTN.txt or \\APC.txt************
    //****************************************************************************************************
    //****************************************************************************************************
    if (!inFile){                      // Checks if file was found
        cerr << "Unable to open file APC.txt";
        exit(1);
    }
// =======================================================================================================





// ====================================VARIABLES DECLARATION==============================================
    string TextRead;                      // String that will receive data from .txt
    char LetterA = 'A';                   // Chars to compare 
    char LetterT = 'T';                   // Chars to compare 
    char LetterC = 'C';                   // Chars to compare 
    char LetterG = 'G';                   // Chars to compare 

    float CountA = 0;                     // Counter for each char
    float CountT = 0;                     // Counter for each char
    float CountC = 0;                     // Counter for each char
    float CountG = 0;                     // Counter for each char

    float TotalAmount = 0;                // Counter for all chars

    char pastAchar;                       // Stores first A character
    char nextAchar;                       // Stores last A character
    int repeatAcounter = 0;               // Stores A counter
    int maxArepeat = 0;                   // Stores maximum continuous A count

    char pastTchar;                       // Stores first T character
    char nextTchar;                       // Stores last T character
    int repeatTcounter = 0;               // Stores T counter
    int maxTrepeat = 0;                   // Stores maximum continuous T count

    char pastCchar;                       // Stores first C character
    char nextCchar;                       // Stores last C character
    int repeatCcounter = 0;               // Stores C counter
    int maxCrepeat = 0;                   // Stores maximum continuous C count

    char pastGchar;                       // Stores first G character
    char nextGchar;                       // Stores last G character
    int repeatGcounter = 0;               // Stores G counter
    int maxGrepeat = 0;                   // Stores maximum continuous G count
//========================================================================================================




//=====================================ASSIGN FILE TEXT TO VARIABLE=======================================
    while (getline(inFile, TextRead)){
        // cout << TextRead << endl;                         //Activate to print all the textfile
        // for (int i = 0; i<TextRead.size();i++){           //Activate to print all the textfile
        //     cout << TextRead[i];
        // }

        for (int i = 0; i<TextRead.size();i++){
            TotalAmount++;                                              // Updates total amount of nucleotides

            if (TextRead[i] == LetterA){                                // This if updates total amount of A T C or C
                CountA++;
            } else if (TextRead[i] == LetterT){
                CountT++;
            } else if (TextRead[i] == LetterC){
                CountC++;
            } else {
                CountG++;
            }
            //======================================MAX AMOUNT OF A======================================
            pastAchar = TextRead[i];
            nextAchar = TextRead[i+1];
            if (pastAchar == LetterA && nextAchar == LetterA){
                repeatAcounter++;

                if (repeatAcounter > maxArepeat){
                    maxArepeat = repeatAcounter;
                }
            } else if (pastAchar == LetterA && nextAchar != LetterA){
                repeatAcounter = 0;
            }


            //======================================MAX AMOUNT OF T======================================
            pastTchar = TextRead[i];
            nextTchar = TextRead[i+1];
            if (pastTchar == LetterT && nextTchar == LetterT){
                repeatTcounter++;

                if (repeatTcounter > maxTrepeat){
                    maxTrepeat = repeatTcounter;
                }
            } else if (pastTchar == LetterT && nextTchar != LetterT){
                repeatTcounter = 0;
            }
            

            //======================================MAX AMOUNT OF C======================================
            pastCchar = TextRead[i];
            nextCchar = TextRead[i+1];
            if (pastCchar == LetterC && nextCchar == LetterC){
                repeatCcounter++;

                if (repeatCcounter > maxCrepeat){
                    maxCrepeat = repeatCcounter;
                }
            } else if (pastCchar == LetterC && nextCchar != LetterC){
                repeatCcounter = 0;
            }


            //======================================MAX AMOUNT OF G======================================
            pastGchar = TextRead[i];
            nextGchar = TextRead[i+1];
            if (pastGchar == LetterG && nextGchar == LetterG){
                repeatGcounter++;

                if (repeatGcounter > maxGrepeat){
                    maxGrepeat = repeatGcounter;
                }
            } else if (pastGchar == LetterG && nextGchar != LetterG){
                repeatGcounter = 0;
            }

        }
    }
//========================================================================================================





// ====================================VARIABLES DECLARATION==============================================
    float percentageA;
    float percentageT;
    float percentageC;
    float percentageG;
    float percentageSum;

    percentageA = (CountA/TotalAmount)*100;
    percentageT = (CountT/TotalAmount)*100;
    percentageC = (CountC/TotalAmount)*100;
    percentageG = (CountG/TotalAmount)*100;
    percentageSum = percentageA+percentageT+percentageC+percentageG;
//========================================================================================================




// ====================================PRINTING DATA==============================================
    cout <<"\nAutor: Melissa Montemayor Riojas \nMatricula: A01283698\n"<<endl;
    cout <<"Results of Data Analysis of TTN:" << endl;
    cout <<"\nTotal amount of Nucleotides :" << TotalAmount << endl;
    cout <<"\nTotal amount of A: "<< CountA << endl;
    cout <<"Total amount of T: "<< CountT << endl;
    cout <<"Total amount of C: "<< CountC << endl;
    cout <<"Total amount of G: "<< CountG << endl;
    cout <<"\nPercentage of A: "<< percentageA << endl;
    cout <<"Percentage of T: "<< percentageT << endl;
    cout <<"Percentage of C: "<< percentageC << endl;
    cout <<"Percentage of G: "<< percentageG << endl;
    cout <<"\nSum of percentages: "<< percentageSum << "\n" <<endl;
    cout <<"Maximum amount of continuous A: " << maxArepeat+1 <<endl;
    cout <<"Maximum amount of continuous T: " << maxTrepeat+1 <<endl;
    cout <<"Maximum amount of continuous C: " << maxCrepeat+1 <<endl;
    cout <<"Maximum amount of continuous G: " << maxGrepeat+1 <<endl;
    cout <<"\n" <<endl;
    

    inFile.close();
    
}

int main(){
    ReadTextFile();
    system ("pause");
    return 0;
}