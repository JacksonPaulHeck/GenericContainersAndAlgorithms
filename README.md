# Fall 2021 CS 3353 PA 02

## By: JP Heck and Garrett Webb

## Introduction

This is the repository for program 2 in the Fall 2021 Algorithms Class at Southern Methodist University.

Created by Jackson Paul Heck and Garrett Webb

## Description of Problem

We are tasked with creating 3 different data structures that are used frequently in c++

- Custom Vector
  - Includes Forward and Random Access Iterators
- Custom List(Linked List)
  - Includes Forward Iterator
- Custom Dictionary(Binary AVL Tree)
  - Includes Forward Iterator

We were then given the task of creating 4 algorithms that would work on these objects

- Find
  - Using Forward Iterators
- Insertion Sort
  - Using Random Access Iterators
- Quick Sort
  - Using Random Access Iterators
- Heap Sort
  - Using Random Access Iterators

Finally we needed to test the sorting algorithms and analyze the results. This was done by generating data sets of random integers and random strings. These sets that are generated are organized in the following order:

- randomized dataset of size s with 0% duplicates
- dataset of size s with 0% duplicates that is sorted in ascending order
- dataset of size s with 0% duplicates that is sorted in descending order
- randomized dataset of size s with 20% duplicates
- randomized dataset of size s with 40% duplicates

Where s is the given size of the data set.

We ran this algorithm with varying data sizes to collect timing data to analyze the performance of the algorithms.

## How to Build/Execute

- Navigate into project folder "21f-pa01-jp-and-garretts-cool-kids-team-reloaded"
- Run `g++ -g src/main.cpp src/DataGen.cpp src/Driver.cpp` to compile the project
- Run `./a.out test/input.txt output/data.csv` to run the project

## Sample I/O

Input:

```
    100
    200
    300
    400
    500
    600
    700
    800
    900
    1000
    2000
    3000
```

test-custom.txt Output:

