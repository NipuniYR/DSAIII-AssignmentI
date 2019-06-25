#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;
#define N 30 //struct array size
#define d 4 //number of characters in the alphabet (A C G T)

struct DNA{
    string descriptor;
    string sequence;
};

int RabinKarp(string P, string T,int Q);

int main(){
    string data;
    int count = 0;
    int offset;
    int temp;
    ifstream dbFILE, queryFILE;
    ofstream outFILE;
    DNA *set = new DNA[N]; 

    dbFILE.open("DNA Database.txt"); //Text
    if(!dbFILE){
        cout<< "The database file cannot be opened" <<endl;
    }
    else{
        for(int i=0;i<N;i++){
            getline(dbFILE,data);
            if(data == ">EOF"){
                break;
            }
            else if(data[0] == '>'){
                data.erase(0,1); //This will erase 1 character starting from index 0 of data string which is '>'
                set[i].descriptor = data;
                getline(dbFILE,data);
            }
            while(data[0]!='>'){
                set[i].sequence +=data; //appending dna sequence lines
                getline(dbFILE,data);
            }
            if(data == ">EOF"){
                break;
            }
            else if(data[0]=='>'){
                data.erase(0,1);
                set[i+1].descriptor = data;
            }
            count++; //To get the size of the struct array
        }
    }
    dbFILE.close();

    outFILE.open("output.txt"); //Output will be written to this file 
    if(!outFILE){
        cout<< "The output file cannot be opened" <<endl;
    }
    else{
        queryFILE.open("querybase.txt"); //pattern
        if(!queryFILE){
            cout<< "The database file cannot be opened" <<endl;
        }
        else{
            while(getline(queryFILE,data)){
                if(data == ">EOF"){
                    break;
                }
                else if(data[0]=='>'){
                    data.erase(0,1);
                    outFILE<< data <<endl;
                }
                else if(data==""){
                    outFILE<< "No Query found\n" <<endl;
                }
                else{
                    temp = 0;
                    for(int i=0;i<=count;i++){
                        offset = RabinKarp(data,set[i].sequence,11);
                        if(offset != -1){
                            outFILE<< "[" << set[i].descriptor << "]" << " at offset " << offset <<endl;
                            temp++; //To mark that there are matches
                        }
                    }
                    if(temp==0){
                        outFILE<< "NOT FOUND" <<endl;
                    }
                    outFILE<< endl;
                }
            }
        }
        queryFILE.close();
    }
    outFILE.close();

    return 0;
}

int RabinKarp(string P, string T, int Q){
    int m = T.length();
    int n = P.length();
    int h = ((int)pow(d,(n-1)))%Q;
    int p=0; //hash value of pattern
    int t=0; //hash value of text
    int temp =0;

    //Calculating hash values for the pattern and the text part when shift is at 0th index
    for(int i=0;i<n;i++){
        p+=(int)pow(d,((n-1)-i))*(int)P[i];
        t+=(int)pow(d,((n-1)-i))*(int)T[i];
    }
    p=p%Q;
    t=t%Q;

    for(int s=0;s<=(m-n);s++){
        if(p==t){
            int i = 0;
            while(i<n && P[i]==T[s+i]){
                i++;
            }
            if(i==n){
                return s;
                temp++; //To mark that there are matches
            }
        }
        t=(d*(t-(int)T[s]*h)+((int)T[s+n]))%Q; //Rolling hash function
        /* If the Rolling hash function returns a negative value we have to add the prime number
        to that negative value inorder to make it a hash value in between 0 and (Q-1) (in this case 0 and 10)*/ 
        if(t<0){
            t=t+Q;
        }
    }
    if(temp == 0){
        return -1;
    }
}
