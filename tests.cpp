#include "tests.h"

extern ofstream myFile;

bool testEncode(shared_ptr<Cipher> cipher, string msg) {
  bool status = true;
  myFile << "Encoding message using a(n) " << cipher->getCipherName() << " Cipher encoder!" << endl;

  // attempts to encode
  // this uses polymorphism. cipher is a shared pointer of the abstract base class Cipher
  // however, it calls the encode function of the derived concrete class in which it points
  if (cipher->encode(msg)) {
    myFile << "Encoded Message is:" << endl;
    myFile << cipher->getEncoded() << endl;
  } else {
    myFile << "Failed to encode message!" << endl;
    status = false;
  }
    
  return status;
}

bool testDecode(shared_ptr<Cipher> cipher, string msg) {
  bool status = true;
  myFile << "Decoding message using a(n) " << cipher->getCipherName() << " Cipher decoder!" << endl;

  // attempts to decode
  // this uses polymorphism. cipher is a shared pointer of the abstract base class Cipher
  // however, it calls the decode function of the derived concrete class in which it points
  if (cipher->decode(msg)) {
    myFile << "Decoded Message is:" << endl;
    myFile << cipher->getDecoded() << endl;
  } else {
    myFile << "Failed to decode message!" << endl;
    status = false;
  }

  return status;
}
