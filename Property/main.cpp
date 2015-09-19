#include "property.h"

class MyClass
{
private:
	int _id;
	MyClass* _class;

	int getID() { return _id; }
	void setID(int newID) { _id = newID; }

	MyClass* getMyClass() { return _class; }
	void setMyClass(MyClass* value) { _class = value; }
public:
	Property<MyClass, int> Id;
	Property<MyClass, MyClass*> Parent;

	MyClass()
	{
		Id.syntetize(this, &MyClass::getID, &MyClass::setID);
		Parent.syntetize(this, &MyClass::getMyClass, &MyClass::setMyClass);
	}
};


int main()
{
	MyClass mc;

	mc.Id = 10;

	int iD = mc.Id;

	mc.Parent = &mc;

	return 0;
}
