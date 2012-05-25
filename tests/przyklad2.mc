defn silnia(macierz)
{
   if((macierz|0,0\ == 1) or
      (macierz|0,1\ == 1) or
      (macierz|1,0\ == 1) or
      (macierz|1,1\ == 1))
      silnia = macierz;
   else 
   {
   b = [1, 1; 1, 1];
   silnia = silnia(macierz-b)*macierz;
   }
}

print(silnia([2, 3; 4, 5])); /*[1,2;3,4] *[2, 3; 4, 5]
