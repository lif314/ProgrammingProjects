# include <iostream>
# include <list>
# include <string>

using std::cout;
using std::endl;
using std::string;


//-------------------------
// Application Framework 
//-------------------------

class Document{
public:
    Document(string& name) : _name(name){
        cout << "Document ctor. name: " << _name << endl;
    }

    /**
     * <<Design Patterns>> p.326 
     */

    void Open(){ // Template Method
        cout << "Document::Open() \n";
        Serialize();
    };


    void Paste() {
        cout << "Document::Paste() \n";
    };

    virtual Document* Serialize(){ cout << "Document::Serialize() \n"; }

private:
    string _name;
//-------------------------
class Application
{
public:
    void Add(Document* doc){
        _docList.push_back(doc);
    };

    Document* GetCurrentDoc(){
        return _docList.back();
    };

private:
    std::list<Document*> _docList;
};


class Command {
public:
    virtual ~Command(){
        cout << "Command dtor \n";
    };

    virtual void Execute() = 0;

protected:
    Command(){
        cout << "Command ctor \n";
    };
};

/**
 * <<Design Patterns>>
 * 
 * 
 */