macierz = [1, 2;
           3, 4]*
                 [5, 6;
                  7, 8];
print(macierz);
defn foo()
{
   macierz = 15;
   print(macierz);
   val macierz = [0, 1;
                  1, 0, 5];
   print(macierz);
   foo = macierz;
}

foo();

print(macierz);           
