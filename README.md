## Chunklist

## Introduction
A ChunkList is like a regular linked list, except each node contains a little
fixed size array of elements instead of just a single element. Each node also 
contains its own `len` int to know how full it is. This project was created under the guidance of Dr. Varick Erickson. Copyright (c) 2021 Varick Erickson.

The ChunkList object contains a head pointer to the first chunk, a tail 
pointer to the last chunk, and an int to track the logical size of the whole 
collection. When the size of the list is 0, the head and tail pointers are 
null.  

- Each chunk contains a fixed size `T[]` array, an int to track how full the chunk is, and a pointer to the next chunk.
The type `T` should be defined by the template as shown in the examples given in
class.

- There should be a constant ARRAY_SIZE = 8 that defines the fixed size of the
  array of each chunk. Elements should be added to the array starting at its
  0 index.

- `listLen` shows the length of the entire length.  `len` shows the length 
  of a node.

- An empty ChunkList should be implemented as null head and tail pointers.
Your ChunkList should allocate chunks only when actually needed and delete 
them when no longer needed.

## Function Description

Each section below describes how each function should behave. 

---

## `ChunkList()`
The default constructor should create an empty ChunkList.  An empty 
ChunkList should be implemented as null head and tail pointers.  Initialized the variables related to the iterator.

---

## `ChunkList(T[] arr, arrLen)`
This constructs a ChunkList using the values from arr.  It should append all 
the values from `arr` to the list. The parameter `arrLen` is the length of arr.
If `arrLen` is an invalid array length, it should throw a `InvalidArrayLength
()`.  Initialize the iterator to start at the beginning of the list. `Append` function used here.

---

## `~ChunkList();`
This is the deconstructor for the list.  It will remove all the nodes in the 
list. 

---

## `bool IsEmpty()`
This function should return true if the list is empty.

---

## `int GetLength()`
GetLength should return the length of the entire list. It does not return 
the number of nodes/chunks. 

---

## `double LoadFactor()`

The load factor is the following value tells us what percentage of the 
ChunkList is actually storing items.  It is calculated using the following:

```
load factor = listLen/(total number of spots in the ChunkList)
```
This function should throw an `EmptyList()` error if
the list is empty.
> **Example:**
>
> The load factor of the the following ChunkList is
> 
> ```load factor = 16/(8*4) = 0.5```
> 
> This means that only 50% of the ChunkList space is being used to store 
> items.  The other 50% is empty.

---

## `bool Contains(T value)`
This function returns true if `value` exists in the ChunkList.  To do this,
you need to check the array of each node until you find `value` or you reach
the end of the list without finding `value`. This function should throw an `EmptyList()` error if
the list is empty and you attempt to find an item.

---

## `void Append(T value)`
This function appends `value` to the end of the list.  This function should 
do the following.
  - Attempt to add the value to the last position of the last node
  - If the last node is full when you try to add `value`, then a new node should 
    be created and placed at the end of the list. `value` can then be added 
    to this new last node.

---

## ```void Remove(T value)```
This function should find the ***first*** instance of value and remove it 
from the list.  When it removes the element, ***it should preserve the order of 
the list***.  In other words, the order of the other elements of the list 
should not be changed.  Shift elements in the node in order 
to accomplish this.  This function should throw an `EmptyList()` error if 
the list is empty and you attempt to remove an item.

---

## `T GetIndex(int i)`

`GetIndex(i)` returns the value at index i with reference to the entire list.
For example, for the list given at the beginning of the assignment, `GetIndex
(8)` would return the 0th element of the second node, which is the value 9.

This function should throw an `EmptyList()` error if
the list is empty.  It should also throw an `IndexOutOfBounds()` error if 
provided a bad index.

Good implementations should be able to "skip" over nodes if it is known that 
the index i is not within the node.  

---

## `void ResetIterator()`
This function should set the `iterNode` to the first node of the list and 
set the `arrPos` to point to the first index.


## `T GetNextItem()`
This function returns the current item and moves to next item in the list.  
It should work exactly the same way as the other iterators we covered in class.  
It should throw an `IteratorOutOfBounds()` error if the user tries to get 
another item and no item is available.
