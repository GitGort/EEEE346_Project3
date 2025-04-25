#ifndef CIPHER_H
#define CIPHER_H

#include <string>

using namespace std;

/*
 * abstract base class
 */
class Cipher {
protected:
  /*  
   * string to store a decoded message
   */
  string decoded;

  /*  
   * string to store an encoded message
   */
  string encoded;

  /*  
   * string to store the name of a cipher
   */
  string cipherName;

public:
  /*  
   * constructor: sets cipherName but may only be called by derived classes
   * @param name - used to set cipherName
   */
  Cipher(string c) : cipherName(c) {;}

  /*  
   * encode(): pure virtual function for encoding
   * @param msg - string-typed original message that requires encoding
   * @return true if encoding was successful
   */
  virtual bool encode(string msg) = 0;

  /*
   * decode(): pure virtual function for decoding
   * @param msg - string-typed encoded message that requires decoding
   * @return true if decoding was successful
   */
  virtual bool decode(string msg) = 0;

  /*
   * isValidCharacter(): checks if a character is valid for a cipher
   * FYI, the ASCII representations of A-Z are decimal numbers 65-90
   * @param c - character to check
   * @return - true if the character is A-Z or space; otherwise false
   */
  bool isValidCharacter(char c)
  {
    if (c > 64 && c < 91 || c == 32) {return true;}
    return false;
  }

  /*
   * getters
   */
  string getEncoded() { return encoded; }
  string getDecoded() { return decoded; }
  string getCipherName() { return cipherName; }
};

#endif