```
  100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000
  Insertion Sort Ascending Integer:
  2.09512, 0.068547, 0.144509, 0.189482, 0.237652, 0.276534, 0.317611, 0.364648, 0.425581, 0.337909,
  Insertion Sort Descending Integer:
  2.70097, 7.0573, 18.4014, 27.7544, 43.8059, 64.7361, 84.4331, 112.301, 140.777, 177.36,
  Insertion Sort Random Integer:
  1.45544, 3.71492, 8.27965, 14.3915, 23.4318, 31.0049, 44.6858, 55.6858, 69.9045, 89.9605,
  Insertion Sort Random 20% Integer:
  1.32865, 2.91412, 6.20241, 11.1881, 17.3887, 25.4339, 32.9232, 43.3329, 53.4745, 66.2306,
  Insertion Sort Random 40% Integer:
  1.58407, 3.79403, 8.32822, 16.5888, 20.9302, 31.2234, 42.1044, 54.9985, 68.9289, 87.3169,
  Insertion Sort Ascending String:
  9.82392, 29.5812, 68.1476, 118.518, 184.809, 264.222, 361.362, 470.324, 592.906, 739.118,
  Insertion Sort Descending String:
  0.824423, 0.152854, 0.217654, 0.289889, 0.370329, 0.434929, 0.501963, 0.584367, 0.651902, 0.725799,
  Insertion Sort Random String:
  4.48294, 17.4707, 32.028, 57.2053, 94.4938, 142.324, 179.923, 241.548, 304.651, 375.954,
  Insertion Sort Random 20% String:
  3.7848, 13.1208, 24.2983, 44.1515, 70.3619, 109.045, 133.424, 185.326, 229.182, 275.331,
  Insertion Sort Random 40% String:
  4.19937, 16.8732, 32.8529, 59.7524, 89.9961, 145.586, 184.627, 240.548, 303.543, 363.294,
  Quick Sort Ascending Integer:
  3.16581, 3.27903, 7.12097, 12.678, 19.3608, 27.4864, 38.8163, 48.0923, 60.956, 76.0759, 305.053, 678.379,
  Quick Sort Descending Integer:
  2.34213, 5.99833, 13.3309, 23.7644, 36.7388, 54.1833, 70.7118, 91.8624, 117.288, 143.527, 568.773, 1272.83,
  Quick Sort Random Integer:
  0.997134, 0.752579, 1.1381, 1.60198, 1.98828, 2.49525, 3.16989, 3.68413, 4.27179, 4.30974, 10.2452, 16.0245,
  Quick Sort Random 20% Integer:
  0.899723, 0.612129, 0.958422, 1.33614, 1.84035, 2.21854, 3.06852, 3.01325, 3.47044, 3.8498, 8.73263, 13.9835,
  Quick Sort Random 40% Integer:
  0.947512, 0.711563, 1.3083, 1.54571, 2.27306, 2.47695, 3.04122, 3.7719, 4.18193, 4.90342, 9.66232, 15.6586,
  Quick Sort Ascending String:
  7.18769, 18.0941, 40.2558, 71.0763, 110.743, 158.064, 215.553, 280.181, 354.044, 438.494, 1738.05, 3900.43,
  Quick Sort Descending String:
  2.61552, 7.55653, 16.3769, 28.8608, 44.2603, 64.3715, 85.8904, 113.102, 143.885, 172.866, 697.669, 1552.69,
  Quick Sort Random String:
  1.43581, 1.91386, 2.9151, 5.18297, 5.65904, 6.73489, 9.92059, 10.1614, 12.0223, 13.077, 29.2233, 44.3974,
  Quick Sort Random 20% String:
  1.41119, 1.8725, 2.63948, 4.02165, 5.22073, 6.20901, 7.66211, 10.2092, 9.5771, 10.6027, 24.6659, 36.7809,
  Quick Sort Random 40% String:
  1.46504, 2.04061, 2.97234, 4.47138, 5.55431, 7.63492, 9.08408, 9.06011, 12.0848, 12.9055, 26.9035, 43.6579,
  Heap Sort Ascending Integer:
  7.21791, 1.46811, 2.34398, 3.27378, 4.17699, 5.1605, 6.14759, 7.12192, 8.10096, 10.5087, 19.7508, 30.8938,
  Heap Sort Descending Integer:
  1.28668, 1.55442, 2.4367, 3.36413, 4.32067, 5.35758, 6.35891, 7.34764, 8.38551, 9.39878, 20.3178, 31.8198,
  Heap Sort Random Integer:
  1.24194, 1.48315, 2.331, 3.21094, 4.12905, 5.0575, 6.05972, 6.99747, 8.02337, 9.02327, 19.5024, 30.6342,
  Heap Sort Random 20% Integer:
  1.14921, 1.26775, 1.99815, 2.79037, 3.57859, 4.41551, 5.26461, 6.08024, 6.97586, 7.84416, 16.9747, 26.8439,
  Heap Sort Random 40% Integer:
  1.24305, 1.46897, 2.34137, 3.18449, 4.07207, 5.01596, 5.96954, 7.00855, 7.97993, 8.98554, 19.4333, 30.473,
  Heap Sort Ascending String:
  8.71352, 2.96991, 4.68282, 6.50365, 8.32533, 10.2622, 12.1434, 14.0459, 15.9468, 17.9823, 38.4595, 61.2065,
  Heap Sort Descending String:
  1.85531, 2.77773, 4.33084, 6.07106, 7.7439, 9.55018, 11.3549, 13.2378, 15.0847, 16.9617, 36.5688, 57.1902,
  Heap Sort Random String:
  1.85867, 2.83676, 4.41323, 6.17408, 7.92126, 9.71889, 11.4611, 13.3285, 15.0867, 16.9637, 36.5303, 57.0631,
  Heap Sort Random 20% String:
  1.71505, 2.42718, 3.81669, 5.21024, 6.8046, 8.26379, 9.88412, 11.4454, 13.0152, 14.6604, 31.6422, 49.3618,
  Heap Sort Random 40% String:
  1.86339, 2.84945, 4.44263, 6.1553, 7.96555, 9.74009, 11.4613, 13.4821, 16.565, 16.9614, 36.6366, 57.4326,
```

## Description of Data Structures

As you can see in the `src` folder, there are many `.h` files that were created for each structure.

- Vector

  - Our custom vector implementation can be found in `AlgoVector.h`
  - This implementation is simply a wrapper class for a templated array.

- List

  - Our custom list implementation can be found in `AlgoList.h` and `AlgoListNode.h`
  - This implementation is a singly linked list that uses a templated list node for any type of data

- Dictionary
  - Our custom dictionary implementation can be found in `AlgoDict.h` and `AlgoStack.h`
  - This implementation is a Binary AVL Tree that balances upon insertion into the tree.
  - The iterator for this structure required a stack object (FIFO) so we created the AlgoStack object that wraps the AlgoVector and makes it a FIFO object.

## Three Sorting Algorithms

There are three sorting algorithms that we were required to implement.

### Insertion Sort

This algorithm is implemented using Random Access Iterators. It first finds the minimum value in the object and swaps it with the beginning. It then iterates over the vector finding the next minimum value and swaps it with the current iterator in the vector. 

This required us to write the algo_min_element, algo_iter_swap, and algo_swap functions that are used by the top level algo_insertion_sort function.

### Quick Sort

This algorithm is implemented using Random Access Iterators. It first checks if the structure is empty. If not, then it sets a pivot. Because this is a simple implementation, we chose to set the first pivot as the beginning element. It then checks the rest of the array for elements that are smaller than the pivot and swaps them with the pivot. It then continues this recursively until the passed elements are the same, halving the size each recursive pass.

