# dynamic_array
A c++ implementation of dynamic-sized array. ./main would produce the excutation time tests for the DynamicArray structure and the std::vector. 

# a simple example
```
DynamicArray<int> da{};       // creates a integer DynamicArray, da, of initial capacity 5
da = DynamicArray<int>{10};   // sets da to a DynamicArray of initial capacity 10
for (int i = 1; i <= 20; i += 1)
    da.push_back(i);          // pushes integers from 1 to 20 into da
da[0] = -1;                   // sets the first element of da to -1
da[0] += 1;                   // increments the first element of da by 1
da.print()                    // print the array, elements separated by two spaces
```

