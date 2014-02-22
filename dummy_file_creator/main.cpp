#include <cstdlib>  // srand, rand
#include <ctime>    // time
#include <climits>
#include <cstdint>  // C++11

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>  // std::copy
#include <iterator>   // std::ostream_iterator


#define BUF_LEN 8192

// file_creator (1)output_file (2)size (3)units
// units: KB MB GB
int main(int argc, char *argv[]) {
    try {
        if (argc != 4) {
			std::cout << "Use with parameters: (1)output_file (2)size (3)units" << std::endl;
			std::cout << "units: KB MB GB" << std::endl;
            throw std::string("Number of input arguments is not equal \"3\".");
        }
        
        srand(time(NULL));
        
        std::ofstream dummy_file(argv[1]);
        if (!dummy_file.good()) {
            throw std::string("Can't create file with this name.");
        }
        
        std::vector<char> buff(BUF_LEN, '0');
        for (int i = 0; i < buff.size(); ++i) {
            buff[i] = static_cast<char>((rand() % (UCHAR_MAX + 1)) - (UCHAR_MAX / 2) + 1);
        }
        
        int64_t file_size = atoi(argv[2]);
        if (file_size <= 0) {
            throw std::string("Incorrect file size.");
        }
        
        std::string units(argv[3]);
        if (units == "KB") {
            file_size *= 1024;
        } else if (units == "MB") {
            file_size *= 1024 * 1024;
        } else if (units == "GB") {
            file_size *= 1024 * 1024 * 1024;
        } else {
            throw std::string("Incorrect size unit.");
        }
        
        int64_t number_of_writes = file_size / buff.size();
        for (int64_t i = 0; i < number_of_writes; ++i) {
            std::ostream_iterator<char> out_it(dummy_file);
            std::copy(buff.begin(), buff.end(), out_it);
        }
        
    } catch (const std::string &ex) {
        std::cout << "Error: " << ex << std::endl;
        return -1;
    } catch (...) {
        std::cout << "Error: unknown error." << std::endl;
        return -1;
    }
    return 0;
}
