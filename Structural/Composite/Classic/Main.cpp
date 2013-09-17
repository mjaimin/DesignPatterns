#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Component {
public:
    virtual void operation() = 0;

    virtual void add( Component* child ) { }
    virtual void remove( Component* child ) { }
    virtual Component* getChild( int index ) { return NULL; }
};

class Leaf : public Component {
public:
    virtual void operation() {
        cout << "Operation by leaf" << endl;
    }
};

class Composite : public Component {
public:

    virtual void add( Component* child ) {
        m_components.push_back( child );
    }

    virtual void remove( Component* child ) {
        list<Component*>::iterator iter;
        iter = find( m_components.begin(), m_components.end(), child);

        if ( m_components.end() != iter ) {
            m_components.erase( iter );
        }
    }

    virtual Component* getChild( int index ) {
        list<Component*>::iterator iter1, iter2;
        int i;
        for ( i = 1, iter1 = m_components.begin(), iter2 = m_components.end();
            iter1 != iter2; ++iter1, ++i) 
        {
            if ( i == index )
                break;
        }

        return *iter1;
    }

    virtual void operation() {
        cout << "Operation by Composite" << endl;
        list<Component*>::iterator iter1, iter2;
        for( iter1 = m_components.begin(), iter2 = m_components.end();
            iter1 != iter2; ++iter1)
        {
            (*iter1)->operation();
        }
    }

private:
    list<Component*> m_components;
};

int main() {
    Leaf* leaf1 = new Leaf();
    Leaf* leaf2 = new Leaf();

    Composite* composite = new Composite();
    composite->add( leaf1 );
    composite->add( leaf2 );
    Composite* composite2 = new Composite();
    composite2->add( new Leaf() );
    composite2->add( new Leaf() );
    composite2->add( new Leaf() );
    composite2->add( new Leaf() );
    composite->add( composite2 );

    composite->operation();


}