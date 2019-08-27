#include <string>
#include <iostream>
using namespace std;
unsigned int polyHash(string keys)
{
    unsigned int hashValue = 0;
    unsigned int a = 33;
    for (int i = 0; i < keys.size(); i++)
        hashValue = (keys[i] + a * hashValue);
    return hashValue & 0x7FFFFFFF;
}
int main()
{
    string keys = "Anne";
    cout << polyHash(keys);
    return 0;
}