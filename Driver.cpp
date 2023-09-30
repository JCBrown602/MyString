#include <iostream>
#include <Windows.h>
#include "MyString.h"

using namespace std;

#pragma region
// Utility & Beautification
void spacer(MyString testDivider, int mode);
void resetMyStrings(MyString *pArray);
void resetMyStrings(MyString mArray);
#pragma endregion UTILITY & BEAUTIFICATION

int main()
{
#pragma region
	MyString title("DIVIDER TITLE");
	spacer("CONSTRUCTOR TESTS",3);
	MyString m1;												// Default CTOR
	MyString m2("onefish");									// (const char * aCString)
	MyString m3("one fish, two fish, fifty-three fishes!");	// arg length > initial capacity
	MyString m4(27);										// (int numChars)
	MyString m5(m3);										// (const MyString & original)
	
#pragma region
	//// For utility and ease of use
	//// (Because programmers are "smart lazy", or at least lazy)
	//MyString *pm1 = &m1, *pm2 = &m2, *pm3 = &m3, *pm4 = &m4, *pm5 = &m5;
	//MyString *mArray[5] = {pm1, pm2, pm3, pm4, pm5};
	//reseetMyStrings(*mArray);
	//cout << " m1 and m2 are now: " << m1 << ", " << m2 << endl;
#pragma endregion STRING ARRAY UTILITY

	// DEBUG: Keep this, if only for the third line - (int)(*m._cstr())
	spacer("DEFAULT CTOR",1);
	cout << " m1._capacity is " << m1.CurrentCapacity() << endl;
	cout << " m1._length is " << m1.Length() << endl;
	cout << " m1_string points to an ascii (0): " << (int)(*m1._cstr()) << "\n\n" << endl;

	cout << " ++++++++++++++++++  (const char * aCString):" << endl;
	cout << " m2 should be (onefish): " << m2 << "\n\n" << endl;

	cout << " ++++++++++++++++++  arg length > initial capacity:" << endl;
	cout << " m3 should be (one fish, two fish, fifty-three fishes!):\n " << m3 << "\n\n" << endl;

	cout << " ++++++++++++++++++  (int numChars):" << endl;
	cout << " m4._capacity should be (27): " << m4.CurrentCapacity() << endl;
	cout << " m4._string points to an ascii (0): " << (int)(*m4._cstr()) << "\n\n" << endl;

	cout << " ++++++++++++++++++  (const MyString & original):" << endl;
	cout << " m5(m3): " << m5 << "\n" << endl;
#pragma endregion CONSTRUCTOR TESTS

#pragma region
	spacer("METHOD TESTS",3);

	m1 = "John";
	m2 = "Paul";
	m3 = "George";
	m4 = "Ringo";
	m5 = "Starr";
	
#pragma region
	spacer("APPEND",0);
	spacer("Append(const MyString & aMyString):",1);
	cout << " Append short MyString to a short MyString.\n When total capacity < initial capacity:" << endl;
	m1.Append(m2);
	cout << "Should say (JohnPaul): " << m1 << endl;
	
	//DEBUG:
	cout << "\n m5 cap: " << m5.CurrentCapacity() << ", m5 length: " << m5.Length() << ",\n m5 value: " << m5 << endl;
	m5 = "They all lived in a yellow submarine, a yellow submarine, a yellow submarine...";
	cout << "\n m5 cap: " << m5.CurrentCapacity() << ", m5 length: " << m5.Length() << ",\n m5 value: " << m5 << endl;
	
	spacer("Append(const MyString & aCString)",1);
	m5 = "Starr"; // Because 'yellow submarine' was annoying...
	cout << " Append short C-style string to a short MyString:\n";
	m4.Append(" ");
	m4.Append(m5);
	cout << " m4 is now (Ringo Starr):\t" << m4 << endl;
	m2.Append(" McCartney");
	cout << " m2 is now (Paul McCartney):\t" << m2 << endl;
#pragma endregion APPEND

#pragma region
	spacer("ASSIGN",0);
	m1 = "John";
	m2 = "Paul";
	m3 = "George";
	m4 = "Ringo";
	m5 = "Starr";

	spacer("Assign(const MyString & aMyString)",1);
	m1.Assign(m3);
	cout << " Assigning \"George\" to m1: " << m1 << endl;

	spacer("Assign(const char * const aCString)",1);
	m1.Assign("Harrison");
	cout << " Assigning \"Harrison\" to m1: " << m1 << endl;
	
#pragma endregion ASSIGN
	
#pragma region
	spacer("AT",0);
	
	m1 = "John";
	m2 = "Tom Sawyer";
	m3 = "George";
	m4 = "Harrison";
	m5 = "Starr";

	cout << " m5: " << m5 << endl;
	cout << " m4: " << m4 << endl;
	cout << " m2: " << m2 << "\n" << endl;

	cout << " m5.At(0) - (S): " << m5.At(0) << endl;
	cout << " m4.At(0) - (H): " << m4.At(0) << endl;
	cout << " m4.At(4) - (i): " << m4.At(4) << endl;
	cout << " m2.At(0) - (T): " << m2.At(0) << endl;
	cout << " m2.At(0) - (T): " << m2.At(0) << endl;
	cout << " m2.At(7) - (y): " << m2.At(7) << endl;
#pragma endregion AT
	
#pragma region
	spacer("CLEAR",0);
	m1 = "John";
	cout << " m1: " << m1 << endl;
	spacer("Clear()",1);
	m1.Clear();
	cout << "\n m1.Clear(): " << m1 << endl;
	cout << " m1._string points to an ascii (0): " << (int)(*m1._cstr()) << "\n" << endl;

	spacer("Clear(int newCapacity)",1);
	m1.Clear(9);
	cout << " m1.Clear(9): " << m1 << endl;
	cout << " m1._string points to an ascii (0): " << (int)(*m1._cstr()) << endl;
	cout << " m1._capacity is (9): " << m1.CurrentCapacity() << "\n" << endl;
#pragma endregion CLEAR
	
#pragma region
	spacer("COMPARE",0);
	m1 = "John";
	m2 = "Paul";
	m3 = "George";
	m4 = "Ringo";
	m5 = "Ringo";
	
	cout << " m1: " << m1 << endl;
	cout << " m2: " << m2 << endl;
	cout << " m3: " << m3 << endl;
	cout << " m4: " << m4 << endl;
	cout << " m5: " << m5 << "\n" << endl;

	int compared = m4.Compare(m5);
	cout << " m4.Compare(m5) - (0): " << compared << ", these are the same." << endl;

	int compared2 = m1.Compare(m5);
	if (compared2 < 0)
		cout << " m1.Compare(m5) - (-1): " << compared2 << ", alphabetically less than m5."  << endl;

	int compared3 = m5.Compare(m1);
	cout << " m5.Compare(m1) - (1): " << compared3 << ", alphabetically greater than m1." << endl;

#pragma endregion COMPARE
	
#pragma region
	spacer("EQUALS",0);

	m1 = "John";
	m2 = "Paul";
	m3 = "Ringo";
	m4 = "Starr";
	m5 = "Starr";
	
	cout << " m1: " << m1 << endl;
	cout << " m2: " << m2 << endl;
	cout << " m3: " << m3 << endl;
	cout << " m4: " << m4 << endl;
	cout << " m5: " << m5 << "\n" << endl;

	if (m4.Equals(m5))
	{
		cout << " m4 == m5: true" << endl;
	}

	if (!m4.Equals(m3))
	{
		cout << " m4 == m3: false\n" << endl;
	}

	if (m4.Equals("Starr"))
	{
		cout << " m4 == Starr: true" << endl;
	}

	if (!m4.Equals("Ringo"))
	{
		cout << " m4 == Ringo: false\n" << endl;
	}
#pragma endregion EQUALS
	
#pragma region
	spacer("FIND",0);

	m1 = "John";
	m2 = "Paul";
	m3 = "Ringo";
	m4 = "Starr";
	m5 = "Starr";
	
	cout << " m1: " << m1 << endl;
	cout << " m2: " << m2 << endl;
	cout << " m3: " << m3 << endl;
	cout << " m4: " << m4 << endl;
	cout << " m5: " << m5 << "\n" << endl;

	MyString tar("tar");
	int found = m4.Find(tar);
	cout << " Found string is at index: " << found << endl;
	cout << " \"tar\" search string is really at index m4[1]: " << m4[1] << endl;

#pragma endregion FIND
	
#pragma region
	spacer("INSERT",0);
#pragma endregion INSERT
	
#pragma region
	spacer("LENGTH",0);
#pragma endregion LENGTH
	
#pragma region
	spacer("REPLACE",0);
#pragma endregion REPLACE
	
#pragma region
	spacer("SUBSTRING",0);
#pragma endregion SUBSTR

#pragma endregion METHOD TESTS

#pragma region
	spacer("OPERATOR TESTS",3);
#pragma endregion OPERATOR TESTS
	
	//system("pause");
	return 0;
}

