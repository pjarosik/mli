z = 10;
print([1,2; 3, 4] == [1, 2; 3, 4]);
print(2+2*2);
print(z+10);
x = 10;
defn foo()
{
   val z = 10; 
   while (z < 100) 
   {
      if((z == 20) or (z == 40) or (z == 60) or (z == 80))
      {
         foo2(z);
      }
      z = z+10;
   }
}

defn foo2(z)
{
   if((z == 40) or (z == 80))
      print(z);
}

print(foo());
print(z);
