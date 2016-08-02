// Factory creates and returns product object
#include <iostream>
class Button { 
    public: virtual void paint() = 0; };

class OSXButton: public Button {
    public: void paint() { std::cout << "OSX button \n"; } };

class WindowsButton: public Button  {
    public: void paint() { std::cout << "Windows button \n"; } };

// Factory creates and returns product object
class GUIFactory {
    public: virtual Button *createButton(char *) = 0; }; 

class Factory: public GUIFactory {
    public:
	Button *createButton(char *type) {
	    if(strcmp(type,"Windows") == 0) {
		return new WindowsButton;
	    }
	    else if(strcmp(type,"OSX") == 0) {
		return new OSXButton;
	    }
	}
};

int main()
{
    GUIFactory* guiFactory = new Factory;
    Button *btn = guiFactory->createButton("OSX");
    btn -> paint();
    return 0;
}
