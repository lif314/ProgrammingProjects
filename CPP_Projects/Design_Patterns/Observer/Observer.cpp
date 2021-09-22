#include <iostream>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::string;

//---------------------------
// Application Framework 
//---------------------------
 
class View {
public:
	virtual ~View() { };
	virtual void Update() = 0;		//virtual void Update(Document* doc) = 0;	
};

class Document {	
public:
	virtual ~Document() { };
	Document(string& name) : _name(name) { 
		cout << "Document ctor. name: " << _name << endl; 
	};
		
	/*
	�mDesign Patterns�np.326
	 A template method defines an algorithm in terms of abstract operations  
	 that subclasses override to provide concrete behavior.
	 By defining some of the steps of an algorithm using abstract operations, 
	 the template method fixes their ordering, but it lets subclasses vary 
	 those steps to suit their needs.
	*/			
	void Open()  {   // Template Method
		cout << "Document::Open() \n";
		Serialize();	 
	};
	
	void Paste() { 
		cout << "Document::Paste() \n"; 
	};	
	
	virtual Document* Serialize() = 0; 
	
	/*
	�mDesign Patterns�np.293
	Many graphical user interface toolkits separate the presentational aspects 
	of the user interface from the underlying application data. Classes defining 
	application data and presentations can be reused independently. They can work 
	together, too. Both a spreadsheet object and bar chart object can depict 
	information in the same application data object using different presentations. 
	The spreadsheet and the bar chart don't know about each other, thereby letting 
	you reuse only the one you need. But they behave as though they do. When the 
	user changes the information in the spreadsheet, the bar chart reflects the 
	changes immediately, and vice versa.

	�mDesign Patterns�np.294	
	This behavior implies that the spreadsheet and bar chart are dependent on 
	the data object and therefore should be notified of any change in its state. 
	And there's no reason to limit the number of dependent objects to two; 
	there may be any number of different user interfaces to the same data.
 
	The Observer pattern describes how to establish these relationships. The key objects 
	in this pattern are subject and observer. A subject may have any number of 
	dependent observers. All observers are notified whenever the subject undergoes 
	a change in state. In response, each observer will query the subject to synchronize 
	its state with the subject's state.
	*/
	void Attach(View* view) {	//AddObserver()
		//cout << "Document::Attach() \n";
		_views.push_back(view);
		//cout << "size of _views : " <<  _views.size()  << endl;		
	}
	
	void Detach(View* view) {	//DeleteObserver()
		//cout << "Document::Detach() \n";	
		_views.remove(view);
		//cout << "size of _views : " <<  _views.size()  << endl;			
	}
	
	void Notify() {				//NotifyObservers()
		//cout << "Document::Notify() \n";
		if (_changed) {
			//cout << "for (auto x : _views) x->Update();  size of _views: " <<  _views.size()  << endl;
			for (auto x : _views)
				x->Update();		 
		}
		_changed = false; //�w�g���s�L�F�A���s�]�� false. 
	}
	
	virtual void LButtonDown() = 0;  //�o�������Ӧb view ���A�����칫�аʧ@������ state 
	
	void DataChanged() {	//���~�ɱo�H���� _changed 
		_changed = true;
	}
	
private:
 	string _name;	
 	
 	std::list<View*> _views;  //Observers collection
 	bool _changed = false;
}; 

//------------------
class Application {
public:
	void Add(Document* doc) {
		_docList.push_back(doc);
	};	
	
	virtual Document* GetCurrentDoc() = 0;	 //20210616
	
    /*
	�mDesign Patterns�np.107
	Because the particular Document subclass to instantiate is application-specific, 
	the Application class can't predict the subclass of Document to instantiate��
	the Application class only knows when a new document should be created,not what  
	kind of Document to create. This creates a dilemma: The framework must instantiate 
	classes, but it only knows about abstract classes, which it cannot instantiate.
 
	The Factory Method pattern offers a solution. It encapsulates the knowledge of 
	which Document subclass to create and moves this knowledge out of the framework.
	*/		
	virtual Document* CreateDocument(string&) = 0;  //Factory Method
	
