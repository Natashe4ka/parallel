#include "AT.hpp"
#include "CIntN0.hpp"


int AutoTest1(){
    CIntN0 X, Y;
    X.new_number("1");
    Y.new_number("10");
    CIntN0 Z=X+Y;
    if (Z.get_number()[0]==1 && Z.get_number()[1]==1) return 1;
    else return 0;
}

int AutoTest2(){
    CIntN1 X, Y;
    X.new_number("10");
    Y.new_number("9");
    CIntN1 Z=X-Y;
    if (Z.get_number()[0]==1) return 1;
    else return 0;
}


int AutoTest3(){
    int flag=0;
    CIntN** arr = new CIntN*[2];
    arr[0] = new CIntN0(2, "25");
    arr[1] = new CIntN1(3, "399");
    //arr[0]->new_file_name("/Users/nataliasafonova/Desktop/c++4/1/n.1/n.1/AT.txt");
    
    arr[0]->new_file_name("AT.txt");
    
    //arr[0]->print("AT.txt");
    //arr[1]->new_file_name("/Users/nataliasafonova/Desktop/c++4/1/n.1/n.1/AT.txt");
    
    arr[1]->new_file_name("AT.txt");
    
    arr[0]->print();
    arr[1]->print();
    //arr[1]->print("AT.txt");
    
    std::string f = "2 5";
    std::string s = "3";
    std::string th = "9";
    std::string forth = "9";
    
    //std::ifstream inp("/Users/nataliasafonova/Desktop/c++4/1/n.1/n.1/AT.txt");
    std::ifstream inp("AT.txt");
    std::string line;
    while (getline(inp, line)){
        
        //std::cout << line<<"\n";
        if (line==f || line==s || line==th || line==forth)  flag++;
        
    }
   // remove ("/Users/nataliasafonova/Desktop/c++4/1/n.1/n.1/AT.txt");
    remove ("AT.txt");
    if (flag==4) return 1;
    else return 0;
    
}

int AutoTest4(){
    std::vector<CIntN0> for_sum1; for_sum1.push_back({1, "3"}); for_sum1.push_back({1, "-4"});
    std::vector<CIntN0> for_sum2; for_sum2.push_back({1, "5"}); for_sum2.push_back({1, "-4"});
    
    std::vector<CIntN0> sum(2);
        
    for(size_t i = 0; i < 2; ++i) {
        sum[i] = for_sum1[i]+for_sum2[i];
    }
    
    if( sum[0].get_number()[0] == 8 && sum[1].get_number()[0] == 8 && sum[1].get_sign() == '-') return 1;
    else return  0;
    //return 1;
}

int AutoTest(){
    int a1=1,a2=1,a3=1,a4=1;
    if(!AutoTest1()){
        std::cout << "AutoTest1 failed." << std::endl;
        a1=0;
    }
     if(!AutoTest2()){
        std::cout << "AutoTest2 failed." << std::endl;
         a2=0;
     
    }
    if(!AutoTest3()){
       std::cout << "AutoTest3 failed." << std::endl;
        a3=0;
    
   }
    if(!AutoTest4()){
       std::cout << "AutoTest4 failed." << std::endl;
       a4=0;
   }
     
    if( a1*a2*a3*a4!=0) return 1;
    else return 0;

}

