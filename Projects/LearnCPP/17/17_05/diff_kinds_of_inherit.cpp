// https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers

class Base {
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};

// all valid
class Pub: public Base {};
class Pro: protected Base {};
class Pri: private Base {};
class Def: Base {}; // defaults to private inheritance