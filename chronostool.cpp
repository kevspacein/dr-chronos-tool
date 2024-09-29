#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <windows.h>


void print(std::string& result){
    result+=(" -[SIGNATURE]");
    std::cout<< std::endl << result <<  std::endl;
    
}

void copy(const std::string result) {    
    
    OpenClipboard(0);
    EmptyClipboard();
    const size_t length = result.length() + 1;
    HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, length);
    memcpy(GlobalLock(h), result.c_str(), length);
    GlobalUnlock(h);
    SetClipboardData(CF_TEXT, h);   
    CloseClipboard();
}

int main(){

    std::string d1,d2,d3;
    char type;
    d3 = "0";
    std::string result;
    std::string spaceBuffer;

    while(type != 'X')
    {
        while(type != 'A' && type != 'D' )
        {
            std::cout<< "(D)ENIAL/(A)LERT: ";
            std::cin>>type;
            type = toupper(type);
        }

        if(type== 'D')
        {
            result = "CLAIM DATED ";
            std::cout<< result<<std::endl;

            std::cout<<"MM: ";
            std::cin>>d1;

            std::cout<<"DD: ";
            std::cin>>d2;

            
            while((stoi(d3) / 10) == 0 || stoi(d3) / 100 != 0) //Checks if year is not in XX format
            {
                std::cout<<"YY: ";
                std::cin>>d3;
            }
            

            result+=(d1)+('/')+(d2)+('/')+(d3)+" DENIED ";

        }

        int entry; 

        reasonTag:

        std::cout<<"REASON: \n0)BASED ON IME, TREATMENT WAS NOT MEDICALLY NECESSARY \n1)BASED ON IME, NO FURTHER ORTHO TX MEDICALLY NECESSARY, \n2)BASED ON PT FAILIURE TO SHOW FOR IMES, \n3)BASED ON NO-FAULT EXHAUSTED \n4)BASED ON LATE FILING RULES \n5)PENDING, ADDITIONAL INFO NEEDED \n6)INVESTIGATION... \n7)BASED ON DUPLICATE BILLING \n8)BASED ON BILL BEING INCORRECTLY SUBMITTED \n9)CUSTOM \n";
        std::cin>>entry;

        switch(entry)
        {
            case 0:
            result.append("BASED ON IME, TREATMENT WAS NOT MEDICALLY NECESSARY, ");
            break;
        
            case 1:
            result.append("BASED ON IME, NO FURTHER ORTHO TX MEDICALLY NECESSARY, ");
            break;
        
            case 2:
            result.append("BASED ON PT FAILIURE TO SHOW FOR IMES, ");
            break;
        
            case 3:
            if(type=='A')
            {
                result = "NO FAULT EXHAUSTED ";
                break;
            }

            result.append("BASED ON NO-FAULT EXHAUSTED ");
            break;
        
            case 4:
            result.append("BASED ON LATE FILING RULES ");
            break;
        
            case 5:
            if(type != 'A')
            {
                std::cout<<"Option unavailible for denial. Press a key to reselect. ";
                std::cin>> spaceBuffer;
                goto reasonTag;
            }

            result.append("PENDING, ADDITIONAL INFO NEEDED TO PROCESS CLAIM ");
            
            std::cout<<"CLAIM DATED: \nMM: ";
            std::cin>>d1;
            std::cout<<"DD: ";
            std::cin>>d2;
            while((stoi(d3) / 10) == 0 || (stoi(d3) / 100) != 0) //Checks if year is not in XX format
            {
                std::cout<<"YY: ";
                std::cin>>d3; 
            }
            
            result.insert(0,"CLAIM DATED " +d1+'/'+d2+'/'+d3+' ');
            break;
        
            case 6: //INVESTIGATION MULTI-TAB

            int investInput;
            std::cout<< "BASED ON INVESTIGATION:\n 1) INJURY NOT RELATED TO INCIDENT \n 2) INCIDENT WAS INTENTIONAL \n 3)PT NOT ELIGIBLE FOR COVERAGE\n";
            std::cin >> investInput;
            result.append("BASED ON ");

            switch(investInput)
            {
                case 1:
                result.append("INVESTIGATION, INJURY NOT RELATED TO INCIDENT, ");
                break;

                case 2:
                result.append("INVESTIGATION, INCIDENT WAS INTENTIONAL, "); 
                break;
                
                case 3:
                result.append("INVESTIGATION, PT NOT ELIGIBLE FOR COVERAGE, ");
                break;
            }
            break;

            case 7:
            result.append("BASED ON DUPLICATE BILLING, ");
            break;
        
            case 8:
            result.append("BASED ON BILL BEING INCORRECTLY SUBMITTED ");
            break;
        
            case 9:
            std::string custom;
            std::cout << "CUSTOM: \nBASED ON ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            std::getline(std::cin, custom);//apparently this does not exec due to a cin>> being in the stream
            std::cout << std::endl;
            
            result += "BASED ON ";
            result += custom;
            result.append("  ");
            
            std::cout<<std::endl;
            break;
            
        }

        
        
        

        if(entry != 3 && entry != 5)
        {
            std::cout<<"ALL CLAIMS DENIED AS OF: \n";
            std::cout<<"X/MM:";
            d1 = "";
            d2 = "";
            d3 = "0";

            std::cin>>d1;
            
            if(d1.at(0) =='0')
            {
                result+="ALL CLAIMS DENIED ";
                
            }

            else if(d1.at(0) =='X' || d1.at(0) == 'x')
            {
                result.pop_back();
                result.pop_back();
            }


            else
            {
            std::cout<<"DD:";
            std::cin>>d2;

            while((stoi(d3) / 10) == 0 || (stoi(d3) / 100) != 0) //Checks if year is not in XX format
            {
                std::cout<<"YY:";
                std::cin>>d3;
            }
        

            std::cout<<std::endl;

            result+=("ALL CLAIMS DENIED AS OF ");
            result+=(d1)+('/')+(d2)+('/')+(d3);
            }
        }
        
        
        print(result);
        copy(result);

        //Reset
        type = ' ';
        result = "";
        d1 = ' ';
        d2 = ' ';
        d3 = '0';

        std::cout<<std::endl;
    
    }
return 0;
}