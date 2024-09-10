# Dynamic Tables


In this assignment we try to verify if the idea of doubling a dynamic array every time it needs to be resized is a winning strategy in terms of performance.

NOTE - you are not allowed to use C++ libraries or data structures such as `vector`. In this assignment we will use only basic C arrays.


### Step 1 - Setup

The `main.cpp` file provides the code needed to test your implementation of the Dynamic Table. Nothing to be changed here for now.

`Time.*` are two external libraries that will help you estimating the time required for performing certain operations. Nothing to be changed here.

`DynamicTable.*` contains the DynamicTable class that you have to implement. Before starting with that, let's try to compile the project to check that everything is ready.

If you are familiar with `cmake`, I am already providing a cmake file for compiling the project. In this case just run the following commands:

```bash
mkdir build
cd build
cmake ..
make
```
you should obtain the executable named `dynamicTable` in the `build` directory.


If you do not want to use cmake you can compile the program from the main folder with the following command.

```bash
g++ main.cpp DynamicTable.cpp Timer.cpp -o dynamicTable
```

### Step 2 - Implementing the Dynamic Table

As we have seen in class, a dynamic table is an array that automatically resize itself when it gets full. This can be implemented by combining two simple functions, `insert` and `resize`.

* Header file - Start from `DynamicTable.h`, and implement the constructor and destructor of the table. This are the functions called when you create a new Dynamic Table or when you don't need it anymore.

* Implementation - Now implement the two functions insert and resize in `DynamicTable.cpp`. You have two methods for resizing the array. The objective of this assignment is to compare these two methods:

    * `resize_dummy` is supposed to resize the array by adding only one empty slot every time the array is full
    * `resize` is supposed to double the size of the array.
    * `insert` has a boolean value in input used to decide whether you will call `resize` or `resize_dummy` upon insertion.

### Step 3 - Testing and Evaluation

According to `main.cpp` we are inserting an integer (just the value `i`, we don't really care about semantic now) into our array `n_insertions` times. Run the program with increasing values of `op` to check that everything is correct and no segmentation faults are happening. 

Once you are confident your implementation is working, uncomment the lines corresponding to STEP 3 in `main.cpp`

Now we are going to use `Timer` to start tracking the time needed to perform the insertions into a table. Start modifying the value `n_insertions` using increasing values for your insertions. For example, 10, 100, 1000, 3000.

What results are you obtaining in terms of time? How can you justify such a behavior and increase in time performance?

For n_insertions = 10, the runtimes were: resize_dummy: 5.20e-06 seconds | resize: 4.39996e-06 seconds

For n_insertions = 100, the runtimes were: resize_dummy: 9.915e-04 seconds | resize: 9.9e-05 seconds

For n_insertions = 1000, the runtimes were: resize_dummy: 0.420546 seconds | resize: 5.9688e-03 seconds

For n_insertions = 3000, the runtimes were: resize_dummy: 9.00 seconds | resize: 0.0520946 seconds

The increase in time performance is due to the fact that loops are very expensive in runtime. As there are many more loops
and copies that have to be made in order to increase 1 space at a time compared to quadratically expanding the space means
that runtime and memory performance is much better. In summary, loops and copies are expensive, and the resize dummy has a
lot more loops and copying than the resize. Thus, it runs much quicker. 

### Step 4 - Visualize results [OPTIONAL]

This step should be easy if you already have a python environment installed in your system. If not, feel free to ignore this step or reach out to the professor or TAs for help. Either way, it won't affect the assignment final grade

Uncomment the lines corresponding to step 4 in the `main.cpp` file
Once the program has been executed you should get two files in output called `results.txt` and `results_dummy.txt`. If you are familiar with python you can run the following commands to get a graphical representation of the timings (be sure that `plot_results.py` and `results.txt` are in the same folder when you run it)

```bash
python plot_results.py
python plot_results_dummy.py
```

No python runtime installed, I've never used python. :(

### Step 5 - Wrap up and submitting on Gradescope

When you are ready to submit perform the following actions
- comment all the code marked as Step 3 or Step 4. Your submitted code should print in output only the result of the following line `cout << table1.get_n_resize() << " " << table2.get_n_resize() << endl;`.
- set `n_insertions=3000`
- push all your code on Github.
- access Gradescope and upload code and readme files [`CMakeLists.txt`, `main.cpp`, `DynamicTable.cpp`,`DynamicTable.h`,`Timer.cpp`,`Timer.h`].

If everything is uploaded correctly the autograder will run with no issues.