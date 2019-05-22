#include <cmath>
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define SEP_SYMB ','
using namespace std;
static int cols=215;
static int rows=11917;
//char headers[215][100];
//char tmp[100];
string headers[216];
map <string,vector <string> > table;
int counter=0;
vector <vector <string> > columns(216); 
string tmp;

long getNumber(string a) {

        for(int i=0; i<=a.size(); i++) {  //Loop through the entire string
                    if(a[i]==SEP_SYMB) { //Check for occurence of SEP_SYMB
                    a.erase(i,1); //If SEP_SYMB , remove that single character
                    }
            }
            return atol(a.c_str()); //Will return integer
}


int main(){
filebuf f;
stringstream iss;
if (f.open("secdata.csv",std::ios::in))
{   cout<<"FILE OPENED"<<endl;
    istream input(&f);getline(input,tmp,'\n');
        iss<<tmp;
    while(input && counter<cols){//setup map from column headers to column vector
        getline(iss,headers[counter],',');
        //cout<<headers[counter]<<endl;
        table[headers[counter]]=columns[counter];
       // cout<<counter<<" "<<headers[counter]<<endl;
        ++counter;
    }
        iss.clear();
    //cout<<table.size()<<" "<<headers[214]<<endl;
    for(int i=0;i<rows;++i){
        counter=0;getline(input,tmp,'\n');
        iss<<tmp;
        while(input && counter<cols){
            getline(iss,tmp,',');
            table[headers[counter]].push_back(tmp);
            //columns[counter].push_back(tmp);
            //cout<<columns[counter].back()<<endl;//prints bottom("back") of column
            //cout<<table[headers[counter]].at(i)<<endl;
            //cout<<columns[counter].at(i)<<endl;
            printf("\r Reading company info %d/%d",i,rows);
            counter++;
    }
            iss.clear();
    }
}
f.close();
//for(int i=0;i<11917;++i){
//for(int c=0;c<cols;++c){
//    printf("%s is %s\n",headers[c].c_str(),table[headers[c]].at(i).c_str());
//}
//}
cout<<"FILE CLOSED"<<endl;
    //for(int i=0;i<11917;++i){
    //}
for(int i=0;i<11917;++i){
    if(table["5F(2)(a)"].at(i)!="NULL" && table["5F(2)(a)"].at(i)!="0" && table["5F(2)(d)"].at(i)!="NULL" && table["5F(2)(d)"].at(i)!="0"){
        //cout<<"Found something at row "<< i<<endl;
        //cout<<table["5F(2)(a)"].at(i)<<endl;
        //cout<<getNumber(table["5F(2)(a)"].at(i))<<endl;
        //cout<<table["5F(2)(d)"].at(i)<<endl;
        //cout<<getNumber(table["5F(2)(d)"].at(i))<<endl;
    if(getNumber(table["5F(2)(a)"].at(i))/getNumber(table["5F(2)(d)"].at(i))>500000000 && table["9A(1)(b)"].at(i)=="Y"&&table["9A(1)(b)"].at(i)=="Y"){
        if(1/*table["5C(1)"].at(i)=="0"||table["5C(1)"].at(i)=="1-10"||table["5C(1)"].at(i)=="11-25"*/){
cout<<table["Legal Name"].at(i)<<table["Main Office City"].at(i)<<"\t"<<table["Main Office State"].at(i)<<"\t"<<table["Main Office Country"].at(i)<<endl;
cout<<table["5F(2)(a)"].at(i)<<"\t"<<table["5F(2)(d)"].at(i)<<endl;
cout<<getNumber(table["5F(2)(a)"].at(i))<<"\t"<<getNumber(table["5F(2)(d)"].at(i))<<endl;
        }
    }
}
}
return 0;
}
//ofstream g("C:\\root\\B2DDs\\bdt_cumulative_D.opt");
//
//for(int j=0;j<100;j++){
//    g<<z[index[j]]<<"\t"<<w[index[j]]<<endl;
//}
//g.close();
