#ifndef AFFINECIPHER_H
#define AFFINECIPHER_H

#include "Cipher.h"

class AffineCipher : public Cipher {
private:
  /**
   * a value for an Affine cipher
   */
  int slope;

  /**
   * b value for an Affine cipher 
   */ 
  int intercept;

public:
  /**
   * constructor: initializes slope and intercept to the parameters; initializes cipherame to "Affine"
   * @param a - used to set slope
   * @param b - used to set intercept
   */
  AffineCipher(int a, int b);

  /**
   * encode(): performs Affine encoding of a message
   * @param msg - string message to encode
   * @return true if encoding is successful; otherwise false
   */
  bool encode(string msg);

  /**
   * decode(): performs Affine decoding of a message
   * @param msg - string message to decode
   * @return true if decoding is successful; otherwise false
   */
  bool decode(string msg);
};

#endif
