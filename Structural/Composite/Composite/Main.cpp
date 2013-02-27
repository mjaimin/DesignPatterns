// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Component.h"
#include "Composite.h"
#include "Leaf.h"

int _tmain(int argc, _TCHAR* argv[])
{
    Component* root = new Composite();
    Component* leaf1 = new Leaf();
    Component* leaf2 = new Leaf();
    Component* composite = new Composite();

    root->Add(leaf1);
    root->Add(leaf2);
    root->Add(composite);

    root->Operation();

    root->Remove(leaf2);

    //clean up
    delete root;

	return 0;
}

