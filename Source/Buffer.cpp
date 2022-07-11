// Buffer.cpp

#include "Buffer.h"
using namespace std;

void Buffer::display() const
{
    int ix_stop_line_ = ix_top_line_ + window_height_;
    for (int i = ix_top_line_; i < ix_stop_line_; ++i) {
        if (i < v_lines_.size()) {
            string total(total_line);
            if (total_line.size() + v_lines_[i].size() + 1 >= line_length_) {
                cout << std::setw(6) << i + 1 << "  " << v_lines_[i];
                cout << '\n';
            }
            else {
                total = total + " " + v_lines_[i];
            }
        }
    }
}
bool Buffer::open(const string & new_file_name)
{
    std::ifstream file(new_file_name);
    if (!file)
        return false;

    v_lines_.clear();
    // Note: the vector is cleared only after we know the file
    // opened successfully.
    string blank = "";
    string line;
    //string total_line;
    //vector <string> words;
    while (file >> line) {
        if (line == "<a")
        {
            link_no++;
            file >> line;
            links.push_back(line);
            file >> line;
            string temp = '<' + line + '>' + '[' + to_string(link_no) + ']';
            v_lines_.push_back(temp);
            file >> line;
            file >> line;
        }
        else if (line == "<p>") {
            v_lines_.push_back(blank);
            file >> line;
        }
        else if (line == "<br>") {
            v_lines_.push_back(blank);
            v_lines_.push_back(line);
        }
        else {
            v_lines_.push_back(line);
        }
    }
    //for (int x = 0; x < words.size(); x++) {
    //    //while (total_line.size() < line_length_) {
    //        if (((words[x] + total_line).size()+1) < line_length_) {
    //            total_line = total_line + ' ' + words[x];
    //            v_lines_.push_back(total_line);
    //        }
    //}
   // }
    file_name_ = new_file_name;
    ix_top_line_ = 0;
    return true;
}
void Buffer::go_back() {
    if (!(history.empty())){
        if (history.size() >= 2) {
            history.pop_back();
            string s = history.back();
            history.pop_back();
            open(s);
        }
        else {
            open(history.back());
        }
    }
}
bool Buffer::search(const std::string& s) {
    for (int i = ix_top_line_; i < v_lines_.size(); i++) {
       if (v_lines_[i].find(s) != string::npos) { // if the line of the vector not returning 'not a postition'
            ix_top_line_ = i;
            return true;
        }
    }
    return false;
}
void Buffer::set_file(string& filename) {
    string current_file = filename;
    history.push_back(current_file);
        return;
}
void Buffer::open_link(int no) {
   if (no <= links.size()) {
        string file = links[((no-1))];
        open(file);
        history.pop_back();
    }
}


 /*void Buffer::format_spaces(std::string line, std::string file_name) {
     ifstream in;
     in.open(file_name);
     getline(in, line);
     size_t pos;
     while ((pos = line.find("  ")) != std::string::npos)
         line = line.replace(pos, 2, " ");*/
     /*int i = 0;
     int j = 0;
    for (int i = ix_top_line_; i < v_lines_.size(); i++) {
        for (j = v_lines_.size() - 1; j >= 0; j--) {
            if (v_lines_[j] == ' ' && v_lines_[j - 1]) {
                v_lines_.erase(v_lines_.begin() + j);
            }
           }
    }*/

//}
//void Buffer::link_search(const int& linkno) {
//    for (int i = ix_top_line_; i < v_lines_.size(); i++) {
//        if (v_lines_[i].find() != string::npos) {
//            ix_top_line_ = i;
//        }
//        return;
//
//    }
//}
//int Buffer::find_links() {
//    int count = 0;
//    for (int i = ix_top_line_; i < v_lines_.size(); i++) {
//        if (v_lines_[i].find("<a ")) {
//            ++count;
//        }
//    }
//    return count;
//}