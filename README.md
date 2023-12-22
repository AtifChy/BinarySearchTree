# Binary Search Tree in C++

This project is a simple implementation of a Binary Search Tree (BST) in C++. It includes methods for insertion, deletion, searching, and traversing the tree in different orders (inorder, preorder, postorder).

## Structure

The project contains a `Node` struct and a `BST` class. The `Node` struct represents a node in the BST, and the `BST` class contains the implementation of the BST.

## Usage

To use this project, you can create a `BST` object and call its methods. Here's an example:

```cpp
BST bst;

bst.insertion(14);
bst.insertion(8);
bst.insertion(3);
bst.insertion(7);
bst.insertion(2);
bst.insertion(22);
bst.insertion(15);
bst.insertion(10);
bst.insertion(19);

bst.inorderTraverse();

bst.deletion(15);
bst.deletion(2);

bst.inorderTraverse();

bst.searching(15);
```

In this example, we first insert several values into the BST. We then traverse the BST in inorder and print the values. Next, we delete a couple of values from the BST and traverse it again. Finally, we search for a value in the BST.

## Building

This project uses CMake for building. The minimum required version of CMake is 3.27. To build the project, you can use the following commands:

```sh
mkdir build
cd build
cmake ..
cmake --build . --config Release --
```

This will create an executable named `BinarySearchTree` in the `build/Release` directory.

## Contributing

Contributions are welcome. Please open an issue or submit a pull request if you would like to contribute.

## License

This project is open source and available under the [MIT License](LICENSE).
