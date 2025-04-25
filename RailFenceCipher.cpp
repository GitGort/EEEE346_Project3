#include "RailFenceCipher.h"

/*
 * definition of the constructor
 */
RailFenceCipher::RailFenceCipher(int r) : rail(r), Cipher("RailFence") {;}

/*
 * definition of encode()
 */
bool RailFenceCipher::encode(string msg) {
  char characters[rail][msg.size()] = {0};
  //use double loop to initialize array
  for (int i = 0; i < rail; i++)
  {
    for (int j = 0; j < msg.size(); j++)
    {
      //set all characters to "*" to read out message later (will skip over when encoding)
      characters[i][j] = '*';
    }
  }
  int direction = 1, position = 0; //control variables to hop rails
  //for every character in the message
  for (int i = 0; i < msg.size(); i++)
  {
    //if it is a valid character then place in character array
    if(isValidCharacter(msg.at(i)))
    {
      //place character in curent rail
      characters[position][i] = msg.at(i);
      //move to the next rail
      position += direction;
      //if at the last/first rail, change direction
      if (position == (rail - 1) || position == 0) {direction *= -1;}
    }
    //else throw error
    //else {return false;}
  }
  int transfered = 0; //loop structure iterable
  do 
  {
    for (int i = 0; i < rail; i++)
    {
      for (int j = 0; j < msg.size(); j++)
      {
        //this time isValidCharacter is used to check whether 
        //stored character is useful data or asterisk
        if (isValidCharacter(msg.at(transfered) == true))
        {
          encoded.insert(transfered, 1, characters[i][j]);
          //increase iterable when useful data is found
          transfered++;
        }
        else {continue;}
      }
    }
    //break when all data has been found
  } while (transfered < msg.size());
  //process complete!
  return true;
}

/*
 * definition of decode()
 */
bool RailFenceCipher::decode(string msg) {
  /*TODO: write your code*/
}
