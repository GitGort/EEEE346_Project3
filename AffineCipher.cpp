#include "AffineCipher.h"

/*
 * definition of the constructor
 */
AffineCipher::AffineCipher(int a, int b) : slope(a), intercept(b), Cipher("Affine")  {;}

/*
 * definition of encode()
 */
bool AffineCipher::encode(string msg) {
  //resize the encoded message to fit the msg string 
  //loop though all characters in msg
  for (int i = 0; i < msg.size(); i++)
  {
    //ensure char is operable
    if (isValidCharacter(msg.at(i)) == true)
    {
      if (msg.at(i) == 32)
      {
        //spaces carry over
        encoded.insert(i, 1, ' ');
      }
      else
      {
        //pull msg char, normalize, calculate new value, then offset to get ASCII val.
        encoded.insert(i, 1, (((msg.at(i) - 65) * slope + intercept) % 26 + 65));
      }
    }
    else
    {
      //exit if invalid char
      return false;
    }
  }
  //return true if iteration completes
  return true;
}

/*
 * definition of decode()
 */
bool AffineCipher::decode(string msg) {
  //determine the modular multiplicative inverse
  int inv = 0;
  for(int i = 1; i < 26; i++)
  {
    if (((slope * i) % 26) == 1) {inv = i; break;}
  }
  //return error if inverse was not found
  if (inv == 0) {return false;}
  //loop though all characters in msg
  for (int i = 0; i < msg.size(); i++)
  {
    //ensure char is operable
    if (isValidCharacter(msg.at(i)) == true)
    {
      if (msg.at(i) == 32)
      {
        //spaces carry over
        decoded.insert(i, 1, 32);
      }
      else
      {
        //pull msg char, normalize, calculate new value, then offset to get ASCII val.
        if (((msg.at(i) - 65) - intercept) < 0)
        {
          //special case to handle negative values
          decoded.insert(i, 1, ((inv * ((msg.at(i) - 65) - intercept + 26)) % 26 + 65));
        }
        else
        {
          //else perform normal decode
        decoded.insert(i, 1, ((inv * ((msg.at(i) - 65) - intercept)) % 26 + 65));
        }
      }
    }
    else
    {
      //exit if invalid char
      return false;
    }
  }
  //return true if iteration completes
  return true;
}

