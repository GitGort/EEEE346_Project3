rm -rf main
g++ -o main *.cpp *.h

rm -rf result.txt
cat inputs/testEncodeAffine.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/resultEncodeAffine.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Encode Affine - FAIL"
  else
    echo "Encode Affine - PASS"
  fi 
else
  echo "Encode Affine - FAIL (MISSING FILE)"
fi

rm -rf result.txt
cat inputs/testDecodeAffine.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/resultDecodeAffine.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Decode Affine - FAIL"
  else
    echo "Decode Affine - PASS"
  fi 
else
  echo "Decode Affine - FAIL (MISSING FILE)"
fi

rm -rf result.txt
cat inputs/testEncodeVigenere.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/resultEncodeVigenere.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Encode Vigenere - FAIL"
  else
    echo "Encode Vigenere - PASS"
  fi 
else
  echo "Encode Vigenere - FAIL (MISSING FILE)"
fi

rm -rf result.txt
cat inputs/testDecodeVigenere.txt | ./main
  
if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/resultDecodeVigenere.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Decode Vigenere - FAIL"
  else
    echo "Decode Vigenere - PASS"
  fi 
else
  echo "Decode Vigenere - FAIL (MISSING FILE)"
fi

rm -rf result.txt
cat inputs/testEncodeRailFence.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/resultEncodeRailFence.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Encode RailFence - FAIL"
  else
    echo "Encode RailFence - PASS"
  fi 
else
  echo "Encode RailFence - FAIL (MISSING FILE)"
fi

rm -rf result.txt
cat inputs/testDecodeRailFence.txt | ./main
  
if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/resultDecodeRailFence.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Decode RailFence - FAIL"
  else
    echo "Decode RailFence - PASS"
  fi 
else
  echo "Decode RailFencee - FAIL (MISSING FILE)"
fi

