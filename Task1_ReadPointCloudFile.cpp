#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main(){
 string data;
 int count = 0;
 //specify the path here
 ifstream file("F:\Ekta Flow\SBD Nosecone.asc");
 if(!file.is_open()){
   cout<<"Error opening file"<<endl;
   return 0;
 }
 while(!file.eof()){
   getline(file,data);
   count++;
   cout<<data<<endl;
 }
 cout<<count<<endl;
 return 0;
}
