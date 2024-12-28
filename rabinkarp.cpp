#include <iostream>
#include <string>

using namespace std;

void rabinKarp(const string& text, const string& pattern, int d, int q)
{
    int n = text.size();
    int m = pattern.size();

    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;
    int p = 0;
    int t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int s = 0; s <= n - m; s++)
    {
        if (p == t)
        {
            bool match = true;
            for (int i = 0; i < m; i++)
            {
                if (text[s + i] != pattern[i])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern occurs with shift " << s << endl;
        }
        if (s < n - m)
            {
            t = (d * (t - text[s] * h) + text[s + m]) % q;
            if (t < 0)
                t += q;
            }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    int d = 26;
    int q = 5381;
    rabinKarp(text, pattern, d, q);

    return 0;
}
