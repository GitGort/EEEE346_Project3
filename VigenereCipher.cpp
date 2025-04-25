#include "VigenereCipher.h"

/*
 * definition of the constructor
 */
VigenereCipher::VigenereCipher(string k) : key(k), Cipher("Vigenere") {;}

/*
 * definition of encode()
 */
bool VigenereCipher::encode(string msg) {
  /*TODO: write your code*/
  string longkey;
  //first use for loop to extend key by storing loop in longkey (use modulus)
  //remember that a key character is not given for spaces!!!

  //for the length of the msg string
  //encoded.insert(i, 1, (encode formula output))
  //remember to check for invalid characters!!!
} 

/*
 * definition of decode()
 */
bool VigenereCipher::decode(string msg) {
  /*TODO: write your code*/
  //first use for loop to extend key by storing loop in longkey (use modulus)
  //remember that a key character is not given for spaces!!!

  //for the length of the msg string
  //encoded.insert(i, 1, (decode formula output))
  //remember to check for invalid characters!!!
}
