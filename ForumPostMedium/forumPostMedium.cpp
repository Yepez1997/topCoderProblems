/*
* ForumPostMedium: using a 24 hour time stamp
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

// first deque pop should be between 0-23 , thereafrer 0-59 
std::string compare_deques(std::deque<std::string> &current, std::deque<std::string> &post) {

    std::string test_str = " "'
    // .... 

    return test_str
}

void test_pop_front(std::vector<std::string> &any_ds) {
    cout << "Pop front: " << any_ds.getFront() << '\n'; 
}

std::deque<std::string> tokenize_to_deque(std::string &any_time, std::deque<std::string> &ds){ 
  
	std::stringstream ss(any_time); 
	std::string holder= "";	
	while (ss) {
 		watch(holder);
		if (ss.peek() == ':') {
			ss.get(); 
			ds.PB(holder); 
			// reset holder
			holder = ""; 
		}
		else { 
			holder += ss.get(); // keep getting until encounter ';'	
		}
	}
	std::string seconds = any_time.substr(any_time.size()-2,  any_time.size());	
	ds.PB(seconds); // add seconds digits 
	return ds; 

} 


int main() { 
	
	std::deque<std::string> current_ds; 
	std::deque<std::string> post_ds;
	std::string current_time = "12:12:12";
	std::string post_time = "12:11:13";

	current_ds = tokenize_to_deque(current_time, current_ds); 
	post_ds = tokenize_to_deque(post_time, post_ds);
		 
	return 0; 
}












