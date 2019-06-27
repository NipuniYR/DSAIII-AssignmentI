#include <iostream>
#include <string>
#include <fstream> //This library is used to open a file
#include <sstream>
using namespace std;

void naiveSearch(string P, string T);

int main(){
    string text,pattern;
    ifstream inFILE; //declaring input file stream variables
    //inFILE.open("pattern1.txt"); //give the required pattern file
    //inFILE.open("pattern2.txt");
    //inFILE.open("pattern3.txt");
    inFILE.open("pattern4.txt");
    //inFILE.open("pattern5.txt");
    //inFILE.open("pattern6.txt");
    int option;

    if(!inFILE){
        cout<< "The pattern file cannot be opened" <<endl;
    }
    else{
        ostringstream ss;
        ss<< inFILE.rdbuf();
        pattern = ss.str();
    }
    inFILE.close();

    //inFILE.open("text1.txt"); //give the required text file
    //inFILE.open("text2.txt");
    //inFILE.open("text3.txt");
    //inFILE.open("text4.txt");
    inFILE.open("text5.txt");
    //inFILE.open("text6.txt");
    if(!inFILE){
        cout<< "The text file cannot be opened" <<endl;
    }
    else{
        ostringstream ss;
        ss<< inFILE.rdbuf();
        text = ss.str();
    }
    inFILE.close();

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
        if(T==""){ 
            outFILE<< "The text file is empty" <<endl;
        }
        else{
            for(s=0;s<m-n;s++){ 
        	    int i = 0;
                while(i<n && (P[i]=='_' || T[s+i]==P[i])){ 
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
