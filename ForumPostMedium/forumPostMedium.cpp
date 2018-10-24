/*
* ForumPostMedium: using a 24 hour time stamp
*/


#include <iostream>
#include <vector>
#include <sstream>
#include <deque>
#include <string>

#define watch(x) cout << (#x) << " is " << (x) << '\n' 
#define PB push_back
//#define PF pop_front

struct TIME {
    int seconds;
    int hours;
    int minutes; 
}; 

using namespace std;
	
void print_deque(std::deque<std::string> &ds) {
	for (auto const& s : ds) {
		cout << s << '\n'; 
	}
}

 
TIME deque_to_structs(std::deque<std::string> &any) {
    TIME tm;
    int iter_count = 0;
    std::string::size_type sz; 
    while (!any.empty()) {   
        switch(iter_count) {
            case 0 : 
                tm.hours = std::stoi(any.front(), &sz);
                any.pop_front();
                iter_count = iter_count + 1; 
            case 2 : 
                tm.minutes = std::stoi(any.front(), &sz);
                any.pop_front(); 
                iter_count = iter_count + 1; 
            case 3: 
                tm.seconds = std::stoi(any.front(), &sz);
                any.pop_front(); 
                iter_count = iter_count + 1;
            default: 
                break; 
        }
    }
    return tm;
}

void test_pop_front(std::deque<std::string> &any_ds) {
    cout << "Pop front: " << any_ds.front() << '\n'; 
}

std::deque<std::string> tokenize_to_deque(std::string &any_time, std::deque<std::string> &ds){ 
  
	std::stringstream ss(any_time); 
	std::string holder= "";	
	while (ss) {
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
        
        // to deques to get right sections
	current_ds = tokenize_to_deque(current_time, current_ds); 
	post_ds = tokenize_to_deque(post_time, post_ds);
        
        // format sections to proper TIME struct
        TIME current = deque_to_structs(current_ds);
        TIME post =  deque_to_structs(post_ds);

        cout << current.hours << current.minutes << current.seconds << '\n'; 
        cout << post.hours << post.minutes << post.seconds << '\n';
	return 0; 
}












