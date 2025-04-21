#ifndef TESTS_H
#define TESTS_H

#include <memory>
#include <fstream> 
#include "Cipher.h"

/**
 * test encoding a message
 * @param cipher - shared pointer pointing to a CaesarCipher, VigenereCipher, or RailFenceCipher object
 * @param msg - string of the message to encode
 * @return true if encoding is successful else false
 */
bool testEncode(shared_ptr<Cipher> cipher, string msg);

/**
 * test decoding a message
 * @param cipher - shared pointer pointing to a CaesarCipher, VigenereCipher, or RailFenceCipher object
 * @param msg - string of the message to decode
 * @return true if decoding is successful else false
 */
bool testDecode(shared_ptr<Cipher> cipher, string msg);

#endif
