#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Page
{
    int page_number;
    string text;
    vector<pair<string, int>> options;

public:
    Page();
    Page(int page_number, string text, vector<pair<string, int>> options);
    virtual ~Page();

protected:
private:
};

#endif // PAGE_H
