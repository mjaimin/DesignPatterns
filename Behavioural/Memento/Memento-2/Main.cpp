#include <iostream>
#include <string>
using namespace std;

class Memento 
{
public:
   string fileName;
   string content;
   Memento(string file, string data):fileName(file), content(data){}
};

class FileWriterUtil //Originator Class
{
private:
   string fileName;
   string content;

public:
   FileWriterUtil(string file) : fileName(file) {}

   void write(string str)
   {
      content.append(str);
   }

   Memento* CreateMemento(void)
   {
      return new Memento(fileName, content);
   }

   void undoToLastSave(Memento *memento)
   {
      fileName = memento->fileName;
      content  = memento->content;
   }
   string getContent(void)
   {
       return content;
   }
};

class FileWriterCaretaker
{
private:
   Memento *memento;

public:
   void save(FileWriterUtil *fileWriter)
   {
      memento = fileWriter->CreateMemento();
   }

   void undo(FileWriterUtil *fileWriter)
   {
      fileWriter->undoToLastSave(memento);
   }
};

int main()
{
   FileWriterCaretaker *caretaker = new FileWriterCaretaker();

   FileWriterUtil *fileWriter = new FileWriterUtil("data.txt");

   fileWriter->write("First Set of Data\n");
   cout << fileWriter->getContent() << endl;

   // lets save the file
   caretaker->save(fileWriter);
   //now write something else
   fileWriter->write("Second Set of Data\n");

   //checking file contents
   cout << fileWriter->getContent() << endl;

   //lets undo to last save
   caretaker->undo(fileWriter);

   //checking file content again
   cout << fileWriter->getContent() << endl;
}
