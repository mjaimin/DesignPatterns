#include <iostream>
#include <string>
#include <stack>
using namespace std;

class GameFrameWorkEditor // Receiver
{
    private:
        int Position;
        string GameBackGroundColor;
    public:
        GameFrameWorkEditor():Position(0), GameBackGroundColor("White"){}
        void MovePlayer( int position )
        {
            Position = position;
        }
        void SetBackGroundColor( string color )
        {
            GameBackGroundColor = color;
        }
        int getPlayerPosition(){return Position;}
        string getBackGroundColor(){return GameBackGroundColor;}
};

class ICommand
{
    public:
        virtual void execute() = 0;
};

class PlayerPositionChanger: public ICommand //concrete command
{
    private:
        GameFrameWorkEditor* GameObj;
        int Position;
    public:
        PlayerPositionChanger(GameFrameWorkEditor* gameObj, int position):GameObj(gameObj),Position(position){}
        void execute()
        {
            GameObj->MovePlayer(Position);
        }

};
class GameBackGroundChanger: public ICommand //concrete command
{
    private:
        GameFrameWorkEditor* GameObj;
        string Color;
    public:
        GameBackGroundChanger(GameFrameWorkEditor* gameObj, string color):GameObj(gameObj),Color(color){}
        void execute()
        {
            GameObj->SetBackGroundColor(Color);
        }
};

class GameStateManager //Invoker
{
    private:
        GameFrameWorkEditor* GameObj;
        stack<ICommand*> undoCommands;
        stack<ICommand*> redoCommands;
    public:
        GameStateManager(GameFrameWorkEditor* gameObj):GameObj(gameObj){};
        void setGameObjectForCommand(GameFrameWorkEditor* gameObj)
        {
            GameObj = gameObj;
        }
        void changePosition( int position )
        {
            ICommand* cmd = new PlayerPositionChanger(GameObj,position);
            cmd->execute();
            undoCommands.push(cmd);
        }
        void changeColor( string color )
        {
            ICommand* cmd = new GameBackGroundChanger(GameObj,color);
            cmd->execute();
            undoCommands.push(cmd);
        }
        void undo()
        {
            if(!undoCommands.empty())
            {
                ICommand* cmd = undoCommands.top();
                redoCommands.push(cmd);
                undoCommands.pop();
                cmd = undoCommands.top();
                cmd->execute();
            }
        }
        void redo()
        {
            if(!redoCommands.empty())
            {
                ICommand* cmd = redoCommands.top();
                undoCommands.push(cmd);
                redoCommands.pop();
                cmd = redoCommands.top();
                cmd->execute();
            }
        }
};

main()
{

    GameFrameWorkEditor* receiver = new GameFrameWorkEditor();
    //because multiple commands any concrete command is not instanciated here, it is there in invoker
    //hence passing receiver directly to Invoker
    GameStateManager* invoker = new GameStateManager(receiver);
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->changePosition(5);// invokeMethod1
    invoker->changeColor("Red");// invokeMethod2
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->changePosition(6);// invokeMethod1
    invoker->changeColor("Blue");// invokeMethod2
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->changePosition(7);// invokeMethod1
    invoker->changeColor("Green");// invokeMethod2
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->changePosition(8);// invokeMethod1
    invoker->changeColor("Yellow");// invokeMethod2
    invoker->undo();
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->undo();
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->undo();
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->undo();
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->undo();
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->undo();
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->undo();
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
    invoker->redo();
    invoker->redo();
    invoker->redo();
    invoker->redo();
    invoker->redo();
    invoker->redo();
    invoker->redo();
    invoker->redo();
    std::cout << receiver->getPlayerPosition() << ", "<< receiver->getBackGroundColor() << std::endl;
}
