// Buffer.h

#ifndef _Buffer_h_
#define _Buffer_h_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Buffer
{
public:
    void display() const;
    void go_back();
    std::string total_line = "";
    const std::string & file_name() const { return file_name_; }
    void move_to_next_page();
    void move_to_previous_page();
    //void format_spaces(std::string line,std::string file_name);
    bool open(const std::string & file_name);
    void set_window_height(int h) { window_height_ = h; }
    void set_line_length(int l) { line_length_ = l; }
   bool search(const std::string& s);
    //void link_search(const int& linkno);
    //int find_links();
   void set_file(std::string& filename);
   std::string current_file;
   void open_link(int no);
    

private:
    std::vector<std::string> history;
    std::vector<std::string> v_lines_;
    std::vector<std::string> links;
    int link_no = 0;
    int ix_top_line_ = 0;
    std::string file_name_;
    int window_height_;
    int line_length_;
};

inline void Buffer::move_to_next_page()
{
    ix_top_line_ += window_height_;
    if (ix_top_line_ >= v_lines_.size())
        ix_top_line_ -= window_height_;
}

inline void Buffer::move_to_previous_page()
{
    ix_top_line_ -= window_height_;
    if (ix_top_line_ < 0)
        ix_top_line_ = 0;
}


#endif
