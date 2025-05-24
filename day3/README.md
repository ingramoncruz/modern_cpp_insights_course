# pointers

* Raw POINTERS ->

int *ptr = new int[100]; //array - 100 -> 400 bytes
delete[] ptr;            // no delete -> memory leak

* Smart Pointers -> automated delete -> no memory leaks -> safe code -> easy to use

Smart pointer - types are 
0. auto_ptr(deprecated)
1. uniqiue_ptr
2. shared_ptr
3. weak_ptr


# std::auto_ptr - deprecated since c++11, removed in c++17
* Maintains single ownership for a resource
* auto deleteion of resources
Library (template) base implementation

# std::unique_ptr
* Maintains single ownership for a resource
* Auto deletion of resources
* Supports only move emantics, no copy semantics

# std::shared_ptr
* multiple ownership
* allows both copy and move semantics
* auto deletion of resources

# std::weak_ptr
* No ownership smart pointer
* It actually references to an object which is managed by a shared_ptr
* Without using shared_ptr you can not use weak_ptr
* Weak pointer is created as a copy of shared_ptr
* It is used to remove the circular depedency between shared_ptr
* We have to convert weak_ptr to shared_ptr in order to use managed object
