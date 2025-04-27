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
  int keyIndex = 0;
  for (int i = 0; i < msg.size(); i++)
  {
    if (isValidCharacter(key.at(keyIndex)))
    {
      if (msg.at(i) == ' ') //if space in message
      {
        longkey.insert(i, 1, ' '); //insert space in longkey
      }
      else
      {
        longkey.insert(i, 1, key.at(keyIndex));
        keyIndex = (keyIndex + 1) % (key.size());
        //           ^increment index   ^reset index if end of key is reached
      }
    }
    else {return false;} //throw error if key character is invalid
  }

  //output longkey for testing purposes, comment out later
  /*
  test successful, removing test output
  for (int i = 0; i < msg.size(); i++) {encoded.insert(i, 1, longkey.at(i));}
  */

  //for the length of the msg string
  //encoded.insert(i, 1, (encode formula output))
  //remember to check for invalid characters!!!

  //encode successful!
  return true;
} 

/*
 * definition of decode()
 */
bool VigenereCipher::decode(string msg) {
  /*TODO: write your code*/
  string longkey;
  //first use for loop to extend key by storing loop in longkey (use modulus)
  //remember that a key character is not given for spaces!!!
  int keyIndex = 0;
  for (int i = 0; i < msg.size(); i++)
  {
    if (isValidCharacter(key.at(keyIndex)))
    {
      if (msg.at(i) == ' ') //if space in message
      {
        longkey.insert(i, 1, ' '); //insert space in longkey
      }
      else
      {
        longkey.insert(i, 1, key.at(keyIndex));
        keyIndex = (keyIndex + 1) % (key.size());
        //           ^increment index   ^reset index if end of key is reached
      }
    }
    else {return false;} //throw error if key character is invalid
  }
  
  //for the length of the msg string
  //encoded.insert(i, 1, (decode formula output))
  //remember to check for invalid characters!!!
}