	/*
	�mDesign Patterns�np.127
	Ensure a class only has one instance, ** and provide a global point of access to it.**
	*/	
public: 
	Application() {	//for Singleton, �p�ƪk 
		++_counter;
		if (_counter > 1) 
			throw std::exception();
	}		

protected:
	std::list<Document*> _docList;
	static int _counter;  //for Singleton
};
int Application::_counter = 0;

//------------------
class Command {
public:
    virtual ~Command() {
    	cout << "Command dtor \n";
	};
    
    virtual void Execute() = 0;
protected:
    Command() {
    	cout << "Command ctor \n";
	}
};

/*	
�B�� Composite pattern ���� MacroCommand.

�mDesign Patterns�np.241
A MacroCommand manages a sequence of subcommands and provides operations 
for adding and removing subcommands. No explicit receiver is required, 
because the subcommands already define their receiver.

The key to the MacroCommand is its Execute member function. This traverses 
all the subcommands and performs Execute on each of them. Note that
should the MacroCommand implement an Unexecute operation, then its 
subcommands must be unexecuted in reverse order relative to Execute's implementation.
 
Finally, MacroCommand must provide operations to manage its subcommands. 
The MacroCommand is also responsible for deleting its subcommands.
*/
class MacroCommand : public Command {
public:
    //MacroCommand();
    //virtual ~MacroCommand();
    
    virtual void Add(Command*);
    virtual void Remove(Command*);
    
    virtual void Execute();
private:
    std::list<Command*> _cmds;		
};
	
void MacroCommand::Execute() {   
    for (auto cp : _cmds) {   
        cp->Execute();
    }
}
	
void MacroCommand::Add(Command* c) {
    _cmds.push_back(c);
}
    
void MacroCommand::Remove(Command* c) {
    _cmds.remove(c);
}	

/* 
�mDesign Patterns�np.239
OpenCommand opens a document whose name is supplied by the user. 
An OpenCommand must be passed an Application object in its constructor. 
AskUser is an implementation routine that prompts the user 
for the name of the document to open. 

�o�� command ���X���u�O "Application" �M "Document" 
*/
class OpenCommand : public Command {
public:
    OpenCommand(Application* app) : _app(app) {
	}
    
    virtual void Execute();
   
protected:
    virtual string AskUser() {
    	cout << "OpenCommand::AskUser() \n";
    	return string("test.txt");  //²�Ƥ��A�����]�w�W��.		
	}

private:
    Application* _app;
};

void OpenCommand::Execute() {
    string name = AskUser();											 
	Document* doc = _app->CreateDocument(name);	 //Factory Method		
			 
    _app->Add(doc);
    doc->Open();	
}
  
/*
�mDesign Patterns�np.240
A PasteCommand must be passed a Document object as its receiver. 
The receiver is given as a parameter to PasteCommand's constructor.

�o�� command ���X���u�O "Document"  
*/	 
class PasteCommand : public Command {
public:
    PasteCommand(Document* doc) : _doc(doc) {	
	};
    
    virtual void Execute() {
    	_doc->Paste();    	
	}
private:
    Document* _doc;
};
      

//====================================
//���� Application Framework & Command    
//====================================
class MyDoc : public Document {
public:
	MyDoc(string& name) : Document(name), _subjectState(1) {
		cout << "MyDoc ctor. i= " << _subjectState << endl;
	}
	
	virtual Document* Serialize() { 
		cout << "MyDoc::serialize() \n";
	}
	
	virtual void LButtonDown() { 	//�o�������Ӧb view ���A�����칫�аʧ@������ state 
		cout << "MyDoc::LButtonDown() \n";
		_subjectState *= 5;
		DataChanged();	//�]�w "state �w�Q����" �аO 
		Notify();
	}
	
	int GetState() {	
		return _subjectState;
	}
	
private:
	int _subjectState; 
};

