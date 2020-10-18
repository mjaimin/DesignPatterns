#include <cctype>
#include <iostream>
#include <list>
#include <memory>
#include <algorithm>
using namespace std;
const char* email [] = {
    "You guys really razz my berries, your gumball machines are totally hip",
    "Cruisin for a bruisin? My kids lost their money trying to win gumballs!",
    "You guys make me frosted, you've got four year olds gambling now!",
    "Mighty Gumball machines are radioactive, keep up the good work!",
    "Mighty Gumball machines are a blast, I can't wait to see whats cooking next",
    "You guys got it made in the shade, these gumball machines are a kick",
    "Mighty Gumball machines are no where daddy-o",
    "Don't have a cow, but your gumball machines really rattle my cage",
    "What's your tale nightingale? slot machine arms on soda machines?!",
    "Wanna make some real bread?! build gumball machines in your home",
    "Grody? got cooties? call Freeman & Freeman, and you'll be in fat city",
    "What's buzzin cuzzin? Make some reals scratch delivering pizzas",
    "You guys are boss! I flip when I see those gumballs drop",
    "Mighty Gumball Inc. is in orbit, we love you guys!",
    "Your gumball machines really make the scene",
    "Cast an eyeball on this beauty",
    "We want gumball machines in all our stores!, sincerly Starbuzz"
};

class Handler {

    private: mutable std::list< std::string > _requests;
    private: const Handler* _successor;

    private: Handler( const Handler& ); // Disable copy constructor
    private: void operator=( const Handler& ); // Disable assignment operator

    protected: explicit Handler( const Handler* successor = 0 ) :
               _successor( successor ) {
               }
    public: virtual ~Handler() {
            }
    public: virtual void handleRequest( std::string request ) const {
                if( _successor ) {
                    _successor->handleRequest( request );
                }
            }
    protected: virtual bool canHandleRequest( const std::string& request ) const {
                   _requests.push_back( request );
                   return true;
               }
    public: virtual void print() const {
                std::cout << " count=" << _requests.size() << std::endl;
                std::list< std::string >::const_iterator iterator = _requests.begin();
                while( iterator != _requests.end() ) {
                    std::cout << " - " << ( *iterator ).c_str() << std::endl;
                    iterator++;
                }
                if( _successor ) {
                    _successor->print();
                }
            }
};

class ComplaintHandler : public Handler {

    public:
        explicit ComplaintHandler( const Handler* successor = 0 ) : Handler( successor ) { }
    public:
        void handleRequest( std::string request ) const
        {
            std::transform( request.begin(), request.end(), request.begin(), ::tolower );

            if( canHandleRequest( request ) == true ) {
                Handler::canHandleRequest( request );
            } else {
                Handler::handleRequest( request );
            }
        }
    public:
        bool canHandleRequest( const std::string& request ) const
        {
            bool value = false;

            if( std::string::npos != request.find( "bruisin" ) ) {
                value = true;
            } else if( std::string::npos != request.find( "frosted" ) ) {
                value = true;
            } else if( std::string::npos != request.find( "no where" ) ) {
                value = true;
            } else if( std::string::npos != request.find( "rattle my cage" ) ) {
                value = true;
            } else if( std::string::npos != request.find( "tale nightingale" ) ) {
                value = true;
            }
            return value;
        }
    public:
        void print() const {
            std::cout << std::endl << "Hate mail, send to Legal:";
            Handler::print();
        }
};

class FanHandler : public Handler {

