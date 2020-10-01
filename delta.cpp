#include <bits/stdc++.h>
#define pc putchar
#define gc getchar
#define gcu getchar_unlocked
#define fi first
#define se second
#define pb push_back
#define mod ((ll)1e9 + 7)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
//===============================================================================================

int n;
double delta, a[9], b[9];
vector<double> ans, p, q;

//===============================================================================================
int main()
{
    printf("\n\n▓█████▄  ▓█████  ██▓   ▄▄▄█████▓ ▄▄▄     \n▒██▀ ██▌ ▓█   ▀ ▓██▒   ▓  ██▒ ▓▒▒████▄   \n░██   █▌ ▒███   ▒██░   ▒ ▓██░ ▒░▒██  ▀█▄ \n░▓█▄   ▌ ▒▓█  ▄ ▒██░   ░ ▓██▓ ░ ░██▄▄▄▄██\n░▒████▓ ▒░▒████▒░██████  ▒██▒ ░ ▒▓█   ▓██\n ▒▒▓  ▒ ░░░ ▒░ ░░ ▒░▓    ▒ ░░   ░▒▒   ▓▒█\n ░ ▒  ▒ ░ ░ ░  ░░ ░ ▒      ░    ░ ░   ▒▒ \n ░ ░  ░     ░     ░ ░    ░        ░   ▒\n   ░    ░   ░  ░    ░                 ░\n");
    printf("\n\nProgram do obliczania pierwiastkow rownan\nwersja 1.2\nautor: Michal Kimborowicz\n\n");
    while (true)
    {
        printf("stopien rownania: ");
        scanf("%d", &n);
        ans.clear();
        if (n > 3 || n < 1)
        {
            printf("huj ci na dupe\n\n");
            continue;
        }
        for (int i = 0; i <= n; i++)
        {
            printf("%c: ", 'a' + i);
            scanf("%lf", &a[i]);
        }
        if (n == 3)
        {
            if (!a[0])
            {
                a[0] = a[1];
                a[1] = a[2];
                a[2] = a[3];
                n--;
            }
            else
            {
                if (!a[3])
                    ans.pb(0),
                        n--;
                else
                {
                    for (int i = 1; i <= a[0]; i++)
                        if (((int)a[0] / i) * i == (int)a[0])
                            q.pb(i),
                                q.pb(-i);
                    for (int i = 1; i <= a[3]; i++)
                        if (((int)a[3] / i) * i == (int)a[3])
                            p.pb(i),
                                p.pb(-i);
                    for (int i = 0; i < p.size(); i++)
                    {
                        for (int j = 0; j < q.size(); j++)
                        {
                            if (a[0] * p[i] * p[i] * p[i] / q[j] / q[j] / q[j] + a[1] * p[i] * p[i] / q[j] / q[j] + a[2] * p[i] / q[j] + a[3] == 0)
                            {
                                ans.pb(p[i] / q[j]);
                                b[0] = a[0];
                                b[1] = b[0] * p[i] / q[j] + a[1];
                                b[2] = b[1] * p[i] / q[j] + a[2];
                                a[0] = b[0], a[1] = b[1], a[2] = b[2];
                                i = p.size();
                                break;
                            }
                        }
                    }
                    if (!ans.size())
                    {
                        printf("to nie jest lama ktorej szukacie\n\n");
                        continue;
                    }
                    n--;
                }
            }
        }
        if (ans.size())
            printf("(x%+.2lf) * (%+.2lf*x^2 %+.2lf*x %+.2lf)=0\n", -ans[0], a[0], a[1], a[2]);
        if (n == 2)
        {
            delta = a[1] * a[1] - 4 * a[0] * a[2];
            printf("delta = %+.2lf^2 -4*%+.2lf*%+.2lf = %+.2lf %+.2lf = %+.2lf\n", a[1], a[0], a[2], a[1] * a[1], (-4) * a[0] * a[2], delta);
            if (delta < 0)
            {
                for (int i = 0; i < ans.size(); i++)
                    printf("x%d = %+.2lf\n", i + 1, ans[i]);
                printf("\n");
                continue;
            }
            if (!delta)
            {
                ans.pb(-a[1] / (2.0 * a[0]));
                for (int i = 0; i < ans.size(); i++)
                    printf("x%d = %+.2lf\n", i + 1, ans[i]);
                printf("\n");
                continue;
            }
            printf("sqrt(delta) = %+.2lf\n", sqrt(delta));
            ans.pb((-a[1] + sqrt(delta)) / (2.0 * a[0]));
            ans.pb((-a[1] - sqrt(delta)) / (2.0 * a[0]));
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                printf("x%d = %+.2lf\n", i + 1, ans[i]);
            printf("\n");
            continue;
        }
        printf("x1 = %+.2lf\n\n", (-a[1]) / a[0]);
    }
}
//===============================================================================================