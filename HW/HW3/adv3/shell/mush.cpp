#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    const int BUFLEN = 1000;
    const int MAXARG = 15;
    char BUF[BUFLEN];
    char *argument_list[MAXARG];

    while (1) {
        // read input
        string line;
        vector<string> arg;
        do {
            cout << getenv("USER") << ":" << getcwd(BUF, BUFLEN) << "$ ";
            getline(cin, line);
            if (cin.eof()) { cout << "eof";  exit(0); }
            stringstream ss;
            ss << line;
            while (ss >> line) {
                arg.push_back(line);
            }
        } while (arg.empty());

        // parse input
        if (arg[0] == "exit") exit(0);
        if (arg[0] == "cd") {
            if (chdir(arg[1].c_str()) == -1)
                cerr << "mush: cd: nu such file or directory '" << arg[1] << "'\n";
        } else {
            // convert vector<string> to char *[];
            for (size_t i = 0; i < arg.size(); i++) {
                argument_list[i] = (char *)arg[i].c_str();
            }
            argument_list[arg.size()] = NULL;

            // execute
            pid_t pid, wpid;
            int status;
            if (!(pid = fork())) { // child
                if (execvp(argument_list[0], argument_list) == -1) {
                    cerr << "mush: command '" << argument_list[0] << "' not found\n";
                }
            } else {
                do {
                    wpid = waitpid(pid, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
                // wait for child
            }
        }   
        
    }
    return 0;
}
