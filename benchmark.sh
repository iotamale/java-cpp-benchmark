#!/bin/bash
echo "Compiling..."
c++ -std=c++17 -O3 -o calcCpp calcCpp.cpp
javac CalcJava.java

echo "Compilation complete."
echo "----------------------------------"

for N in 500 1000; do 
    echo "Running tests for N=$N"

    echo -n "C++ (-O3): "
    ./calcCpp $N | grep ms

    echo -n "Java (default): "
    java CalcJava $N | grep ms

    echo -n "Java (-Xcomp): "
    java -Xcomp -Xdiag CalcJava $N | grep ms

    echo -n "Java (-Xint): "
    java -Xint -Xdiag CalcJava $N | grep ms

    echo "----------------------------------"
done

echo "Program complete."