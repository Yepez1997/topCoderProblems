// TopCoder Division Two Problem
// @author Aureliano Yepez
// @date October 22, 2018

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "getAccepted.h"

std::vector<std::string> nots;

// iterate over all list and return true/false based on contsraints 
bool get_result() {
        // check if func makes it to here 
        cout << "get_result" << std::endl;
	int count = 0; 
        for (std::string s : nots) {
                count += 1; 
        }
	
	// false & false is true 	
	if (count % 2 == 0) {
		return true; 	
	}
	else {
		// if odd number of nots return false 
		return false; 
	}
}

// tokenize input and retrieve nots 
bool get_string_tokens(std::string &sentence) {
	// use a string stream
	stringstream ss(sentence);
	std::string holder = " "; 

	while (ss) {
		//only want get holders for "not"
		if(ss.peek() == 'n') {
			holder += ss.get();
			if (ss.peek() == 'o' ) {
				holder += ss.get();
				if (ss.peek() == 't') {
					holder += ss.get(); 
					nots.push_back(holder);
					// reset holder to detect new ones 
					holder = " ";
				} else {
				ss.get();
				holder = " ";
				}
			} else {
			ss.get();
			holder = " ";
			}
		} else {
		ss.get();
		holder = " "; 
		} 	
	}	
	return get_result(); 	 
	
}



TEST_CASE("Strings tested in get_string_tokens to result","[get_string_tokens]"){
	std::string string_false = "I want to not go the the park";
        std::string string_true = "I want to not not go to the park";
	REQUIRE(get_string_tokens(string_false) == 0);
}




