#include <iostream>

class Button
{
    public:
	virtual void paint() = 0;
};

class WinButton : public Button
{
    public:
	void paint() { std::cout << " Window Button \n"; }
};

class MacButton : public Button
{
    public:
	void paint() { std::cout << " Mac Button \n"; }
};

class LinuxButton : public Button
{
    public:
	void paint() { std::cout << " Linux Button \n"; }
};

class ComboBox
{
    public:
	virtual void paint() = 0;
};

class WinComboBox : public ComboBox
{
    public:
	void paint() { std::cout << " Window ComboBox \n"; }
};

class MacComboBox : public ComboBox
{
    public:
	void paint() { std::cout << " Mac ComboBox \n"; }
};

class LinuxComboBox : public ComboBox
{
    public:
	void paint() { std::cout << " Linux ComboBox \n"; }
};

class ScrollBar
{
    public:
	virtual void paint() = 0;
};

class WinScrollBar : public ScrollBar
{
    public:
	void paint() { std::cout << " Window ScrollBar \n"; }
};

class MacScrollBar : public ScrollBar
{
    public:
	void paint() { std::cout << " Mac ScrollBar \n"; }
};

class LinuxScrollBar : public ScrollBar
{
    public:
	void paint() { std::cout << " Linux ScrollBar \n"; }
};

//allows adding and remove specific look and feel here

class GUIFactory
{
    public:
	virtual Button *createButton()       = 0;
	virtual ScrollBar *createScrollBar() = 0;
	virtual ComboBox *createComboBox()   = 0;
	//simillarly new look and feel can be added here
};

class WinFactory : public GUIFactory
{
    public:
	Button *createButton() { return new WinButton; }

	ScrollBar *createScrollBar() { return new WinScrollBar; }

	ComboBox *createComboBox() { return new WinComboBox; }
};

class MacFactory : public GUIFactory
{
    public:
	Button *createButton() { return new MacButton; }

	ScrollBar *createScrollBar() { return new MacScrollBar; }

	ComboBox *createComboBox() { return new WinComboBox; }
};

class LinuxFactory : public GUIFactory
{
    public:
	Button *createButton() { return new LinuxButton; }

	ScrollBar *createScrollBar() { return new LinuxScrollBar; }

	ComboBox *createComboBox() { return new WinComboBox; }
};

int main()
{
    GUIFactory *guiFactory;
    Button     *btn;
    ScrollBar  *sb;
    ComboBox   *cb;

    guiFactory = new MacFactory;
    btn        = guiFactory->createButton();
    btn->paint();
    sb = guiFactory->createScrollBar();
    sb->paint();
    cb = guiFactory->createComboBox();
    cb->paint();

    guiFactory = new WinFactory;
    btn        = guiFactory->createButton();
    btn->paint();
    sb = guiFactory->createScrollBar();
    sb->paint();
    cb = guiFactory->createComboBox();
    cb->paint();

    guiFactory = new LinuxFactory;
    btn        = guiFactory->createButton();
    btn->paint();
    sb = guiFactory->createScrollBar();
    sb->paint();
    cb = guiFactory->createComboBox();
    cb->paint();

    return 0;
}
