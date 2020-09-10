#include <iostream>
#include <string.h>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::cout;
using std::endl;

string generateShortUrl(string url) {
	int i = 0;
	int count = 0;
	string result;

	while (count < 3) {
		if (url[i+1] == '/') {
			count++;
		}
		i++;
	}

	result = url.substr(0, i);

	return result;
}

void generator(unordered_map<string, string>& umap, string url) {
	string smallUrl = generateShortUrl(url);
	
	umap[smallUrl] = url;
}



int main()
{
	unordered_map<string, string> urls;
	string example = "https://www.geeksforgeeks.org/how-to-design-a-tiny-url-or-url-shortener/";

	generator(urls, example);

	cout << urls["https://www.geeksforgeeks.org"] << endl;

	return 0;
}