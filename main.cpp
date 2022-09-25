#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <utility>

#include "include/Page.h"
#include "Page.cpp" //not good! it works, but it's NOT GOOD!!

using namespace std;

void load_adv(string filename, vector<Page *> &adventure)
{
    int mode = 0; /*
                    0 - page
                    1 - text
                    2 - options
                    */

    int page_number;
    string text;
    string option_text;
    vector<pair<string, int>> options;

    ifstream fin;
    fin.open(filename);

    string line;
    while (getline(fin, line))
    {
        if (line[0] == '#')
        {
            stringstream s(line);
            string keyword;
            getline(s, keyword, ' ');
            if (keyword == "#page")
            {
                if (mode != 0)
                {
                    Page *p = new Page(page_number, text, options);
                    adventure.push_back(p);
                    text = "";
                    option_text = "";
                }

                mode = 0;
                getline(s, keyword, ' ');
                page_number = atoi(keyword.c_str());
            }
            else if (keyword == "#text")
            {
                mode = 1;
                continue;
            }
            else if (keyword == "#options")
            {
                mode = 2;
                continue;
            }
        }
        else
        {
            if (mode == 1)
            {
                text += line;
                text += "\n";
            }
        }
    }

    fin.close();
}

int main()
{
    vector<Page *> adventure;
    load_adv("DemoAdv.txt", adventure);
    adventure[0]->show_text();
    adventure[1]->show_text();
    adventure[2]->show_text();
    // adventure[3]->show_text();       // segmentation fault, i know how to fix it, i'll do it later;
    return 0;
}