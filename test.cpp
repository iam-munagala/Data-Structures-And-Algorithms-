#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char *a = "Hello\0World";
    cout << strlen(a) << endl;
    return 0;
}