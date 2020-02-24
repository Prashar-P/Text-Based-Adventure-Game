#pragma once
#include <string>
#include <sstream>

std::string joinString(std::string & one ,std::string & two){
    std::stringstream stream;
    stream << one << two;
    
    return(stream.str());
}
