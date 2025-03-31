#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sentence = ".";
    stack<char> s;

    int chk = 0;

    while (true)
    {
        sentence.clear();
        getline(cin, sentence, '.');
        if (sentence == "\n" || sentence == "")
        {
            break;
        }
        while (s.empty() != 1)
        {
            s.pop();
        }
        chk = 0;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == '(')
            {
                s.push(sentence[i]);
            }
            else if (sentence[i] == ')')
            {
                if (s.empty() == 1 || s.top() == '[')
                {
                    chk = 1;
                    break;
                }
                else
                {
                    s.pop();
                }
            }
            else if (sentence[i] == '[')
            {
                s.push(sentence[i]);
            }
            else if (sentence[i] == ']')
            {
                if (s.empty() == 1 || s.top() == '(')
                {
                    chk = 1;
                    break;
                }
                else
                {
                    s.pop();
                }
            }
        }
        if (chk == 1 || s.empty() != 1)
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
    }

    return 0;
}