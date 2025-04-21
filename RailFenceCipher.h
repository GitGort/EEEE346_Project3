#ifndef RAILFENCECIPHER_H
#define RAILFENCECIPHER_H

#include "Cipher.h"

class RailFenceCipher : public Cipher {
private:
  /*  
   * the number of rails for a Rail Fence cipher
   */
  int rail;

public:
  /*  
   * constructor: initializes rail to the parameter and cipherName to "Rail Fence"
   * @param r - used to set rail
   */
  RailFenceCipher(int r); 

  /*  
   * encode(): performs Rail Fence encoding of a message
   * @param msg - string message to encode
   * @return true if encoding is successful; otherwise false
   */
  bool encode(string msg);

  /*  
   * decode(): performs Rail Fence decoding of a message
   * @param msg - string message to decode
   * @return true if decoding is successfull otherwise false
   */
  bool decode(string msg);
};

#endif
