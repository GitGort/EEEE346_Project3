#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include "Cipher.h"

class VigenereCipher : public Cipher {
private:
  /*  
   * original key used in a Vigenere cipher
   */
  string key;

public:
  /* 
   * constructor: initializes key to the parameter and cipherName to "Vigenere"
   * @param k - used to set key
   */
  VigenereCipher(string k); 
  
  /*  
   * encode(): performs Vigenere encoding of a message
   * @param msg - string message to encode
   * @return true if encoding is successful; otherwise false
   */
  bool encode(string msg);

  /*  
   * decode(): performs Vigenere decoding of a message
   * @param msg - string message to decode
   * @return true if decoding is successful; otherwise false
   */
  bool decode(string msg);
};
#endif
