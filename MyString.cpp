#include <cstring>
#include "MyString.h"

using namespace std;

// strlen, strcat, strcmp, strcpy

#pragma region
// CONSTRUCTORS
      // default constructor
            // initializes _capacity to 16 chars
            // initializes this MyString to an empty MyString
      MyString::MyString()
	  {
		  // cstyle str == /0 termed 
		  // capacity
		  this->_capacity = 16;

		  // length
		  this->_length = 0;

		  // the pointer: where it points
		  // 2 pieces of responsibility - where it pts, and what it pts to
		  // EVERY time new happens, you must say delete
		  this->_string = new char[this->_capacity + 1]; 

		  // the pointer: what it points to
		  //*_string = '\0';
		  _string[0] = '\0';

		  /*cout << "\n\t *** DEFAULT CONSTRUCTOR ***" << endl;
		  cout << "\t *** _capacity: " << _capacity;
		  cout << ", _length is: " << _length;
		  cout << ", _string &address is: " << &_string << "\n" << endl;*/
	  }
// 
//      // parameterized constructors
//            // takes a c style string argument
//            // initializes capacity to greater of strlen(cString) or 16 chars
//            // initializes this MyString to cString
      MyString::MyString(const char * aCString)
	  {
		  // _length
		  this->_length = (int)strlen(aCString);

		  // _capacity
		  //DEBUG: doesn't take greater of 16 of strlen
		  this->_capacity = this->_length <= 16 ? 16 : this->_length;
		  /*if (strlen(aCString) > this->_capacity)
			  this-> _capacity = strlen(aCString);*/

		  // _string pointer: where it points
		  this->_string = new char[ this->_capacity + 1 ];

		  // _string pointer: what it points to
		  // As well as experimenting with 'strcpy_s'
		  strcpy_s(_string, (_length+1), aCString);

		  /*cout << "\n\t *** CTOR: MyString(const char * aCString) ***" << endl;
		  cout << "\t *** _capacity is: " << _capacity;
		  cout << " _length is: " << _length;
		  cout << " _string &address is: " << &_string << "\n" << endl;*/
	  }
 
	  // takes an int argument
	  // initializes capacity to numChars chars
	  // initializes this MyString to an empty MyString
      MyString::MyString(int numChars)
	  {
		  // _length
		  this->_length = 0;

		  // _capacity
		  this->_capacity = numChars;
		  
		  // _string pointer: where it points
		  this->_string = new char[ this->_capacity + 1 ];
		  
		  // _string pointer: what it points to
		  _string[0] = '\0';

		  /*cout << "\n\t *** CTOR: MyString(int numChars) ***" << endl;
		  cout << "\t *** _capacity is: " << _capacity;
		  cout << " _length is: " << _length;
		  cout << " _string &address is: " << &_string << "\n" << endl;*/
	  }
 
      // copy constructor
	  // initializes this MyString to a deep copy 
	  // of the original
      MyString::MyString(const MyString & original)
	  {
		  // _length
		  this->_length = original._length;

		  // _capacity
		  this->_capacity = original._capacity;
		  
		  // _string pointer: where it points
		  this->_string = new char[ this->_capacity + 1 ];
		  
		  // _string pointer: what it points to
		  strcpy_s(_string, this->_length, original._string);
		  
		  /*cout << "\n\t *** CTOR: MyString(const MyString & original) ***" << endl;
		  cout << "\t *** _capacity is: " << _capacity;
		  cout << " _length is: " << _length;
		  cout << " _string &address is: " << &_string << "\n" << endl;*/
	  }

	  MyString::~MyString()
	  {
		  delete[] this->_string;
	  }
#pragma endregion CONSTRUCTORS
	  
#pragma region
//// METHODS
#pragma region
      // Append
            // Takes a MyString argument
            // Appends chars to the end of this MyString
      void MyString::Append(const MyString & aMyString)
	  {
		  // HAVE to know if there is enough room in the original MyString 
		  // and the appended string
		  int totalLength = _length + aMyString._length;

		  if (this->_capacity < totalLength)
		  {
			  // If not, make a buffer area that does have room
			  // (I may not control the memory that follows the original MyString)
			  this->_capacity = (this->_length + aMyString._length);
			  this->_length = this->_capacity;
			  char *buffer = new char[ this->_capacity + 1 ];

			  // Copy the original MyString to the new buffer
			  strcpy_s(buffer, this->_length, this->_string);

			  // delete[] the original MyString
			  delete[] this->_string;

			  // Make the original string point to what's in the buffer
			  // which is the orig string PLUS enough room to append aMyString
			  this->_string = buffer;

			  // Append aMyString to the new MyString using strcat
			  strcat_s(this->_string, this->_length, aMyString._string);
		  }
		  else
		  {
			  // If there is enought room, just append aMyString 
			  // to the original MyString using strcat
			  strcat_s(this->_string, totalLength, aMyString._string);
		  }
	  }

