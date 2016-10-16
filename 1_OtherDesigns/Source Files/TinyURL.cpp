#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
 
// Function to generate a short url from intger ID
string idToShortURL(long int n)
{
    // Map to store 62 possible characters
    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                 "GHIJKLMNOPQRSTUVWXYZ0123456789";
 
    string shorturl;
 
    // Convert given integer id to a base 62 number
    while (n)
    {
        // use above map to store actual character
        // in short url
        shorturl.push_back(map[n%62]);
        n = n/62;
    }
 
    // Reverse shortURL to complete base conversion
    reverse(shorturl.begin(), shorturl.end());
 
    return shorturl;
}
 
// Function to get integer ID back from a short url
long int shortURLtoID(string shortURL)
{
    long int id = 0; // initialize result
 
    // A simple base conversion logic
    for (int i=0; i < shortURL.length(); i++)
    {
        if ('a' <= shortURL[i] && shortURL[i] <= 'z')
          id = id*62 + shortURL[i] - 'a';
        if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
          id = id*62 + shortURL[i] - 'A' + 26;
        if ('0' <= shortURL[i] && shortURL[i] <= '9')
          id = id*62 + shortURL[i] - '0' + 52;
    }
    return id;
}
 
// Driver program to test above function
int main()
{
    int n = 589257;
    string shorturl = idToShortURL(n);
    cout << "Generated short url for a long link such as \nwww.tinyurl.com/acc=Jenna%20Fabray&id=233&type=twit&locale=usa \nwith ID : "<<shortURLtoID(shorturl)<<" is "<<endl;
	cout<<"\n\twww.tinyurl.com/" << shorturl << endl;
	cin.get();
	cin.get();

    return 0;
}

