/*
* ForumPostMedium: using a 24 hour time 
*/


#include <iostream>
#include <vector>
#include <sstream>
#include <deque>

#define watch(x) cout << (#x) << " is " << (x) << '\n' 
#define PB push_back



using namespace std;
	
void print_deque(std::deque<std::string> &ds) {
	for (auto const& s : ds) {
		cout << s << '\n'; 
	}
}

std::deque<std::string> tokenize_to_deque(std::string &any_time, std::deque<std::string> &ds){ 
  
	std::stringstream ss(any_time); 
	std::string holder= " ";	
	// do parsing and add to appro
	while (ss) {
 		watch(holder);
		if (ss.peek() == ':') {
			ss.get(); 
			ds.PB(holder); 
			// reset holder
			holder = " "; 
		}
		else { 
			holder += ss.get(); // keep getting until encounter ';'	
		}

	}

	return ds; 

} 


int main() { 
	// two strings to test 
	// can use hashmap to distiguihs  ? 
	// hours,minutes,seconds
	std::deque<std::string> current_ds; 
	std::deque<std::string> post_ds;
	std::string current_time = "12:12:12";
	std::string post_time = "12:11:13";

	current_ds = tokenize_to_deque(current_time, current_ds); 
	//post_ds = tokenize_to_deque(post_time);
	// want to test one 

	print_deque(current_ds); 
	// should we test if values are correct? 
	// shoud return "few seconds ago" 
	 

	return 0; 
} 