This required us to use the algo_iter_swap and algo_swap functions that were implemented for the insertion sort algorithm.

### Heap Sort

This algorithm is implemented using Random Access Iterators. It first makes the data into a heap structure and then uses the pop_heap function and adjust_heap function to sort the heap.

This required us to write the make_heap, pop_heap, push_heap, and adjust_heap functions that are used by the top level algo_heap_sort function.

## Performance Write-Up

For data generation, we began by writing the ascending data functions. This was straight-forward for integers. We just wrote a loop that would iterate the number of required times for the size of the data and then each time added a randomly generated number (using rand()) to the previous value and added it to the vector. Strings were a very different story. Because it is not as straight forward to generate a random string "jumping" up by a random value, we decided to utilize our Dictionary object which by nature orders in ascending order. A random string would be generated and added to the Dictionary object using the insert() function. Then the data would be parsed through and added to a vector. This produces a vector of strings sorted in ascending order.

The next set of data to generate is the Descending order data. This is in fact straight-forward as well. Because our vector's size is known, we can iterate back to front and add the data in descending order that way.

Then the randomly ordered data was required. We at first began with creating new random data. However, this added a lot of time to our program's run time and because it is "random" it has the potential for worst-case runtime of never finishing. This was unacceptable. So, taking influences from the standard library, we implemented our own random_shuffle algorithm. Applying this to the ascending data and copying it to another vector, we were able to generate randomly sorted data.

Finally we needed to generate a random dataset with a certain number of duplicates included in it. We did this in a similar way to the random dataset with 0% duplication. By parsing through and adding the data from the random vector. However, the difference was how many times the data was added each time. By checking each time that a value is added the size of the dataset, for 20% duplication, we added an additional copy of a specific value each time that the size was divisible by 5 (size % 5 == 0). Similarly, for 40% duplication, we added three additional copy of a specific value each time that the size was divisible by 10 (size % 10 == 0). This gave us datasets with repeating values.

### Specific performance based on sorting algorithm

As can be seen in ```writeup/data.xlsx```, there are 6 graphs depicting the different sorting algorithms and their performance based on the type (arrangement) of data that is given.

#### Insertion Sort

For insertion sort, ascending data was the easiest for the algorithm to sort. It simply required one pass over the vector and no swaps. This means that the time taken for the algorithm was minimal. Descending data was the worst for the insertion sort algorithm as it requires the most number of passes through the vector. Random data and Random 40% Dupe data seemed to have almost duplicate performance with Random 20% being the second fastest: behind Ascending.

#### Quick Sort

For quick sort, both ascending and descending data took much longer for the algorithm to sort than any of the random datasets. This is because with both, the quick sort algorithm requires a similar number of passes through, however, for random datasets, it may require less swaps. Quick sort took the longest amount of time for the data given, however, this is not true in general. It beats insertion sort if the dataset is signifigantly larger.

#### Heap Sort

For heap sort, all of the datasets took a similar amount of time. This is because of the heapification process. This algorithm has a similar number of accesses regardless of how the data is sorted. Because of this, the algorithm is very consistent. But, at very large data sizes it loses out to quicksort. But for the mid-range of data sizes that are shown in these graphs, in general, heap sort is the algorithm to go with. 

### Comparative Performance and Interesting Takeaways

If I were to choose a certain algorithm to sort a general dataset size, I would choose heap sort because of it's consistency no matter the configuration of the generated data. However, If I knew the data was going to be in ascending or almost ascending order, I would choose Insertion sort. Quick sort would be the algorithm I go with if the dataset is extremely large. 

An interesting and noticeable effect the character data seemed to have on the relative speed of the algorithms was drastically increasing the time taken to sort ascending sets without proportionally similar change to time taken to sort other sets (e.g. see "Quick Sort Performance on Integer Sets" and "Quick Sort Performance on String Sets" in data.xlsx).

Overall, when compared to one another, the different sorting algorithms' relative performances seem to replicate the findings of the Data Structures sorting algorithm project. However, every algorithm's time taken inexplicably seems to spike on the first set in the ascending order group. This is believed to be computer error, or likely another action is being timed in addition to the sorting itself (e.g. see "Heap Sort Performance on Integer Sets"). However, we were unable to identify the true source of this issue.

## Verification of sorting

Included in the ```Algorithm.h``` file, there are functions that can check if the data is sorted in ascending, descending, and random order(not ascending or descending). These simply do a pass through checking if the previous value fulfills the required qualities to tell if it is ascending. If the previous number is less than the next, then the data is sorted in ascending order. After all the algorithms complete, the data is then run through the algo_check_ascending function to check if it is sorted or not.