/*
�ѩ��o�Ӫ����ϥΤF Factory Method, �ҥH application ���ઽ���ϥ� class Application, 
�������ͥX MyApp, �o�~�� override the Factory Method. 

�mDesign Patterns�np.108
Application subclasses redefine an abstract CreateDocument operation on Application 
to return the appropriate Document subclass. Once an Application subclass is instantiated, 
it (�o�� it �O�� class Application) can then instantiate application-specific Documents 
without knowing their class. We call CreateDocument a factory method because 
it's responsible for "manufacturing" an object.
*/
class MyApp : public Application {
public:	
	virtual Document* CreateDocument(string& name) {  //Factory Method
	    cout << "MyApp::CreateDocument() \n";
		return new MyDoc(name);
	}
	
	virtual MyDoc* GetCurrentDoc() override {	 //20210616
		return dynamic_cast<MyDoc*>(_docList.back());
	}
};

class MyView1 : public View
{
public:
	MyView1(MyDoc* myDoc) : _subject(myDoc) {
		_subject->Attach(this);
	}

 	virtual void Update() override {		//virtual void Update(Document* doc) {	
		cout << "MyView1::Update()  data= " << _subject->GetState() << endl; 
	}	
private:
	MyDoc* _subject;
};

class MyView2 : public View
{
public:
	MyView2(MyDoc* myDoc) : _subject(myDoc) {
		_subject->Attach(this);
	}

 	virtual void Update() override {		//virtual void Update(Document* doc) {	
		cout << "MyView2::Update()  data= " << _subject->GetState() << endl; 
	}	
private:
	MyDoc* _subject;
};

class MyView3 : public View
{
public:
	MyView3(MyDoc* myDoc) : _subject(myDoc) {
		_subject->Attach(this);
	}

 	virtual void Update() override {		//virtual void Update(Document* doc) {	
		cout << "MyView3::Update()  data= " << _subject->GetState() << endl; 
	}	
private:
	MyDoc* _subject;
};

//------------------	
int main()
{
	MyApp* myApp = new MyApp;  
	cout << "\ntest OpenCommand ... \n";	 
	OpenCommand oCmd(myApp);
	oCmd.Execute();		//Document::Open()
	                    //MyDoc::Serialize() <= �o�O�ڭn���ĪG, Good.
		                    
	cout << "\ntest PasteCommand ... \n";	 	
	Document* myDoc = myApp->GetCurrentDoc();	
	PasteCommand pCmd(myDoc);	
	pCmd.Execute();		//Document::Paste()
	
	cout << "\ntest MacroCommand ... \n";
    MacroCommand macroCmd;
    macroCmd.Add(&oCmd);
    macroCmd.Add(&pCmd);
    macroCmd.Execute();
	cout << endl;    
	
	cout << "\ntest Document-Views (Subject-Observers) ... \n";	
	MyView1* myView1_1 = new MyView1(myApp->GetCurrentDoc()); 
	MyView1* myView1_2 = new MyView1(myApp->GetCurrentDoc()); 	
	MyView1* myView1_3 = new MyView1(myApp->GetCurrentDoc()); 	
	MyView2* myView2   = new MyView2(myApp->GetCurrentDoc()); 		
	MyView3* myView3   = new MyView3(myApp->GetCurrentDoc()); 	
					
	//change data
	myApp->GetCurrentDoc()->LButtonDown(); 
	myApp->GetCurrentDoc()->LButtonDown();   
	myApp->GetCurrentDoc()->LButtonDown();  
	//myDoc->LButtonDown(); 
	//���o�N���o���~���G�CmyDoc ���Y�� _views �j�p�� 0. 
	//�]�N�O�� myDoc �M myApp->GetCurrentDoc() ���O�P�@�ӪF��. 
	//�������H�Q�Q. (�`�N GetCurrentDoc() ���u���ܲ��W��²�ƾާ@)
	  
	delete myApp;
	delete myDoc;  	//�������ӥ� Application dtor �t�d. 
	delete myView1_1;
	delete myView1_2;
	delete myView1_3;
	delete myView2;
	delete myView3;		
	   
    cout << "\nprogram done ... \n";
    return 0;
}				  