//            // Takes  a c style string argument
//            // Appends chars to the end of this MyString
      void MyString::Append(const char * aCString)
	  {
		  // HAVE to know if there is enough room in the original MyString 
		  // and the appended string
		  int totalLength = _length + strlen(aCString);

		  if (this->_capacity < totalLength)
		  {
			  // If not, make a buffer area that does have room
			  // (I may not control the memory that follows the original MyString)
			  this->_capacity = (this->_length + strlen(aCString));
			  this->_length = this->_capacity;
			  char *buffer = new char[ this->_capacity + 1 ];

			  // Copy the original MyString to the new buffer
			  strcpy_s(buffer, this->_length, this->_string);

			  // delete[] the original MyString
			  delete[] this->_string;

			  // Make the original string point to what's in the buffer
			  // which is the orig string PLUS enough room to append aMyString
			  this->_string = buffer;

			  // Append aMyString to the new MyString using strcat
			  strcat_s(this->_string, this->_length, aCString);
		  }
		  else
		  {
			  // If there is enough room already, just append aCString 
			  // to the original MyString using strcat
			  strcat_s(this->_string, totalLength, aCString);
		  }

	  }
#pragma endregion APPEND
 
#pragma region
//      // Assign
//            // Takes a MyString argument
//            // makes this MyString a copy of aMyString
      void MyString::Assign(const MyString & aMyString)
	  {
		  // DEBUG: Do I have to get rid of any data stored by the orig MyString?
		  // HAVE to know if there is enough room in the original 
		  if (this->_capacity < aMyString.Length())
		  {
			  // If it is, make a buffer area that does have room
			  // (I may not control the memory that follows the original MyString)
			  this->_capacity = aMyString.Length();
			  this->_length = this->_capacity;
			  char *buffer = new char[ this->_capacity + 1 ];

			  // Copy aMyString to the new buffer
			  strcpy_s(buffer, this->_length, aMyString._string);

			  // delete[] the original MyString
			  delete[] this->_string;

			  // Make the original string point to what's in the buffer
			  // which is aCString
			  this->_string = buffer;
		  }
		  else
		  {
			  this->_length = aMyString.Length();
			  this->_capacity = this->_length;
			  strcpy_s(this->_string, this->_length, aMyString._string);
		  }
	  }

	  // Takes a c style string argument
	  // makes this MyString contain the chars of aCString
      void MyString::Assign(const char * const aCString)
	  {
		  // HAVE to know if there is enough room in the original 
		  if (this->_capacity < strlen(aCString))
		  {
			  // If not, make a buffer area that does have room
			  // (I may not control the memory that follows the original MyString)
			  this->_capacity = strlen(aCString);
			  this->_length = this->_capacity;
			  char *buffer = new char[ this->_capacity + 1 ];

			  // Copy aCString to the new buffer
			  strcpy_s(buffer, this->_length, aCString);

			  // delete[] the original MyString
			  delete[] this->_string;

			  // Make the original string point to what's in the buffer
			  // which is aCString
			  this->_string = buffer;
		  }
		  else
		  {
			  this->_length = strlen(aCString);
			  this->_capacity = this->_length;
			  strcpy_s(this->_string, this->_length, aCString);
		  }
	  }
#pragma endregion ASSIGN

#pragma region
      // At
            // Takes an int argument
            // Returns a copy of the char at that index
            // throws an exception if index is < 0 or >= _length
      char MyString::At(int index) const
	  {
		  char atChar = this->_string[index];
		  return atChar;
	  }
 
#pragma endregion AT

#pragma region
//      // Clear
//            // Makes this MyString empty
//            // does not change capacity;
      void MyString::Clear()
	  {
		  this->_length = 0;
		  this->_string[0] = '\0';
	  }
//            // Makes this MyString empty
//            // changes capacity to newCapacity
//            // throws an exception if newCapacity < 0
      void MyString::Clear(int newCapacity)
	  {
		  this->Clear();
		  this->_capacity = newCapacity;
	  }
 
#pragma endregion CLEAR

#pragma region
      // Compare
	  // Takes a MyString argument
	  // Returns (zero) if the argument contains
	  //   the same string of chars as this MyString
	  //   alphabetically less than this MyString
	  // Returns (a negative int) if the argument is
	  //   alphabetically greater than this MyString
      int MyString::Compare(const MyString & aMyString)
	  {
		  return strcmp(this->_string, aMyString._string);
	  }
 
#pragma endregion COMPARE

#pragma region
//      // CurrentCapacity
//            // Returns number of characters that this instance can hold
//            // without reallocating
	  // const promises not to change the state of an obj - the value of it's variables
      int MyString::CurrentCapacity() const
	  {
		  return this->_capacity;
	  }
