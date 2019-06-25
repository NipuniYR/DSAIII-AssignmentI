#include <iostream>
#include <string>
#include <fstream> //This library is used to open a file
#include <sstream>
using namespace std;

void naiveSearch(string P, string T);

int main(){
    string text,pattern;
    ifstream patFILE,textFILE; //declaring input file stream variables
    //patFILE.open("pattern1.txt"); //give the required pattern file
    //patFILE.open("pattern2.txt");
    //patFILE.open("pattern3.txt");
    //patFILE.open("pattern4.txt");
    //patFILE.open("pattern5.txt");
    patFILE.open("pattern6.txt");
    int option;

    if(!patFILE){
        cout<< "The pattern file cannot be opened" <<endl;
    }
    else{
        ostringstream ss;
        ss<< patFILE.rdbuf();
        pattern = ss.str();
    }
    patFILE.close();

    //textFILE.open("text1.txt"); //give the required text file
    //textFILE.open("text2.txt");
    //textFILE.open("text3.txt");
    //textFILE.open("text4.txt");
    //textFILE.open("text5.txt");
    textFILE.open("text6.txt");
    if(!textFILE){
        cout<< "The text file cannot be opened" <<endl;
    }
    else{
        ostringstream ss;
        ss<< textFILE.rdbuf();
        text = ss.str();
    }
    textFILE.close();

    naiveSearch(pattern,text);
    //cout << text << " " << pattern <<endl;

    return 0;
}

void naiveSearch(string P,string T){
    int temp = 0;
    int s = 0;
    int n = P.length();
    int m = T.length();
    ofstream outFILE;
    //outFILE.open("patternmatch1.output");
    //outFILE.open("patternmatch2.output");
    //outFILE.open("patternmatch3.output");
    //outFILE.open("patternmatch4.output");
    //outFILE.open("patternmatch5.output");
    outFILE.open("patternmatch6.output");
    if(!outFILE){
        cout<< "The output file cannot be opened" <<endl;
    }
    else{
        if(P==""){
            outFILE<< "The pattern file is empty" <<endl;
        }
        else if(T==""){
            outFILE<< "The text file is empty" <<endl;
        }
        else{
            for(s=0;s<m;s++){
        	    int i = 0;
                while(i<n && (T[s+i]==P[i]) || P[i]=='_'){
                    i++;
                }
                if(i==n){
                    outFILE<< "Pattern found at index " << s << " in the text" <<endl;
                    temp++;
                }
            }
            if(temp==0){
                outFILE<< "Pattern did not occur" <<endl;
            }
        }
    }
    outFILE.close();
}
