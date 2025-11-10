#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <string>

using namespace std;

int print_syntax();
int soft2hard();

int soft2hard()
{
    // Optimize I/O performance
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string buffer;

    while (getline(cin, buffer))
    {
        if (buffer.size() == 0)
            continue;
        if (buffer[0] == '>')
        {
            cout << buffer << '\n';
        }
        else
        {
            // Single-pass transformation: replace lowercase nucleotides with 'N'
            std::transform(buffer.begin(), buffer.end(), buffer.begin(),
                [](char c) {
                    return (c == 'a' || c == 't' || c == 'c' || c == 'g') ? 'N' : c;
                });

            cout << buffer << '\n';
        }

        // Check for output errors
        if (cout.fail())
        {
            cerr << "Error: Failed to write to stdout" << endl;
            return 1;
        }
    }

    // Check for input errors
    if (cin.bad())
    {
        cerr << "Error: Failed to read from stdin" << endl;
        return 1;
    }

    return 0;
}

int print_syntax()
{

    cerr << "Usage: cat/zcat/bzcat *.fa | soft2hard | or > into another program or file" << endl;
return 0;
}

int main()
{

    (isatty(fileno(stdin)) ? print_syntax : soft2hard)();
    return 0;
}
