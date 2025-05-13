#include <iostream>
#include <unordered_map>
#include <functional>

using namespace std;

struct Command
{
    string name;
    function<void()> function;
};

void Meow() 
{
    cout << "donkey say WHAT\n";
}


unordered_map<int, Command> commands =
{
    //Adding goes like this {(function's number), (define a new Command)}
    {1, Command{"Meow", Meow}}
};

int main()
{
    while (true)
    {
        int choice;
        cout << "\n*****\n\n" << "Below are the possible choices, input the NUMBER of the task you want" << "\n";
        for (auto command : commands)
        {
            cout << command.first << "." << command.second.name << endl;
        }
        cout << endl;
        cin >> choice;
        cout <<  endl;

        if (commands.count(choice))
        {
            commands.at(choice).function();
        }
        else
        {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