#pragma endregion CURRENT CAPACITY

#pragma region
	  // Equals
	  // Takes a MyString argument
	  // Returns (true) if the argument contains
	  //   the same string of chars as this MyString,
	  //   otherwise it returns (false).
      bool MyString::Equals(const MyString & aMyString) const
	  {
		  MyString noostring = this->_string;
		  if (noostring.Compare(aMyString) == 0)
		  {
			  return true;
		  }
		  else
		  {
			  return false;
		  }
	  }
	  // Takes a c style string argument
	  // Returns (true) if the argument contains
	  //   the same string of chars as this MyString,
	  //   otherwise it returns (false).
      bool MyString::Equals(const char * const aCString) const
	  {
		  MyString noostring = this->_string;
		  MyString otherString = aCString;
		  if (noostring.Compare(otherString) == 0)
		  {
			  return true;
		  }
		  else
		  {
			  return false;
		  }
	  }

#pragma endregion EQUALS

#pragma region
	  // Find
	  // Takes a myString argument
	  // Returns the index (int)
	  //   where the argument MyString was found
	  //   in this MyString. If it is not found, then returns -1.
      int MyString::Find(const MyString & aMyString) const
	  {
		  char *searchString = (strstr(this->_string, aMyString._string));
		  cout << "********** searchString: " << searchString << endl;
		  cout << "********** *searchString: " << *searchString << endl;
		  cout << "********** &searchString: " << &searchString << endl;
		  return *searchString;
	  }
#pragma endregion FIND

#pragma region
//      // Insert
//            // Takes two arguments
//            // An int – the index in this MyString
////   at which to insert the new chars
//            // A MyString containing the chars to be inserted
//      void Insert(const MyString & aMyString, int index);
// 
#pragma endregion INSERT

#pragma region
      // Length
	  // Returns the number (int) of chars in this MyString
	  int MyString::Length(void) const
	  {
		  return this->_length;
	  }
#pragma endregion LENGTH

#pragma region
//      // Replace
//            // Takes three arguments
//            // An int – the index of the char in thisMyString
////   to begin replacing at.
//            // An int – the number of chars to replace
//            // And a MyString containg the replacement string
//            // throws an exception if startIndex >= Length
//            // throws an exception if startIndex + numChars > Length()
//            // throws an exception if aMyString.Length() < numChars
//      void Replace(int startIndex, int numChars, const MyString & aMyString);
// 
#pragma endregion REPLACE

#pragma region
//      // Substr
//            // Takes two int arguments,
//            // An int for the starting index,
//            // An int for the number of chars to return.
//            // Returns a MyString with the requested sub-string
////   from the original MyString
//            // throws an exception if startIndex + numChars > Length()
//      MyString SubStr(int startIndex, int numChars) const;
// 
#pragma endregion SUBSTR
#pragma endregion METHODS
	  
#pragma region
// OPERATORS
 
      // = (assignment - takes a MyString or a c style string)
      MyString MyString::operator= (const MyString & aMyString)
	  {
		  this->Assign(aMyString);
		  return this->_string;
	  }
      MyString MyString::operator= (const char *  const aCString)
	  {
		  this->Assign(aCString);
		  return this->_string;
	  }
 
      // +, += (concatenation - takes a MyString or a c style string)
     /* MyString operator+ (const MyString & aMyString);
      MyString operator+= (const MyString & aMyString);*/
 
      // [] (read/write char access by index)
	  // Returns a reference to the char at that index
	  // throws an exception if index is < 0 or >= _length
      char &MyString::operator[] (int index) const
	  {
		  if (index < 0 || index > this->_length)
		  {
			  cout << " ERRRRRRROR!" << endl;
			  throw out_of_range("&MyString::operator[] (int index) const");
			  //DEBUG: This needs to be changed!
			  //return this->_string[0];
		  }
		  return this->_string[index];
	  }
// 
//      // >, <, >=, <=, ==, != (boolean relational test operators)
//      bool operator> (const MyString & aMyString) ;
//      bool operator< (const MyString & aMyString) ;
//      bool operator>= (const MyString & aMyString) ;
//      bool operator<= (const MyString & aMyString) ;
//      bool operator== (const MyString & aMyString) ;
//      bool operator!= (const MyString & aMyString) ;
// 
//     // returns a pointer to the underlying c-style string
      const char* MyString::_cstr() const
	  {
		  return this->_string;
	  }
// 
//      // <<, >> stream insertion and extraction
	  ostream &operator<< (ostream &output, const MyString &aMyString)
	  {
		output << aMyString._string;
		return output;
	  }
 
//      friend istream & operator>> (istream & is, MyString & aMyString);
#pragma endregion OPERATORS