#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){

    std::string d1,d2,d3,key;
    int acd;
    char type;
    
while(type != 'X')
{
    std::cout<< "(D)ENIAL/(A)LERT: ";
    std::cin>>type;
    std::string result;
    type = toupper(type);

    if(type== 'D'||type=='d')
    {
        result="CLAIM DATED ";
        std::cout<< result<<std::endl;

        std::cout<<"MM: ";
        std::cin>>d1;

        std::cout<<"DD: ";
        std::cin>>d2;

        std::cout<<"YY: ";
        std::cin>>d3;

        result+=(d1)+('/')+(d2)+('/')+(d3)+" DENIED";

    }
    else;


    int entry; 

    std::cout<<"REASON: \n0)BASED ON IME, TREATMENT WAS NOT MEDICALLY NECESSARY \n1)BASED ON IME, NO FURTHER ORTHO TX MEDICALLY NECESSARY, \n2)BASED ON PT FAILIURE TO SHOW FOR IMES, \n3)BASED ON NO-FAULT EXHAUSTED \n4)BASED ON LATE FILING RULES \n5)PENDING, ADDITIONAL INFO NEEDED \n6)INVESTIGATION, INJURY WAS INTENTIONAL \n7)BASED ON BILL BEING INCORRECTLY SUBMITTED \n9)CUSTOM \n";
    cin>>entry;
    if(entry==0)
    {
        result.append(" BASED ON IME, TREATMENT WAS NOT MEDICALLY NECESSARY, ");
    }
    else if(entry==1)
    {
        result.append(" BASED ON IME, NO FURTHER ORTHO TX MEDICALLY NECESSARY, ");
    }
    else if(entry==2)
    {
        result.append(" BASED ON PT FAILIURE TO SHOW FOR IMES, ");
    }
    else if(entry==3)
    {
        result.append(" BASED ON NO-FAULT EXHAUSTED ");
    }
    else if(entry==4)
    {
        result.append(" BASED ON LATE FILING RULES ");
    }
    else if(entry==5)
    {
        result.append(" PENDING, ADDITIONAL INFO NEEDED TO PROCESS CLAIM ");
    }
    else if(entry==6)
    {
        result.append(" INVESTIGATION, INCIDENT WAS INTENTIONAL ");
    }
        else if(entry==7)
    {
        result.append(" BASED ON BILL BEING INCORRECTLY SUBMITTED ");
    }
    else if(entry==9)
    {
        std::string custom;
        std::cout<<"CUSTOM: BASED ON ";
        std::getline(std::cin, custom);//apparently this does not exec due to a cin>> being in the stream
        std::cout<<endl;
        result += " BASED ON ";
        result += custom;
        
        std::cout<<"ACD?: 0 NO /1 YES ";
        std::cin>>acd;
        std::cout<<endl;
    }
    else;

    if(entry==3 && type=='A')
    {
        goto print;
    }
    if(entry==4 ||acd==0)
    {
        goto print;
    }

    std::cout<<"ALL TREATMENT DENIED AS OF: \n";
    std::cout<<"X/MM:";
    std::cin>>d1;
    if(d1.at(0)=='0')
    {
        result+="ALL CLAIMS DENIED ";
        goto print;
    }
    else if(d1.at(0)=='X'||d1.at(0)=='x')
    {
        
        goto print;
    }
    std::cout<<"DD:";
    std::cin>>d2;
    std::cout<<"YY:";
    std::cin>>d3;
    std::cout<<endl;


    result+=("ALL TREATMENT DENIED AS OF ");
    result+=(d1)+('/')+(d2)+('/')+(d3);
    


print:
    result+=(" -[SIGNTURE]");
    std::cout<< std::endl<< result <<std::endl;


}
std::cout<<std::endl;
    return 0;
}