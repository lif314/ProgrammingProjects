# include <iostream>
# include <list>
# include <string>

using std::cout;

/*
 * <<Design Patterns>> p.233
 * 
 * 
 */


// <<Design Pattern>> p.239
class Command{
    public:
    virtual ~Command(){
        cout << "Command dtor \n";
    };

    virtual void Execute() = 0;

    protected:
    Command(){
        cout << "Command ctor \n";
    }
};



/*
 * <<Design Patterns>> p.240 
 * 
 */


template <class Receiver>
class SimpleCommand : public Command{
    public:
    typedef void (Receiver::*Action)();

    SimpleCommand(Receiver* r, Action a):_receiver(r), _action(a){}

    virtual void Execute();

    private:
    Action _action;
    Receiver * _receiver;
};



template <class Receiver>
void SimpleCommand<Receiver>::Execute(){
    (_receiver->*_action)();
}



/*
 * <<Design Patterns>> p.241 
 * 
 * 
 */

class MacroCommand : public Command{
    public:
    // MacroCommand();
    // virtual ~MacroCommand();

    virtual void Add(Command*);
    virtual void Remove(Command*);

    virtual void Execute();

    private:
    std::list<Command*> _cmds;
};


void MacroCommand::Execute(){
    for(auto cp : _cmds){
        cp->Execute();
    }
}


void MacroCommand::Add(Command * c){
    _cmds.push_back(c);
}

void MacroCommand::Remove(Command * c){
    _cmds.remove(c);
}



// ==============================
// test
// ==============================
class MyClass1{
    public:
    void Action() { cout << "MyClass1::Action(); \n"; }
};

class MyClass2{
    public:
    void Action() { cout << "MyClass2::Action(); \n"; }
};




int main()
{
    cout << "Test SimpleCommand<> ... \n";

    MyClass1 receiver1;
    Command * cmd1 = new SimpleCommand<MyClass1>(&receiver1, & MyClass1::Action);
    cmd1->Execute();

    MyClass2 receiver2;
    Command * cmd2 = new SimpleCommand<MyClass2>(&receiver2, & MyClass2::Action);
    cmd2->Execute();

    cout << "Test MacroCommand ... \n";
    MacroCommand macroCmd;
    macroCmd.Add(cmd1);
    macroCmd.Add(cmd2);
    macroCmd.Execute();

    macroCmd.Remove(cmd2);
    macroCmd.Execute();

    delete cmd1;
    delete cmd2;

    cout << "Program done ... \n";

    return 0;
}