    public: explicit FanHandler( const Handler* successor = 0 ) :
            Handler( successor ) {
            }
    public: void handleRequest( std::string request ) const {
                std::transform( request.begin(), request.end(), request.begin(), ::tolower );

                if( canHandleRequest( request ) == true ) {
                    Handler::canHandleRequest( request );
                } else {
                    Handler::handleRequest( request );
                }
            }
    public: bool canHandleRequest( const std::string& request ) const {
                bool value = false;

                if( std::string::npos != request.find( "razz" ) ) {
                    value = true;
                } else if( std::string::npos != request.find( "hip" ) ) {
                    value = true;
                } else if( std::string::npos != request.find( "radioactive" ) ) {
                    value = true;
                } else if( std::string::npos != request.find( "blast" ) ) {
                    value = true;
                } else if( std::string::npos != request.find( "boss" ) ) {
                    value = true;
                } else if( std::string::npos != request.find( "orbit" ) ) {
                    value = true;
                } else if( std::string::npos != request.find( "kick" ) ) {
                    value = true;
                }
                return value;
            }
    public: void print() const {
                std:: cout << std::endl << "Fan mail, send to CEO:";
                Handler::print();
            }
};

class NewLocationHandler : public Handler {

    public: explicit NewLocationHandler( const Handler* successor = 0 ) :
            Handler( successor ) {
            }
    public: void handleRequest( std::string request ) const {
                std::transform( request.begin(), request.end(), request.begin(), ::tolower );

                if( canHandleRequest( request ) == true ) {
                    Handler::canHandleRequest( request );
                } else {
                    Handler::handleRequest( request );
                }
            }
    public: bool canHandleRequest( const std::string& request ) const {
                bool value = false;
                if( std::string::npos != request.find( "store" ) ) {
                    value = true;
                }
                return value;
            }
    public: void print() const {
                std::cout << std::endl << "Request mail, send to Business Development:";
                Handler::print();
            }
};

class SpamHandler : public Handler {
    public: explicit SpamHandler( const Handler* successor = 0 ) :
            Handler( successor ) {
            }
    public: void handleRequest( std::string request ) const {
                std::transform( request.begin(), request.end(), request.begin(), ::tolower );

                if( canHandleRequest( request ) == true ) {
                    Handler::canHandleRequest( request );
                } else {
                    Handler::handleRequest( request );
                }
            }
    public: bool canHandleRequest( const std::string& request ) const {
                bool value = false;

                if( std::string::npos != request.find( "bread" ) ) {
                    value = true;
                } else if( std::string::npos != request.find( "buzzin" ) ) {
                    value = true;
                } else if( std::string::npos != request.find( "cuzzin" ) ) {
                    value = true;
                } else if( std::string::npos != request.find( "eyeball" ) ) {
                    value = true;
                }
                return value;
            }
    public: void print() const {
                std::cout << std::endl << "Spam mail, send to shredder:";
                Handler::print();
            }
};

class LastHandler : public Handler {

    public: explicit LastHandler( const Handler* successor = 0 ) :
            Handler( successor ) {
            }
    public: void handleRequest( std::string request ) const {
                Handler::canHandleRequest( request );
            }
    public: void print() const {
                std:: cout << std::endl << "Unclassified, send to AI team:";
                Handler::print();
            }
};

class Client {

    private: std::unique_ptr< Handler > _lastHandler;
    private: std::unique_ptr< Handler > _newHandler;
    private: std::unique_ptr< Handler > _hateHandler;
    private: std::unique_ptr< Handler > _fanHandler;
    private: std::unique_ptr< Handler > _spamHandler;

    private: Client( const Client& ); // Disable copy constructor
    private: void operator=( const Client& ); // Disable assignment operator

    public: Client() :
            _lastHandler( new LastHandler() ),
            _newHandler(  new NewLocationHandler( _lastHandler.get() ) ),
            _hateHandler( new ComplaintHandler( _newHandler.get() ) ),
            _fanHandler(  new FanHandler( _hateHandler.get() ) ),
            _spamHandler( new SpamHandler ( _fanHandler.get() ) ) {
            }
    public: void handleRequest( std::string request ) const {
                _spamHandler->handleRequest( request );
            }
    public: void print() const {
                _spamHandler->print();
            }
};

int main( int argc, char* argv[] ) {

    std::unique_ptr< Client > client( new Client() );

    for( int i = 0; i < sizeof( email ) / sizeof( char* ); i++ ) {
        client->handleRequest( email[i] );
    }

    client->print();

    return 0;
}
