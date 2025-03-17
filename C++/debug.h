#ifndef DEBUG_CPP
#define DEBUG_CPP
#include <bits/stdc++.h>
using namespace std;
namespace __DEBUG_UTIL__
{
    /* Print primitive datatypes */
    void print(const char *x) { cout << x; }
    void print(bool x) { cout << (x ? "T" : "F"); }
    void print(char x) { cout << '\'' << x << '\''; }
    void print(signed short int x) { cout << x; }
    void print(unsigned short int x) { cout << x; }
    void print(signed int x) { cout << x; }
    void print(unsigned int x) { cout << x; }
    void print(signed long int x) { cout << x; }
    void print(unsigned long int x) { cout << x; }
    void print(signed long long int x) { cout << x; }
    void print(unsigned long long int x) { cout << x; }
    void print(float x) { cout << x; }
    void print(double x) { cout << x; }
    void print(long double x) { cout << x; }
    void print(string x) { cout << '\"' << x << '\"'; }
    template <size_t N>
    void print(bitset<N> x) { cout << x; }
    void print(vector<bool> v)
    { /* Overloaded this because stl optimizes vector<bool> by using
          _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cout << '{';
        for (auto &&i : v)
            cout << (f++ ? "," : "") << (i ? "T" : "F");
        cout << "}";
    }

    /* Template declarations to support nested datatypes */
    template <typename T>
    void print(T &&x);
    template <typename T>
    void print(vector<vector<T>> mat);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(pair<F, S> x);
    template <typename T, size_t N>
    struct Tuple;
    template <typename T>
    struct Tuple<T, 1>;
    template <typename... Args>
    void print(tuple<Args...> t);
    template <typename... T>
    void print(priority_queue<T...> pq);
    template <typename T>
    void print(stack<T> st);
    template <typename T>
    void print(queue<T> q);

    /* Template datatypes definitions */
    template <typename T>
    void print(T &&x)
    {
        /*  Works for every container that supports range-based loop
            i.e. vector, set, map, oset, omap, dequeue */
        int f = 0;
        cout << '{';
        for (auto &&i : x)
            cout << (f++ ? "," : ""), print(i);
        cout << "}";
    }
    template <typename T>
    void print(vector<vector<T>> mat)
    {
        int f = 0;
        cout << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cout << setw(2) << left << f++, print(i), cout << "\n";
        }
        cout << "~~~~~\n";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        int f = 0;
        cout << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cout << setw(2) << left << f++, print(i), cout << "\n";
        }
        cout << "~~~~~\n";
    }
    template <typename F, typename S>
    void print(pair<F, S> x)
    {
        cout << '(';
        print(x.first);
        cout << ',';
        print(x.second);
        cout << ')';
    }
    template <typename T, size_t N>
    struct Tuple
    {
        static void printTuple(T t)
        {
            Tuple<T, N - 1>::printTuple(t);
            cout << ",", print(get<N - 1>(t));
        }
    };
    template <typename T>
    struct Tuple<T, 1>
    {
        static void printTuple(T t) { print(get<0>(t)); }
    };
    template <typename... Args>
    void print(tuple<Args...> t)
    {
        cout << "(";
        Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
        cout << ")";
    }
    template <typename... T>
    void print(priority_queue<T...> pq)
    {
        int f = 0;
        cout << '{';
        while (!pq.empty())
            cout << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cout << "}";
    }
    template <typename T>
    void print(stack<T> st)
    {
        int f = 0;
        cout << '{';
        while (!st.empty())
            cout << (f++ ? "," : ""), print(st.top()), st.pop();
        cout << "}";
    }
    template <typename T>
    void print(queue<T> q)
    {
        int f = 0;
        cout << '{';
        while (!q.empty())
            cout << (f++ ? "," : ""), print(q.front()), q.pop();
        cout << "}";
    }

    /* Printer functions */
    void printer(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        /* Using && to capture both lvalues and rvalues */
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cout.write(names, i) << " = ";
        print(head);
        if (sizeof...(tail))
            cout << " ||", printer(names + i + 1, tail...);
        else
            cout << "]\n";
    }
    void printerArr(const char *) {}
    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t ind = 0;
        for (; names[ind] and names[ind] != ','; ind++)
            cout << names[ind];
        for (ind++; names[ind] and names[ind] != ','; ind++)
            ;
        cout << " = {";
        for (size_t i = 0; i < N; i++)
            cout << (i ? "," : ""), print(arr[i]);
        cout << "}";
        if (sizeof...(tail))
            cout << " ||", printerArr(names + ind + 1, tail...);
        else
            cout << "]\n";
    }
}
#ifndef ONLINE_JUDGE
#define deb(...) cout << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define deb(...)
#endif
#endif
