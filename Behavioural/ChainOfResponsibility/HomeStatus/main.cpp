#include <cstdio>
using namespace std;
class HomeStatus {
    public:
        bool alarmOn = false;
        bool locked = true;
        bool lightsOff = true;
};

class HomeChecker {

    protected:
        HomeChecker *successor;

    public:
        virtual void check(HomeStatus *home) = 0;

        void succeedWith(HomeChecker *successor)
        {
            this->successor = successor;
        }

        void next(HomeStatus *home)
        {
            if (this->successor)
            {
                this->successor->check(home);
            }
        }

};

class Locks : public HomeChecker {
    public:
        void check(HomeStatus *home)
        {
            if (!home->locked)
            {
                printf("The doors are not locked!! Abort abort.\n");
            }
            this->next(home);
        }
};

class Lights : public HomeChecker {
    public:
        void check(HomeStatus *home)
        {
            if (!home->lightsOff)
            {
                printf("The lights are still on!! Abort abort.\n");
            }
            this->next(home);
        }

};

class Alarm : public HomeChecker {
    public:
        void check(HomeStatus *home)
        {
            if (!home->alarmOn)
            {
                printf("The alarm has not been set!! Abort abort.\n");
            }
            this->next(home);
        }
};

int main()
{
    // create new instances
    Locks *locks = new Locks();
    Lights *lights = new Lights();
    Alarm *alarm = new Alarm();

    // set the successor chain
    locks->succeedWith(lights);
    lights->succeedWith(alarm);

    // create HomeStatus instance
    HomeStatus *home = new HomeStatus();

    printf("Begin check.\n");

    // start the chain
    locks->check(home);

    printf("End check.\n");

    return 0;
}
