x = 10;

defn test_lokalnej()
{
   val x = 20;
   print(x);
   test_lokalnej = x;
}

print(x);
print(test_lokalnej());