#pragma region
	  void spacer(MyString testTitleDivider, int mode)
	  {
		  int sideSpacer = 7;
		  int lineLength = 56;
		  // Account for a space on each side of the title
		  int titleLength = testTitleDivider.Length() + 2;
		  int adjustedLength = (lineLength - titleLength - sideSpacer);

		  char fillerCharTitle = ' ';
		  char fillerCharSpacer = '=';
		  char space = ' ';

		  cout << "\n";
		  if (mode == 0 || mode == 3)
		  {
			  cout << "\n";
			  // Print fillerCharSpacer, lineLength times, new line
			  for (int count = 0; count < lineLength; count++)
			  {
				  cout << fillerCharSpacer;
			  }
			  cout << "\n";
		  }

		  // Print fillerCharTitle, sideSpacer times
		  for (int count = 0; count < sideSpacer; count++)
		  {
			  if (mode == 0)
			  {
				  sideSpacer = 2;
			  }
			  else if (mode == 3)
			  {
				  sideSpacer = lineLength/3;
			  }
			  cout << fillerCharTitle;
		  }

		  // Print title
		  cout << " " << testTitleDivider << " ";

		  // Print fillerCharTitle, adjustedLength times, new line
		  if (lineLength <= 0)
			  lineLength = 10;
		  for (int count = 0; count < adjustedLength; count++)
		  {
			  cout << fillerCharTitle;
		  }
		  //DEBUG:
		  //cout << lineLength;
		  cout << "\n";

		  // Print fillerCharSpacer, lineLength times, new line
		  for (int count = 0; count < lineLength; count++)
		  {
			  cout << fillerCharSpacer;
		  }
		  cout << "\n";
	  }
	  void resetMyStrings(MyString *pArray)
	  {
		  pArray[1] = "John";
		  pArray[2] = "Paul";
		  pArray[3] = "George";
		  pArray[4] = "Ringo";
		  pArray[5] = "Starr";
	  }
#pragma endregion UTILITIES