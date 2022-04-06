#include "head.hpp"
#include "AT.hpp"
#include "factory.hpp"
#include "map"

int main(){

    if(!AutoTest()) {
        return 0;
    }
    
    MeasTime();
    
    return 0;
}
