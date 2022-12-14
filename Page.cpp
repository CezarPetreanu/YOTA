#include "include/Page.h"
#include <iostream>

Page::Page()
{
    this->page_number = -1;
    this->text = "";
    this->options.push_back(make_pair("", -1));
}

Page::Page(int page_number, string text, vector<pair<string, int>> options)
{
    this->page_number = page_number;
    this->text = text;
    this->options = options;
}

Page::~Page()
{
}

void Page::show_text()
{
    cout << this->text;
}

void Page::show_options()
{
    int n = 1;
    for (auto i : this->options)
        cout << n++ << ". " << i.first << '\n';
}