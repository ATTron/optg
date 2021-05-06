#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <OPTGConfig.h>
#include <block.h>
#include <events.h>

using namespace std;

void fileInfo();
void processFile(string *filename);
void processBlock(string *block);
void readHeader(string *header);
void listEvents();
bool checkEvents(Block *block);
void exportToCSV();

vector<Block> allBlocks {};
vector<Block> pendingBlocks {};

int main(int argc, char** argv) {
    string filename {argv[1]};
    fileInfo();
    processFile(&filename);
    // listEvents();
    exportToCSV();
    return 0; 
}

void fileInfo() {
    cout << "** OPTG Version " << OPTG_VERSION_MAJOR << "." << OPTG_VERSION_MINOR << " **"<< endl;
    cout << "** Anthony Templeton **" << endl;
    cout << "** " << OPTG_HOMEPAGE_URL << " **\n" << endl;
}

void processFile(string *filename) {
    string tmpString {};
    string header {};
    string block{};

    bool is_header_done = false;
    regex header_reg("^\\$\\$EOH");
    regex file_end_reg("^\\$\\$EOF");
    regex new_block_reg("^([a-zA-z]{6}|[a-zA-z]{5})");

    ifstream txtFile(*filename);
    if(txtFile.is_open()) {
        while(txtFile.good()) {
            getline(txtFile, tmpString);
            if (!is_header_done) {
                header += tmpString + "\n";
                if (regex_search(tmpString, header_reg)) {
                    readHeader(&header);
                    is_header_done = true;
                }
            } else {
                if (regex_search(tmpString, new_block_reg) && !regex_search(tmpString, file_end_reg)) {
                    if (!block.empty()) {
                        processBlock(&block);
                    }
                    block = tmpString;
                } else if (regex_search(tmpString, file_end_reg)){
                    processBlock(&block);
                } else {
                    block += tmpString;
                }
            }
        }
        txtFile.close();
    }
}

void processBlock(string *block) {
    // pointers need to be dereferenced -- (*block).erase or block->erase
    block->erase(remove(block->begin(), block->end(), '\r'), block->end());
    block->erase(remove(block->begin(), block->end(), ' '), block->end());

    Block event(*block);

    allBlocks.push_back(event);
}

void readHeader(string *header) {
    string tmp {};
    istringstream head(*header);
    while(getline(head, tmp)) {
        cout << tmp << endl;
    }
}

// helpful for debugging
void listEvents() {
    for (Block b : allBlocks) {
        cout << "GOT EVENT: " << b.get_all_info() << endl;
    }
}

void exportToCSV() {
    std::ofstream exportedFile;

    exportedFile.open("optg_exported.csv");
    exportedFile << "event_name,description,object_name,event_time,orbit_number,periap_time,event_data\n";
    for (Block b : allBlocks) {
        exportedFile << b.get_event_name() << "," << b.get_description() << "," << b.get_obj_name() << "," << b.get_sc_evt_time()
            << "," << b.get_orbit_num() << "," << b.get_plus_minus_periap() << "," << b.get_event_data() << "\n";
    }
    exportedFile.close();
}