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
      if ((position == (rail - 1)) || (position == 0)) {direction = -direction;}
    }
    //else throw error
    else {return false;}
  }
  int transfered = 0; //loop structure iterable
  for (int i = 0; i < rail; i++)
  {
    for (int j = 0; j < msg.size(); j++)
    {
      //this time isValidCharacter is used to check whether 
      //stored character is useful data or asterisk
      if (isValidCharacter(characters[i][j]))
      {
        encoded.insert(transfered, 1, characters[i][j]);
        //increase iterable when useful data is found
        transfered++;
      }
    }
  } 
  //process complete!
  return true;
}

/*
 * definition of decode()
 */
bool RailFenceCipher::decode(string msg) {
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
    //place a special character to mask the array
    characters[position][i] = '%';
    //move to the next rail
    position += direction;
    //if at the last/first rail, change direction
    if ((position == (rail - 1)) || (position == 0)) {direction = -direction;}   
  }
  /*
  array should look something like this now:
    %***%***%
    *%*%*%*%*
    **%***%**
  now the characters from "msg" go into the masked slots
  */
 int msgIndex = 0;
 //read right to left then top to bottom
 for (int i = 0; i < rail; i++)
 {
   for (int j = 0; j < msg.size(); j++)
   {
    //if the position in the array is marked
     if (characters[i][j] == '%')
     {
      //and the next char in the msg string is valid
        if (isValidCharacter(msg.at(msgIndex)))
        {
          //place the char from msg into the array
          characters[i][j] = msg.at(msgIndex);
          msgIndex++;
        }
        else {return false;}
     }
   }
 }
 //now we can read the characters in the correct order by using the zig-zag code again
 //remember to reset control variables
 position = 0; direction = 1;
 for (int i = 0; i < msg.size(); i++)
  {    
    //place a special character to mask the array
    decoded.insert(i, 1, characters[position][i]);
    //move to the next rail
    position += direction;
    //if at the last/first rail, change direction
    if ((position == (rail - 1)) || (position == 0)) {direction = -direction;}   
  }
  //message recovery complete!
  return true;
}

