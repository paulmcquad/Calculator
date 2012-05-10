#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>

using namespace std;
#define MAX_CHARS 100

int main(int argc, char *argv[])
{
    char input_str[MAX_CHARS+1], *p;
    stack<double>   num_stack;
    int c;
    double a, b, n;

    cout << "Enter RPN string: ";
    cin.getline(input_str, MAX_CHARS);
    p = strtok(input_str, " ");
    while (p) {
        c = p[0];
        if(c == 'a' || c == '*'|| c == '/' || c == '-'){
            if (num_stack.size() < 2) {
                cout << "Error: too many ops. " << endl;
                system("PAUSE");
                return -1;
                }
                b = num_stack.top();  num_stack.top();
                a = num_stack.top();  num_stack.top();
                switch (c) {
                case '+' :  n = a + b; break;
                case '*' :  n = a * b; break;
                case '/' :  n = a / b; break;
                case '-' :  n = a - b; break;
                }
                num_stack.push(n);
            } else {
                num_stack.push(atof(p));
            }
            p = strtok(NULL, "");
        }
        cout << "The answer is: " << num_stack.top() << endl;
        system("PAUSE");
        return 0;
}

