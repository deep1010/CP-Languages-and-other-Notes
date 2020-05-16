# Standard Template Library 
## C++ (Geeks for Geeks)

### Sorting

-   sort(startaddress, endaddress,comp_func)

    -    startaddress: the address of the first element of the array
    -   endaddress: the address of the next contiguous location of the last element of the array.
    -   comp_func: the comparator function for specifiying the order & method to compare for sorting.
    -   ``` c
            bool comp_func(<datatype> a, <datatype> b){
                if (comparision)
                    return true;
                else
                    return false;
            }
        ```
    -   Internally this function is implemented as Quick-sort. The complexity of it is O(N*log(N))

### Searching

-   binary_search(startaddress, endaddress, valuetofind)
    -   startaddress: the address of the first element of the array.
    -   endaddress: the address of the last element of the array.
    -   valuetofind: the target value which we have to search for.
    -   requires the array to be sorted before search is applied.
    -   returns boolean value

-   lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’.

-   upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘x’. 

### Miscellaneous

-   sort(first_iterator, last_iterator) – To sort the given vector.
-   reverse(first_iterator, last_iterator) – To reverse a vector.

-   *max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
-   *min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
-   accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements

-   next_permutation(first_iterator, last_iterator) – This modified the vector to its next permutation.
-   prev_permutation(first_iterator, last_iterator) – This modified the vector to its previous permutation.

-   count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
-   find(first_iterator, last_iterator, x) – Points to last address of vector ((name_of_vector).end()) if element is not present in vector. 

### Containers
-   Sequence Containers:
    -   Vectors:
        -   declaration:
            ``` c
            vector<datatype> varible_name;
            ```
        -   begin() – Returns an iterator pointing to the first element in the vector
        -   end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
        -   size() – Returns the number of elements in the vector.
        -   empty() – Returns whether the container is empty.
        -   reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
        -   at(g) – Returns a reference to the element at position ‘g’ in the vector
        -   front() – Returns a reference to the first element in the vector
        -   back() – Returns a reference to the last element in the vector
        -   assign() – It assigns new value to all the vector elements by replacing old ones
            ``` c
                vector_name.assign(array_size,value)
            ```
        -   push_back() – It push the elements into a vector from the back
        -   pop_back() – It is used to pop or remove elements from a vector from the back.
        -   insert() – It inserts new elements before the element at the specified position
        -   erase() – It is used to remove elements from a container from the specified position or range.
        -   swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
        -   clear() – It is used to remove all the elements of the vector container
    -   Queue:
        -   declaration:
            ``` c
                queue<datatype> queue_name;
            ```
        -   empty() – Returns whether the queue is empty.
        -   size() – Returns the size of the queue.
        -   front() – returns a reference to the first element of the queue. 
        -   back() – function returns a reference to the last element of the queue.
        -   push(g) – adds the element ‘g’ at the end of the queue. 
        -   pop() – function deletes the first element of the queue.

    -   Stack:
        -   declaration:
            ``` c
                stack<datatype> stack_name;
            ```
        -   empty() – Returns whether the stack is empty – Time Complexity : O(1)
        -   size() – Returns the size of the stack – Time Complexity : O(1)
        -   top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
        -   push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
        -   pop() – Deletes the top most element of the stack – Time Complexity : O(1)
    -   Priority Queue:
        -   Priority queues are a type of container adapters, specifically designed such that the first element of the queue is the greatest of all elements in the queue and elements are in non decreasing order.
        -   Functionalities are same as normal queue.
        -   declaration:
        ``` c
        priority_queue <int> var_name;
        ```
        -   Comparators for using priority_queue for a modified data_structure
        ``` c
            struct Person { 
                int age; 
                float height; 
            }; 
            
            // this is an strucure which implements the 
            // operator overlading 
            struct CompareHeight { 
                bool operator()(Person const& p1, Person const& p2) 
                { 
                    // return "true" if "p1" is ordered  
                    // before "p2", for example: 
                    return p1.height < p2.height; 
                }
            }; 
            // how to initialize this p_queue
            priority_queue<Person, vector<Person>, CompareHeight> queue_name; 
        ```
    -   Double Ended Queue:
        -   deque::push_front() in C++ STL: This function is used to push elements into a deque from the front.
        -   deque::push_back() in C++ STL: This function is used to push elements into a deque from the back.
        -   deque::pop_front() and deque::pop_back() in C++ STL: pop_front() function is used to pop or remove elements from a deque from the front. pop_back() function is used to pop or remove elements from a deque from the back.
        -   deque::front() and deque::back() in C++ STL: front() function is used to reference the first element of the deque container. back() function is used to reference the last element of the deque container.
        -   deque::clear() and deque::erase() in C++ STL: clear() function is used to remove all the elements of the deque container, thus making its size 0. erase() function is used to remove elements from a container from the specified position or range.
        -   deque::empty() and deque::size() in C++ STL: empty() function is used to check if the deque container is empty or not. size() function is used to return the size of the deque container or the number of elements in the deque container.

-   Associative Containers:
    -   Set:
        -   Sets are a type of associative containers in which each element has to be unique, because the value of the element identifies it. The value of the element cannot be modified once it is added to the set, though it is possible to remove and add the modified value of that element.
        -   begin() – Returns an iterator to the first element in the set.
        -   end() – Returns an iterator to the theoretical element that follows last element in the set.
        -   size() – Returns the number of elements in the set.
        -   empty() – Returns whether the set is empty.
        -   insert(const g) – Adds a new element ‘g’ to the set.
        -   erase(iterator position) – Removes the element at the position pointed by the iterator.
        -   erase(const g)– Removes the value ‘g’ from the set.
        -   clear() – Removes all the elements from the set.
        -   find(const g) – Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
        -   count(const g) – Returns 1 or 0 based on the element ‘g’ is present in the set or not.
        -   lower_bound(const g) – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in      the set.
        -   upper_bound(const g) – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will go after the element ‘g’ in the       set.
    -   Map:
        -   Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values     can have same key values.
        -   begin() – Returns an iterator to the first element in the map
        -   end() – Returns an iterator to the theoretical element that follows last element in the map
        -   size() – Returns the number of elements in the map
        -   max_size() – Returns the maximum number of elements that the map can hold
        -   empty() – Returns whether the map is empty
        -   pair insert(keyvalue, mapvalue) – Adds a new element to the map
        -   erase(iterator position) – Removes the element at the position pointed by the iterator
        -   erase(const g)– Removes the key value ‘g’ from the map
        -   clear() – Removes all the elements from the map
        -   example for insert and accesing value for a key.
            ``` c
                //For inserting
                map <datatype,datatype> map_name;
                map_name.insert(make_pair(key,value));
                
                // For accessing
                
                if(map_name.find(key)!=map_name.end())
                {
                    cout<<map_name[key]<<endl;
                }
            ```
    -   Multimap and Multiset: Same as normal map and set respectively, only difference being for multimap the key and value pair together should be unique rather than the key only, whereas for multiset more than one element with same value is allowed
    -   unordered_set and unordered_map: Same as set and map respectively, only difference being,the elements are not stored in some specific order, rather a hash table is used for the same. Due to which the average look-up reduces from O(logn) to O(1).
