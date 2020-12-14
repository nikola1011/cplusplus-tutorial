#include <iostream>

// Detailed read -> https://www.learncpp.com/cpp-tutorial/115-inheritance-and-access-specifiers/

class Base
{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};

// class <derived_class_name> : [optional_access_specifier] <name_of_the_base_class>

class Derived : /*private access specifier by deafult*/ Base  {};
class PublicDerived : public Base // note: public inheritance
{
    // Public inheritance means:
    // Public inherited members stay public (so m_public is treated as public)
    // Protected inherited members stay protected (so m_protected is treated as protected)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    PublicDerived()
    {
        m_public = 1; // okay: m_public was inherited as public
        m_protected = 2; // okay: m_protected was inherited as protected
        // m_private = 3; // not okay: m_private is inaccessible from derived class
    }
};

class PrivateDerived : private Base // note: private inheritance
{
    // Private inheritance means:
    // Public inherited members become private (so m_public is treated as private)
    // Protected inherited members become private (so m_protected is treated as private)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    PrivateDerived()
    {
        m_public = 1; // okay: m_public is now private in PrivateDerived
        m_protected = 2; // okay: m_protected is now private in PrivateDerived
        // m_private = 3; // not okay: derived classes can't access private members in the base class
    }
};

class ProtectedDerived : protected Base // note: private inheritance
{
    // Protected inheritance means:
    // Public inherited members become protected (so m_public is treated as protected)
    // Protected inherited members become protected (so m_protected is treated as protected)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    ProtectedDerived()
    {
        m_public = 1; // okay: m_public is now protected
        m_protected = 2; // okay: m_protected is now protected
        // m_private = 3; // not okay: derived classes can't access private members in the base class
    }
};



int main()
{
    // Outside access uses the access specifiers of the class being accessed.
    Base base;
    base.m_public = 1; // okay: m_public is public in Base
    // base.m_protected = 2; // not okay: m_protected is protected in Base
    // base.m_private = 3; // not okay: m_private is private in Base

    PublicDerived pub;
    pub.m_public = 1; // okay: m_public is public in PublicDerived
    // pub.m_protected = 2; // not okay: m_protected is protected in PublicDerived
    // pub.m_private = 3; // not okay: m_private is inaccessible in PublicDerived
    
    PrivateDerived pri;
    // pri.m_public = 1; // not okay: m_public is now private in PrivateDerived
    // pri.m_protected = 2; // not okay: m_protected is now private in PrivateDerived
    // pri.m_private = 3; // not okay: m_private is inaccessible in PrivateDerived


    ProtectedDerived pro;
    // pro.m_public = 1; // not okay: m_public is now protected in ProtectedDerived
    // pro.m_protected = 2; // not okay: m_protected is now protected ProtectedDerived
    // pro.m_private = 3; // not okay: m_private is inaccessible ProtectedDerived


    /// 
    /// Access specifiers:
    /// 
    //  In base class 	    When inherited publicly 	When inherited privately 	When inherited protectedly
    //  Public 		        Public 				        Private 			        Protected
    //  Protected 	        Protected 			        Private 			        Protected
    //  Private	            Inaccessible 			    Inaccessible 			    Inaccessible

}
