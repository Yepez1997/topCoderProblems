// TopCoder Division Two Problem
// @author Aureliano Yepez
// @date October 22, 2018

#include <iostream>
#include <algorithm>
#include <deque>
#include <sstream>
#include <vector> 

using namespace std;

// iterate over all list and return true/false based on contsraints 
bool get_result(std::vector<std::string> &nots) {
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
bool get_string_tokens(std::string &sentence, std::vector<std::string> &nots) {
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
	return get_result(nots); 	 
	
}


int main() {
	
	// test sentence
	std::string test_string = "I want not not not to go to the park"; 
	// holds nots -- if there are any 
	std::vector<std::string> nots_vector; 
	bool result = get_string_tokens(test_string, nots_vector);	 
	cout << "result: " << result << std::endl; 
}

